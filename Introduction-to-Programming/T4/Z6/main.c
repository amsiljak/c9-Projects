#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int a, x;
	printf("Izabrao sam broj. Probaj ga pogoditi (-1 za izlaz).\n");
	printf("\n");
	
	srand(time(0)); /* u zadaci koristi samo srand(0) */
	a=rand()%100+1;
	while (1) {
		printf("Unesite broj: ");
	    scanf("%d", &x);
		if(x==-1) {
			printf("Kraj igre.");
			break;
		} else if (x>a) {
			printf("MANJI\n");
		} else if(x==a) {
			break;
		} else if(x<a) {
		printf("VECI\n");
		}

	}


	return 0;
}
