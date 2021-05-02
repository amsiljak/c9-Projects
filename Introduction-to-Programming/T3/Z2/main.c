#include <stdio.h>

int main() {
	int broj, suma;
	for(suma=0; suma<=100; suma=suma+broj) {
		printf("Unesite broj: ");
		scanf("%d", &broj);
	}
	printf("Suma je: %d", suma);
	return 0;
}
