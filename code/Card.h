#ifndef CARD_H
#define CARD_H

#include <string>
class Card {

    public :
    enum typeCard {
        safe,
        explose,
        bomb
    } ;

    private :
    typeCard type ;
    std::string id ;


} ;
#endif // CARD_H
