#include <stdio.h>
#include <string.h>
#define kapacitet 1000
//brindexa predmet ocjena\n

void unesi(char niz[], int velicina) {
     char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}

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
	
	FILE *ulaz2=fopen("predmeti.txt", "r");
	if(!ulaz) {
		printf("Greska pri otvaranju.\n");
		return 2;
	}
	
	char imena_predmeta[kapacitet][100];
	int brojevi_predmeta[100]={-1};
	int br_p=0, i=0;
	
	while(fscanf(ulaz2, "%d ", &brojevi_predmeta[br_p])==1) {
		i=-1;
		do{
			if(i<100) i++;
			imena_predmeta[br_p][i]=fgetc(ulaz2);
		} while(imena_predmeta[br_p][i]!='\n' && imena_predmeta[br_p][i]!=EOF);
		imena_predmeta[br_p][i]='\0';
		br_p++;
	}
	fclose(ulaz2);
	
	char ime_pred[100];
	int predmet=-1;
	int comp=-5;
	
	while(1) {
		printf("Unesite predmet: ");
		unesi(ime_pred,100);
		for(i=0; i<br_p; i++) {
			comp=strcmp(ime_pred,imena_predmeta[i]);
			if(comp==0) {
				predmet=brojevi_predmeta[i];
				break;
			}
		}
		if(predmet>0) break;
		printf("Nepostojeci predmet!\n");
	}
	
	int br_pol=0, ukupno=0;
	float prosjek=0, prolaznost;
	for(i=0; i<br; i++) {
		if(predmeti[i]==predmet) {
			ukupno++;
			if(ocjena[i]>=6) br_pol++;
			prosjek+=ocjena[i];
		}
	}
	if(ukupno==0) {
		printf("Zalimo, ali ne postoje podaci o predmetu %s!", ime_pred);
		return 0;
	}
	prosjek=prosjek/ukupno;
	prolaznost=br_pol*100./ukupno;
	printf("Prosjecna ocjena: %.2f", prosjek);
	printf("\nProlaznost: %g%%", prolaznost);


	return 0;
}
