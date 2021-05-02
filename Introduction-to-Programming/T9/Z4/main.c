#include <stdio.h>

char max_slovo(char* s) {
    int niz[26]={0}, i, max=0;
    
    while(*s!='\0') {
        if(*s>='a' && *s<='z') niz[*s-'a']++;
        else if(*s>='A' && *s<='Z') niz[*s-'A']++;
        s++;
    }
    
    for(i=0; i<26; i++) {
        if (niz[i]>niz[max]) max=i;
    }
    return max+'A';
}
	
int main () {
	return 0;
}
