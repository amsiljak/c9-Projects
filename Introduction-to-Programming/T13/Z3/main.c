#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//treba nam unesi za unos imena i prezimena
void unesi(char niz[], int velicina){
	char znak = getchar();
	if ( znak == '\n' ) znak=getchar();
	int i=0;
	while ( i < velicina -1 && znak!='\n' ){
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}

struct Student {
	char prezime[20];
	char ime[15];
	int broj_bodova1; //izmjena
	int broj_bodova2; //izmjena
};

//funkcija koja trazi unos studenata i vraca takvu strukturu
struct Student unos_studenta(){
	struct Student x;
	printf("Unesite ime: ");
	unesi(x.ime, 15);
	printf("Unesite prezime: ");
	unesi(x.prezime, 20);
	printf("Unesite broj bodova na I parcijalnom: ");
	scanf("%d", &x.broj_bodova1);
	printf("Unesite broj bodova na II parcijalnom: ");
	scanf("%d", &x.broj_bodova2);
	return x;
}


int main() {
	FILE *ulaz;
	int i, meni;
	struct Student pom_student;
	//napravimo meni, vise nam ne treba niz studenata, vec direktno vrsimo
	//manipulacije nad datotekom. citamo iz datoteke studenta po studenta
	//isto tako i pisemo studenta po studenta, kao pomocnu varijabli koristimo
	//pom_student
	while(1){
		printf("Unesite 1 za unos, 2 za ispis, 0 za izlaz: ");
		scanf("%d", &meni);
		switch (meni){
			case 0:
				return(0);
				break;
				
			case 1:
				pom_student=unos_studenta();
				if ( ( ulaz = fopen("ispit.txt", "a") )==NULL ){
					printf("Greska pri otvaranju datoteke ispit.txt");
					return(1);
				}
				fprintf(ulaz,"%-20s%-15s%2d %2d\n", pom_student.prezime, pom_student.ime,
				pom_student.broj_bodova1, pom_student.broj_bodova2);
				fclose(ulaz);
				break;
				
			case 2:
				if ( ( ulaz = fopen("ispit.txt", "r") )==NULL ){
					printf("Greska pri otvaranju datoteke ispit.txt");
					return(2);
				}
				i=1;
				while ( fscanf(ulaz,"%20s%15s%2d %2d\n", pom_student.prezime, pom_student.ime,
				&pom_student.broj_bodova1, &pom_student.broj_bodova2) == 4 ){
					printf("\n%d. %s %s - %d, %d\n", i, pom_student.ime, pom_student.prezime,
					pom_student.broj_bodova1, pom_student.broj_bodova2);
					i++;
				}
				fclose(ulaz);
		}
	}
	return 0;
}
