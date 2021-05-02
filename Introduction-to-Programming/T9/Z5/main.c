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

int prva_rijec(char *s){
	char* pozicija;
	int broj=0;
	int triger=0;
	while(*s!='\0'){
		if(*s!=' ')	triger=1;
		if(*s==' ' || *(s+1)=='\0'){
			if (triger) broj++;
			if (broj==1) pozicija=s;
			triger=0;
		}
		s++;
	}
	if (broj!=1) *pozicija='\0';
	return broj;
}

int main() {
	char niz[80];
	printf("\nUnesi neki string: ");
	unesi(niz,80);
	printf("\nString ima ukupno %d rijeci, i  sada glasi: %s", prva_rijec(niz), niz);
	return 0;
}
