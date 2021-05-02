#include <stdio.h>

int main() {
	int i, j, mat[10][10],min;
	
	for(i=0;i<10;i++) {
		for(j=0;j<10;j++) {
			scanf("%d", &mat[i][j]);
			if(i==j) {
				if(i==0) min=mat[i][j];
				if(mat[i][j]<min) min=mat[i][j];
			}
		}
	}
	
	printf("%d", min);
	

	return 0;
}
