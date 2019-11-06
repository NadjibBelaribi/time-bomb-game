#ifndef __GSOCKET_H__
#define __GSOCKET_H__

#define GSDATA_MAX 4096
#define PSEUDO_MAX 32

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

class GSocket
{
public:
    enum gsdataReq {
        // host
        HreqPlay = 0,
        HreqEnd,
        // client
        CreqJoin,
        CresPlay
    };

    enum stateGS {
        Waiting,
        Playing,
        End,
        Error
    };

    typedef struct {
        unsigned char addr[16];
        in_port_t port;
        gsdataReq req;
        unsigned char data[GSDATA_MAX];
        size_t dataLen;
    } gsdata;

    stateGS getState () const;
    int getError () const;

protected:
    stateGS state;
    string pseudo;
    int sck;
    int error;

    GSocket ();
    void putError ();
    bool sckCreate ();
    bool sckAccept ();
    ssize_t sckSend (const void *data, const size_t len, const struct sockaddr_in6 &saddr);
    ssize_t sckRecv (void * const data, const size_t size, struct sockaddr_in6 &saddr);

    gsdata * parse (const void * const data, const size_t len, const struct sockaddr_in6 &saddr) const;
    gsdata * sckWait ();
    bool sendReq (const gsdataReq req, const char *str, const unsigned char *addr, const in_port_t port);
    bool end ();
};

#endif
