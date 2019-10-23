#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include "Card.h"
#include "Player.h"
using namespace std;

class Game {
public :
    Game (size_t nbPlayers);
    ~Game ();
    void start_game ();

private :
    vector <Player> players;
    unsigned currentPlayer;
    unsigned nbExplosif;
    size_t nbMoriarty (const size_t nbPlayers) const;
    size_t nbSafeCards (const size_t nbPlayers) const;
    Card::typeCard genRandCardType (size_t &nbSafeCards, size_t &nbExploseCards, size_t &nbBombCard) const;
};

#endif // GAME_H
