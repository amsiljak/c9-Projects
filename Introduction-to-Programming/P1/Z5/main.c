#include <stdio.h>

int main() {
    int a;
    char z;
    
	printf("Unesite znak kojim ce broj biti okruzen: ");
	scanf("%c", &z);
	printf("Unesite prirodan broj u intervalu [0, 9]: ");
	scanf("%d", &a);

	
	
	printf("%c%c%c%c%c\n", z, z, z, z, z);
	printf("%c%c%c%c%c\n", z, z, z, z, z);
	printf("%c %d %c\n", z, a, z);
	printf("%c%c%c%c%c\n", z, z, z, z, z);
	printf("%c%c%c%c%c\n", z, z, z, z, z);
	
	
	return 0;
}
