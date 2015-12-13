#include <stdio.h>
#include <stdlib.h>
#include <ctime>
//usuniety plik na galezi z komentarzem
char tab[3][3] = {
                 {'1','2','3'},
                 {'4','5','6'},
                 {'7','8','9'}
                        };

int gracz = 0;                        
int runda = 0;
int wygrana = 0;
int wiersz = 0;
int kolumna = 0;

/*rysuje plansze*/
void plansza(void)
{
	printf("\n");
	printf(" %c | %c | %c \n", tab[0][0], tab[0][1], tab[0][2]);
	printf(" ---------\n");
	printf(" %c | %c | %c \n", tab[1][0], tab[1][1], tab[1][2]);
	printf(" ---------\n");
	printf(" %c | %c | %c \n", tab[2][0], tab[2][1], tab[2][2]);
	printf("__________\n\n");
}

/*ruch czlowieka*/
void ruchCzlowiek()
{	
	int wiersz, kolumna, x;
	
	do
	{
		printf("	Twoj ruch: ");
		scanf("%d",&x);	
		x=--x;
		wiersz=(x/3);										
		kolumna=(x%3);
	} while (x<0 || x>9 || tab [wiersz][kolumna]>'9'); 

	tab[wiersz][kolumna] = 'X';	
}

/*ruch komputera*/
void ruchKomputer()
{	
	srand(time(NULL));
	int wierszKomputer, kolumnaKomputer, wyborKomputera;
	do
	{
		wierszKomputer = rand() % 3;							// ciagle ta sama kolejnosc???????????
		kolumnaKomputer = rand() % 3;		
	} while (tab [wierszKomputer][kolumnaKomputer]>'9'); 

	wyborKomputera=tab[wierszKomputer][kolumnaKomputer];
	printf("	Moj ruch: %c\n", wyborKomputera);
	tab[wierszKomputer][kolumnaKomputer] = 'O';
}

/*sprwadzenie wygranej*/
void czyWygrana() 
{
	int i;	
	
	if ((tab[0][0]==tab[1][1] && tab[0][0]==tab[2][2]) ||              /* sprawdz diagonalne */
		(tab[2][0]==tab[1][1] && tab[2][0]==tab[0][2]))
	
		wygrana=gracz;
		
	else 
		for (i=0; i<3; ++i)
		{ 
			if ((tab[i][0]==tab[i][1] && tab[i][0]==tab[i][2]) ||     /* sprawdz wiersze */
		  		(tab[0][i]==tab[1][i] && tab[0][i]==tab[2][i]))		  /* sprawdz kolumny */		
			
				wygrana=gracz;			
		}
}


/* glowna funkcja */
int main(void)             
{
	plansza();

	for (runda=0; runda<9 && wygrana==0; runda++)
	{	
		gracz=runda%2 + 1;	
		
		if (gracz==1)
			ruchCzlowiek();
		else
			ruchKomputer();
		
		plansza();
		czyWygrana();	
	}
	
	if (!wygrana)												//mniej sprawdzania niz w warunku nizej
		printf("Remis!");
	
	else if (gracz==1)
			printf("Wygrales!\n");
			else printf("Wygralem!");


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