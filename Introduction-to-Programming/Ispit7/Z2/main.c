#include <stdio.h>

char* pocetna_slova(char* s1,char* s2,int k) {
	int neslovo=0, brojac=0;
	char* pok;
	char* prvi=s1;
	char* drugi=s2;
	while(*s1!='\0') {
		if(s1==prvi) neslovo=1;
		
		if((*s1>='a' && *s1<='z') || (*s1>='A' && *s1<='Z')) {
			if(neslovo==1) {
				pok=s1;
				while(((*s1>='a' && *s1<='z') || (*s1>='A' && *s1<='Z')) && *s1!='\0') {
					s1++;
					brojac++;
				}
				s1--;
				if(brojac>k) {
					*s2=*pok;
					s2++;
				}
				neslovo=0;
			}
			brojac=0;
		}
		else neslovo=1;
		s1++;
		
	}
	*s2='\0';
	return drugi;
}
int main() {
	char buf[100];
pocetna_slova("Ovo je primjer neke recenice. Sada ide auto-stop.", buf, 3);
printf("'%s'", buf);
	return 0;
}
