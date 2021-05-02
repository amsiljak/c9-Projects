#include <stdio.h>

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

struct Osoba {
	char ime[15];
	char prezime[20];
	int telefon;
};

struct Osoba unos_osobe(){
	struct Osoba x;
	printf("Unesite ime: ");
	unesi(x.ime, 15);
	printf("Unesite prezime: ");
	unesi(x.prezime, 20);
	printf("Unesite broj telefona: ");
	scanf("%d", &x.telefon);
	return x;
}

void ispis_osobe(struct Osoba x){
	printf("%s %s, Tel: %d", x.ime, x.prezime, x.telefon);
}

int main() {
	int meni,i,br_osoba=0;
	struct Osoba niz[100];
	while(1){
		printf("Pritisnite 1 za unos, 2 za ispis, 0 za izlaz: ");
		scanf("%d", &meni);
		if ( meni==0 ) break;
		if ( meni==1 ) {
			niz[br_osoba]=unos_osobe();
			br_osoba++;
		}
		if ( meni==2 ){
			for(i=0; i<br_osoba; i++){
				printf("\n%d. ", i+1);
				ispis_osobe(niz[i]);
				printf("\n");
			}
		}
	}
	return 0;
}
