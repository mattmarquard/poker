//guard
#ifndef __HAND_H_INCLUDED__
#define __HAND_H_INCLUDED__
#include "card.h"

#define NUMCARDS 5

class Hand
{
private:
	int currentCards;
	int score;
	int highcard;
	bool flush;
	int pair;
	int secondPair;
	int three;
	int four;
	int house;
	Card *cards[NUMCARDS];
	void handlePairs(int v);
	bool isStraight();
public:
	Hand();
	~Hand();
	int getScore();
	int addCard(Card *s);
	void printHand();
	int getCC();
};

#endif
