#ifndef GAME_H
#define GAME_H


#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include "Card.h"
#include "Player.h"
using namespace std;

class Game
{
public :
    enum stateGame {
        Active,
        MoriartyWin,
        SherlockWin
    };

    Game (const size_t nbPlayers, const string * const pseudos);
    Card::typeCard next (const Card &card);

    Player & getCurrentPlayer () const;
    unsigned getRound () const;
    stateGame getState () const;
    Player * getPlayerForCard (const Card &card);
    vector<Player *> getPlayersForRevealingCard ();
    size_t getNbDefusingCardsRevealed () const;
    vector<Player> & getPlayers ();

private :
    vector<Player> players;
    Player * currentPlayer;
    size_t nbDefusingCardsRevealed;
    size_t nbRoundCardsRevealed;
    size_t round;
    stateGame state;

    void nextRound ();
    size_t initialNbMoriarty (const size_t nbPlayers) const;
    size_t initialNbSafeCards (const size_t nbPlayers) const;
    Card::typeCard genRandCardType (size_t &nbSafeCards, size_t &nbExploseCards, size_t &nbBombCard) const;
    Player::rolePlayer genRandPlayerRole (size_t &nbMoriarty, size_t &nbSherlock) const;
    vector<Card *> getAllPlayerCards ();

};

#endif // GAME_H
