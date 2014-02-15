#include <iostream>
#include "card.h"
#include "hand.h"
using namespace std;

int main()
{
    Hand h = Hand();
    Card myCard = Card('h', 5);
    Card myCard2 = Card('s', 10);
    Card myCard3 = Card('c', 3);
    Card myCard4 = Card('d', 2);
    Card myCard5 = Card('h', 4);
    
    int i;

    i = h.addCard(&myCard5);
    cout << "AddCard worked if this isnt -1: " << i << endl;
    i = h.addCard(&myCard);
    i = h.addCard(&myCard2);
    i = h.addCard(&myCard3);
    i = h.addCard(&myCard4);
    i = h.addCard(&myCard);

    cout << "The char is : " << myCard.getSuit() << endl;
    cout << "The value is : " << myCard.getValue() << endl;
    cout << "The currentCard value is: " << h.getCC() << endl;
    cout << "AddCard worked if this isnt -1: " << i << endl;

    return 0;
}
