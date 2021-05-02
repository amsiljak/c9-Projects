#include <stdio.h>
#include <stdlib.h>
//u stringu treba  da udvostruci svaku rijec
//pod rijec se misli na
//skup znakova odvojenih razmakom,\n,\t,tacka,zarez ili broj

void udvostruci(char* s) {
    char* pok1;
    char* pok2;
    char* pomocni;
    int br;
    //ja sa.m budala
    while(*s!='\0') {
        if(*s!=' ' && *s!='\n' && *s!='\t' && *s!='.' && *s!=',' && !(*s>='1' && *s<='9')) {
            pok1=s;
            while(*s!=' ' && *s!='\n' && *s!='\t' && *s!='.' && *s!=',' && !(*s>='1' && *s<='9') && *s!='\0') s++;
            pok2=s;
            br=pok2-pok1;
            pomocni=pok2;
            while(*pomocni!='\0') pomocni++;
            while(1) {
                *(pomocni+br)=*pomocni;
                if(pomocni==pok2) break;
                pomocni--;
           }
           //ja sam budala
           while(pok1!=pomocni) {
                *pok2=*pok1;
                pok1++; pok2++;
           }
           s=pok2;
           if(*s=='\0') return;
        }
        s++;
    }
}

int main()
{
    char s[100]="Ja    sa.m budala";
    udvostruci(s);
    printf("%s", s);
    return 0;
}
