//guard
#ifndef __POKER_H_INCLUDED__
#define __POKER_H_INCLUDED__
#include <vector>
#include "hand.h"

#define NUMINDECK 52

class PokerDeck
{
private:
	std::vector<Card*> shuffledCards;
public:
	Card cards[NUMINDECK];
	PokerDeck();
	~PokerDeck();
	void shuffle();
	void deal(Hand* hands[], int numHands);
	void printDeck();
};

#endif
