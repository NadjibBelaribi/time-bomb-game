#ifndef GAME_H
#define GAME_H

#include "Card.h"
#include "Player.h"
using namespace std;

class Game {
public :
    void start_game ();

private :
    Player * players;
    Card * cards;
    int currentPlayer;
    int nbExplosif;
};

#endif // GAME_H
