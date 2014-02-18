//guard
#ifndef __HAND_H_INCLUDED__
#define __HAND_H_INCLUDED__
#include "card.h"

#define NUMCARDS 5

class Hand
{
private:
	int values[NUMCARDS];
	char* rank = "nothing";
	bool aceStraight;
	bool straight;
	int currentCards;
	int score;
	int unusedHigh;
	bool flush;
	int pair;
	int secondPair;
	int three;
	int four;
	int house;
	Card *cards[NUMCARDS];
	void handlePairs(int v);
	bool isStraight();
	void fixAces();
public:
	Hand();
	~Hand();
	int valuesIndex(int index);
	int getScore();
	int addCard(Card *s);
	void printHand();
	int getCC();
	int getPair();
	int getSecondPair();
	int getThree();
	int getFour();
	int getHouse();
	int getHighcard();
	int getUnused();
	bool isFlush();
	bool sortByScore(Hand *h1, Hand *h2);
	void Hand::printRank();
	static bool highCardCompare(Hand *h1, Hand *h2);
	static bool comparePair(Hand *h1, Hand *h2);
};

#endif
