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

ssize_t GSocket::sckSend (const int sck, const void *data, const size_t len)
{
    ssize_t bytes = send(sck, data, len, 0);
    if (bytes == -1) {
        this->putError();
        return -1;
    }

    return bytes;
}

ssize_t GSocket::sckRecv (const int sck, void * const data, const size_t size)
{
    ssize_t bytes = recv(sck, data, size, 0);
    if (bytes == -1) {
        this->putError();
        return -1;
    }

    return bytes;
}

GSocket::gsdata * GSocket::parse (const void * const data, const size_t len) const
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
    return gsd;
}

GSocket::gsdata * GSocket::sckWait (const int sck)
{
    void * const data = new void* [GSDATA_MAX];
    ssize_t bytes = this->sckRecv(sck, data, GSDATA_MAX);
    if (bytes == -1)
        return nullptr;
    gsdata *gsd = this->parse(data, bytes);
    delete (char *) data;

    return gsd;
}

bool GSocket::sendReq (const gsdataReq req, const char *str, const int sck)
{
    size_t strLen = strnlen(str, GSDATA_MAX);
    void *buf = new void* [GSDATA_MAX];
    ((uint8_t *) buf)[0] = (uint8_t) req;
    memcpy(&((char *) buf)[1], str, strLen);
    delete (char *) buf;

    if (this->sckSend(sck, buf, strLen + 1) == -1) {
        this->putError();
        return false;
    }
    return true;
}
