#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ROW 3
#define COL 3

/* int create_matrix(void)
{

srand(time(NULL));
for (i = 0; i <= 2; i++)
{
printf("[ ");
for (j = 0; j <= 2; j++)
{
macierz1[i][j] = rand() % 9;

printf("%3d", macierz1[i][j]);
if (j == 2) printf(" ]\n");
}
}

printf("--------------------\n\n");
for (i = 0; i <= 2; i++)
{
printf("[ ");
for (j = 0; j <= 2; j++)
{
macierz2[i][j] = rand() % 6;

printf("%3d", macierz2[i][j]);
if (j == 2) printf(" ]\n");

}
}
}

int transpozycja()
{
int temp1, temp2;


for (i=0; i<=2; i++)
{
for (j=0; j<=2; j++)
{
macierzT[j][i]=macierz2[i][j];
}
}

}
int mnozenie_macierzy(int tab1[][3], int tab2[][3])
{
for(i=0; i<3; i++)
{
for(j=0;j<3;j++)
wynik[i][j] = 0;
}

for(i=0; i<3; i++)
{
for(j=0;j<3;j++)
{
for(k=0;k<3;k++)
wynik[i][j] = wynik[i][j] + (tab1[i][k]*tab2[k][j]);
}

}
}
*/

void print_matrix(int ilosc_wierszy, int ilosc_kolumn, int *tab)
{
	int i, j;

	for (i = 0; i < ilosc_wierszy; i++)
	{
		printf("[");
		for (j = 0; j < ilosc_kolumn; j++)
		{
			printf("%4d", tab[i*ilosc_kolumn + j]);
			if (j == 2) printf(" ]\n");
		}
	}

	printf("\n\n");
	/*
	printf("--------------------\n\n");
	for (i = 0; i <= 3; i++)
	{
	printf("[ ");
	for (j = 0; j <= 3; j++)
	{
	printf("%3d", macierz2[i][j]);
	if (j == 3) printf(" ]\n");

	}
	} */
}

void suma_macierzy(int ilosc_wierszy, int ilosc_kolumn, int *tab1, int *tab2, int *suma)
{
	int i, j;
	for (i = 0; i < ilosc_wierszy; i++)
	{
		for (j = 0; j < ilosc_kolumn; j++)
			suma[i*ilosc_kolumn + j] = tab1[i*ilosc_kolumn + j] + tab2[i*ilosc_kolumn + j];
	}

}
int main(void)
{
	int matrixA[ROW][COL], matrixB[ROW][COL], suma[ROW][COL], i, j;

	for (i = 0; i<ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			matrixA[i][j] = i * 2;
			matrixB[i][j] = i * 2 + j;
		}
		
	}

	printf("macierzA: \n");
	print_matrix(ROW, COL, matrixA);
	printf("macierzB: \n");
	print_matrix(ROW, COL, matrixB);
	printf("macierz1 + macierz2: \n\n");
	suma_macierzy(ROW, COL, matrixA, matrixB, suma);
	print_matrix(ROW, COL, suma);
	getchar();
	return 0;
}

/*

int t[3][5]

t[2][1]=zmienione

pisz(int a[], int l.wierszy, int l.kolumn)
{
printf("%d", a[2*lkolumn+1])               >> a[i*KOLUMNY+WIERWSZ]

}

*/
