#include <iostream>
#include "card.h"

#define HEART 'h'
#define SPADE 's'
#define DIAMOND 'd'
#define CLUB 'c'

Card::Card(char s, int v) {
	value = v;
	suit = s;
}

Card::Card(){
}

Card::~Card() {
}

int Card::getValue()
{
	return value;
}

void Card::setValue(int i) {
	value = i;
}

char Card::getSuit()
{
	return suit;
}

//printcards
void Card::printCard() {
	char* suitword = "printfailed";

	if (suit == HEART) {
		suitword = "HEARTS";
	}
	else if (suit == DIAMOND) {
		suitword = "DIAMONDS";
	}
	else if (suit == CLUB) {
		suitword = "CLUBS";
	}
	else if (suit == SPADE) {
		suitword = "SPADES";
	}
	if (value == 14) {std::cout << "ACE" << " of " << suitword << std::endl;}
	else if (value == 13){ std::cout << "KING" << " of " << suitword << std::endl; }
	else if (value == 12){ std::cout << "QUEEN" << " of " << suitword << std::endl; }
	else if (value == 11){ std::cout << "JACK" << " of " << suitword << std::endl; }
	else { std::cout << value << " of " << suitword << std::endl; }
}
	
