#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

void verifySort(int v[], int count){
    cout << "Number of integers: " << count << "\n";

    bool sorted = false;
    int sorted_cnt = 0;

    std::cout << "Is sorted: " << std::boolalpha <<
        std::is_sorted(v, v+count) << "\n";
}


int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cout << "Please include sorted filename in param list.\n";
		cout << "Example:\n";
		cout << "     % verifySort mySorted.txt\n";
		exit(EXIT_SUCCESS);
	}


	const int MAX = 1000000;
	ifstream fin;
	int n, i = 0;
	
	int v[MAX];
	int count = 0;
	
	fin.open(argv[1]);
	while (fin >> n )
	{
		v[count++] = n;
        i++;	
	}
     
    verifySort(v, count);
    
	fin.close();
    return 0;
} 