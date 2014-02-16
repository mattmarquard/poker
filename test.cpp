#include <iostream>
#include "card.h"
#include "hand.h"
#include "deck.h"

#define NUMHANDS 5
using namespace std;

int main()
{
	Hand h = Hand();
	Hand h2 = Hand();
	Hand h3 = Hand();
	Hand h4 = Hand();
	Hand h5 = Hand();

	Hand hands[]= { h, h2, h3, h4, h5 };
	

	PokerDeck myDeck = PokerDeck();

	myDeck.printDeck();
	myDeck.shuffle();
	cout << endl;
	cout << endl;
	myDeck.printDeck();

	myDeck.deal(hands, NUMHANDS);
	for (int i = 0; i < NUMHANDS; i++) {
		cout << "Hand number " << i + 1 << " is:" << endl;
		hands[i].printHand();
	}

	cin.get();

	return 0;
}
