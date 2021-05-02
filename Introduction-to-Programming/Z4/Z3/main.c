#include <stdio.h>
#include <math.h>

char* dvostruko(char* s) {
	int m, temp;
	int k=0, br1=0, br2=0;
	char* p;
	char* t=s;
	while(*s!='\0') {
		if(*s>='1' && *s<='9') {
			m=*s;
			*s=m*2;
		}
		s++;
	}
	return t;
}

int main() {
	char tekst[100] = "U ovoj recenici se nalazi broj 4.";
	printf("'%s'", dvostruko(tekst));

	return 0;
}
