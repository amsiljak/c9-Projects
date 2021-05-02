#include <stdio.h>

int main() {
	int M,N,i,j,mat[100][100], kolona[100]={0},max;
	
	do{
		printf("Unesite M i N: ");
		scanf("%d %d", &M, &N);
		if((M<0 || M>100) || (N<0 || N>100)) printf("Pogresan unos!\n");
	} while ((M<0 || M>100) || (N<0 || N>100));
	
	printf("Unesite elemente matrice: ");
	for(i=0; i<M; i++) {
		for(j=0;j<N;j++) {
			scanf("%d", &mat[i][j]);
		}
	}

	for(j=0;j<N;j++){
		for(i=0;i<M;i++){
			kolona[j]+=mat[i][j];
		}
	}
	max=0;
	for(j=0;j<N;j++){
		if(kolona[j]>kolona[max]) max=j;
	}
	
	for(i=0;i<M;i++){
		mat[i][max]=mat[i][N-1];
	}
	N--;
	
	for(i=0; i<M; i++) {
		for(j=0;j<N;j++) {
			printf("%5d", mat[i][j]);
		}
		printf("\n");
	}

	return 0;
}
