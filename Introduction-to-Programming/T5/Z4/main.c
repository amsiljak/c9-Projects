#include <stdio.h>

int main() {
	int x, br5=0, br7=0, br11=0;
	
	printf("Unesite brojeve: ");
	do{
		scanf("%d", &x);
		if(x%5==0) br5++;
		if(x%7==0) br7++;
		if(x%11==0) br11++;
	} while(x!=-1);
	
	printf("\nDjeljivih sa 5: %d", br5);
	printf("\nDjeljivih sa 7: %d", br7);
	printf("\nDjeljivih sa 11: %d", br11);

	return 0;
}
