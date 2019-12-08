#ifndef __CLIENT_H__
#define __CLIENT_H__

#include "GSocket.h"

class Client : public GSocket
{
public:
    Client (const string pseudo, const char * const hostAddr, const in_port_t hostPort, void (*gameCallback) (Client::gstate &gameState), void (*tchatCallback) (const gmess &mess));
    ~Client ();
    void sendTchatMess (const gmess &mess);
    void gameNext (const string &cardPlayer, const uint8_t &cardNum);

private:
    unsigned char hostAddr[16];
    in_port_t hostPort;
    thread *sckThread;

    void sckConnect ();
    void thread_wait ();
    void gameStarted (const unsigned char *data, const size_t len);
    void processSync (const unsigned char *data, const size_t len);
    void joinedSuccess ();
    void addTchatMess (const unsigned char *data, const size_t len);
    void end ();
};

#endif
