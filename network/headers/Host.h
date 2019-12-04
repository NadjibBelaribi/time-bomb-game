#ifndef __HOST_H__
#define __HOST_H__

#include "GSocket.h"

class Host : public GSocket
{
public:
    Host (const string pseudo, const size_t nbClients, const in_port_t port, void (*gameCallback) (gstate &gst), void (*tchatCallback) (const gmess &mess));
    ~Host ();
    void gameNext (const string &cardPlayer, const uint8_t &cardNum);

private:
    typedef struct {
        int sck;
        string pseudo;
    } client;

    vector<thread *> threads;
    vector<int> sockets; // sockets connected via TCP (pas forcément CLIENT !)
    vector<client> clients;
    // pour etre comptabilité comme client: être connecté en TCP + avoir envoyé la requete CreqJoin + réponse
    Game *game;
    size_t nbClients;
    in_port_t port;

    void sckBind ();
    void sckListen ();
    void sckAccept ();

    client &findClient (int sck) const;
    void thread_wait (const int sck);
    void addTchatMess (const gmess &mess);
    void sync ();
    void startGame ();
    bool pseudoExists (const string &pseudo);
    vector<Card::typeCard> playerTypeCardsRandOrder (const string &pseudo);
    void gcWorkaround ();
};

#endif
