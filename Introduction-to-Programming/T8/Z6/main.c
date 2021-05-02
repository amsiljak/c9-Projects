#include <stdio.h>

void sortiraj(double *niz, int vel){
	double *pok1;
	double *pok2;
	double temp;
	double *min;
	for(pok1=niz;pok1<niz+vel;pok1++) {
		min=pok1;
		for(pok2=pok1;pok2<niz+vel;pok2++) {
			if(*pok2<*min) {
				min=pok2;
			}
		}
		temp=*pok1;
		*pok1=*min;
		*min=temp;
	}
}

int main() {
	int i,vel=0;
	double niz[100];
	printf("Unesi elemente niza: ");
	do{
		scanf("%f", &niz[vel]);
	}while(niz[vel++] + 1 > 0);
	vel--;
	sortiraj(niz, vel);
	printf("Sortirani niz glasi: ");
	for(i=0; i<vel; i++){
		printf("%f ", niz[i]);
	}
	return 0;
}
