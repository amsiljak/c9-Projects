#include <stdio.h>

int faktorijel(int n) { 
	if(n==1) return 1;
	return n*faktorijel(n-1);
}
int main() {
	int n,i;
	float x,suma;
	printf("Unesite broj n u intervalu [1, 12]: ");
	scanf("%d", &n);
	printf("Unesite realan broj x: ");
	scanf("%f", &x);
	for(i=1;i<n;i++) {
		suma+=x/faktorijel(i);
	}
	printf("Suma od 1 do %d za x = %.3f je %.3f", n,x,suma);
	return 0;
}
