#include <stdio.h>

int main() {
	int n, i;
	printf("Unesite broj n: ");
	scanf("%d", &n);
	
	/*Obrnuta petlja*/
	
	for (i=n; i>0; i--) {
		if (i%5==0 || i%7==0 || i%11==0) {
			printf("%d \n", i);
			}
			
	}
	
	return 0;
}
