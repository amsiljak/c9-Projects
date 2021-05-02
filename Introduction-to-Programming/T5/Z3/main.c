#include <stdio.h>

int main() {
	int i;
	float A[5], B[5], C[5];
	printf("Unesite clanove niza A: ");
	for (i=0; i<5; i++) {
		scanf("%f", &A[i]);
	}
	printf("Unesite clanove niza B: ");
	for(i=0; i<5; i++) {
		scanf("%f", &B[i]);
		C[i]=2*A[i]+B[i];
		}
	printf("Niz A glasi: ");
	for(i=0; i<5; i++) {
		if(i!=4) {
		printf("%.2f, ", A[i]);
	} else {
		printf("%.2f", A[i]);
	}
	}
	printf("\nNiz B glasi: ");
	for(i=0; i<5; i++) {
		if(i!=4) {
		printf("%.2f, ", B[i]);
	} else {
		printf("%.2f", B[i]);
	}
	}
	printf("\nNiz C glasi: ");
	for(i=0; i<5; i++) {
		if(i!=4) {
		printf("%.2f, ", C[i]);
	} else {
		printf("%.2f", C[i]);
	}
	}
	return 0;
}

