#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Card.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>

using namespace std;

class Player {
public :
    enum rolePlayer {
        Sherlock,
        Moriarty
    };

    Player (string pseudo, rolePlayer role, Card cards[5]);
    rolePlayer getRole ();
    Card * getCards ();
    void mixCards ();
    rolePlayer getRole() ; 
    void setRole (rolePlayer role); 

private :
    Card cards[5];
    string pseudo;
    rolePlayer role;
};

#endif // PLAYER_H
