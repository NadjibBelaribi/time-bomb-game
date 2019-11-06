#include "GSocket.h"

class Client : public GSocket
{
public:
    Client (const string pseudo, const char * const hostAddr, const in_port_t hostPort);

private:
    unsigned char hostAddr[16]; // only for CLIENT
    in_port_t hostPort;

    bool sckConnect () const;
};

#endif
