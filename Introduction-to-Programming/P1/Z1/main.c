#include <stdio.h>

int main() {
			
	/* Izlaz */

	if (padavine=='d' || padavine=='D') {
		printf("Ne odgovara niti jedan grad.");
		
	} else if (padavine=='n' || padavine=='N') {
		if (temperatura>-5 && temperatura<30) {
			printf("Elma i Anja mogu u Sarajevo.");
		}
		else if (temperatura<5) {
			printf("Anja i Una mogu u Sarajevo");
		}
		else if (temperatura>20) {
			printf("Anja i Una mogu u Sarajevo");
		}
		else if (temperatura>-5 && temperatura<5) {
			printf("Drugarice idu u Sarajevo");
		}
	}

	return 0;
}
