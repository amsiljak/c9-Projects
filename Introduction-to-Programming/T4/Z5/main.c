#include <stdio.h>

int main()
{
	int broj, cifra, novi_broj=0; /*123456*/ /*vraijabla broj je varijabla 
	u koju unosimo broj sa tastature, a varijabla "novi broj" je varijabla 
	u koju pohranjujemo obrnute brojeve ali bez cifre koju moramo izbaciti */
	do
		{
			printf("Unesite broj: ");
			scanf("%d", &broj);
		}
	while (broj<0);


	do
		{
			printf("Unesite cifru: ");
			scanf("%d", &cifra);
			if(cifra>=0 && cifra<=9) break;
		}
	while(1);

	while(broj>0)
		{
			if(broj%10==cifra)
				{
					broj=broj/10;
					continue;
				}
			else
				{
					novi_broj = novi_broj + (broj%10);  /*Nova vrijednost varijable "novi_broj" 
					je jednaka zbiru stare vrijednosti varijable "novi_broj" i zadnje cifre unesenog
					broja (modul unesenog broja)*/
					novi_broj = novi_broj * 10;     /*pravimo mjesto za novi broj koji treba da upisemo*/
					broj = broj / 10;       /*Uneseni broj dijelimo sa deset da bi se oslobodili cifre
					iz unesenog broja koju smo vec provjerili i da bi mogli da provjeravamo sljedecu cifru unesenog broja*/
				}
		}

	novi_broj=novi_broj/10;     /*rjesavanje nule u varijabli "novi broj"*/

	while(novi_broj>0)
		{
			broj=broj+(novi_broj%10);
			novi_broj=novi_broj/10;
			broj=broj*10;
		}
	broj=broj/10;

	printf("Nakon izbacivanja broj glasi %d.",broj);
	printf("\nBroj pomnozen sa dva glasi %d.",broj*2);



	return 0;
}
