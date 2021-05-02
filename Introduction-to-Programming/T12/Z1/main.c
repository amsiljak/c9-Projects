#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *ulaz;
    char znak, ime[20];
    int broj_redova=0, broj_rijeci=0, broj_znakova=0, razmak=1;
    
    printf("Unesite ime datoteke: ");
    scanf("%s", ime);
    ulaz=fopen(ime, "r");
    if(ulaz==NULL) {
        printf("Pogreska kod otvaranja datoteke %s!\n\n", ime);
        return 1;
    }
    while((znak=fgetc(ulaz))!=EOF) {
        if(znak=='\n') ++broj_redova;
        if(znak==' ' || znak=='\n' || znak=='\t') razmak=1;
        else {
            ++broj_znakova;
            if(razmak==1) ++broj_rijeci;
            razmak=0;
        }
    }
    if(broj_znakova!=0) broj_redova++;
    printf ("Broj redova: %d\nBroj rijeci: %d\nBroj znakova: %d\n", 
broj_redova, broj_rijeci, broj_znakova);
	fclose (ulaz);
	return 0;
}
