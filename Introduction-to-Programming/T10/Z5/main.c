#include <stdio.h>

char *ukloni_komentare(char *s) {
	
	char *restart=s, *pok=s, *p=s;
	
	int tacno, duzina=0;
	while(*s != '\0') {
		tacno = 1;
		if(*s == '/' && *(s+1) == '*') {
			pok = s;
			p = s+2;
			while(*(p+1) != '/' && *p != '*' && *p != '\0') {
				p++;
				duzina++;
			}
			if(*p == '\0') {
				
				s += duzina;
				continue;
					
			}	
			p = p+2;
			duzina += 4;
			while(s < p && *p != '\0') {
				*s = *p;
				s++;
				p++;
			}
			tacno = 0;
		}
		if(!tacno) {
			*(p-duzina) = '\0';
			p = pok;
			s = pok;
			duzina = 0;
		}
		
		
		s++;
	}
	s = restart;
	duzina = 0;
	while(*s != '\0') {
		tacno = 1;
		if(*s == '/' && *(s+1) == '/') {
			pok = s;
			p = s+2;
			while(*p != '\n' && *p != '\0') {
				p++;
				duzina++;
			}
				
			duzina += 2;
			
			while(s < p && *p != '\0') {
				*s = *p;
				s++;
				p++;
			}
			tacno = 0;
		}
		if(!tacno) {
			*(p-duzina) = '\0';
			p = pok;
			s = pok;
			duzina = 0;
		}
		
		s++;
	}
	return restart;
}

int main() {
	//printf("Tutorijal 10, Zadatak 5");
	char s[] = {"   abc //testiramo komentare u C++ stilu\n   def//drugi komentar"};
	ukloni_komentare(&s);
	printf("%s", s);
	return 0;
}
