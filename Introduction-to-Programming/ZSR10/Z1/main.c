#include <stdio.h>

int PronadjiPosljednji(const char* str, const char* trazi) {
	
	int index=-1;
	char *s1=str, *s2=trazi;
	
	
	
	
	while(*s1 != '\0') {
	
		char *pomjeraj=s1;
		
		if(*s1 == *s2) {
			
			while(*s2 != '\0') {
				
				if(*s1 != *s2 || *s1 == '\0')
					break;
				s1++;
				s2++;
				
			}
			
			
		}
		
		if(*s2 == '\0') index = pomjeraj - str;
		
		if(*s1 == '\0')
			return index;		
		
		s1 = pomjeraj;
		s2 = trazi;
		s1++;
	}
	
	return index;
}

int main() {
	printf("ZSR 10, Zadatak 1");
	return 0;
}
