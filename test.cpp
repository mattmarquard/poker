#include <iostream>
#include <algorithm>
#include <vector>
#include "card.h"
#include "hand.h"
#include "deck.h"

#define NUMHANDS 10
using namespace std;

bool sortByScore(Hand *h1, Hand *h2) {
	int h1Score = h1->getScore();
	int h2Score = h2->getScore();
	if (h1Score != h2Score) {
		return h1Score < h2Score;
	}
	else {
		switch (h1Score)
		{
		case 2:
			return h1->getHighcard() < h2->getHighcard();
		case 3:
			return h1->getFour() > h2->getFour();
		case 4:
			return h1->getThree() > h2->getThree();
		case 5:
			return h1->getHighcard() > h2->getHighcard();
		case 6:
			return h1->getHighcard() > h2->getHighcard();
		case 7:
			return h1->getUnused() > h2->getUnused();
		case 8:
			return Hand::comparePair(h1, h2);
		case 9:
			return Hand::highCardCompare(h1, h2);
		}
	}
}

int main(int argc, char *argv[])
{
	int shuffles = atoi(argv[1]);
	cout << shuffles << endl;
	Hand h = Hand();
	Hand h2 = Hand();
	Hand h3 = Hand();
	Hand h4 = Hand();
	Hand h5 = Hand();
	Hand h6 = Hand();
	Hand h7 = Hand();
	Hand h8 = Hand();
	Hand h9 = Hand();
	Hand h10 = Hand();

	Hand* hands[] = { &h, &h2, &h3, &h4, &h5, &h6, &h7, &h8, &h9, &h10 };

	PokerDeck myDeck = PokerDeck();

	for (int i = 0; i < shuffles; i++) {
		myDeck.shuffle();
	}
	cout << "BEGIN" << endl;
	std::vector<Hand*> handees;

	//deal hands
	myDeck.deal(hands, NUMHANDS);

	//print hands out prior to sort
	for (int i = 0; i < NUMHANDS; i++) {
		cout << "HAND # " << i + 1 << endl;
		hands[i]->printHand();
		handees.push_back(hands[i]);
	}
	cout << endl;

	//sort hands based on custom sorter
	std::sort(handees.begin(), handees.end(), sortByScore);

	//printout hands in ranked order
	cout << "POST SORTED ORDER" << endl;
	for (Hand *n : handees) {
		cout << endl;
		n->printRank();
		n->printHand();
	}

	cin.get();

	return 0;
}
