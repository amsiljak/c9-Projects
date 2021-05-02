#include <stdio.h>

int main() {
	int i,niz[100],brojac[101]={0},n,max,min;
	printf("Unesite niz: ");
	for(i=0;i<100;i++) {
		scanf("%d", &niz[i]);
		if(niz[i]==-1) break;
		if(niz[i]<0 || niz[i]>100) {
			printf("Neispravan unos!");
			i--;
	}
	n=i;
	for(i=0;i<n;i++) {
		brojac[niz[i]]++;
	}
	max=0;
	min=-1;
	for(i=0;i<=101;i++) {
		if(brojac[i]>brojac[max]) i=max;
		if(brojac[i]>0 && ((min==-1) || (brojac[min]>brojac[i])) min=i;
	}
	return 0;
}
