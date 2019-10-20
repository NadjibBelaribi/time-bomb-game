#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include"Card.h"
class Player {
    public :
    enum rolePlayer {
       sherlock,
        marjo
    } ;

    rolePlayer showRole () ;
    Card* showCards() ;
    void mixCards() ;

    private :

     Card cards[5] ;
     std::string pseudo;
     rolePlayer role ;

} ;
#endif // PLAYER_H
