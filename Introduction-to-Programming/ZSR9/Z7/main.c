#include <stdio.h>

int JeLiPalindrom(const char *s) {
	
	char s1[20], s2[20];
	char *pocetak=s;
	int i=0, j=0;
	
	while(*s != '\0') {
		
		if(*s >= 'A' && *s <= 'Z' || *s >= 'a' && *s <= 'z' || *s >= '0' && *s <= '9') {
			if(*s >= 'A' && *s <= 'Z') {
				s1[i] = *s + 32;
				i++;
			}
			
			else {
				s1[i] = *s;
				i++;
			}
			
		}	
		s++;
	}
	
	while(s >= pocetak) {
		
		if(*s >= 'A' && *s <= 'Z' || *s >= 'a' && *s <= 'z' || *s >= '0' && *s <= '9') {
			if(*s >= 'A' && *s <= 'Z') {
				s2[j] = *s + 32;
				j++;
			}
			
			else {
				s2[j] = *s;
				j++;
			}
			
		}
		s--;
		
		
	}
	
	if( i != j)
		return 0;
	else if(i == j && i == 0)
		return 0;
		
	else
		for(i=0;i<j;i++) {
			
			if(s1[i] != s2[i])
				return 0;
			
			
		}
	return 1;	
	
}

int main() {
	printf("ZSR 9, Zadatak 7");
	printf ("%d", JeLiPalindrom("2Kapak1"));
	return 0;
}

