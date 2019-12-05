#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include "Card.h"
using namespace std;

class Player {
public :
    enum rolePlayer {
        Sherlock,
        Moriarty
    };

    Player (const string pseudo, const rolePlayer role, vector <Card> cards, bool reveal) :
        pseudo(pseudo), role(role), cards(cards), reveal(reveal) {};

    void del_card (const unsigned ind);
    bool hasCard (const Card &card);
    void delCard (const Card &card);
    void setCards (vector<Card> cards);
    bool reveal;
    rolePlayer getRole() const;
    vector<Card> & getCards ();
    string getPseudo () const;
    Card * getCard (const size_t i);

private :
    const string pseudo;
    const rolePlayer role;
    vector<Card> cards;

};

#endif // PLAYER_H
