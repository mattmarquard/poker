#include <iostream>
#include "card.h"
#include "deck.h"

#define HEART 'h'
#define SPADE 's'
#define DIAMOND 'd'
#define CLUB 'c'


PokerDeck::PokerDeck() {

	char suits[] = { HEART, SPADE, DIAMOND, CLUB };
	char suit;
	int n, i, j;
	for (n = 0, i = 1, j = 0; n < NUMINDECK; n++) {
		char suit = suits[j];
		cards[n] = Card(suit, i);
		if (i == 13) {
			i = 1;
			j++;
		}
		else { i++; }
	}
}

PokerDeck::~PokerDeck() {
}

//shuffle cards using a vector
void PokerDeck::shuffle() {
	shuffledCards.erase(shuffledCards.begin(), shuffledCards.end());
	int min = 1;
	int max = NUMINDECK;
	Card tmp;
	int i;
	for (i = 51; i >= 0; i--) {
		int x = (rand() % (int)(max - min + 1));
		tmp = cards[x];
		cards[x] = cards[i];
		cards[i] = tmp;
		Card *p = &cards[i];
		shuffledCards.push_back(p);
		max--;
	}
}

//deal hands based on number of hands
void PokerDeck::deal(Hand* hands[], int numHands){
	int maxcards = 5;
	int i, j;
	for (i = 0; i < maxcards; i++) {
		for (j = 0; j < numHands; j++) {
			Card *p = shuffledCards.back();
			hands[j]->addCard(p);
			shuffledCards.pop_back();
		}
	}
}

//printdekc
void PokerDeck::printDeck() {
	for (int i = 0; i < NUMINDECK; i++) {
		cards[i].printCard();
		std::cout << i << std::endl;
	}
}
