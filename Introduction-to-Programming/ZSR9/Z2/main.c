#include <stdio.h>

char *PosljednjaRijec(char *s) {
	
	char *kraj=s;
	
	int broj_rijeci=0, razmak=1;
	while(*s != '\0') {
		
		if(*s == ' ')
			razmak = 1;
			
		else if(razmak) {
			
			razmak = 0;
			broj_rijeci++;
			
		}
		s++;
	}
	int max = broj_rijeci;
	
	if(broj_rijeci == 0)
		return s;
	
	s = kraj;
	razmak = 1;
	broj_rijeci = 0;
	
	while(*s != '\0') {
		
		if(*s == ' ')
			razmak = 1;
			
		else if(razmak) {
			
			razmak = 0;
			broj_rijeci++;
			
			if(broj_rijeci == max) {
				
				while(*s != ' ' && *s != '\0')
					s++;
				*s = '\0';
				break;
			}
			
		}
		s++;
	}
	
	s = kraj;
	razmak = 1;
	broj_rijeci = 0;
	
	while(*s != '\0') {
		
		if(*s == ' ')
			razmak = 1;
			
		else if(razmak) {
			
			razmak = 0;
			broj_rijeci++;
			
			if(broj_rijeci == max)
				return s;
			
		}
		s++;
		
	}
}

int main() {
	printf("ZSR 9, Zadatak 1");
	
	printf("%s", PosljednjaRijec("troll"));
	return 0;
}