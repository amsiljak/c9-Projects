#include <stdio.h>


char* rot13(char* s) {
	char* p=s;
	while(*s!='\0') {
		if(*s>='A' && *s<='M' || *s>='a' && *s<='m') {
			*s=*s+13;
		}
		else if(*s>='N' && *s<='Z' || *s>='n' && *s<='z') {
			*s=*s-13;
		}
		s++;
	}
	return p;
}

int main() {
	return 0;
}
