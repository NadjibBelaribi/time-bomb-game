#ifndef __GSOCKET_H__
#define __GSOCKET_H__

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include "../../kernel/headers/Game.h"
#include "../../kernel/headers/Card.h"
using namespace std;

#define HREQ_INIT 1
#define HREQ_TOUR 2
#define CRES_TOUR 3

class GSocket
{
public:
    enum stateGS {
        Waiting,
        Playing,
        End,
        Error
    };

    GSocket (const string pseudo, const size_t nbPlayers, const in_port_t port); // HOST constructor
    GSocket (const string pseudo, const unsigned char * const addr, const in_port_t port);
    Card::typeCard next (); // ask game->currentPlayer to choose a card, and wait for his reply

    stateGS getState () const;
    int getError () const;

private:
    stateGS state;
    string pseudo;
    Game game; // only for HOST
    size_t nbPlayers; // only for HOST
    unsigned char addr[16]; // only for CLIENT
    in_port_t port;
    int sck;
    int error;

    void putError ();
    bool sckCreate ();
    bool sckBind ();
    bool sckAccept ();
    ssize_t sckSend (const void *data, const size_t len) const;
    ssize_t sckRecv (void * const data, const size_t size) const;

    void * parse (const void * const data) const;
    bool end ();
};

#endif
