#include "../headers/Card.h"

Card::typeCard Card::getType () const {
    return this->type;
}

bool Card::operator== (const Card &other) const
{
    return this == &other;
}
