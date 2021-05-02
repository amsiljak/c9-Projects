#include <stdio.h>
#define kapacitet 1000

int main() {
	int indexi[kapacitet]={0};
	int predmeti[kapacitet]={0};
	int ocjena[kapacitet]={0};
	int br=0; 
	FILE *ulaz=fopen("ispiti.txt", "r");
	if(!ulaz) {
		printf("Greska pri otvaranju.\n");
		return 1;
	}
	while (br<kapacitet) {
		if(fscanf(ulaz, "%d %d %d\n", &indexi[br], &predmeti[br], &ocjena[br])!=3) break;
		br++;
	}
	fclose(ulaz); 


	int predmet=0, br_pol=0, ukupno=0, i=0;
	float prosjek=0, prolaznost;
	printf("Unesite predmet: ");
	scanf("%d", &predmet);
	for(i=0; i<br;i++) {
		if(predmeti[i]==predmet) {
			ukupno++;
			if(ocjena[i]>=6) br_pol++;
			prosjek+=ocjena[i];
		}
	}
	if(ukupno==0) {
		printf("Zalimo, ali ne postoje podaci o predmetu sa brojem %d!", predmet);
		return 0;
	}
	prosjek=prosjek/ukupno;
	prolaznost=br_pol*100./ukupno;
	printf("Prosjecna ocjena: %.2f", prosjek);
	printf("\nProlaznost: %g%%", prolaznost);
	return 0;
}
