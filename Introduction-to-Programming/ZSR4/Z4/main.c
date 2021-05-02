#include <stdio.h>
//ispitni 2.
int main() {
	int i,br=0,niz[100]={2,2,2,3,2,3,2,2},N=8,j,L;
	for(i=1;i<N;i++) {
		if(niz[i]<niz[i-1]) {
			br++;
			for(j=i;j<N-1;j++){
				if(niz[j]<niz[j+1]) break;
				else i++;
			}
		}
	}
	printf("Ima %d", br);
	return 0;
}
