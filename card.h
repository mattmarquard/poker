// guard
#ifndef __CARD_H_INCLUDED__
#define __CARD_H_INCLUDED__

class Card
{
private:
	int value;
	char suit;
public:
	Card();
	Card(char s, int v);
	~Card();
	char getSuit();
	int getValue();
	void setValue(int i);
	void printCard();
};

#endif
