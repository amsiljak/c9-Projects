#include <stdio.h>

char* whitespace(char* s) {
	char *pok=s;
	char* poc;
	char* kraj;
	while(*s!='\0')
	{
		if(*s==' ' || *s=='\n' || *s=='\t')
		{
			poc=s;
			while((*s==' ' || *s=='\n' || *s=='\t')&& *s!='\0') s++;
			kraj=s;
			if(poc!=pok && *kraj!='\0') {*poc=' '; poc++; }
			s=poc;
			while(*poc++=*kraj++);
		}
		s++;
	}
	return pok;
}

int main() {
	printf("Tutorijal 10, Zadatak 4");
	return 0;
}
