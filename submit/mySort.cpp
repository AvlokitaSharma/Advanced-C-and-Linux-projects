#include"pthread.h"
#include"stdlib.h"
#include"iostream"
#include"stdio.h"


using namespace std;


int tab[1000000];
int sections[8][2];

void* Sort(void* section){

	int* index = (int*)section;
	int tmp;

	for(int i = index[0];i<index[1];i++){
		for(int j=index[0];j<i;j++){

			
			
			if(tab[i]<tab[j]){
			tmp = tab[i];
			for(int k=i-1;k>=j;k--)
				tab[k+1]=tab[k];
			 tab[j]=tmp;	
			}
			
		}
	}
	return section;
}

void merge(int min,int half,int max){

	int *tmp_tab = (int*) malloc(1000000*sizeof(int));
	int i=min,j=half,k=0;

	if(tmp_tab==NULL)
		exit(0);

	while(i<half && j<max){
	
		if(tab[i]<tab[j]){
			tmp_tab[k]=tab[i];
			i++;
		}else if(tab[j]<tab[i]){
			tmp_tab[k]=tab[j];
			j++;
		}
		else{
			tmp_tab[k]=tab[i];
			i++;
			k++;
			tmp_tab[k]=tab[j];
			j++;
		}
		k++;
	}

	for(int m=i;m<half;m++,k++)
		tmp_tab[k]=tab[m];

	for(int m=j;m<max;m++,k++)
		tmp_tab[k]=tab[m];

	for(i=min,k=0;i<max;i++,k++){
		tab[i]=tmp_tab[k];
	}

	free(tmp_tab);
}

void load_numbers(char* fileName){

	FILE *fp;
	char line[10];

	fp=fopen(fileName,"r");

	if(fp==NULL){
		cout<<"error while opening the file\n";
		exit(0);
	}

	for(int i=0;i<1000000;i++){

		fgets(line,19,fp);
		tab[i]=atoi(line);
	}
	fclose(fp);
}
void save_numbers(char  *fileName){

	FILE *fp;
	fp=fopen(fileName,"w");

	if(fp==NULL){
		cout<<"error while opening the file\n";
		exit(0);
	}

	for(int i=0;i<1000000;i++)
		fprintf(fp, "%d\n",tab[i] );

	fclose(fp);

}


int main(int argc,char** argv){

	pthread_t thread1,thread2,thread3,thread4,thread5,thread6,thread7,thread8;

	sections[0][0]=0*125000;sections[0][1]=1*125000;
	sections[1][0]=1*125000;sections[1][1]=2*125000;
	sections[2][0]=2*125000;sections[2][1]=3*125000;
	sections[3][0]=3*125000;sections[3][1]=4*125000;
	sections[4][0]=4*125000;sections[4][1]=5*125000;
	sections[5][0]=5*125000;sections[5][1]=6*125000;
	sections[6][0]=6*125000;sections[6][1]=7*125000;
	sections[7][0]=7*125000;sections[7][1]=8*125000;


	load_numbers(argv[1]);
	
	pthread_create(&thread1,NULL,Sort,(void*) sections[0]);
	pthread_create(&thread2,NULL,Sort,(void*) sections[1]);
	pthread_create(&thread3,NULL,Sort,(void*) sections[2]);
	pthread_create(&thread4,NULL,Sort,(void*) sections[3]);
	pthread_create(&thread5,NULL,Sort,(void*) sections[4]);
	pthread_create(&thread6,NULL,Sort,(void*) sections[5]);
	pthread_create(&thread7,NULL,Sort,(void*) sections[6]);
	pthread_create(&thread8,NULL,Sort,(void*) sections[7]);

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	pthread_join(thread3,NULL);
	pthread_join(thread4,NULL);
	pthread_join(thread5,NULL);
	pthread_join(thread6,NULL);
	pthread_join(thread7,NULL);
	pthread_join(thread8,NULL);
	
	

	merge(125000*0,125000*1,125000*2);
	merge(125000*2,125000*3,125000*4);
	merge(125000*4,125000*5,125000*6);
	merge(125000*6,125000*7,125000*8);

	merge(125000*2*0,125000*2*1,125000*2*2);
	merge(125000*2*2,125000*2*3,125000*2*4);

	merge(0,500000,1000000);

	save_numbers(argv[2]);

	return 0;

}

