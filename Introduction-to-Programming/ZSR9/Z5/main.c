#include <stdio.h>

void IspisiUnazad(const char *str) {
	
	char *pocetak=str;
	
	while(*str != '\0')
		str++;
		
	while(str >= pocetak) {
		
		printf("%c", *str);
		str--;
		
	}
		
	
}

int main() {
	printf("ZSR 9, Zadatak 5");
	return 0;
}
