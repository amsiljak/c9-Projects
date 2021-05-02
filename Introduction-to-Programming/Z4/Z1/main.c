#include <stdio.h>

int provjeri_zagrade(char* s) {
	while(*s!='\0') {
		
	// Prolazi se kroz string sve dok se ne naidje na otvorenu zagradu
		if(*s=='[' || *s=='(' || *s=='{') {
			
			if(*s=='(') { // uslov za male zagrade
				s++;
				while(*s!='\0' && *s!=']' && *s!=')' && *s!='}' && *s!='[' && *s!='(' && *s!='{') s++;
				if(*s!=')') 
					return 0;
			}
			
			else if(*s=='[') { // uslov za srednje zagrade
				s++;
				while(*s!='\0' && *s!=']' && *s!=')' && *s!='}' && *s!='[' && *s!='(' && *s!='{') s++;
				while(1) {
					if(*s=='(') { // provjera malih zagrada unutar srednjih
						s++;
						while(*s!='\0' && *s!=']' && *s!=')' && *s!='}' && *s!='[' && *s!='(' && *s!='{') s++;
						if(*s!=')') 
							return 0;
						s++;
						while(*s!='\0' && *s!=']' && *s!=')' && *s!='}' && *s!='[' && *s!='(' && *s!='{') s++;
					}
					else if(*s==']') {
						s++;
						break;
					}
					else if(*s=='\0' || *s=='}' || *s=='{' || *s=='[' || *s==')') 
						return 0;
				}
			}
			
			else if(*s=='{') { // Uslov za velike zagrade
				s++;
				while(*s!='\0' && *s!=']' && *s!=')' && *s!='}' && *s!='[' && *s!='(' && *s!='{') s++;
				if(*s=='\0' || *s=='{' || *s==']' || *s==')') 
					return 0;
				
				while(1) {
				
					if(*s=='(') { // provjera malih zagrada unutar velikih
						s++;
						while(*s!='\0' && *s!=']' && *s!=')' && *s!='}' && *s!='[' && *s!='(' && *s!='{') s++;
						if(*s!=')') 
							return 0;
						s++;
						while(*s!='\0' && *s!=']' && *s!=')' && *s!='}' && *s!='[' && *s!='(' && *s!='{') s++;
					}
					
					else if(*s=='[') { // provjera srednjih unutar velikih
						s++;
						while(*s!='\0' && *s!=']' && *s!=')' && *s!='}' && *s!='[' && *s!='(' && *s!='{') s++;
						while(1) {
							if(*s=='(') { // provjera malih zagrada unutar srednjih
								s++;
								while(*s!='\0' && *s!=']' && *s!=')' && *s!='}' && *s!='[' && *s!='(' && *s!='{') s++;
								if(*s!=')') 
									return 0;
								s++;
								while(*s!='\0' && *s!=']' && *s!=')' && *s!='}' && *s!='[' && *s!='(' && *s!='{') s++;
							}
							else if(*s==']') {
								s++;
								break;
							}
							else if(*s=='\0' || *s=='}' || *s=='{' || *s=='[' || *s==')') 
								return 0;
						}
					}
					else if(*s=='}') {
						s++;
						break;
					}
					else if(*s=='\0' || *s=='{' || *s==']' || *s==')') 
						return 0;
				}
			}
		}
		else if(*s==']' || *s==')' || *s=='}')
			return 0;
		s++;
	}
	// ako funkcija nije nasla nepravilnosti u izrazu vraca 1
	return 1;
}

int main() {
printf("%d ", provjeri_zagrade("{(A)}"));
printf("%d ", provjeri_zagrade("{[A]}"));
printf("%d ", provjeri_zagrade("{[A]}"));
printf("%d ", provjeri_zagrade("{(A)}"));
//printf("%d ", provjeri_zagrade("d&(*sa"));
	return 0;
}
