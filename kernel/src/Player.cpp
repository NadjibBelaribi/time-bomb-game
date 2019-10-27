#include "../headers/Player.h"

vector<Card> Player::getCards () const
{
    return this->cards;
}

Player::rolePlayer Player::getRole () const
{
    return Player::role;
}

bool Player::hasCard (const Card &card)
{
    for (vector<Card>::iterator cd = this->cards.begin(); cd != this->cards.end(); cd ++) {
        if (card == *cd)
            return true;
    }

    return false;
}

void Player::delCard (Card &card)
{
    for (vector<Card>::iterator it = this->cards.begin(); it != this->cards.end(); it ++) {
        if (card == *it) {
            this->cards.erase(it);
            break;
        }
    }
}

void Player::setCards (vector <Card> &cards)
{
    if (cards.empty()) {
        cerr << "[Warning] setCards: cards is empty" << endl;
        return;
    }
    this->cards = cards;
}

