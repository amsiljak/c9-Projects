#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
	char prezime[20];
	char ime[15];
	int broj_bodova1;
	int broj_bodova2;
};

/* komentar - ovaj zadatak je malo modifikovan obzirom da postavka, autotestovi i zadatak 2,3 i 4
nisu najbolje uskladjeni u trenutku izrade zadatka.
Dalje je dato objasnjenje kako je interpretiran zadatak te sta je uradjeno:
Koristili smo zadatak 2, u kojem smo citali ispit.txt datoteku, kao tekstualnu,
zatim smo sortirali studente po broju bodova i onda u datoteku usmeni.txt tako upisali studente koji
MOGU na usmeni (pri tome naravno studenti ostaju sortirani). Ovo je zadatak 2.
U ovom zadatku smo uradili istu stvar, s tim sto datoteka usmeni.txt vise nije tekstualna, vec binarna,
pa smo je kao takvu i zapisali. na kraju smo onda "zatvorili" ovu datoteku pa je ponovo otvorili
i procitali kao binarnu da bismo se zaista uvjerili da smo ispravno uradili. */

int main() {
	struct Student studenti[300], tmp;
	FILE *ulaz, *izlaz;
	int i,j,vel, max;
	
	/*otvaranje datoteka */
	if ( ( ulaz = fopen("ispit.txt", "r") )==NULL ){
		printf("Greska pri otvaranju datoteke ispit.txt");
		exit(1);
	}
	//izmjena - sad je datoteka binarna!
	if ( ( izlaz = fopen("usmeni.dat", "wb") )==NULL ){ //izmjena
		printf("Greska pri otvaranju datoteke usmeni.dat");
		exit(2);
	}
	
	// ovaj dio ostaje isti, ucitamo studente, pa sortiramo po broju bodova
	i=0;
	while ( fscanf(ulaz,"%20s%15s%2d %2d\n", studenti[i].prezime, studenti[i].ime,
	&studenti[i].broj_bodova1, &studenti[i].broj_bodova2) == 4 && i <100 ) i++;
	vel = i;
	
	for ( i=0; i<vel; i++){
		max = i;
		for(j=i+1; j<vel; j++){
			if ( (studenti[j].broj_bodova1 + studenti[j].broj_bodova2) > 
			(studenti[max].broj_bodova1  + studenti[max].broj_bodova2) ) //izmjena
				max=j;
		}
		tmp = studenti[i];
		studenti[i] = studenti[max];
		studenti[max] = tmp;
	}
	

	/*izmjena - treba u binarnu datoteku upisati studente koji mogu na usmeni
      stoga necemo pohraniti komplet niz, vec izdvojiti one studente koji mogu na
      usmeni u novi niz i takav niz pohraniti */
	
	struct Student idu_na_usmeni[300]; //novi niz
	int br_u=0; // br elem novog niza
	for ( i=0; i<vel; i++){
		if( (studenti[i].broj_bodova1 >=10) &&  (studenti[i].broj_bodova2 >=10) ){
			//studente ubacujemo u novi niz samo ako mogu na usmeni
			idu_na_usmeni[br_u] = studenti[i];
			br_u++;
		}
	}
	
	//zapis u binarnu datoteku
	int zapisano = fwrite(idu_na_usmeni, sizeof(struct Student), br_u, izlaz);
	if ( ferror(izlaz) ){
		printf("Greska prilikom pisanja datoteke.\n");
		printf("Zapisano je samo %d osoba\n", zapisano);
	}
	
	printf("Izlazna datoteka usmeni.dat je kreirana\n");
	fclose(ulaz);
	fclose(izlaz);
	
	//moj dodatak , nije trazeno zadatkom ali doprinosi razumijevanju
	//provjera da li smo ispravno upisali podatke u binarnu datoteku
	//ponovo otvaramo binarnu datoteku, ali sada za citanje
	FILE* provjera;
	if ( ( provjera = fopen("usmeni.dat", "rb") )==NULL ){
		printf("Greska pri otvaranju datoteke usmeni.dat");
		exit(1);
	}
	
	//ovaj niz nam ne treba ali hocemo da provjerimo ispravnost zapisa u datoteku
	struct Student spisak_studenata[300];
	int ucitano = fread(spisak_studenata, sizeof(struct Student), 300, provjera);
	printf("\n Ucitano je %d, a bilo je zapisano %d studenata koji mogu na usmeni", ucitano, zapisano);
	for(i=0; i<ucitano; i++){
			printf("\n%d. %s %s - %d, %d", i+1, spisak_studenata[i].ime, spisak_studenata[i].prezime,
					spisak_studenata[i].broj_bodova1, spisak_studenata[i].broj_bodova2);
	}
	return 0;
}
