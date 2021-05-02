#include <stdio.h>

int main() {
	int i, x, niz[101]={0};
	
	printf("Unesite brojeve: ");
	while(1){
		scanf("%d", &x);
		if(x==-1) break;
	    if(x<0 || x>100) {
	        printf("\nBrojevi moraju biti izmedju 0 i 100!");
	        continue;
	    }
	    niz[x]++;
    }
	
	for(i=0; i<101; i++) {
	    if(niz[i]==0) continue;
	    printf("\nBroj %d se javlja %d puta.", i, niz[i]);   
	}

	return 0;
}
