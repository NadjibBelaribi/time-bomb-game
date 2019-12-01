#include "../headers/Client.h"

Client::Client (const string pseudo, const char * const hostAddr, const in_port_t hostPort, void (*gameCallback) (Client::gstate &gameState), void (*tchatCallback) (const gmess &mess))
{
    this->state = Waiting;
    this->pseudo = pseudo;
    this->hostPort = htons(hostPort);
    if (inet_pton(AF_INET6, hostAddr, this->hostAddr) == -1) {
        perror("inet_pton");
        exit(1);
    }

    this->state = Waiting;
    this->gst.round = 1;
    this->gst.nbDefusingFound = 0;
    this->gst.players.push_back(pseudo);
    this->gst.playersNbCards.push_back(5);
    this->gameCallback = gameCallback;
    this->tchatCallback = tchatCallback;

    this->sckCreate();
    this->sckConnect();
    this->sendReq(CreqJoin, pseudo.c_str(), this->sck);

    if (sem_init(&this->sem, 0, 1) == -1) {
        perror("sem_init");
        exit(1);
    }

    this->sckThread = new thread(&Client::thread_wait, this);
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
        exit(1);
    }
}

void Client::thread_wait ()
{
    gsdata *gsd = nullptr;
    while (true) {
        if (sem_wait(&this->sem) == -1) {
            perror("sem_wait");
            exit(1);
        }

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
                this->addTchatMessage(gsd->data, gsd->dataLen);
                break;
            case HreqEnd:
                this->end();
                break;
            default:
                cerr << "thread_wait: gsd->req non reconnue" << endl;
                exit(1);
        }

        if (sem_post(&this->sem) == -1) {
            perror("sem_post");
            exit(1);
        }
    }
}

void Client::gameStarted (const unsigned char *data, const size_t len)
{
    // data = <pseudo1>:<pseudo2>:...:<pseudoN>
    string str ((const char *) data, len);
    vector<string> vec = this->split(str, ':');
    for (vector<string>::iterator it = vec.begin(); it != vec.end(); it ++) {
        this->gst.players.push_back(*it);
        this->gst.playersNbCards.push_back(5);
    }
}

void Client::joinedSuccess ()
{
    this->state = Playing;
}

void Client::processSync (const unsigned char *data, const size_t len)
{
    // data = <gameState>:<currentPlayer>:<lastCardRevealed>:<round>
    string str ((const char *) data, len);
    vector<string> vec = this->split(str, ':');
    if (vec.size() != 4) {
        cerr << "processSync: vec.size() != 4" << endl;
        exit(1);
    }

    const uint8_t oldRound = this->gst.round;
    this->gst.gameState = (Game::stateGame) stoi(vec.at(0));
    this->gst.currentPlayer = vec.at(1);
    this->gst.lastCardRevealed = (Card::typeCard) stoi(vec.at(2));
    this->gst.round = stoi(vec.at(3));

    if (this->gst.lastCardRevealed == Card::Defusing)
        this->gst.nbDefusingFound ++;

    if (this->gst.round > oldRound) {
        for (vector<uint8_t>::iterator it = this->gst.playersNbCards.begin(); it != this->gst.playersNbCards.end(); it ++)
            (*it) = 6 - this->gst.round;
    } else {
        unsigned i = 0;
        for (vector<string>::iterator it = this->gst.players.begin(); it != this->gst.players.end(); it ++, i ++) {
            if ((*it) == this->gst.currentPlayer) {
                this->gst.playersNbCards.at(i) --;
                break;
            }
        }
    }

    this->gameCallback(this->gst);
}

void Client::addTchatMessage (const unsigned char *data, const size_t len)
{
    // data = <pseudo>:<message>
    string str ((const char *) data, len);
    vector<string> vec = this->split(str, ':');
    if (vec.size() != 2) {
        cerr << "addTchatMessage: vec.size() != 2" << endl;
        exit(1);
    }

    gmess mess;
    mess.player = vec.at(0);
    mess.mess = vec.at(1);
    mess.time = time(NULL);
    this->tchat.push_back(mess);
    this->tchatCallback(mess);
}

void Client::sendTchatMess (string mess)
{
    if (sem_wait(&this->sem) == -1) {
        perror("sem_wait");
        exit(1);
    }

    this->sendReq(CreqTchat, mess.c_str(), this->sck);

    if (sem_post(&this->sem) == -1) {
        perror("sem_post");
        exit(1);
    }
}

void Client::end ()
{
    this->state = End;
    this->gameCallback(this->gst);
}

void Client::gameNext (const string &cardPlayer, const uint8_t &cardNum)
{
    if (sem_wait(&this->sem) == -1) {
        perror("sem_wait");
        exit(1);
    }

    string mess;
    mess.append(cardPlayer);
    mess.append(":");
    mess.append(to_string(cardNum));
    this->sendReq(CresPlay, mess.c_str(), this->sck);

    if (sem_post(&this->sem) == -1) {
        perror("sem_post");
        exit(1);
    }
}
