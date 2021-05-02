#include <stdio.h>

// Autotest 3, kako moze tacka da bude rijec
// Mislim da i on nevalja
void NtaRijec(const char *str, char *rijec, int n) {

	char *s1=str;
	int razmak=1, broj_rijeci=0;
	
	while(*s1 != '\0') {
		
		if(*s1 >= '\0' && *s1 < 'A' || *s1 > 'Z' && *s1 < 'a' || *s1 > 'z')
			razmak = 1;
		else if(razmak) {
			
			razmak = 0;
			broj_rijeci++;
			
			
		}	
		
		if(broj_rijeci == n && razmak == 0) {
			
			while(*s1 != '\0' && *s1 != ' ' && (*s1 >= 'A' && *s1 <= 'Z' || *s1 >= 'a' && *s1 <= 'z')) {
				
				*rijec = *s1;
				rijec++;
				s1++;
				
			}
			s1--;
			
			
		}
		s1++;
	}
	*rijec = '\0';
	
}

int main() {
	printf("ZSR 10, Zadatak 5\n");
	
	const char *tekst = "neka proba";
char rijec[101];
NtaRijec(tekst, rijec, 1); 
printf ("1. rijec: '%s'", rijec);
	return 0;
}
