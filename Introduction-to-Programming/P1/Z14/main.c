#include <stdio.h>

int main() {
	int i, suma=0;
	for(i=3;i<52;i++) {
		if(i%2==0) continue;
		suma+=i;
	} printf("Suma je: %d", suma);
	return 0;
}
