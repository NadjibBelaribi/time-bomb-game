#include "../headers/Host.h"

Host::Host (const string pseudo, const size_t nbClients, const in_port_t port)
{
    this->state = Host::Waiting;
    this->pseudo = pseudo;
    this->nbClients = nbClients;
    this->port = htons(port);

    if (!this->sckBind())
        return;

    this->waitClients();
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

void Host::waitClients ()
{
    Host::gsdata *gsd;
    while (this->clients.size() < nbClients) {
        gsd = this->sckWait();
        if (gsd->req != Host::CreqJoin) {
            delete gsd;
            continue;
        }

        client cl;
        memcpy(cl.addr, gsd->addr, 16);
        cl.port = gsd->port;
        cl.pseudo.assign((const char *) gsd->data, gsd->dataLen);
        delete gsd;
        this->clients.push_back(cl);
    }
}

Card::typeCard Host::next (ssize_t cardN) // si curPlayer de Game et l'hôte, il faut mettre le numéro de carte qu'il choisi, sinon -1 (car autre player doit choisir)
{
    if (this->game->getState() != Game::Active) {
        cerr << "The game has ended and next was called" << endl;
        exit(1);
    }
    Host::client &curClient = this->findCurClient();

    if (curClient.pseudo == this->pseudo) {
        if (cardN == -1) {
            cerr << "next: cardN == -1 and the actual game player is the host" << endl;
            exit(1);
        }

        Card::typeCard cardType = this->game->next(this->game->getCurrentPlayer().getCards().at(cardN));

        this->sync();
        return cardType;
    }

    Host::gsdata *gsd;
    if (!this->sendReq(Host::HreqPlay, "", curClient.addr, curClient.port)) {
        cerr << "sendReq error" << endl;
        exit(1);
    }
    while (true) {
        gsd = this->sckWait();
        if (gsd == nullptr) {
            cerr << "sckWait error" << endl;
            exit(1);
        }
        if ((gsd->addr != curClient.addr) || (gsd->port != curClient.port)) {
            delete gsd;
            continue;
        }
        size_t cardNumber = atoi((const char *) gsd->data);

        delete gsd;
        Card::typeCard cardType = this->game->next(this->game->getCurrentPlayer().getCards().at(cardNumber));

        this->sync();
        return cardType;
    }
}
