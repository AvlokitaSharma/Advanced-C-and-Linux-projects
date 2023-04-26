#include <iostream>
#include <random>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
    
    random_device rd; 
    mt19937 gen(rd()); 
    uniform_int_distribution<> distr(stoi(argv[2]),stoi(argv[3])); 

    ofstream numbersFile("numbers.txt");

    for(int i =0;i<stoi(argv[1]);i++){
        numbersFile << distr(gen)<<"\n";
    }

    return 0;
}