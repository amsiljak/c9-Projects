#include <stdio.h>
#include <math.h>

int UnesiRealan(const char *string, double *broj) {
	
	int predznak=1, i=-1, brojac=0;
	
	double tmp;
	
	char *restart=string;
	
	while(*string != '\0') {
		
		if(!(*string >= '0' && *string <= '9' || *string == '.'))
			return 0;
			
		if(*string == '.')
			brojac++;
			
		if(brojac > 1)
			return 0;
		string++;	
		
	}
		
	string = restart;	
	while(*string != '\0') {
		
		if(*string == '-') predznak = -1;
		
		else if(*string >= '0' && *string <= '9' || *string == '.') {
			
			tmp=0;
			while(*string >= '0' && *string <= '9' && *string != '\0' || *string == '.') {
				
				if(*string == '.') {
					string++;
				
				while(*string >= '0' && *string <= '9' && *string != '\0') {
					
					tmp += (*string - '0')*pow(10, i);
					
					string++;
					i--;
				}
				
				}
				else
				 tmp = tmp*10 + *string - '0';
					
				if(*string == '\0')
					break;
				string++;
				
				
			}
			
				
			}
		
	}
	if(predznak == -1)
		*broj = tmp*predznak;
	
	*broj = tmp;
	
	return 1;
}

int main() {
	double d;
	printf("ZSR 9, Zadatak 9\n");
	
	int a = UnesiRealan (".8", &d);
	printf("%d %g", a, d);
	return 0;
}
