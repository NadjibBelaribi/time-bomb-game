#ifndef GAME_H
#define GAME_H

#include"Card.h"
#include"Player.h"

class Game {
   public :

   private :
    Player * players ;
    Card  * cards ;
    int currentPlayer ;
    int nbExplosif ;

} ;

#endif // GAME_H
