#include <stdio.h>

int main() {
	int i, niz[10], min;
	min=niz[0];
	for(i=0; i<10; i++) {
		printf("Unesi %d-i clan niza: ", i+1);
		scanf("%d", &niz[i]);
		if(niz[i]%2==0) {
			if(niz[i]<min) min=niz[i];
		}
	}
	printf("Minimum je %d", min);
	return 0;
}
