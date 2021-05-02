#include <stdio.h>

void unesi(char niz[], int velicina) {
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}


char* kapitaliziraj(char* s) {
    char* poc=s;
    while(*s!='\0') {
        if(s==poc || *(s-1)==' ') {
            if(*s>='a' && *s<='z') {
                *s=*s-'a'+'A';   
            }
        }
        s++;
    }
    return poc;
}
int main() {
    char s[100];
    printf("Unesite neki tekst: ");
    unesi(s,100);
    printf("%s", kapitaliziraj(s));
	return 0;
}
