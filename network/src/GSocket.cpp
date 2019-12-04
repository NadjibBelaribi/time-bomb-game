#include "../headers/GSocket.h"

GSocket::GSocket () {}

GSocket::stateGS GSocket::getState () const
{
    return this->state;
}

int GSocket::getError () const
{
    return this->error;
}

// PRIVATE METHODS

void GSocket::sckCreate ()
{
    this->sck = socket(AF_INET6, SOCK_STREAM, 0);
    if (this->sck == -1) {
        perror("socket");
        exit(1);
    }
}

ssize_t GSocket::sckSend (const int sck, const void *data, const size_t len)
{
    ssize_t bytes = send(sck, data, len, 0);
    if (bytes == -1) {
        perror("bytes");
        exit(1);
    }

    return bytes;
}

ssize_t GSocket::sckRecv (const int sck, void * const data, const size_t size)
{
    ssize_t bytes = recv(sck, data, size, 0);
    if (bytes == -1) {
        perror("bytes");
        exit(1);
    }

    return bytes;
}

GSocket::gsdata * GSocket::parse (const void * const data, const size_t len) const
{
    /* MESSAGE FORMAT
     * 1st octet => request
     * data
     */

    if ((len >= (GSDATA_MAX - 1)) || (len < 1))
        return nullptr;
    GSocket::gsdata *gsd = new GSocket::gsdata;
    gsd->req = (GSocket::gsdataReq) ((uint8_t *) data)[0];
    memcpy(gsd->data, ((unsigned char *) data) + 1, len - 1);
    gsd->data[len - 1] = '\0';
    gsd->dataLen = len - 1;
    return gsd;
}

GSocket::gsdata * GSocket::sckWait (const int sck)
{
    void * const data = malloc(GSDATA_MAX);
    ssize_t bytes = this->sckRecv(sck, data, GSDATA_MAX);
    if (bytes == -1)
        return nullptr;
    gsdata *gsd = this->parse(data, bytes);
    free(data);
    return gsd;
}

void GSocket::sendReq (const gsdataReq req, const char *str, const int sck)
{
    size_t strLen = strnlen(str, GSDATA_MAX);
    void *buf = malloc(GSDATA_MAX);
    ((uint8_t *) buf)[0] = (uint8_t) req;
    memcpy(&((char *) buf)[1], str, strLen);

    if (this->sckSend(sck, buf, strLen + 1) == -1) {
        perror("this");
        exit(1);
    }
    free(buf);
}

vector<string> GSocket::split (const string &s, char del)
{
   vector<string> tokens;
   string token;
   istringstream tokenStream(s);
   while (getline(tokenStream, token, del))
       tokens.push_back(token);

   return tokens;
}

string & GSocket::getPseudo ()
{
    return this->pseudo;
}
