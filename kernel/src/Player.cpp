#include "../headers/Player.h"

using namespace std;

Player::Player(std::string pseud,rolePlayer r,vector<Card> card) {
        pseudo = pseud ;
        role = r ;
        for (int i=0; i<5; i++) 
        Player::cards.push_back(card.at(i)); 

    }
    
Player::rolePlayer Player::getRole () {

    return Player::role;
}

void Player::showCards () {

    
     for (int i=0; i<cards.size(); i++) 
        cout << cards.at(i).getType() << endl;
 }

void Player::mixCards () {

    auto rng = default_random_engine {};
    shuffle(begin(cards),end(cards), rng);
}

void Player::setRole(rolePlayer r) {
    Player::role = r ;
}
