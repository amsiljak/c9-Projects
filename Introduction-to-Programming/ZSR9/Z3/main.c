#include <stdio.h>

void unesi(char niz[], int vel){
	
	char znak=getchar();
	if(znak == '\n') znak = getchar();
	
	int i=0;
	while(i < vel - 1 && znak != '\n') {
		
		niz[i] = znak;
		i++;
		znak = getchar();
		
	}
	niz[i] = '\0';
	
}

char *velika(char *s) {
	
	char *restart=s;
	
	while(*s != '\0') {
		
		if(*s >= 'a' && *s <= 'z')
			*s -= 32;
		
		s++;
	}
	
	return restart;
	
}

int main() {
	
	char s[100];
	printf("Unesite neki tekst: ");
		unesi(s, 100);
		
	printf("%s", velika(s));	
	return 0;
}
