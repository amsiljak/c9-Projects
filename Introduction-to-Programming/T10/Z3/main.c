#include <stdio.h>

char* izbaci_rijec(char* s, int n) {
	char* poc=s;
	char* pocetak;
	int nije_slovo=1;
	int broj_rijeci=0;
	while (*s!='\0') {
		if(!((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))) nije_slovo=1;
		else if(nije_slovo==1) {
			broj_rijeci++;
			nije_slovo=0;
			if(broj_rijeci==n) {
				pocetak=s;
				while((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) s++;
				while(*pocetak++=*s++);
				return poc;
			}
		}
		s++;
	}
	return poc;
}

int main() {
	printf("Tutorijal 10, Zadatak 3");
	return 0;
}
