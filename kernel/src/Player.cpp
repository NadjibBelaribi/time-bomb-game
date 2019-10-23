#include "../headers/Player.h"

using namespace std;


Player::Player (string pseudo, Player::rolePlayer role, Card cards[5]) {
        this->pseudo = pseudo;
        this->role = role;
        for (int i = 0; i < 5; i ++) 
            this->cards[i] = cards[i];
}
    
Card * Player::getCards () {
    return this->cards;
}

Player::rolePlayer Player::getRole () {

    return Player::role;
}

void Player::mixCards () {
    /* auto rng = default_random_engine {}; */
    /* shuffle(begin(cards),end(cards), rng); */
}

void Player::setRole (rolePlayer role) {
    this->role = role;
}
