#include <stdio.h>

int main() {
	int a, b, c, d, e, z;
	float p;
	
	printf("Unesite 5. ocjena: ");
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
	
	z=a+b+c+d+e;
	p=z/5.;
	
	printf("Zbir unesenih ocjena je %d, a prosjek je: %.2f", z, p);
	
	
	return 0;
}
