#include <stdio.h>

int main()
{
	int n, i;
	printf("Unesite broj: ");
	scanf("%d", &n);
	if(n<=0) {
		printf("Broj nije prirodan.");
		return 0;
	}

	if(n==1) {
		printf("Broj nije ni prost ni slozen.");
		return 0;
	}

	if(n==2) {
		printf("Broj nije slozen.");
		return 0;
	}
	
	for(i=2; i<n; i++) {
		if(n%i==0) {
			printf("Broj je slozen.");
			return 0;}
		}
		
	printf("Broj je prost.");
	


	return 0;
}
