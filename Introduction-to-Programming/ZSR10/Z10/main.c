#include <stdio.h>

char* prebroji (char* tekst, char* slova) {
	char* s= tekst;
	int i,min,j,temp;
	int brojaci[26]={0};
	while(*s!='\0') {
		if(*s>='a' && *s<='z') brojaci[*s-'a']++;
		if(*s>='A' && *s<='Z') brojaci[*s-'A']++;
		s++;
	}
	for (i=0; i<26; i++) {
		min=-1;
		for (j=i+1; j<26; j++) {
			if (brojaci[i] > 0 && (min == -1 || brojaci[i] < brojaci[min])) {
			min = i;
			}
		}
		temp = brojaci[i];
		brojaci[i] = brojaci[min];
		brojaci[min] = temp;
	}
	for(i=0;i<26;i++) {
		if(brojaci[i]!=0) {
			*slova=brojaci[i];
			s++;
		}
	}
	*slova='\0';
	return
}
int main() {
	printf("ZSR 10, Zadatak 10");
	return 0;
}
