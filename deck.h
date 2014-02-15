//guard
#ifndef __POKER_H_INCLUDED__
#define __POKER_H_INCLUDED__
#include "hand.h"

#define NUMINDECK 52

class PokerDeck 
{
    private:
        Card cards[NUMINDECK];
    public:
        void shuffle();
        void deal();
}

#endif
