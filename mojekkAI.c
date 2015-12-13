#include <stdio.h>
#include <stdlib.h>
#include <ctime>
//stara nazwa na branchu
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

	tab[wiersz][kolumna] = 'O';	
}

/*ruch komputera*/
void ruchKomputer()
{	
	srand(time(NULL));
	int wierszKomputer, kolumnaKomputer, wyborKomputera;
	do
	{
		wierszKomputer = rand() % 3;							
		kolumnaKomputer = rand() % 3;		
	} while (tab [wierszKomputer][kolumnaKomputer]>'9'); 

	wyborKomputera=tab[wierszKomputer][kolumnaKomputer];
	
	printf("	Moj ruch: %c\n", wyborKomputera);
	
	tab[wierszKomputer][kolumnaKomputer] = 'X';
}

/*sprawdzenie nastepnego ruchu dla komputera*/
void testRuch()
{
	
	int i, nicNieZaszlo;
	if (runda == 1 && tab[1][1]<'9')
	{
		printf("	Moj ruch: %c\n", tab[1][1]);
		tab[1][1]='X';
	}
	else
	if (runda == 1 && tab[1][1]>'9')
		ruchKomputer();
	else
	{
		if ((tab[0][0]==tab[2][2] || tab[0][2]==tab[2][0]) && tab[1][1]<'9') 	/* sprawdza przekatne 1 i 9, 3 i 7 */
			tab[1][1]='X'; 
																				/* sprawdza 2/3 z przekatnych: */
		else	if (tab[0][0]==tab[1][1] && tab[2][2]<'9') 						/* pola 1 i 5 */
					{
						printf("	Moj ruch: %c\n", tab[2][2]);
						tab[2][2]='X';
					}
																				
		else	if (tab[1][1]==tab[2][2] && tab[0][0]<'9')								/* pola 5 i 9 */
					{
						printf("	Moj ruch: %c\n", tab[0][0]);
						tab[0][0]='X';
					}															
		else	if (tab[0][2]==tab[1][1] && tab[2][0]<'9')								/* pola 3 i 5 */
					{
						printf("	Moj ruch: %c\n", tab[2][0]);
						tab[2][0]='X';
					}																
		else	if (tab[1][1]==tab[2][0] && tab[0][2]<'9')								/* pola 5 i 7 */
					{
						printf("	Moj ruch: %c\n", tab[0][2]);
						tab[0][2]='X';
					}																						
		else
		{	
			for (i=0; i<3; i++)
			{
				nicNieZaszlo=0;		
				if (tab[i][0]==tab[i][1] && tab[i][2]<'9')				/* sprawdza komorki 1 i 2, 4 i 5, 7 i 8 */
					{
						printf("	Moj ruch: %c\n", tab[i][2]);
						tab[i][2]='X';						
						break;
					}			
				if (tab[i][1]==tab[i][2] && tab[i][0]<'9')				/* sprawdza komorki 2 i 3, 6 i 7, 8 i 9 */
					{						
						printf("	Moj ruch: %c\n", tab[i][0]);
						tab[i][0]='X';						
						break;
					}
				if (tab[0][i]==tab[1][i] && tab[2][i]<'9')				/* sprawdza komorki 1 i 4, 2 i 5, 3 i 6 */
					{						
						printf("	Moj ruch: %c\n", tab[2][i]);
						tab[2][i]='X';						
						break;
					} 
				if (tab[i][0]==tab[i][2] && tab[1][i]<'9')				/* sprawdza komorki 4 i 7, 5 i 6, 6 i 9 */
					{
						printf("	Moj ruch: %c\n", tab[1][i]);
						tab[1][i]='X';						
						break;
					}
				if (tab[0][i]==tab[2][i] && tab[i][2]<'9')				/* sprawdza komorki 1 i 3, 4 i 6, 7 i 9 */
					{
						printf("	Moj ruch: %c\n", tab[i][2]);
						tab[i][2]='X';						
						break;
					}	
				if (tab[0][i]==tab[2][i] && tab[1][i]<'9')				/* sprawdza komorki 1 i 7, 2 i 8, 3 i 9 */
					{						
						printf("	Moj ruch: %c\n", tab[1][i]);
						tab[1][i]='X';						
						break;
					}
				else													
						nicNieZaszlo=1;											
			}
		}
		if (nicNieZaszlo==1) 
			ruchKomputer();
	}
	
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
	int i;
	for(i=0;;i++)
	{	
		plansza();

		for (runda=0; runda<9 && wygrana==0; runda++)
		{	
			gracz=runda%2 + 1;	
			
			if (gracz==1)
				ruchCzlowiek();
			else
				// ruchKomputer();
				testRuch();
			plansza();
			czyWygrana();	
		}
		
		if (!wygrana)												
			printf("Remis!");
		
		else if (gracz==1)
				printf("Wygrales!\n");
				else printf("Wygralem!");
		getchar();
		runda=0;

		
	
	
	} 
		
							  
	return 0;

}						  