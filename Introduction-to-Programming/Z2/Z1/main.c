#include <stdio.h>

int main()
{
	int i, j, n;

	while (1) {
		printf("Unesite broj N: ");
		scanf("%d", &n);

		if (n%4==1) break;
		else printf("N nije ispravno!");
		printf("\n");
	}
	printf("\n");
	n+=2;

	for(i=0; i<n-2; i++) {
		for(j=0; j<n-2; j++) {
			if (i==0 || i==n-1 || j==n-1 || j==0 && i>1) printf("*");
			else printf(" ");
            if(n>1) n-=2;

		}
		printf("\n");
	}
		return 0;
	}
