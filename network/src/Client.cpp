#include "../headers/Client.h"

Client::Client (const string pseudo, const char * const hostAddr, const in_port_t hostPort, void (*gameCallback) (Client::gstate &gameState), void (*tchatCallback) (const gmess &mess))
{
    this->state = Waiting;
    this->pseudo = pseudo;
    this->hostPort = htons(hostPort);
    if (inet_pton(AF_INET6, hostAddr, this->hostAddr) == -1) {
        perror("inet_pton");
        return;
    }

    this->state = Waiting;
    this->gst.round = 1;
    this->gst.nbDefusingFound = 0;
    this->gameCallback = gameCallback;
    this->tchatCallback = tchatCallback;

    this->sckCreate();
    this->sckConnect();
    this->sendReq(CreqJoin, pseudo.c_str(), this->sck);

    this->sckThread = new thread(&Client::thread_wait, this);
}

Client::~Client ()
{
   close (this->sck);
}

void Client::sckConnect ()
{
    struct sockaddr_in6 saddr;
    memset(&saddr, 0, sizeof(struct sockaddr_in6));
    saddr.sin6_family = AF_INET6;
    saddr.sin6_port = this->hostPort;
    memcpy(saddr.sin6_addr.s6_addr, this->hostAddr, 16);
    if (connect(this->sck, (struct sockaddr *) &saddr, sizeof(struct sockaddr_in6)) == -1) {
        perror("connect");
        return;
    }
}

void Client::thread_wait ()
{
    gsdata *gsd = nullptr;
    while (true) {
        while ((gsd = this->sckWait(this->sck)) == nullptr);
        switch (gsd->req) {
            case HreqStart:
                this->gameStarted(gsd->data, gsd->dataLen);
                break;
            case HresJoin:
                this->joinedSuccess();
                break;
            case HreqSync:
                this->processSync(gsd->data, gsd->dataLen);
                break;
            case HreqTchat:
                this->addTchatMess(gsd->data, gsd->dataLen);
                break;
            case HreqEnd:
                this->end();
                break;
            default:
                cerr << "thread_wait: gsd->req non reconnue" << endl;
                return;
        }
    }
}

void Client::gameStarted (const unsigned char *data, const size_t len)
{
    // data = <nbPlayers>:<pseudo1>:...:<role1>:...
    string str ((const char *) data, len);
    vector<string> vec = this->split(str, ':');
    size_t i = 0, nbPlayers = 0, indMe = 0;
    for (vector<string>::iterator it = vec.begin(); it != vec.end(); it ++, i ++) {
        if (i == 0)
            nbPlayers = atoi((*it).c_str());
        else if (i <= nbPlayers) {
            if (*it == this->pseudo)
                indMe = i;
            else {
                this->gst.oPlayers.push_back(*it);
                this->gst.oNbCards.push_back(5);
            }
        } else {
            if (i == (indMe + nbPlayers))
                this->gst.role = (Player::rolePlayer) atoi((*it).c_str());
            else
                this->gst.oRoles.push_back((Player::rolePlayer) atoi(((*it).c_str())));
        }
    }
    this->gst.pseudo = this->pseudo;
    this->gst.nbCards = 5;
}

void Client::joinedSuccess ()
{
    this->state = Playing;
}

void Client::processSync (const unsigned char *data, const size_t len)
{
    // data = <gameState>:<currentPlayer>:<lastCardRevealed>:<round>:<card1Player>:...
    static bool first = true;
    string str ((const char *) data, len);
    vector<string> vec = this->split(str, ':');
    if (vec.size() < 5) {
        cerr << "processSync: vec.size() < 5" << endl;
        return;
    }

    const uint8_t oldRound = this->gst.round;
    this->gst.gameState = (Game::stateGame) stoi(vec.at(0));
    this->gst.currentPlayer = vec.at(1);
    this->gst.lastCardRevealed = (Card::typeCard) stoi(vec.at(2));
    this->gst.round = stoi(vec.at(3));

    if (this->gst.lastCardRevealed == Card::Defusing)
        this->gst.nbDefusingFound ++;

    if (this->gst.round > oldRound) {
        for (vector<uint8_t>::iterator it = this->gst.oNbCards.begin(); it != this->gst.oNbCards.end(); it ++)
            (*it) = 6 - this->gst.round; // LES AUTRES
        this->gst.nbCards = 6 - this->gst.round; // MOI
    } else if (!first) {
        if (this->gst.currentPlayer == this->gst.pseudo)
            this->gst.nbCards --; // MOI
        else {
            unsigned i = 0;
            for (vector<string>::iterator it = this->gst.oPlayers.begin(); it != this->gst.oPlayers.end(); it ++, i ++) {
                if ((*it) == this->gst.currentPlayer) {
                    this->gst.oNbCards.at(i) --; // LES AUTRES
                    break;
                }
            }
        }
    }

    // récupération de MES cartes
    this->gst.cards.clear();
    for (unsigned i = 0; i < this->gst.nbCards; i ++) {
        if ((4 + i) >= vec.size()) {
            // rectifier
            this->gst.nbCards --;
            break;
        }
        this->gst.cards.push_back((Card::typeCard) stoi(vec.at(4 + i)));
    }

    this->gameCallback(this->gst);
    first = false;
}

void Client::addTchatMess (const unsigned char *data, const size_t len)
{
    // data = <pseudo>:<message>
    string str ((const char *) data, len);
    vector<string> vec = this->split(str, ':');
    if (vec.size() != 2) {
        cerr << "addTchatMess: vec.size() != 2" << endl;
        return;
    }

    gmess mess;
    mess.player = vec.at(0);
    mess.mess = vec.at(1);
    mess.time = time(NULL);
    this->tchat.push_back(mess);
    this->tchatCallback(mess);
}

void Client::sendTchatMess (const Client::gmess &mess)
{
    string data (mess.mess);
    this->sendReq(CreqTchat, data.c_str(), this->sck);
}

void Client::end ()
{
    this->state = End;
    this->gameCallback(this->gst);
}

void Client::gameNext (const string &cardPlayer, const uint8_t &cardNum)
{
    string mess;
    mess.append(cardPlayer);
    mess.append(":");
    mess.append(to_string(cardNum));
    this->sendReq(CresPlay, mess.c_str(), this->sck);
}
