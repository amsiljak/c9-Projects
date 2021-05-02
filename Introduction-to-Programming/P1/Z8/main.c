#include <stdio.h>

/* pogresan pravougaonik */

int main() {
	int a, b, i, j, k;
	printf("Unesite stranice pravougaonika a,b: ");
	scanf("%d,%d", &a, &b);
	
	/* prva linija */
	printf("+");
	for(i=1; i<(a-1); i++) {
		printf("-"); 
	}
	printf("+\n");
	
	/* tijelo */
	for(k=1; k<(b-1); k++) {
	printf("|");
	for(j=1; j<(a-1); j++) {
		printf(" ");
	}
	printf("|");
	printf("\n");
}

    /* zadnja linija*/
    
    printf("+");
	for(i=1; i<(a-1); i++) {
		printf("-"); 
	}
	printf("+");
		return 0;
}