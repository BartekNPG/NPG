#include <stdio.h>
#include <stdlib.h>

char tab[3][3] = {
                 {'1','2','3'},
                 {'4','5','6'},
                 {'7','8','9'}
                        };
//int x, o, gracz, wiersz, kolumna, runda, wygrana;

int gracz = 0;                        
int runda = 0;
int wygrana = 0;

void plansza(void)
{
	printf("\n");
	printf(" %c | %c | %c \n", tab[0][0], tab[0][1], tab[0][2]);
	printf(" ---------\n");
	printf(" %c | %c | %c \n", tab[1][0], tab[1][1], tab[1][2]);
	printf(" ---------\n");
	printf(" %c | %c | %c \n", tab[2][0], tab[2][1], tab[2][2]);
}

void ruch()
{	
	int wiersz, kolumna, x;
	
	do
	{
		printf("\n");
		printf("gracz %d, podaj gdzie chcesz postawic %c: ", gracz, (gracz==1)? 'X' : 'O');
		scanf("%d",&x);	
		x=--x;
		wiersz=(x/3);										
		kolumna=(x%3);
	}
	while (x<0 || x>9 || tab [wiersz][kolumna]>'9'); 

	tab[wiersz][kolumna] = (gracz==1) ? 'X':'O';
	
	
}

void czyWygrana()
{
	int i;	
	
	if ((tab[0][0]==tab[1][1] && tab[0][0]==tab[2][2]) ||              /* sprawdz diagonalne */
		(tab[2][0]==tab[1][1] && tab[2][0]==tab[0][2]))
		{
			wygrana=gracz;
		}	
	else 
		for (i=0; i<3; ++i)
		{ 
			if ((tab[i][0]==tab[i][1] && tab[i][0]==tab[i][2]) ||     /* sprawdz wiersze */
		  		(tab[0][i]==tab[1][i] && tab[0][i]==tab[2][i]))		  /* sprawdz kolumny */		
				{
					wygrana=gracz;
				}
		}
}

void rywal();
{
	wierszRywal = rand() % 3;
	kolumnaRywal = rand() % 3;




}

int main(void)
{
	plansza();

	for (runda=0; runda<9 && wygrana==0; runda++)
	{	
		gracz=runda%2 + 1;	
		if (gracz==1)
			
		ruch();
		plansza();
		czyWygrana();	
	}
	
	if (!wygrana)												//mniej sprawdzania niz w warunku nizej
		printf("Remis!");
	
	else printf("Koniec! Gracz %d zwyciezyl!", gracz);


/*	if (wygrana==1 || wygrana==2)
		{
			printf("Koniec! Gracz %d zwyciezyl!", gracz);
		}
		else printf("remis!");
*/

	getchar();
	getchar();						  
	return 0;

}						  