#include <stdio.h>
#define SP1 90
#define SP2 120
#define DSP1 60
#define DSP2 80
#define P1 55
#define P2 100

int main() {
	float SP, DSP, P;
	printf("Dobrodosli kod Vaseg kucnog ljekara!\n");
	printf("Unesite sistolicki, dijastolicki pritisak i puls: ");
	scanf("%f%f%f", &SP, &DSP, &P);
	
	if (SP>=SP1 && SP<=SP2) {
		printf("SP: normalan\n");
	} else {
		printf("SP: nije normalan\n");
	}
	
	if (DSP>=DSP1 && DSP<=DSP2) {
		printf("DP: normalan\n");
	} else {
		printf("DP: nije normalan\n");
	}
	
	if (P>=P1 && P<=P2) {
		printf("Puls: normalan\n");
	} else {
		printf("Puls: nije normalan\n");
	}
	return 0;
}
