#include "../headers/Host.h"

Host::Host (const string pseudo, const size_t nbClients, const in_port_t port, void (*gameCallback) (gstate &gst), void (*tchatCallback) (const gmess &mess))
{
    this->state = Host::Waiting;
    this->pseudo = pseudo;
    this->nbClients = nbClients;
    this->port = htons(port);
    this->gameCallback = gameCallback;
    this->tchatCallback = tchatCallback;

    if (sem_init(&this->sem, 0, 1) == -1) {
        perror("sem_init");
        exit(1);
    }

    this->sckCreate();
    this->sckBind();
    this->sckListen();

    if (fcntl(this->sck, F_SETFL, O_NONBLOCK) == -1) {
        perror("fcntl");
        exit(1);
    }

    while (this->clients.size() < this->nbClients) {
        sleep(0.1);
        this->sckAccept();
    }


    if (sem_wait(&this->sem) == -1) {
        perror("sem_wait");
        exit(1);
    }
    this->startGame();
    if (sem_post(&this->sem) == -1) {
        perror("sem_post");
        exit(1);
    }
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
        if ((errno == EAGAIN) || (errno == EWOULDBLOCK))
            return;
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
    gsdata *gsd = nullptr;
    string *pseudo = nullptr;
    while (1) {
        while ((gsd = this->sckWait(sck)) == nullptr);
        if ((pseudo == nullptr) && (this->clients.size() >= this->nbClients)) {
            close(sck);
            return;
        }

        if (sem_wait(&this->sem) == -1) {
            perror("sem_wait");
            exit(1);
        }
        if ((pseudo == nullptr) && (gsd->req == CreqJoin)) {
            // data <= pseudo
            pseudo = new string((const char *) gsd->data, gsd->dataLen);
            if (this->pseudoExists(*pseudo)) {
                cerr << "Pseudo already exists: " << *pseudo << ", skipping it" << endl;
                if (sem_post(&this->sem) == -1) {
                    perror("sem_post");
                    exit(1);
                }
                close(sck);
                return;
            }
            client cl;
            cl.pseudo = *pseudo;
            cl.sck = sck;
            this->clients.push_back(cl);
            this->gst.oPlayers.push_back(*pseudo);
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
            vector<string> vec = this->split(data, ':');
            const string target = vec.at(0);
            uint8_t cardNum = stoi(vec.at(1));
            this->gameNext(target, cardNum);
        }

        if (sem_post(&this->sem) == -1) {
            perror("sem_post");
            exit(1);
        }
    }
}

void Host::addTchatMess (const Host::gmess &mess)
{
    this->tchat.push_back(mess);
    this->tchatCallback(mess);
    // send mess: <pseudo>:<message>
    string data (mess.player);
    data.push_back(':');
    data.append(mess.mess);

    for (vector<client>::iterator it = this->clients.begin(); it != this->clients.end(); it ++)
        this->sendReq(HreqTchat, data.c_str(), (*it).sck);
}

void Host::gameNext (const string &cardPlayer, const uint8_t &cardNum)
{
    Player *player = nullptr;
    vector<Player> &players = this->game->getPlayers();
    for (vector<Player>::iterator it = players.begin(); it != players.end(); it ++) {
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
    this->gst.lastCardRevealed = this->game->next(card);
    this->gst.currentPlayer = this->game->getCurrentPlayer().getPseudo();
    this->gst.gameState = this->game->getState();
    this->gst.round = this->game->getRound();
    this->gst.nbDefusingFound = this->game->getNbDefusingCardsRevealed();

    unsigned i;
    for (vector<Player>::iterator it = players.begin(); it != players.end(); it ++) {
        if ((*it).getPseudo() == this->gst.pseudo)
            this->gst.nbCards = (*it).getCards().size();
        else {
            i = 0;
            for (vector<string>::iterator it2 = this->gst.oPlayers.begin(); it2 != this->gst.oPlayers.end(); it2 ++, i ++) {
                if ((*it).getPseudo() == *it2)
                    this->gst.oNbCards.at(i) = (*it).getCards().size();
            }
        }
    }

    this->gst.cards = this->playerTypeCardsRandOrder(this->gst.pseudo);
    // call callback
    sync();
    this->gameCallback(this->gst);
}

void Host::sync ()
{
    // message: <gameState>:<currentPlayer>:<lastCardRevealed>:<round>:<card1Player>:...
    string str = "";
    str.append(to_string(this->gst.gameState));
    str.push_back(':');
    str.append(this->gst.currentPlayer);
    str.push_back(':');
    str.append(to_string(this->gst.lastCardRevealed));
    str.push_back(':');
    str.append(to_string(this->gst.round));

    for (vector<client>::iterator it = this->clients.begin(); it != this->clients.end(); it ++) {
        // rajouter les cartes du joueur
        string clientStr (str);
        vector<Card::typeCard> cards = this->playerTypeCardsRandOrder((*it).pseudo);
        for (vector<Card::typeCard>::iterator it2 = cards.begin(); it2 != cards.end(); it2 ++) {
            clientStr.push_back(':');
            clientStr.append(to_string(*it2));
        }

        this->sendReq(HreqSync, clientStr.c_str(), (*it).sck);
    }
}

void Host::startGame ()
{
    string *pseudosArr = new string[this->gst.oPlayers.size() + 1];
    string pseudos = ""; // <pseudo1>:<pseudo2>:...:<pseudoN>
    size_t i = 0;
    for (vector<string>::iterator it = this->gst.oPlayers.begin(); it != this->gst.oPlayers.end(); it ++, i ++) {
        pseudos.append(*it);
        pseudos.push_back(':');
        pseudosArr[i] = (*it);
    }

    // ajouter mon pseudo
    pseudos.append(this->pseudo);
    pseudosArr[i ++] = this->pseudo;
    // i => index de MOI

    // start this->game and init gst
    this->game = new Game(i, pseudosArr);
    this->state = Playing;
    this->gst.currentPlayer = this->game->getCurrentPlayer().getPseudo();
    this->gst.round = this->game->getRound();
    this->gst.gameState = this->game->getState();
    this->gst.nbDefusingFound = this->game->getNbDefusingCardsRevealed();
    this->gst.lastCardRevealed = Card::Safe; // juste pour ne pas faire geuler valgrind mdr

    // prepare mess for network and continue init gst
    this->gst.pseudo = this->pseudo;
    this->gst.nbCards = 5;
    this->gst.cards = this->playerTypeCardsRandOrder(this->gst.pseudo);
    vector<Player> &players = this->game->getPlayers();
    unsigned j = 0;
    string startMess (to_string(i));
    startMess.push_back(':');
    startMess.append(pseudos);

    for (vector<string>::iterator it = this->gst.oPlayers.begin(); it != this->gst.oPlayers.end(); it ++, j ++) {
        this->gst.oNbCards.push_back(5);
        for (vector<Player>::iterator it2 = players.begin(); it2 != players.end(); it2 ++) {
            if ((j == 0) && ((*it2).getPseudo() == this->pseudo))
                this->gst.role = (*it2).getRole();

            if (*it != (*it2).getPseudo())
                continue;
            startMess.push_back(':');
            startMess.append(to_string((*it2).getRole()));
            this->gst.oRoles.push_back((*it2).getRole());
        }
    }

    startMess.push_back(':');
    startMess.append(to_string(this->gst.role));

    // send start infos to clients
    // startMess = <nb_players>:<pseudo1>:...:<role1>:...
    for (vector<client>::iterator it = this->clients.begin(); it != this->clients.end(); it ++)
        this->sendReq(HreqStart, startMess.c_str(), (*it).sck);

    // sync + callback
    sync();
    new thread(&Host::gcWorkaround, this);
}

void Host::gcWorkaround ()
{
    this->gameCallback(this->gst);
}

bool Host::pseudoExists (const string &pseudo)
{
    if (pseudo == this->pseudo)
        return true;
    for (vector<string>::iterator it = this->gst.oPlayers.begin(); it != this->gst.oPlayers.end(); it ++) {
        if (pseudo == *it)
            return true;
    }

    return false;
}

vector<Card::typeCard> Host::playerTypeCardsRandOrder (const string &pseudo)
{
    vector<Card::typeCard> cards;
    vector<Player> &players = this->game->getPlayers();
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();

    for (vector<Player>::iterator it = players.begin(); it != players.end(); it ++) {
        if ((*it).getPseudo() != pseudo)
            continue;
        vector<Card> cardsCopy = (*it).getCards();
        shuffle(cardsCopy.begin(), cardsCopy.end(), default_random_engine(seed));
        for (vector<Card>::iterator it2 = cardsCopy.begin(); it2 != cardsCopy.end(); it2 ++)
            cards.push_back((*it2).getType());
        break;
    }

    return cards;
}
