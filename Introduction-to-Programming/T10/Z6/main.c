#include <stdio.h>

void unesi(char niz[], int velicina){
	char znak = getchar();
	if ( znak == '\n' ) znak=getchar();
	int i=0;
	while ( i < velicina -1 && znak!='\n' ){
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}

int prebroji(char* s){
	int brojac =0 ;
	while(*s!=' ' && *s!='\0'){
		s++; brojac++;
	}
	return brojac;
}


char* tritacke(char* s){
	int razmak = 1, br_slova;
	char* poc=s;
	char* pom=s;
	while( *s!='\0'){
		if (*s == ' '){
			razmak=1;
		}
		else if (razmak == 1 ){
			razmak=0;
			pom = s;
			br_slova = prebroji(s);
			if ( br_slova >= 10 ){
				pom = pom + 3;
				*pom='.';
				pom++;
				while( *(pom+br_slova-4) != '\0' ){
					*pom = *(pom+br_slova-4);
					pom++;
				}
				*pom = '\0';
			} 
		}
		s++;
	}
	return poc;
}


int main() {
	char str[100];
	unesi(str,100);
	tritacke(str);
	printf("%s", str);
	return 0;
}
