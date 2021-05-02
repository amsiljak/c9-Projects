#include <stdio.h>

void zamijeni(int *a, int *b){
	int pom;
	pom = *b;
	*b = *a;
	*a = pom;
}

int main() {
	int x,y;
	printf("Unesi 2 broja: ");
	scanf("%d %d", &x, &y);
	printf("Nakon zamjene glase: ");
	zamijeni(&x,&y);
	printf("%d %d", x,y);
	return 0;
}
