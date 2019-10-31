ifndef CARD_H
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

    Card (const typeCard type) :
        type(type) {}
    typeCard getType () const;

private :
    typeCard type;
};

#endif // CARD_H
