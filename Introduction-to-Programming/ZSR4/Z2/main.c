#include <stdio.h>
//niz sa ispita

int main() {
	int i, niz[100],n,br=1;
	printf("Unesite niz: ");
	for(i=0;i<100;i++) {
		scanf("%d", &niz[i]);
		if(niz[i]==-1) break;
	}
	n=i;
	for(i=1;i<n;i++) {
		if(niz[i]>niz[i-1]) br++;
	}
	printf("Ima %d opadajucih podnizova", br);
	return 0;
}
