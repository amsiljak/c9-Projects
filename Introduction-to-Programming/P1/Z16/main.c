#include <stdio.h>

int main() {
	int n, i, j;
	printf("Unesi broj n: ");
	scanf("%d", &n);
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			if(i==0 || i==n-1 || i==2 || j==n-1 && i>2 || j==0 && i<2) printf("*");
			else printf(" ");
		}printf ("\n");
	} 
	return 0;
}
