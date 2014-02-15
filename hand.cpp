#include "card.h"
#include "hand.h"

Hand::Hand() {
    currentCards = 0;
}

Hand::~Hand() {

}

int Hand::getScore() {
    return -1;
}

int Hand::addCard(Card *s) {
    if (currentCards >= 5) {
        return -1;    
    }
    Card *forArray = s;
    cards[currentCards] = s;
    currentCards = currentCards + 1;
    return currentCards;

}

int Hand::getCC() {
    return currentCards;
}
