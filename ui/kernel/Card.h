#ifndef CARD_H
#define CARD_H

#include <iostream>
using namespace std;

class Card {
public :
    enum typeCard {
        Safe,
        Defusing,
        Bomb
    };

    Card (const typeCard type, bool chosen) :
        type(type), chosen(chosen) {};
    typeCard getType () const;
    bool chosen;
private :
    typeCard type;
};

#endif // CARD_H
