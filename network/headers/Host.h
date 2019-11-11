#ifndef __HOST_H__
#define __HOST_H__

#include "GSocket.h"
#include "../../kernel/headers/Game.h"
#include "../../kernel/headers/Card.h"
#include "../../kernel/headers/Player.h"

class Host : public GSocket
{
public:
    Host (const string pseudo, const size_t nbClients, const in_port_t port, void (*gameCallback) (const gstate &gst), void (*tchatCallback) (const vector<gmess> &tchat);
    ~Host ();

    Card::typeCard next (ssize_t cardN);

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

    bool sckBind ();
    bool sckListen ();
    bool sckAccept ();

    client &findClient (int sck) const;
    void thread_wait (const int sck);
    void addTchatMess (const gmess &mess);
    void gameNext (const string &cardPlayer, const uint8_t &cardNum);
    bool sync ();
};

#endif
