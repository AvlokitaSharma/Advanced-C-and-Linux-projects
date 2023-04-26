#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <thread>
#include <unistd.h>
using namespace std;

#define SPLIT_SIZE 125000

void print_tab_content(void *tab);



vector<int> *insertsort(void *tab){
    int i, j, tmp;
    vector<int> *v = (vector<int> *)tab;

    for (i=1 ; i <= v->size() - 1; i++) {
        j = i;
    
        while (j > 0 && (*v)[j-1] > (*v)[j]) {
            tmp = (*v)[j];
            (*v)[j] = (*v)[j-1];
            (*v)[j-1] = tmp;
            j--;
        }
    }

    for(int g = 0; g < v->size(); g++){
        (*(vector<int> *)tab)[g] = (*v)[g];
    }
    return v;
}



int *quicksort(int v[], int low, int high)                                                    
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

vector<int> *fill_array(void *v){
    int i;
    vector<int> *tab = new vector<int>;
    tab = (vector<int> *)v;
    return tab;
}

vector<int> *split_sort_thread(void *v, int size){
    vector<int> *tab = (vector<int> *)v;

    vector<int> *tab0, *tab1, *tab2, *tab3, *tab4, *tab5, *tab6, *tab7;

    pthread_t thread0, thread1, thread2, thread3, thread4, thread5, thread6, thread7;

    int iret0, iret1, iret2, iret3, iret4, iret5, iret6, iret7;

    int split_size = size / 8, j = 0;

    int step;
    
    vector<int>::const_iterator inf_born0 = (*tab).begin();
    vector<int>::const_iterator sup_born0 = (*tab).begin() +  SPLIT_SIZE + 1;
    vector<int> v0(inf_born0, sup_born0);
    tab0 = &v0;
    iret0 = pthread_create(&thread0, NULL, wrapper_quicksort, tab0);
    pthread_join(thread0, NULL);
    step  =  SPLIT_SIZE;


    vector<int>::const_iterator inf_born1 = (*tab).begin() + step;
    vector<int>::const_iterator sup_born1 = (*tab).begin() + step +  SPLIT_SIZE + 1;
    vector<int> v1(inf_born1, sup_born1);

    tab1 = &v1;
    iret1 = pthread_create(&thread1, NULL, wrapper_quicksort, tab1);
    pthread_join(thread1, NULL);
    step  = 2 * SPLIT_SIZE;


    vector<int>::const_iterator inf_born2 = (*tab).begin() + step;
    vector<int>::const_iterator sup_born2 = (*tab).begin() + step + SPLIT_SIZE + 1;
    vector<int> v2(inf_born2, sup_born2);

    tab2 = &v2;

    iret2 = pthread_create(&thread2, NULL, wrapper_quicksort, tab2);
    pthread_join(thread2, NULL);
    step  = 3 * SPLIT_SIZE;


    vector<int>::const_iterator inf_born3 = (*tab).begin() + step;
    vector<int>::const_iterator sup_born3 = (*tab).begin() + step + SPLIT_SIZE + 1;
    vector<int> v3(inf_born3, sup_born3);

    tab3 = &v3;
    iret3 = pthread_create(&thread3, NULL, wrapper_quicksort, tab3);
    pthread_join(thread3, NULL);
    step  = 4 * SPLIT_SIZE;

    vector<int>::const_iterator inf_born4 = (*tab).begin() + step;
    vector<int>::const_iterator sup_born4 = (*tab).begin() + step + SPLIT_SIZE + 1;
    vector<int> v4(inf_born4, sup_born4);

    tab4 = &v4;

    iret4 = pthread_create(&thread4, NULL, wrapper_quicksort, tab4);
    pthread_join(thread4, NULL);
    step  = 5 * SPLIT_SIZE;


    vector<int>::const_iterator inf_born5 = (*tab).begin() + step;
    vector<int>::const_iterator sup_born5 = (*tab).begin() + step + SPLIT_SIZE + 1;
    vector<int> v5(inf_born5, sup_born5);

    tab5 = &v5;
    iret5 = pthread_create(&thread5, NULL, wrapper_quicksort, tab5);
    pthread_join(thread5, NULL);
    step  = 6 * SPLIT_SIZE;

    vector<int>::const_iterator inf_born6 = (*tab).begin() + step;
    vector<int>::const_iterator sup_born6 = (*tab).begin() + step + SPLIT_SIZE + 1;
    vector<int> v6(inf_born6, sup_born6);

    tab6 = &v6;
    iret6 = pthread_create(&thread6, NULL, wrapper_quicksort, tab6);
    pthread_join(thread6, NULL);
    step  = 7 * SPLIT_SIZE;

    vector<int>::const_iterator inf_born7 = (*tab).begin() + step;
    vector<int>::const_iterator sup_born7 = (*tab).begin() + step + SPLIT_SIZE + 1;
    vector<int> v7(inf_born7, sup_born7);

    tab7 = &v7;
    iret7 = pthread_create(&thread7, NULL, wrapper_quicksort, tab7);
    pthread_join(thread7, NULL);

    vector<int> super_tab0(2 * SPLIT_SIZE), super_tab1(2 * SPLIT_SIZE), super_tab2(2 * SPLIT_SIZE), super_tab3(2 * SPLIT_SIZE);
    vector<int> *s_tab0, *s_tab1, *s_tab2, *s_tab3;

    for(int k = 0, z = 0; k < super_tab0.size() ; k++){
        if( k < SPLIT_SIZE){
            super_tab0[k] = (*tab0)[k];
            super_tab1[k] = (*tab2)[k];
            super_tab2[k] = (*tab4)[k];
            super_tab3[k] = (*tab6)[k];
        }
        else{
            super_tab0[k] = (*tab1)[z];
            super_tab1[k] = (*tab3)[z];
            super_tab2[k] = (*tab5)[z];
            super_tab3[k] = (*tab7)[z];
            z++;
        }
    }
    
    s_tab0 = &super_tab0;
    s_tab1 = &super_tab1;
    s_tab2 = &super_tab2;
    s_tab3 = &super_tab3;

    insertsort(s_tab0);
    insertsort(s_tab1);
    insertsort(s_tab2);
    insertsort(s_tab3);

    vector<int> super_tab01(4 * SPLIT_SIZE), super_tab02(4 * SPLIT_SIZE);
    vector<int> *s_tab01, *s_tab02;

    for(int k = 0, z = 0; k < super_tab01.size(); k++){
        if( k < 2 * SPLIT_SIZE){
            super_tab01[k] = (*s_tab0)[k];
            super_tab02[k] = (*s_tab2)[k];
        }
        else{
            super_tab01[k] = (*s_tab1)[z];
            super_tab02[k] = (*s_tab3)[z];
            z++;
        }
    }

    s_tab01 = &super_tab01;
    s_tab02 = &super_tab02;


    insertsort(s_tab01);
    insertsort(s_tab02);

    vector<int> super_tab_f(8 * SPLIT_SIZE);
    vector<int> *s_tab_f;

    for(int k = 0, z = 0; k < super_tab_f.size(); k++){
        if( k < 4 * SPLIT_SIZE){
            super_tab_f[k] = (*s_tab01)[k];
        }
        else{
            super_tab_f[k] = (*s_tab02)[z];
            z++;
        }
    }

    s_tab_f = &super_tab_f;

    insertsort(s_tab_f);

    print_tab_content(s_tab_f);
    return NULL;
}


void print_tab_content(void *v){
    int i;
    vector<int> *tab = (vector<int> *)v;

    for(i = 0; i < tab->size(); i++){
        if(i != tab->size() - 1)
            printf("%d\n", (*tab)[i]);
        else
            printf("%d", (*tab)[i]);
    }
    
}





int main(int argc, char* argv[])
{
	


	const int MAX = 1000000;
  	ofstream fout;
	ifstream fin;
	int n, i = 0;
	
	vector<int> v(MAX);
	int count = 0;
	
	fin.open(argv[1]);
	while (fin >> n )
	{
		v[count++] = n;
        i++;	
	}

    split_sort_thread(&v, MAX); 
    
    
    return 0;
} 