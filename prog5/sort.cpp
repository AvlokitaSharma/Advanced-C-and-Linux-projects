#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

void Sort(int v[], int count){

    bool sorted = false;
    int sorted_cnt = 0;

    sort(v,v+count);
    for(int i = 0; i < count; i++){
        if(i != count - 1)
            printf("%d\n", v[i]);
        else
            printf("%d", v[i]);
    }
}


int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cout << "Please include filename in param list.\n";
		cout << "Example:\n";
		cout << "     % sort myfile.txt\n";
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
     
    Sort(v, count);
    
	fin.close();
    return 0;
} 