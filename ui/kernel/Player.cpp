#include "Player.h"

vector<Card> & Player::getCards ()
{
    return this->cards;
}

Player::rolePlayer Player::getRole () const
{
    return Player::role;
}

bool Player::hasCard (const Card &card)
{
    for (vector<Card>::iterator it = this->cards.begin(); it != this->cards.end(); it ++) {
        if (&card == &(*it))
            return true;
    }

    return false;
}

void Player::delCard (const Card &card)
{
    for (vector<Card>::iterator it = this->cards.begin(); it != this->cards.end(); it ++) {
        if (&card == &(*it)) {
            this->cards.erase(it);
            cout << this->cards.size();
            break;
        }
    }
}

void Player::setCards (vector<Card> &cards)
{
    if (cards.empty()) {
        cerr << "[Warning] setCards: cards is empty" << endl;
        return;
    }
    this->cards = cards;
}

string Player::getPseudo () const
{
    return this->pseudo;
}

Card *Player::getCard(size_t i)
{
    size_t j;
    for (j = 0; j < this->getCards().size(); j++)
    {
        if (i == j)
            return &this->getCards().at(i);
    }
    return nullptr;
}
