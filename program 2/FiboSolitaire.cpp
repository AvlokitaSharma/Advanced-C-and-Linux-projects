#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

class Card
{
    private:
        char r;
        char s;
    public:
      Card(){}
  
      Card(char rank, char suit)
      {
          r = rank;
          s = suit;
      }
      void setCard(char rank, char suit)
      {
          r = rank;
          s = suit;
          
      }
      
      int getValue()
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
      
      void display()
      {
          if(r == 'T'){cout << "10" << s << ", ";}
          else{cout << r << s <<", ";}
      }
};
class Deck
{
    private:
        int top;
        Card deck[52];
    public:
        Deck()
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
        
        void refreshDeck()
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
        
        Card deal()
        {
            return deck[top++];
        }
        
        void shuffle()
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
        
        bool isEmpty()
        {
            if(top >= 52){return true;} else{return false;}
        }
        
        void display()
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
};



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
