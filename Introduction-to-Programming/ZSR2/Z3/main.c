#include <stdio.h>

const char* posljednja_rijec (const char *s) {

	char* pok=s;
	while(*s!='\0') {
		
		s++;
	}	
	while(*s++);
	while(*s!=' ' && s!=pok) s--;
	if(*s==' ') s++;
	return s;
}

//Danas   je   divan     dan
int main() {
	printf ("Posljednja rijec: '%s'",
posljednja_rijec("Danas    je   divan   dan!"));

	return 0;
}
