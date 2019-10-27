#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

class Card {
public :
    enum typeCard {
        Safe,
        Defusing,
        Bomb
    };

    Card (const typeCard type) :
        type(type) {};
    bool operator== (const Card & other) const;
    typeCard getType () const;

private :
    typeCard type;
};

#endif // CARD_H
