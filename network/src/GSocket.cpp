#include "../headers/GSocket.h"

GSocket::GSocket (const string pseudo, const size_t nbPlayers, const in_port_t port) // HOST
{
    this->state = GSocket::Waiting;
    this->pseudo = pseudo;
    this->nbPlayers = nbPlayers;
    this->port = htons(port);

    if (inet_pton(AF_INET6, "::1", this->addr) == -1) {
        this->putError();
        return;
    }

    if (!this->sckBind())
        return;
}

GSocket::GSocket (const string pseudo, const unsigned char * const addr, const in_port_t port) // CLIENT
{
    this->state = GSocket::Waiting;
    this->pseudo = pseudo;
    this->port = htons(port);

    if (inet_pton(AF_INET6, (const char *) addr, this->addr) == -1) {
        this->putError();
        return;
    }
}

GSocket::stateGS GSocket::getState () const
{
    return this->state;
}

int GSocket::getError () const
{
    return this->error;
}

// PRIVATE METHODS

void GSocket::putError ()
{
    this->error = errno;
    this->state = GSocket::Error;
}

bool GSocket::sckCreate ()
{
    int fd = socket(AF_INET6, SOCK_STREAM, 0);
    if (fd == -1) {
        this->putError();
        return false;
    }

    return true;
}

bool GSocket::sckBind ()
{
    struct sockaddr_in6 saddr;
    saddr.sin6_family = AF_INET6;
    saddr.sin6_port = this->port;
    memcpy(saddr.sin6_addr.s6_addr, this->addr, 16);

    if (bind(this->sck, (struct sockaddr *) &saddr, sizeof(struct sockaddr_in6)) == -1) {
        this->putError();
        return false;
    }

    return true;
}

ssize_t GSocket::sckSend (const void *data, const size_t len)
{
    ssize_t bytes = send(this->sck, data, len, 0);
    if (bytes == -1) {
        this->putError();
        return -1;
    }

    return bytes;
}

ssize_t GSocket::sckRecv (void * const data, const size_t size)
{
    ssize_t bytes = recv(this->sck, data, size, 0);
    if (bytes == -1) {
        this->putError();
        return -1;
    }

    return bytes;
}
