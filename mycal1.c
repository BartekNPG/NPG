#include <stdio.h>
int main(void)
{
	
	int i, m, d, p;
	printf("podaj ilosc dni miesiaca: \n");
	scanf("%d",&m);
	printf("podaj pierwszy dzien tygodnia\n");
	scanf("%d",&d);




	 if (m==31)
		{
			printf("  PN  WT  SR  CZ  PT  SB  ND\n");
			for (p=1;p<d;p++) printf("  --");
				p=p;
			for (i=1; i<=31; ++i)
				{				
					printf(" %3d", i); 					
					if (((i+d-1) % 7)==0)
						{
							putchar('\n');
						}
				}
		}
	 else if (m=30)
			{
				printf("  PN  WT  SR  CZ  PT  SB  ND\n");
				for (p=1;p<d;p++) printf("  --");
					p=p;
				for (i=1; i<=30; ++i)
					{					
						printf(" %3d", i); 						
						if (((i+d-1) % 7)==0)
							{
								putchar('\n');
							}
					}
			}
			else if (m=29)
				{
					printf("  PN  WT  SR  CZ  PT  SB  ND\n");
					for (p=1;p<d;p++) printf("  --");
						p=p;
					for (i=1; i<=29; ++i)
						{					
							printf(" %3d", i); 						
							if (((i+d-1) % 7)==0)
								{
									putchar('\n');
								}
						}
				}
			else  //dla lutego 28
				{
					printf("  PN  WT  SR  CZ  PT  SB  ND\n");
					for (p=1;p<d;p++) printf("  --");
						p=p;
					for (i=1; i<=28; ++i)
					{					
						printf(" %3d", i); 
						
						if (((i+d-1) % 7)==0)
							{
								putchar('\n');
							}
					}
				}
getchar();
return 0;

}