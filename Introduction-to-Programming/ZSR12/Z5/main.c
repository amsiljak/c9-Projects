#include <stdio.h>

int analiza() {
	int niz[100000];
	int br_procitanih,i,max,br_pojavljivanja=0;
	int brojaci[65536]={0};
	FILE* ulaz=fopen("brojevi.dat", "rb");
	if(!ulaz) {
		printf("Greska");
		return 1;
	}
	br_procitanih=fread(niz, 2, 100000, ulaz);
	for(i=0;i<br_procitanih;i++){
		brojaci[niz[i]]++;
	}
	max=0;
	for(i=0;i<=65535;i++) {
		if(brojaci[i]>brojaci[max]) max=i;
	}
	for(i=max;i<=65535;i++) {
		br_pojavljivanja+=brojaci[i];
	}
	return br_pojavljivanja;
}
int main() {
	
	printf("ZSR 12, Zadatak 5");
	return 0;
}
