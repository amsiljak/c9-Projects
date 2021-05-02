#include <stdio.h>

void ispisi_unazad (const char *str) {
	if(*str=='\0') return;
	else {ispisi_unazad(str+1); printf("%c",*str);}
}


int main() {const char *str = "Osnove racunarstva - OR";
ispisi_unazad(str);


	return 0;
}
