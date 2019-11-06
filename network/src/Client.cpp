#include "../headers/Client.h"

Client::Client (const string pseudo, const char * const hostAddr, const in_port_t hostPort)
{
    this->state = Client::Waiting;
    this->pseudo = pseudo;
    this->hostPort = htons(hostPort);

    if (inet_pton(AF_INET6, hostAddr, this->hostAddr) == -1) {
        this->putError();
        return;
    }
}

bool Client::sckConnect () const
{


    return true;
}
