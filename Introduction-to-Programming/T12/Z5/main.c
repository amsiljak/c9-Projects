#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void unesi(char niz[], int velicina)
{
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

int main()
{
	int opcija;
	do {
		FILE *ulaz, *predmeti;

		ulaz = fopen("ispiti.txt", "r");
		if (ulaz == NULL)
			exit (1);

		predmeti = fopen("predmeti.txt", "r");
		if (predmeti == NULL)
			exit (1);

		printf("Unesite 1 za statistiku studenta, 2 za statistiku predmeta, 0 za izlaz: ");
		scanf("%d", &opcija);

		if(opcija == 1) {
			int trazeniIndeks;

			printf("Unesite broj indexa: ");
			scanf("%d", &trazeniIndeks);

			int brIndeksa, indeksPredmeta, ocjena, brPredmeta = 0, prosao = 0;
			float prosjecnaOcjena = 0;
			while(fscanf(ulaz, "%d %d %d\n", &brIndeksa, &indeksPredmeta, &ocjena) == 3) {
				if(brIndeksa == trazeniIndeks) {
					brPredmeta++;
					if(ocjena > 5)
						prosao++;
					prosjecnaOcjena += ocjena;
				}
			}
			prosjecnaOcjena /= brPredmeta;

			if(brPredmeta == 0)
				printf("Zalimo, ali ne postoje podaci o studentu sa brojem indexa %d!", trazeniIndeks);
			else {
				printf("Student je slusao %d predmeta, a polozio %d (%d%%).", brPredmeta, prosao, (int)((float)prosao/brPredmeta * 100));

				printf("\nProsjecna ocjena polozenih predmeta je %.1f\n", prosjecnaOcjena);
			}
		} else if(opcija == 2) {
			int indeksTrazenogPredmeta = -1, indeksPredmeta = -1;
			char imeTrazenogPredmeta[30];
			do {
				printf("Unesite predmet: ");
				unesi(imeTrazenogPredmeta, 30);

				char imePredmeta[30];
				fseek(predmeti, 0, SEEK_SET);
				while(fscanf(predmeti, "%d %30[0-9a-zA-Z ]\n", &indeksPredmeta, imePredmeta) == 2)
					if(strcmp(imePredmeta, imeTrazenogPredmeta) == 0) {
						indeksTrazenogPredmeta = indeksPredmeta;
						break;
					}

				if(indeksTrazenogPredmeta == -1)
					printf("Nepostojeci predmet!\n");
			} while(indeksTrazenogPredmeta == -1);

			int brIndeksa, ocjena,
			    brojUnosa = 0, brojPolozenih = 0;
			float prosjecnaOcjena = 0;
			while(fscanf(ulaz, "%d %d %d\n", &brIndeksa, &indeksPredmeta, &ocjena) == 3) {
				if(indeksPredmeta == indeksTrazenogPredmeta) {
					++brojUnosa;
					if(ocjena > 5)
						++brojPolozenih;

					prosjecnaOcjena += ocjena;
				}
			}

			prosjecnaOcjena /= brojUnosa;

			if(brojUnosa == 0)
				printf("Zalimo, ali ne postoje podaci o predmetu %s!", imeTrazenogPredmeta);
			else
				printf("Prosjecna ocjena: %.2f\nProlaznost: %d%%", prosjecnaOcjena, (int)((float)brojPolozenih/brojUnosa * 100));

		}

		fclose(ulaz);
		fclose(predmeti);
	} while(opcija != 0);

	return 0;
}
