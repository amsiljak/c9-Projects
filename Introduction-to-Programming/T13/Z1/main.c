#include <stdio.h>
#include <stdlib.h>

struct Student {
	char prezime[20];
	char ime[15];
	int broj_bodova;
};


int main() {
	struct Student studenti[300], tmp;
	FILE *ulaz, *izlaz;
	int i,j,vel, max;
	
	/*otvaranje datoteka */
	if ( ( ulaz = fopen("ispit.txt", "r") )==NULL ){
		printf("Greska pri otvaranju datoteke ispit.txt");
		exit(1);
	}
	if ( ( izlaz = fopen("ispit_sortiran.txt", "w") )==NULL ){
		printf("Greska pri otvaranju datoteke ispit_sortiran.txt");
		exit(2);
	}
	
	/*Ucitavanje datoteke u niz studenti */
	i=0;
	//greska u postavci, ne treba %2d% vec %2d
	while ( fscanf(ulaz,"%20s%15s%2d\n", studenti[i].prezime, studenti[i].ime,
	&studenti[i].broj_bodova) == 3 && i <100 ) i++;
	vel = i;
	// P za kolege - zasto & negdje idu, zasto ne
	
	//sortiranje niza po broju bodova
	// P za kolege - kako garantujemo da je na istom indeksu ime/prez/br_boba
	for ( i=0; i<vel; i++){
		max = i;
		for(j=i+1; j<vel; j++){
			if ( studenti[j].broj_bodova > studenti[max].broj_bodova ) //greska u postavci
				max=j;
		}
		tmp = studenti[i];
		studenti[i] = studenti[max];
		studenti[max] = tmp;
	}
	
	//pohrana u datoteku ispis_sortiran
	for ( i=0; i<vel; i++){
		fprintf(izlaz, "%-20s%-15s%2d\n", studenti[i].prezime, studenti[i].ime, studenti[i].broj_bodova);
	}
	printf("Izlazna datoteka ispit_sortiran.txt je kreirana\n");
	fclose(ulaz);
	fclose(izlaz);
	return 0;
}
