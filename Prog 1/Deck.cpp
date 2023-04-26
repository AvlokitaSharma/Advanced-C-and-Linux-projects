#include <iostream>
#include <string>
#include "Card.h"
#include "Deck.h"

using namespace std;


Deck::Deck()
{
  top = 0;
  char rank [13] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
  char suit [4] = {'S','H','D','C'};
  Card c;
  int b = 0;

  for (int i = 0; i <= 3; i++)
  {
    for(int j = 0; j < 13; j++)
    {
      
      deck[b].setCard(rank[j], suit[i]);
      b++;
    }
  }
}

void Deck::refreshDeck()
{
  top = 0;
  char rank [13] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
  char suit [4] = {'S','H','D','C'};
  Card c;
  int b = 0;

  for (int i = 0; i <= 3; i++)
  {
    for(int j = 0; j < 13; j++)
    {
      
      deck[b].setCard(rank[j], suit[i]);
      b++;
    }
  }
}

Card Deck::deal()
{
    return deck[top++];
}

void Deck::shuffle()
{
    top = 0;
    srand(time(NULL));
    for(int i = 0; i <= 100; i++)
    {
        int x = rand() % 52;
        int y = rand() % 52;

        Card tp = deck[x];
        deck[x] = deck[y];
        deck[y] = tp;
    }
}

bool Deck::isEmpty()
{
    if(top >= 52){return true;} else{return false;}
}

void Deck::display()
{
    Card c;
    int b = 0;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 13; j++)
        {   
          deck[b].display();
          b++;
        }
        cout << endl;
    }
}
