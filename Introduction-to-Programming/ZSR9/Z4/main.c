#include <stdio.h>

char *izbaci_viska_razmake(char *s){
	
	
	char *kraj=s, *restart=s, *pocetak=s;
	int brojac=0;
	while(*s != '\0') {
		
		if(*s == ' ') {
			
			if(brojac == 0) {
				kraj = s;
				pocetak = s;
				
				while(*kraj == ' ')
					kraj++;
					
				while(*pocetak++ = *kraj++);
				
			}
			else {
				kraj = s+1;
				pocetak = s+1;
					
					
				while(*kraj == ' ')
					kraj++;
						
				
				while(*pocetak++ = *kraj++);
				
			}
			
			
		}
		
		if(*(kraj-1) == ' ')
			*(kraj-1) = '\0';
		
		
		s++;
		brojac++;
	}
	
	s = restart;
	
	while(*s != '\0') {
		
		if(*s == ' ' && *(s+1) == '\0') {
			*s = '\0';
			break;
		}
		s++;
	}
	return restart;
}

int main() {
	printf("ZSR 9, Zadatak 4\n");
	printf("%s", izbaci_viska_razmake("   volim"));
	return 0;
}
