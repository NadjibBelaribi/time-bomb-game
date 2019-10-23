#include "../headers/Game.h"
using namespace std;

Game::Game (size_t nbPlayers)
{
    if (nbPlayers > 8) {
        cerr << "Players number should be < 8\n";
        exit(1); 
    } else if (nbPlayers < 4) {
        cerr << "Players number should be > 4\n";
        exit(1);
    }
    size_t nbMoriarty = this->nbMoriarty(nbPlayers);
    Player::rolePlayer role;

    size_t nbSafeCards = this->nbSafeCards(nbPlayers);
    size_t nbExploseCards = nbPlayers;
    size_t nbBombCard = 1;
    Card cards[5];
    Card::typeCard randCardType;
    for (size_t i = 0; i < 5; i ++) {
        randCardType = this->genRandCardType(nbSafeCards, nbExploseCards, nbBombCard);
        cards[i] = Card(randCardType);
    }

    for (unsigned i = 0; i < nbPlayers; i ++) {
        if (nbMoriarty > 0) {
            role = Player::Moriarty;
            nbMoriarty --;
        }
        else
            role = Player::Sherlock;

        Player *player = new Player(role, cards);
        this->players.push_back(*player);
    }
}

size_t Game::nbMoriarty (const size_t nbPlayers) const
{
    if (nbPlayers >= 7)
        return 3;
    else
        return 2;
}

size_t Game::nbSafeCards (const size_t nbPlayers) const
{
    return 15 + (nbPlayers - 4) * 4;
}

Card::typeCard Game::genRandCardType (size_t &nbSafeCards, size_t &nbExploseCards, size_t &nbBombCard) const
{
    const size_t sum = nbSafeCards + nbExploseCards + nbBombCard;
    const size_t random = rand() % sum + 1;

    if (random <= nbSafeCards) {
        nbSafeCards --;
        return Card::Safe;
    } else if (random <= (nbSafeCards + nbExploseCards)) {
        nbExploseCards --;
        return Card::Explose;
    } else {
        nbBombCard --;
        return Card::Bomb;
    }
}
