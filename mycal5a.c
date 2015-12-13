#include <stdio.h>
int main(void)
{
	int i, m, d, p, koniec, c, dzienOK;

	koniec = 0;

	do {		
		printf("podak ilosc dni miesiacaa (31,30,29,28): \n");
		if(scanf("%d", &m)==1) 
		{
			if (m >= 28 && m <= 31) 
			{
				do 
				{
					printf("podak pierwszy dzien tygodnia: (1-PN, 7-ND)\n");
					scanf("%d", &d);
					dzienOK = d>0 && d<8;

					if (dzienOK) 
					{
						printf("  PN  WT  SR  CZ  PT  SB  ND\n");
						
						for (p = 1; p < d; p++) 
							printf("  --");
						
						
						for (i = 1; i <= m; ++i)
						{
							printf(" %3d", i);
							if (((i + d - 1) % 7) == 0)
							{
								putchar('\n');
							}
						}

						printf("\n");
						printf("Nacicnik dowolny klawisz aby kontynuowac lub x aby zakonnzyc");
						printf("\n");

						c = getchar();
						c = getchar();

						if(c == 'x')
							koniec = 1;
					}
					else 
					printf("BLAD: nie ma takiego dnia tygodnia\n");	

				} while (!dzienOK);
			} else
				printf("BLAD: nie ma takiego miesiaca!\n");
				
		
		} 
		else		
		{
			printf("BLAD: podak liczbe!\n");
			fflush(stdin);
		}
		

/*
		switch (m)
		{
			case 31:
			{
				printf("podak pierwszy dzien tygodnia: (1-PN, 7-ND)\n");
				scanf("%d", &d);
				
				if ((d>0) & (d<8)) 
				{
					printf("  PN  WT  SR  CZ  PT  SB  ND\n");
					
					for (p = 1; p < d; p++) 
						printf("  --");
					
					
					for (i = 1; i <= 31; ++i)
					{
						printf(" %3d", i);
						if (((i + d - 1) % 7) == 0)
						{
							putchar('\n');
						}
					}
				}
				else 
				printf("nie ma takiego dnia tygodnia\n");	
			}
			break;
			case 30:
			{
				printf("podak pierwszy dzien tygodnia: (1-PN, 7-ND)\n");
				scanf("%d", &d);
				printf("  PN  WT  SR  CZ  PT  SB  ND\n");

				for (p = 1; p < d; p++) 
					printf("  --");

				for (i = 1; i <= 30; ++i)
				{
					printf(" %3d", i);
					if (((i + d - 1) % 7) == 0)
					{
						putchar('\n');
					}
				}
			}
			break;
			case 29: // luty 29 
			{
				printf("podak pierwszy dzien tygodnia: (1-PN, 7-ND)\n");
				scanf("%d", &d);
				printf("  PN  WT  SR  CZ  PT  SB  ND\n");
				
				for (p = 1; p < d; p++) 
					printf("  --");
				
				for (i = 1; i <= 29; ++i)
				{
					printf(" %3d", i);
					if (((i + d - 1) % 7) == 0)
					{
						putchar('\n');
					}
				}
			}
			break;
			case 28: // la lutego 28   
			{
				printf("podak pierwszy dzien tygodnia: (1-PN, 7-ND)\n");
				scanf("%d", &d);
				printf("  PN  WT  SR  CZ  PT  SB  ND\n");

				for (p = 1; p < d; p++) 
					printf("  --");

				for (i = 1; i <= 28; ++i)
				{
					printf(" %3d", i);
					if (((i + d - 1) % 7) == 0)
					{
						putchar('\n');
					}
				}
			}
			break;
			default: printf("nie ma takiego miesiaca!");
		} 
*/

		

	} while (koniec == 0);

	return 0;
}
