#include "../headers/Host.h"

Host::Host (const string pseudo, const size_t nbClients, const in_port_t port, void (*gameCallback) (const gstate &gst))
{
    this->state = Host::Waiting;
    this->pseudo = pseudo;
    this->nbClients = nbClients;
    this->port = htons(port);
    this->gameCallback = gameCallback;

    if (!this->sckBind())
        return;
    if (!this->listen())
        return;

    while (1) {
        if (!this->sckAccept())
            return;
        if (this->clients.size() >= this->nbClients)
            break;
    }
}

bool Host::sckBind ()
{
    struct sockaddr_in6 saddr;
    saddr.sin6_family = AF_INET6;
    saddr.sin6_addr = in6addr_any;
    saddr.sin6_port = this->port;

    if (bind(this->sck, (struct sockaddr *) &saddr, sizeof(struct sockaddr_in6)) == -1) {
        this->putError();
        return false;
    }

    return true;
}

bool Host::sckListen ()
{
    if (listen(this->sck, 10) == -1) {
        this->putError();
        return false;
    }
}

bool Host::sckAccept ()
{

    struct sockaddr_in6 saddr;
    socklen_t saddrLen = sizeof(saddr);
    int newSck = accept(this->sck, (struct sockaddr *) &saddr, &saddrLen);
    if (newSck == -1) {
        this->putError();
        return false;
    }
    this->sockets.push_back(newSck);

    // launch thread
    thread *thd = new thread(this->thread_wait, newSck);
    this->threads.push_back(thd);

    return true;
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
            // data <= pseudo
            *pseudo = string((const char *) gsd->data, gsd->dataLen);
        } else if (gsd->req == CreqTchat) {
            // data <= message
            gmess mess;
            mess.player = *pseudo;
            mess.mess = string((const char *) gsd->data, gsd->dataLen);
            mess.time = time(nullptr);

            this->addTchatMess(mess);
        } else if (gsd->req == CresPlay) {
            // data <= <playerPseudo>:<cardNum>
            const string data((const char *) gsd->data, gsd->dataLen);
            const string target = data.substr(0, data.find(":"));
            uint8_t cardNum = stoi(data.substr(1, data.find(":")));

            this->gameNext(target, cardNum);
        }
    }
}

void Host::addTchatMess (const Host::gmess &mess)
{
    if (sem_wait(&this->sem) == -1) {
        this->putError();
        return;
    }

    this->tchat.push_back(mess);
    this->tchatCallback(this->tchat);

    if (sem_post(&this->sem) == -1) {
        this->putError();
        return;
    }
}

void Host::gameNext (const string &cardPlayer, const uint8_t &cardNum)
{
    if (cardNum < 0) {
        cerr << "gameNext: cardNum < 0" << endl;
        return;
    }

    if (sem_wait(&this->sem) == -1) {
        this->putError();
        return;
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

    // call callback
    this->gameCallback(this->gst);

    if (sem_post(&this->sem) == -1) {
        this->putError();
        return;
    }
}

bool Host::sync ()
{
    // message: <gameState>:<currentPlayer>:<lastCardRevealed>
    string str = "";
    str.append(to_string(this->gst.gameState));
    str.push_back(':');
    str.append(this->gst.currentPlayer);
    str.push_back(':');
    str.append(to_string(this->gst.lastCardRevealed));
    const char *cStr = str.c_str();

    for (vector<client>::iterator it = this->clients.begin(); it != this->clients.end(); it ++) {
        if (!this->sendReq(HreqSync, cStr, (*it).sck))
            return false;
    }

    return true;
}
