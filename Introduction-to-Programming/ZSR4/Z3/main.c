#include <stdio.h>

int trazi_rijec(const char *s1, const char *s2) {
	const char* temp=s1;
	while(*s1!='\0') {
		const char* p=s1;
		const char* q=s2;
		while(*p++=*q++) {
			if(*q=='\0' && (s1=temp || (s1-1)==' ') && (*p=='\0' || *p==' ')) return 1;
		} 
		s1++;
	}
	return 0;
}

int prebrojavanje_rijeci(*s1) {
	int broj_rijeci=0, razmak=1;
	while(s1!='\0') {
		if(*s1=' ') {
			razmak=1;
		}
		else if(razmak=1) {
			razmak=0;
			broj_rijeci++;
			if(broj_rijeci=n) pocetak=s1;
			if(broj_rijeci=n+1) {
				while(pocetak++=s1++);
			}
		}
		s1++;		
	}
	return broj_rijeci;
}
int main() {
	printf("ZSR 4, Zadatak 3");
	return 0;
}
