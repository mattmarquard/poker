#include <iostream>
#include "card.h"

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

char Card::getSuit()
{
	return suit;
}

void Card::printCard() {
	std::cout << "Card suit is: " << suit << std::endl;
	std::cout << "Card value is: " << value << std::endl;
}
