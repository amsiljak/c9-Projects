#include <stdio.h>

int Prebroji(const char *str, const char *slova) {
	
	int brojac=0;
	
	char *restart = str;
	
	while(*slova != '\0') {
		
		while(*str != '\0') {
			
			if(*str == *slova + 32 || *str == *slova || *str == *slova - 32)
				brojac++;
				
			str++;	
			
		}
		str = restart;
		
		
		slova++;
	}
	
	
	return brojac;
}

int main() {
	printf("ZSR 9, Zadatak 8");
	return 0;
}
