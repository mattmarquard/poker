#include "card.h"
#include "hand.h"
#include <algorithm>
#include <vector>
#include <iostream>

Hand::Hand() {
	aceStraight = 0;
	rank;
	straight = 0;
	currentCards = 0;
	unusedHigh = 0;
	flush = 1;
	score = 0;
	pair = 0;
	secondPair = 0;
	three = 0;
	four = 0;
	house = 0;
}

Hand::~Hand() {

}

int Hand::addCard(Card *s) {
	if (currentCards >= NUMCARDS) {
		return -1;
	}
	values[currentCards] = s->getValue();
	if (currentCards > 0) {
		if (s->getSuit() != cards[currentCards - 1]->getSuit()){
			flush = 0;
		}
		handlePairs(values[currentCards]);
	}
	else { unusedHigh = s->getValue(); }
	cards[currentCards] = s;
	currentCards = currentCards + 1;
	if (currentCards == 5) {
		straight = isStraight();
		fixAces();
	}
	return currentCards;
}

int Hand::getCC() {
	return currentCards;
}

void Hand::handlePairs(int v) {
	for (int i = 0; i < currentCards; i++) {
		int currentVal = values[i];

		//does added card make four of a kind?
		if (v == three) {
			four = v;
			three = 0;
			break;
		}
		//does added card make full house?
		else if (three > 0 && v == currentVal) {
			pair = v;
			house = three;
		}
		//does added card make 3 of a kind?
		else if (v == pair) {
			three = pair;
			pair = 0;
			break;
		}
		else if (v == secondPair) {
			three = secondPair;
			secondPair = 0;
			break;
		}
		//does added card make a second pair?
		else if (pair > 0 && v == currentVal) {
			secondPair = v;
			break;
		}
		//does added card make a pair?
		else if (v == currentVal) {
			pair = v;
			break;
		}
		//added card is just high card
		else if (v > unusedHigh) {
			unusedHigh = v;
		}
		else if (v == 1){
			unusedHigh = 14;
		}
	}
}

bool Hand::isStraight() {
	// if any of these hold true, no straight
	if (pair > 0 || three > 0 || four > 0) {
		return 0;
	}

	int target;
	int sum = 0;
	for (int i = 0; i < NUMCARDS; i++) {
		sum += values[i];
	}

	std::sort(std::begin(values), std::end(values));
	
	int high = values[4];
	int low = values[0];
	target = high * 5 - 10;

	if (high != 13) {
		if (target == sum) {
			return 1;
		}
	}
	else if (high == 13 && low != 1) {
		if (target == sum) {
			return 1;
		}
	}
	else {
		low = 14;
		target = 14 * 5 - 10;
		sum += 13;
		if (target == sum) {
			aceStraight = 1;
			return 1;
		}
	}
	return 0;
}

bool Hand::highCardCompare(Hand *h1, Hand *h2) {
	int h1Card;
	int h2Card;
	for (int i = NUMCARDS; i > 0; i--) {
		h1Card = h1->values[i];
		h2Card = h2->values[i];
		if (h1Card != h2Card) {
			return h1Card > h2Card;
		}
	}
	return h1Card > h2Card;
}

bool Hand::comparePair(Hand *h1, Hand *h2) {
	int h1Pair = h1->getPair();
	int h2Pair = h2->getPair();
	if (h1Pair != h2Pair) {
		return h1Pair > h2Pair;
	}
	else{
		return h1->getUnused() > h2->getUnused();
	}
}

int Hand::valuesIndex(int index){
	return values[index];
}

int Hand::getScore() {
	if (flush && aceStraight) {
		rank = "Royal Flush";
		return 1;
	}
	else if (flush && straight) {
		rank = "Straight Flush";
		return 2;
	}
	else if (four > 0) {
		rank = "Four of a Kind";
		return 3;
	}
	else if ((pair > 0 && three > 0) || (secondPair > 0 && three > 0)) {
		rank = "My Favourit 90s sitcom";
		return 4;
	}
	else if (flush) {
		rank = "Flush";
		return 5;
	}
	else if (three) {
		rank = "Three of a kind";
		return 6;
	}
	else if (pair > 0 && secondPair > 0) {
		rank = "2 Pairs";
		return 7;
	}
	else if (pair) {
		rank = "A single pair";
		return 8;
	}
	else { return 9; }
}

void Hand::fixAces() {
	for (int i = 0; i < NUMCARDS; i++) {
		if (cards[i]->getValue() == 1) {
			cards[i]->setValue(14);
		}
	}
	if (pair == 1){
		pair = 14;
	}
	if (three == 1){
		three = 14;
	}
	if (secondPair == 1){
		secondPair = 14;
	}
	if (four == 1){
		four = 14;
	}
}

//GETTER METHODS
int Hand::getUnused() {
	return unusedHigh;
}

int Hand::getPair() {
	return pair;
}

int Hand::getSecondPair() {
	return secondPair;
}
int Hand::getThree() {
	return three;
}
int Hand::getFour(){
	return four;
}
int Hand::getHouse() {
	return house;
}
int Hand::getHighcard(){
	return values[4];
}
bool Hand::isFlush() {
	return flush;
}

//printout Hand
void Hand::printHand() {
	for (int i = 0; i < currentCards; i++) {
		cards[i]->printCard();
	}
}
void Hand::printRank() {
	std::cout << "Rank is : " << rank << std::endl;
}
