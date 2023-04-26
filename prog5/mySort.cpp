#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <unistd.h>
using namespace std;

#define SPLIT_SIZE 125000


int* quicksort(int v[], int low, int high)                                                    
{                                                                                             
    int i = low;                                                                              
    int j = high;                                                                             
    int pivot = v[(i + j) / 2];                                                               
    int temp;                                                                                 
                                                                                              
    while (i <= j)                                                                            
    {                                                                                         
        while (v[i] < pivot)                                                                  
            i++;                                                                              
        while (v[j] > pivot)                                                                  
            j--;                                                                              
        if (i <= j)                                                                           
        {                                                                                     
            temp = v[i];                                                                      
            v[i] = v[j];                                                                      
            v[j] = temp;                                                                      
            i++;                                                                              
            j--;                                                                              
        }                                                                                     
    }                                                                                         
    if (j > low)                                                                              
        quicksort(v, low, j);                                                                 
    if (i < high)                                                                             
        quicksort(v, i, high); 
    return v;
                                                              
}                                                                                             

void * wrapper_quicksort(void* v){
    int low = 0, high = SPLIT_SIZE - 1;

    int tab[SPLIT_SIZE];

    int *r;

    for(int g = 0; g < SPLIT_SIZE; g++){
        tab[g] = (*(vector<int> *)v)[g];
    }
    r = quicksort(tab, low, high);


    for(int g = 0; g < SPLIT_SIZE; g++){
        (*(vector<int> *)v)[g] = r[g] ;
    }
    

    return NULL;
}

vector<int> merge_lists(vector<int> &u, vector<int> &v, int size){

    int a = 0, b = size-1, c = 0, d = size-1;
    // a-->b and c--> d are 2 adjacent sections

    vector<int> temp;   // will do an outplace merge
    int i=a,j=c;

    while( i<=b and j<=d){
        if(u[i] < v[j])
            temp.push_back(u[i++]);
        else
            temp.push_back(v[j++]);
    }

    while(i<=b) 
        temp.push_back(u[i++]);

    while(j<=d) 
        temp.push_back(v[j++]);

    return temp;
}


void print_tab_content(void *v){
    int i;
    vector<int> *tab = (vector<int> *)v;
    ;
    for(i = 0; i < tab->size(); i++){
        if(i != tab->size() - 1)
            printf("%d\n", (*tab)[i]);
        else
            printf("%d", (*tab)[i]);
    }
    
}

int thread_sort(vector<int> &v, int size){
    
    vector<int> v0,v1,v2,v3,v4,v5,v6,v7, t0,t1,t2,t3, p0,p1, s;
    v0.assign(v.begin(), v.begin()+SPLIT_SIZE);
    v1.assign(v.begin()+SPLIT_SIZE, v.begin()+2*SPLIT_SIZE);
    v2.assign(v.begin()+2*SPLIT_SIZE, v.begin()+3*SPLIT_SIZE);
    v3.assign(v.begin()+3*SPLIT_SIZE, v.begin()+4*SPLIT_SIZE);
    v4.assign(v.begin()+4*SPLIT_SIZE, v.begin()+5*SPLIT_SIZE);
    v5.assign(v.begin()+5*SPLIT_SIZE, v.begin()+6*SPLIT_SIZE);
    v6.assign(v.begin()+6*SPLIT_SIZE, v.begin()+7*SPLIT_SIZE);
    v7.assign(v.begin()+7*SPLIT_SIZE, v.begin()+8*SPLIT_SIZE);
    

    thread thread0(wrapper_quicksort, &v0);
    thread thread1(wrapper_quicksort, &v1);
    thread thread2(wrapper_quicksort, &v2);
    thread thread3(wrapper_quicksort, &v3);
    thread thread4(wrapper_quicksort, &v4);
    thread thread5(wrapper_quicksort, &v5);
    thread thread6(wrapper_quicksort, &v6);
    thread thread7(wrapper_quicksort, &v7);
    
    
    // force the threads to join back to the main program
    thread0.join();
    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();
    thread5.join();
    thread6.join();
    thread7.join();

    // merging 8 thread results into 4

   t0 = merge_lists(v0,v1, SPLIT_SIZE);
   t1 = merge_lists(v2,v3, SPLIT_SIZE);
   t2 = merge_lists(v4,v5, SPLIT_SIZE);
   t3 = merge_lists(v6,v7, SPLIT_SIZE);
    
    // merging 4 into 2

    p0 = merge_lists(t0, t1, 2* SPLIT_SIZE);
    p1 = merge_lists(t2, t3, 2*SPLIT_SIZE);

    // finally merging 2 into 1 sorted list 

    s = merge_lists(p0, p1, 4* SPLIT_SIZE);

    
    print_tab_content(&s);
    
}



int main(int argc, char* argv[])
{
	
	const int MAX = 1000000;
  	ofstream fout;
	ifstream fin;
	int n, i = 0;
	
	vector<int> v;
	int count = 0;
	
	fin.open(argv[1]);
	while (fin >> n )
	{
		v.push_back(n);
        i++;	
	}
    
    thread_sort(v, i);
    
    return 0;
} 