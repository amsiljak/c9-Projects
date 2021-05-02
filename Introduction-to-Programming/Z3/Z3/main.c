#include <stdio.h>

/*Pomocna funkcija koja daje sredinu intervala */
int sr_intervala(int x, int y)
{
	return (x+y)/2;
}

/*glavna funkcija koja pogadja broj*/
int daj_sljedeci_broj(int parametar)
{
	static int x=0,y=100;

	if (parametar==-1)
		{
			y=sr_intervala(x,y);
			return sr_intervala(x,y);
		}
	if (parametar==1)
		{
			x=sr_intervala(x,y);
			return sr_intervala(x,y);
		}

	return sr_intervala(x,y);
}

int main()
{

	char odgovor;

	printf("Zamislite neki broj...");
	printf("\nDa li je taj broj %d? ", daj_sljedeci_broj(0));

	/*petlja koja se ponavlja dok broj ne bude pogodjen*/
	do
		{
			scanf(" %c", &odgovor);

			if(odgovor=='M')
				{
					printf("Da li je taj broj %d? ", daj_sljedeci_broj(-1));
					continue;
				}

			if(odgovor=='V')
				{
					printf("Da li je taj broj %d? ", daj_sljedeci_broj(1));
					continue;
				}

			/*pogresan unos*/
			if(odgovor!='V' && odgovor!='M' && odgovor!='J')
				{
					printf("Pogresan unos, probajte ponovo. \n");
					printf("Da li je taj broj %d? ", daj_sljedeci_broj(0));

				}
		}
	while (odgovor!='J');

	printf("Pogodio sam!");
	return 0;
}
