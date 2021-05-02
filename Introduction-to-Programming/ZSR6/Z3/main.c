#include <stdio.h>

int main() {
	int niz[2];
	int i=0;
	FILE* ulaz=fopen("Ime","r");
	while(i<2 && fscanf(ulaz, "%d", &niz[i] )==1) i++;
	printf("%d el",i);
	fclose(ulaz);
	return 0;
}
