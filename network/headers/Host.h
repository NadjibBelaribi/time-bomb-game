#ifndef __HOST_H__
#define __HOST_H__

#include "GSocket.h"

class Host : public GSocket
{
public:
    Host (const string pseudo, const size_t nbClients, const in_port_t port);
    ~Host ();

    Card::typeCard next (ssize_t cardN);

private:
    typedef struct {
        unsigned char addr[16];
        in_port_t port;
        string pseudo;
    } client;

    vector<client> clients;
    Game *game;
    size_t nbClients;
    in_port_t port;

    bool sckBind ();
    void waitClients ();
    client &findCurClient () const;
    void sync () const; // envoie les nouveautées aux clients
};

#endif
