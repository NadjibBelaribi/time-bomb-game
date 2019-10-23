#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Card.h"
using namespace std;

class Player {
public :
    enum rolePlayer {
        Sherlock,
        Moriarty
    };

    Player (rolePlayer role, Card &cards);
    rolePlayer getRole ();
    Card * getCards ();
    void mixCards ();

private :
    Card cards[5];
    rolePlayer role;
};

#endif // PLAYER_H
