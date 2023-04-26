#include<iostream>
#include<string>
#include "Card.h"
#include "Deck.h"

using namespace std;

bool isFibo(int number)
{
    int fibo_elements [13] = {1,1,2,3,5,8,13,21,34,55,89,144,233};

    for(int i = 0; i < 13; i++)
    {
      if(fibo_elements[i] == number)
      {
        return true;
      }
    }
    return false;
}

int main()
{
    int tries = 1;
    int input;
    
    cout << "Welcome to Fibonacci Solitaire! \n";
    cout << "1) New Deck \n";
    cout << "2) Display Deck \n";
    cout << "3) Shuffle Deck \n";
    cout << "4) Play Solitaire \n";
    cout << "5) Exit \n";
    cin >> input;

    Deck deck;
    while(input != 5){
        if(input == 1)
        {
            deck.refreshDeck();
        }
        else if(input == 2)
        {
            deck.display();
        }
        else if(input == 3)
        {
            deck.shuffle();
        }
        else if(input == 4)
        {   
            int piles = 0;
            Card a;
            
            cout << "Playing Fibonacci Solitaire !!! \n";
            int sum_cards = 0;
            while(deck.isEmpty() == false)
            {   
                if(isFibo(sum_cards) == false){
                  a = deck.deal();
                  a.display();
                  sum_cards = sum_cards + a.getValue();
                }
                  
                else
                {
                    cout << "fibo: " << sum_cards;
                    sum_cards = 0;
                    piles++;
                    
                    cout << endl;
                }
                
                if(deck.isEmpty())
                {
                  cout << "last hand value: " << sum_cards;
                }
            }
            
            
            if(isFibo(sum_cards) == true && deck.isEmpty() == true)
            {
                cout << "\nWinner in " << piles+1 << " piles! \n";
                cout << "\nWinner in " << tries+1 << " tries! \n";
                tries = 0;
            }
            else if(deck.isEmpty() == true && isFibo(sum_cards) == false)
            {
                tries++;
                cout << "\nLoser in " << piles+1 << " piles! \n";

            }

            deck.refreshDeck();
        }
        
        cout << "\nWelcome to Fibonacci Solitaire! \n";
        cout << "1) New Deck \n";
        cout << "2) Display Deck \n";
        cout << "3) Shuffle Deck \n";
        cout << "4) Play Solitaire \n";
        cout << "5) Exit \n";
        cin >> input;
    }

    return 0;
}