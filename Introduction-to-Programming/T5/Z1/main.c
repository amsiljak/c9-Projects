#include <stdio.h>
#define BROJ_EL 10

int main() {
	int niz[BROJ_EL], suma, i;
	float prosjek;
	
	for(i=0; i<BROJ_EL; i++) {
		printf("Unesite %d. cijeli broj: ", i+1);
		scanf("%d", &niz[i]);
	}
	
	suma=0;
	for(i=0; i<BROJ_EL; i++) 
	suma=suma+niz[i];
	prosjek=(float)suma/BROJ_EL;
	printf("Srednja vrijednost unesenih brojeva je %.2f.\n", prosjek);
	return 0;
}
