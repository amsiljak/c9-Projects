#include <stdio.h>

struct Kurs {
	
	char valuta[5];
	float vrijednost;
	
};

int provjera (char niz[], char niz1[]) {
	
	while(*niz != '\0' && *niz1 != '\0') {
		
		if(*niz != *niz1)
			return 0;
		
		niz++;
		niz1++;
	}
	if(*niz != *niz1)
		return 0;
	
	return 1;
}

float razmjena(struct Kurs niz[], int vel, char s[], float broj) {
	
	float suma=0;
	int i;
	
	for(i=0;i<vel;i++) {
		
		if(provjera(niz[i].valuta, s)) {
			
			suma += niz[i].vrijednost * broj;
			
		}
		
	}
	
	return suma;
}

int main() {
	printf("ZSR 11, Zadatak 3");
	return 0;
}

