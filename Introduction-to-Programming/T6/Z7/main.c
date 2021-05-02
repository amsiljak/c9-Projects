#include <stdio.h>

int main() {
	int i, j, max, min, mat[10][10], maxred, minred, temp;
	
	printf("Unesite elemente matrice: ");
	for(i=0;i<10;i++) {
		for(j=0;j<10;j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	 /*Utvrdjivanje max i min*/
	for(i=0;i<10;i++) {
		for(j=0;j<10;j++) {
			if(i==0 && j==0) {
				max=mat[i][j];
				min=mat[i][j];
				maxred=i;
				minred=i;
			}
			if(mat[i][j]>max) {
				max=mat[i][j];
				maxred=i;
			}
			if(mat[i][j]<min) {
				min=mat[i][j];
				minred=i;
			}
		}
	}
	
	if(maxred==minred) {
		printf("Najmanji i najveci element se nalaze u istom redu.");
		return 0;
	}
	
	/*zamjena*/
	for(j=0;j<10;j++) {
		temp=mat[maxred][j];
		mat[maxred][j]=mat[minred][j];
		mat[minred][j]=temp;
	}
	
			
	printf("Nakon zamjene matrica glasi: \n");
	for(i=0; i<10;i++) {
		for(j=0;j<10;j++) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
			
			
			
			
			
return 0;
}
