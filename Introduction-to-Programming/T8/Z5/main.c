#include <stdio.h>
#include <math.h>

void zaokruzi(double* niz, int vel) {
	double *pok;
	for(pok=niz;pok<niz+vel;pok++) {
		(*pok)*=10;
		*pok=round(*pok)/10;
	}
}
int main() {
	return 0;
}

