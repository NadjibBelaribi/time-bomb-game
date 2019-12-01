#include "../headers/Host.h"

Host::Host (const string pseudo, const size_t nbClients, const in_port_t port, void (*gameCallback) (gstate &gst), void (*tchatCallback) (const gmess &mess))
{
    this->state = Host::Waiting;
    this->pseudo = pseudo;
    this->nbClients = nbClients;
    this->port = htons(port);
    this->gameCallback = gameCallback;
    this->tchatCallback = tchatCallback;

    this->sckCreate();
    this->sckBind();
    this->sckListen();

    for (size_t i = 0; i < nbClients; i ++)
        this->sckAccept();
}

void Host::sckBind ()
{
    struct sockaddr_in6 saddr;
    memset(&saddr, 0, sizeof(struct sockaddr_in6));
    saddr.sin6_family = AF_INET6;
    saddr.sin6_addr = in6addr_any;
    saddr.sin6_port = this->port;

    if (bind(this->sck, (struct sockaddr *) &saddr, sizeof(struct sockaddr_in6)) == -1) {
        perror("bind");
        exit(1);
    }
}

void Host::sckListen ()
{
    if (listen(this->sck, 10) == -1) {
        perror("listen");
        exit(1);
    }
}

void Host::sckAccept ()
{
    struct sockaddr_in6 saddr;
    socklen_t saddrLen = sizeof(saddr);
    int newSck = accept(this->sck, (struct sockaddr *) &saddr, &saddrLen);
    if (newSck == -1) {
        perror("newSck");
        exit(1);
    }
    this->sockets.push_back(newSck);

    // launch thread
    thread *thd = new thread(&Host::thread_wait, this, newSck);
    this->threads.push_back(thd);
}

void Host::thread_wait (const int sck)
{
    string *pseudo = nullptr;
    while (1) {
        gsdata *gsd = this->sckWait(sck);
        if (!gsd)
            return;
        if ((pseudo == nullptr) && (this->clients.size() >= this->nbClients)) {
            close(sck);
            return;
        }

        if ((pseudo == nullptr) && (gsd->req == CreqJoin)) {
            cout << "CREQ JOIN" << endl;
            // data <= pseudo
            pseudo = new string((const char *) gsd->data, gsd->dataLen);
            client cl;
            cl.pseudo = *pseudo;
            cl.sck = sck;
            cout << "pseudo = " << *pseudo << endl;
            this->clients.push_back(cl);
            if (this->clients.size() >= nbClients)
                this->startGame();
        } else if (gsd->req == CreqTchat) {
            cout << "CREQ  TCHAT" << endl;
            // data <= message
            gmess mess;
            mess.player = *pseudo;
            mess.mess = string((const char *) gsd->data, gsd->dataLen);
            mess.time = time(nullptr);

            this->addTchatMess(mess);
        } else if (gsd->req == CresPlay) {
            cout << "CRES  PLAY" << endl;
            // data <= <playerPseudo>:<cardNum>
            const string data((const char *) gsd->data, gsd->dataLen);
            vector<string> vec = this->split(data, ':');
            const string target = vec.at(0);
            uint8_t cardNum = stoi(vec.at(1));
            this->gameNext(target, cardNum);
        }
    }
}

void Host::addTchatMess (const Host::gmess &mess)
{
    if (sem_wait(&this->sem) == -1) {
        perror("sem_wait");
        exit(1);
    }

    this->tchat.push_back(mess);
    this->tchatCallback(mess);

    if (sem_post(&this->sem) == -1) {
        perror("sem_post");
        exit(1);
    }
}

void Host::gameNext (const string &cardPlayer, const uint8_t &cardNum)
{
    if (sem_wait(&this->sem) == -1) {
        perror("sem_wait");
        exit(1);
    }

    Player *player = nullptr;
    for (vector<Player>::iterator it = this->game->getPlayers().begin(); it != this->game->getPlayers().end(); it ++) {
        if ((*it).getPseudo() == cardPlayer) {
            player = &(*it);
            break;
        }
    }

    if (player == nullptr) {
        cerr << "gameNext: player == nullptr" << endl;
        return;
    }

    if (cardNum >= player->getCards().size()) {
        cerr << "gameNext: cardNum >= player->getCards().size()" << endl;
        return;
    }

    Card &card = player->getCards().at(cardNum);
    this->game->next(card);
    this->gst.currentPlayer = this->game->getCurrentPlayer().getPseudo();
    this->gst.gameState = this->game->getState();
    this->gst.lastCardRevealed = card.getType();

    if (this->gst.lastCardRevealed == Card::Defusing)
        this->gst.nbDefusingFound ++;

    if (this->gst.round < this->game->getRound()) {
        this->gst.round = this->game->getRound();
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

    // call callback
    sync();
    this->gameCallback(this->gst);

    if (sem_post(&this->sem) == -1) {
        perror("sem_post");
        exit(1);
    }
}

void Host::sync ()
{
    // message: <gameState>:<currentPlayer>:<lastCardRevealed>:<round>
    string str = "";
    str.append(to_string(this->gst.gameState));
    str.push_back(':');
    str.append(this->gst.currentPlayer);
    str.push_back(':');
    str.append(to_string(this->gst.lastCardRevealed));
    str.push_back(':');
    str.append(to_string(this->gst.round));
    const char *cStr = str.c_str();

    for (vector<client>::iterator it = this->clients.begin(); it != this->clients.end(); it ++)
        this->sendReq(HreqSync, cStr, (*it).sck);
}

void Host::startGame ()
{
    cout << "STARRTGAME" << endl;
    string *pseudosArr = new string[this->clients.size() + 1];
    string pseudos = ""; // <pseudo1>:<pseudo2>:...:<pseudoN>
    bool first = true;
    size_t i = 0;
    for (vector<client>::iterator it = this->clients.begin(); it != this->clients.end(); it ++, i ++) {
        if (!first)
            pseudos.push_back(':');
        first = false;
        pseudos.append((*it).pseudo);
        pseudosArr[i] = (*it).pseudo;
    }

    // ajouter mon pseudo
    pseudos.append(this->pseudo);
    pseudosArr[i ++] = this->pseudo;

    // send pseudos to clients
    for (vector<client>::iterator it = this->clients.begin(); it != this->clients.end(); it ++)
        this->sendReq(HreqStart, pseudos.c_str(), (*it).sck);

    // start this->game
    this->game = new Game(i, pseudosArr);
    this->state = Playing;
    this->gst.currentPlayer = this->game->getCurrentPlayer().getPseudo();
    sync();
    this->gameCallback(this->gst);
}
