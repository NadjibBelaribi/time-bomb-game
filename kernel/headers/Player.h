#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Card.h"
using namespace std;

class Player {
public :
    enum rolePlayer {
        sherlock,
        moriarty
    };

    rolePlayer showRole ();
    Card * showCards ();
    void mixCards ();

private :
    Card cards[5];
    string pseudo;
    rolePlayer role;
};

#endif // PLAYER_H
