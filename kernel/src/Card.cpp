#include "../headers/Card.h"
using namespace std;

Card::Card (typeCard type) {
    this->type = type;
}

Card::typeCard Card::getType () const {
    return this->type;
}
