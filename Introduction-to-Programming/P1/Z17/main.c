#include <stdio.h>

int main()
{
	int n, i, j;
	printf("Unesi n: ");
	scanf("%d", &n);
	for(i=0; i<n; i++) {
		for(j=0; j<2*n; j++) {
			if (i==0) {
				if(j==0 || j==2*n-2 || j==n-1) printf("+");
				else printf("-");
			}
		}
			if((j==0 && i>0 && i<n-1) || (j==n-1 && i>0 && i<n-1) || (j==2*n-2 && i>0 && i<n-1)) {
				printf("-");
			}


		}
		printf("\n");
	}
	return 0;
}
