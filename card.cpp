#include "card.h"

Card::Card(char s, int v) {
   value = v;
   suit = s;
}

Card::~Card() {
}

int Card::getValue()
{
    return value;
}

char Card::getSuit()
{
    return suit;
}

