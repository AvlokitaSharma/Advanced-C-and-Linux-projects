#ifndef deck_h
#define deck_h
#include <iostream>
#include "Card.h"
#include <string>

using namespace std;

class Deck
{
    private:
        int top;
        Card deck[52];
    public:
        Deck();
        void refreshDeck();
        Card deal();
        void shuffle();
        bool isEmpty();
        void display();
};

#endif