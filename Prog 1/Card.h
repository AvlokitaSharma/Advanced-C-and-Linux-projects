#ifndef card_h
#define card_h
#include<iostream>
#include<string>

using namespace std;

class Card
{
    private:
        char r;
        char s;
    public:
        Card();
        Card(char rank , char suit);
        void setCard(char rank, char suit);
        int getValue();
        void display();
};

#endif
