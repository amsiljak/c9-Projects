#include <stdio.h>


// Radi kako treba na mojim primjerima, ja msm da je ovo do drugog autotesta
char *IzbaciTekst(char *str, const char *tekst, int cs) {
	
	char *s1=str, *s2=tekst;
	
	
	while(*s2 != '\0')
		s2++;
		
	int duzina = s2-tekst, brojac=0;
	s2 = tekst;
	if(duzina == 0)
		return str;
	
	if(cs)	
	while(*s1 != '\0') {
		
		char *pomjeraj=s1;
		
		if(*s1 == *s2) {
			char *pamti=s1;
			
			while(*s2 != '\0') {
				
				if(*s1 != *s2 || *s1 == '\0')
					break;
				s1++;
				s2++;
				brojac++;
					
			}
			
			if(duzina == brojac) {
				//Ovo dole je sablonsko izbacivanje iz stringa ili niza
				// Znam donekle kako radi ali nisam milijardu posto siguran
				// Znam da posto pamti pokazuje na dio stringa koji trebamo izbaciti
				// kada na to dodamo duzinu -1, dobijemo prvo slovo poslije dijela koji trebamo izbaciti
				while(*(pamti + duzina - 1) != '\0') {
					
					*pamti = *(pamti + duzina);
					pamti++;
					
				}
				
			}
			
			
		}
		
		s1 = pomjeraj;
		s2 = tekst;
		s1++;
		
		if(brojac == duzina)
			s1 = str;
		brojac = 0;	
	}
	if(cs)
		return str;
		
		while(*s1 != '\0') {
		
		char *pomjeraj=s1;
		
		char c1=*s1, c2=*s2;
		
		if(c1 >= 'A' && c1 <= 'Z') c1 += 32;
		if(c2 >= 'A' && c2 <= 'Z') c2 += 32;
		
		if(c1 == c2) {
			char *pamti=s1;
			
			while(*s2 != '\0') {
				
				c1 = *s1;
				c2 = *s2;
				
				if(c1 >= 'A' && c1 <= 'Z') c1 += 32;
				if(c2 >= 'A' && c2 <= 'Z') c2 += 32;
				
				if(c1 != c2 || c1 == '\0')
					break;
				s1++;
				s2++;
				brojac++;
					
			}
			
			if(duzina == brojac) {
				//Ovo dole je sablonsko izbacivanje iz stringa ili niza
				// Znam donekle kako radi ali nisam milijardu posto siguran
				// Znam da posto pamti pokazuje na dio stringa koji trebamo izbaciti
				// kada na to dodamo duzinu -1, dobijemo prvo slovo poslije dijela koji trebamo izbaciti
				while(*(pamti + duzina - 1) != '\0') {
					
					*pamti = *(pamti + duzina);
					pamti++;
					
				}
				
			}
			
			
		}
		
		s1 = pomjeraj;
		s2 = tekst;
		s1++;
		
		if(brojac == duzina)
			s1 = str;
		brojac = 0;	
	}
	return str;
	
}

int main() {
	printf("ZSR 10, Zadatak 3\n");
	char niz[] = "test a B cje a b covoA B C onako provjeravam";
printf("'%s'", IzbaciTekst(niz, "A b C", 0));
	return 0;
}
