#include <stdio.h>

int strcmpi(const char* s1, const char* s2, int velikamala)
{
	while(*s1!='\0' && *s2!='\0')
		if((velikamala && *s1<*s2)|| (!velikamala && *s1<*s2 && *s1!=*s2-32))
			return -1;
		else if((velikamala && *s1>*s2) || (!velikamala && *s1>*s2 && *s1!=*s2+32))
			return 1;
		else {
			s1++;
			s2++;
		}
		
		
	if(*s1!='\0') return 1;
	if(*s2!='\0') return -1;
	else return 0;
}
int main()
{
	return 0;
}
