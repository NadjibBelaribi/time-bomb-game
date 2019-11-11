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
#include <time.h>
#include <semaphore.h>
#include <thread>
#include "../../kernel/headers/Game.h"
#include "../../kernel/headers/Card.h"
using namespace std;

class GSocket
{
public:
    enum gsdataReq {
        // host
        HreqStart = 0, // signaler le debut du jeu aux clients
        HreqEnd, // fin de partie
        HresJoin, // si client la recoit: il est dans le jeu, sinon NON
        HreqSync, // actualiser l'état du jeu aux clients
        // client
        CreqJoin, // envoyer apres acceptation du connect TCP pour jouer
        CresPlay, // données de tour de client
        CreqTchat // envoie dun mess de tchat
    };

    enum stateGS {
        Waiting,
        Playing,
        End,
        Error
    };

    typedef struct {
        int sck;
        gsdataReq req;
        unsigned char data[GSDATA_MAX];
        size_t dataLen;
    } gsdata;

    typedef struct {
        string player;
        string mess;
        time_t time;
    } gmess;

    typedef struct {
        vector<string> players;
        string currentPlayer;
        Game::stateGame gameState;
        Card::typeCard lastCardRevealed;
    } gstate;

    stateGS getState () const;
    int getError () const;

protected:
    stateGS state;
    string pseudo;
    int sck;
    int error;
    vector<gmess> tchat;
    void (*gameCallback) (const gstate &gst);
    void (*tchatCallback) (const vector<gmess> &tchat);
    gstate gst;
    sem_t sem;

    GSocket ();
    void putError ();
    bool sckCreate ();
    bool sckAccept ();
    ssize_t sckSend (const int sck, const void *data, const size_t len);
    ssize_t sckRecv (const int sck, void * const data, const size_t size);

    gsdata * parse (const void * const data, const size_t len) const;
    gsdata * sckWait (const int sck);
    bool sendReq (const gsdataReq req, const char *str, const int sck);
    bool end ();
};

#endif
