#include <stdio.h>

//Danas   je   divan     dan    
const char* posljednja_rijec ( char *s) {
	char c;
	char* pok=s;
	char* tmp=s;
	
	while(*s!='\0') {
		s++;
	}	
	s--;
	c=*s;
	
	if(*s==' ') {
		while(*s==' ') s--;
		s++;
		c=*s;
		printf("'%c'",c); //do ovdje dobro
		*s='\0';
		s--;
		c=*s;
		printf("'%c'",c);
	}
	while(*s!=' ' && s!=pok) s--;
		
	if(*s==' ') s++;
	return s;
}

int main() {
	printf ("Posljednja rijec: '%s'",
posljednja_rijec("Danas    je   divan   dan!     "));
	return 0;
}
