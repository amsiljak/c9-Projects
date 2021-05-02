#include <stdio.h>
#define BROJ_EL 10

int main() {
	int niz[BROJ_EL], suma=0, i, suma1=0, br1=0, min, max;
	float prosjek, prosjek1=0;
	
	for(i=0; i<BROJ_EL; i++) {
		printf("Unesite %d. cijeli broj: ", i+1);
		scanf("%d", &niz[i]);
		if(i==0) {
			min=niz[i];
			max=niz[i];
		}
		if (niz[i]<min) min=niz[i];
		if (niz[i]>max) max=niz[i];
		
		suma=suma+niz[i];
		if(niz[i]%2==0) {
			suma1=suma1+niz[i];
			br1++;
		}
		
	}
	
	
	prosjek=(float)suma/BROJ_EL;
	if (br1!=0)	prosjek1=(float)suma1/br1;
	printf("Srednja vrijednost unesenih brojeva je %.2f.\n", prosjek);
	printf("Srednja vrijednost parnih brojeva je %.2f.\n", prosjek1);
	printf("Najveci element je %d a najmanji %d.\n", max, min);

	return 0;
}
