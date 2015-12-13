#include <stdio.h>
//#include <time.h>
#include <stdlib.h>
#define SIZE 6

void inicjalizacka_wektorow(void)
{
//	srand(time(NULL));
	//n = rand();
	int wektor1[5];
	int wektor2[5];
	
	int i;

	
	{
//		wektor1[i] = rand() % 6;
//		wektor2[i] = rand() % 7;
		
	}
}
int * suma_wektorow(int rozmiar, int *wektor1, int wektor2[], int suma[])
{
	int i;
	for (i = 0; i < rozmiar; i++) 
		suma[i] = wektor1[i] + wektor2[i];

	return suma;
		
	
/*	printf("[");
	for (i = 0; i < 5; i++)
	{
		printf(" %d ", wektor1[i]);
	}
	printf("]\n");

	printf("[");
	for (i = 0; i < 5; i++)
	{
		printf(" %d ", wektor2[i]);
	}
	printf("]\n");
	printf("suma tych wektorow to: \n");
	printf("[");
	for (i = 0; i < 5; i++)
	{
		printf(" %d ", suma[i]);
	}
	printf("]");
  
*/
}

int main(void)
{
	//srand(time(NULL));
	//n = rand();
	int wektor1[SIZE], wektor2[SIZE], suma[SIZE], i;
	int *wsk;
	
	
	for (i=0;i<SIZE;i++)
	{
		wektor1[i] = i*2;
		wektor2[i] = i*2+1;		
	}
	for (i = 0; i < SIZE; i++)		
		printf(" %d ", wektor1[i]);
	printf("\n");
	for (i = 0; i < SIZE; i++)		
		printf(" %d ", wektor2[i]);
	printf("\n\n");
	
	wsk = suma_wektorow(SIZE, wektor1, wektor2, suma);


	for (i = 0; i < SIZE; i++)		
		printf(" %d ", suma[i]);

	//getchar();
	return 0;
}
