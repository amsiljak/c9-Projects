#include <stdio.h>

int PronadjiPosljednji(const char* str, const char* trazi) {
	
	int index=-1;
	char *s1=str, *s2=trazi;
	
	while(*s1 != '\0') {
	
		char *pomjeraj=s1;
		char c1=*s1, c2=*s2;
		
		// Mora se ovako mijenjati, mislim dodavati 32 
		// Zbog nekog razloga kada isto uradim u while petlji, samo preskoci if uslov, potpuno izadje iz while petlje
		// Pojma nemam zasto, ali sada znas kako treba
		if(c1 >= 'A' && c1 <= 'Z') c1 += 32;
				
		if(c2 >= 'A' && c2 <= 'Z') c2 += 32;
		
		if(c1 == c2) {
			
			while(*s2 != '\0') {
				c1 = *s1;
				c2 = *s2;
				
				if(c1 >= 'A' && c1 <= 'Z') c1 += 32;
				
				if(c2 >= 'A' && c2 <= 'Z') c2 += 32;
				
				if(c1 != c2 || c1 == '\0')
					break;
				s1++;
				s2++;
				
			}
			
			
		}
		
		 if(*s2 == '\0')
			index=pomjeraj-str;
 
    if(*s1=='\0')return index;
    s1=pomjeraj;
		s2 = trazi;
		s1++;
	}
	
	return index;
}

int main() {
	printf("ZSR 10, Zadatak 1\n");
	printf ("%d", PronadjiPosljednji("DAnAs jE dIvAn DAN!", "dan"));
	return 0;
}
