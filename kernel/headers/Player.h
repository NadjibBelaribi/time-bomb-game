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
        sherlock,
        moriarty
    };

    Player(string pseud,rolePlayer r,vector<Card> cards) ;
    void showCards ();
    void mixCards ();
    rolePlayer getRole() ; 
    void setRole(rolePlayer r) ; 

private :
    vector<Card> cards;
    string pseudo;
    rolePlayer role;
};

#endif // PLAYER_H
