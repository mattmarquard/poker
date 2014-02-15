//guard
#ifndef __HAND_H_INCLUDED__
#define __HAND_H_INCLUDED__
#include "card.h"

#define NUMCARDS 5

class Hand
{
    private:
        int currentCards;
        Card *cards[NUMCARDS];
    public:
        Hand();
        ~Hand();
        int getScore();
        int addCard(Card *s);
        int getCC();
};

#endif
