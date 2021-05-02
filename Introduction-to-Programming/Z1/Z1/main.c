#include <stdio.h>

int main()
{
	char padavineS, padavineB, padavineM;
	int temperaturaS, temperaturaB, temperaturaM;



	/* Sarajevo */

	/* Ulaz */

	printf("Unesite prognozu za Sarajevo:");
	printf("\nTemperatura: ");
	scanf("%d", &temperaturaS);


	do {
		printf("Padavine (D/N): ");
		scanf(" %c", &padavineS);
		if(padavineS!='d' && padavineS!='n' && padavineS!='D' && padavineS!='N') {
			printf("Pogresan unos. ");
			printf("\n");
		}
	} while (padavineS!='d' && padavineS!='n' && padavineS!='D' && padavineS!='N');



	/* Tuzla */

	/* Ulaz */

	printf("Unesite prognozu za Mostar:");
	printf("\nTemperatura: ");
	scanf("%d", &temperaturaM);


	do {
		printf("Padavine (D/N): ");
		scanf(" %c", &padavineM);
		if(padavineM!='d' && padavineM!='n' && padavineM!='D' && padavineM!='N') {
			printf("\nPogresan unos. ");
			printf("\n");

		}
	} while (padavineM!='d' && padavineM!='n' && padavineM!='D' && padavineM!='N');



	/* Bihac */

	/* Ulaz */

	printf("Unesite prognozu za Bihac:");
	printf("\nTemperatura: ");
	scanf("%d", &temperaturaB);


	do {
		printf("Padavine (D/N): ");
		scanf(" %c", &padavineB);
		if(padavineB!='d' && padavineB!='n' && padavineB!='D' && padavineB!='N') {
			printf("\nPogresan unos. ");
			printf("\n");

		}
	} while (padavineB!='d' && padavineB!='n' && padavineB!='D' && padavineB!='N');



	/* Nakon ulaza */

	if (padavineS=='n' || padavineS=='N') {
		if((temperaturaS<5 && temperaturaS>=-5) ||(temperaturaS<=30 && temperaturaS>20)) {
			printf("Drugarice idu u Sarajevo.");
			return 0;
		}
	}

	if (padavineM=='n' || padavineM=='N') {
		if((temperaturaM<5 && temperaturaM>=-5) ||(temperaturaM<=30 && temperaturaM>20)) {
			printf("Drugarice idu u Mostar.");
			return 0;
		}
	}

	if (padavineB=='n' || padavineB=='N') {
		if((temperaturaB<5 && temperaturaB>=-5) ||(temperaturaB<=30 && temperaturaB>20)) {
			printf("Drugarice idu u Bihac.");
			return 0;
		}
	}

	if (padavineS=='n' || padavineS=='N') {
		if(temperaturaS>=-5 && temperaturaS<=30) {
			printf("Anja i Elma mogu u Sarajevo.");
			return 0;
		} else if(temperaturaS<5 || temperaturaS>20) {
			printf("Anja i Una mogu u Sarajevo.");
			return 0;
		}
	} else if (padavineS=='d' || padavineS=='D') {
		if(temperaturaS>=-5 && temperaturaS<=0) {
			printf("Anja i Elma mogu u Sarajevo.");
			return 0;
		}
	}





	if (padavineM=='n' || padavineM=='N') {
		if(temperaturaM>=-5 && temperaturaM<=30) {
			printf("Anja i Elma mogu u Mostar.");
			return 0;
		} else if(temperaturaM<5 || temperaturaM>20) {
			printf("Anja i Una mogu u Mostar.");
			return 0;
		}
	} else if (padavineM=='d' || padavineM=='D') {
		if(temperaturaM>=-5 && temperaturaM<=0) {
			printf("Anja i Elma mogu u Mostar.");
			return 0;
		}
	}



	if (padavineB=='n' || padavineB=='N') {
		if(temperaturaS>=-5 && temperaturaS<=30) {
			printf("Anja i Elma  mogu u Bihac.");
			return 0;
		} else if(temperaturaB<5 || temperaturaB>20) {
			printf("Anja i Una mogu u Bihac.");
			return 0;
		}

	} else if (padavineB=='d' || padavineB=='D') {
		if(temperaturaB>=-5 && temperaturaB<=0) {
			printf("Anja i Elma mogu u Bihac.");
			return 0;
		}
	}

	printf("Ne odgovara niti jedan grad.");





	return 0;
}
