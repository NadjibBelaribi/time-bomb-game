#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

class Card {
public :
    enum typeCard {
        Safe,
        Explose,
        Bomb
    };
    Card ();
    Card (typeCard type);
    typeCard getType () const;

private :
    typeCard type;
};

#endif // CARD_H
