#include<iostream>
#include<string>
#include "Card.h"

using namespace std;


Card::Card(){}

Card::Card(char rank , char suit)
{
    r = rank;
    s = suit;
}
void Card::setCard(char rank, char suit)
{
    r = rank;
    s = suit;
    
}

int Card::getValue()
{
    if(r == 'A'){ return 1; }
    if(r == 'T' || r == 'J' || r == 'Q' || r == 'K'){ return 10;}
    else if(r == '2'){return 2;}
    else if(r == '3'){return 3;}
    else if(r == '4'){return 4;}
    else if(r == '5'){return 5;}
    else if(r == '6'){return 6;}
    else if(r == '7'){return 7;}
    else if(r == '8'){return 8;}
    else{return 9;}
}

void Card::display()
{
    if(r == 'T'){cout << "10" << s << ", ";}
    else{cout << r << s <<", ";}
    
}
