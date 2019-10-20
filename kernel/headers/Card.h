#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

class Card {
public :
    enum typeCard {
        safe,
        explose,
        bomb
    };

private :
    typeCard type;
    string id;
};

#endif // CARD_H
