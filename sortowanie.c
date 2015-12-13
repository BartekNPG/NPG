#include <stdio12.h>
#include <time.h>
#include <stdlib.h>

int n, size;
int tab[50];

void bubblesort(int size) {
	int i, k, temp;
	for (i = 0; i<size-1; i++) {
		for (k = 0; k<size - 1 - i; k++) {
			if (tab[k] > tab[k+1]) {
 				temp = tab[k+1];
				tab[k+1] = tab[k];
				tab[k] = temp;
			}		
		}
	}
}



int main(void) {
	
	srand(time(NULL));
	for(n=0; n<50;n++) {
		tab[n] = rand() % 124;
	}

	for(n=0; n<50;n++) {
		if (((n % 10) == 0) && n>0) printf("\n");
		printf("%4d, ", tab[n]);		
	}

	bubblesort(50);
	
	printf("\n\n");
	
	for (n=0; n<50;n++) {
		if (((n % 10) == 0) && n>0) printf("\n");
		printf("%4d, ", tab[n]);		
	}
	
	getchar();
	return 0;
}