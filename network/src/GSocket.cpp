#include "../headers/GSocket.h"

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

ssize_t GSocket::sckSend (const void *data, const size_t len, const struct sockaddr_in6 &saddr)
{
    ssize_t bytes = sendto(this->sck, data, len, 0, (struct sockaddr *) &saddr, sizeof(struct sockaddr_in6));
    if (bytes == -1) {
        this->putError();
        return -1;
    }

    return bytes;
}

ssize_t GSocket::sckRecv (void * const data, const size_t size, struct sockaddr_in6 &saddr)
{
    socklen_t saddrLen = sizeof(struct sockaddr_in6);
    ssize_t bytes = recvfrom(this->sck, data, size, 0, (struct sockaddr *) &saddr, &saddrLen);
    if (bytes == -1) {
        this->putError();
        return -1;
    }

    return bytes;
}

GSocket::gsdata * GSocket::parse (const void * const data, const size_t len, const struct sockaddr_in6 &saddr) const
{
    /* MESSAGE FORMAT
     * 1st octet => request
     * data
     */

    if (len >= (GSDATA_MAX - 1))
        return NULL;
    GSocket::gsdata *gsd = new GSocket::gsdata;
    gsd->req = (GSocket::gsdataReq) ((uint8_t *) data)[0];
    memcpy(gsd->data + 1, ((char *) data) + 1, len - 1);
    gsd->data[len - 1] = '\0';
    gsd->dataLen = len - 1;
    gsd->port = saddr.sin6_port;
    memcpy(gsd->addr, saddr.sin6_addr.s6_addr, 16);
    return gsd;
}

GSocket::gsdata * GSocket::sckWait ()
{
    void * const data = new void* [GSDATA_MAX];
    struct sockaddr_in6 saddr;
    ssize_t bytes = this->sckRecv(data, GSDATA_MAX, saddr);
    if (bytes == -1)
        return nullptr;
    gsdata *gsd = this->parse(data, bytes, saddr);
    delete (char *) data;

    return gsd;
}

bool GSocket::sendReq (const gsdataReq req, const char *str, const unsigned char *addr, const in_port_t port)
{
    size_t strLen = strnlen(str, GSDATA_MAX);
    void *buf = new void* [GSDATA_MAX];
    ((uint8_t *) buf)[0] = (uint8_t) req;
    memcpy(&((char *) buf)[1], str, strLen);
    delete (char *) buf;

    struct sockaddr_in6 saddr;
    saddr.sin6_family = AF_INET6;
    memcpy(saddr.sin6_addr.s6_addr, addr, 16);
    saddr.sin6_port = port;

    if (this->sckSend(buf, strLen + 1, saddr) == -1) {
        this->putError();
        return false;
    }
    return true;
}
