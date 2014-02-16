#include "card.h"
#include "hand.h"

Hand::Hand() {
	currentCards = 0;
	highcard = 0;
	flush = true;
	score = 0;
	pair = -1;
	secondPair = -1;
	three = -1;
	four = 0;
	house = -1;
}

Hand::~Hand() {

}

int Hand::getScore() {
	return -1;
}

int Hand::addCard(Card *s) {
	if (currentCards >= NUMCARDS) {
		return -1;
	}
	int value = s->getValue();
	if (currentCards > 0) {
		if (s->getSuit() != cards[currentCards - 1]->getSuit()){
			flush = false;
		}
		handlePairs(value);
	}
	cards[currentCards] = s;
	currentCards = currentCards + 1;
	return currentCards;
}

int Hand::getCC() {
	return currentCards;
}

void Hand::handlePairs(int v) {
	for (int i = 0; i < currentCards; i++) {
		int currentVal = cards[i]->getValue();
		//does added card make four of a kind?
		if (v == three) {
			four = v;
		}
		//does added card make full house?
		else if (three > 0 && v == currentVal) {
			pair = v;
			house = three;
		}
		//does added card make 3 of a kind?
		else if (v == pair) {
			three = pair;
		}
		//does added card make a second pair?
		else if (pair > 0 && v == currentVal) {
			secondPair = v;
		}
		//does added card make a pair?
		else if (v == currentVal) {
			pair = v;
		}
		//added card is just high card
		else {
			highcard = v;
		}
	}
}

bool Hand::isStraight() {
	int values[NUMCARDS];
	for (int i = 0; i < NUMCARDS; i++) {
		values[i] = cards[i]->getValue();
	}
	values.sort();
}

void Hand::printHand() {
	for (int i = 0; i < currentCards; i++) {
		cards[i]->printCard();
	}
}
