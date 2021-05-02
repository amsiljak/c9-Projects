#include <stdio.h>
#include <string.h>

struct klub
{
	char naziv[20];
	int broj_igraca;
};

int f(struct klub* pok,int vel)
{
	int br=0;
	int i,j;
	for(i=0;i<vel;i++)
	{
		for(j=0;j<strlen(pok[i].naziv);j++)
		{
			if(pok[i].naziv[j]=='_' && pok[i].naziv[j+1]!='\0' && pok[i].naziv[j+1]!='_') 
			br+=pok[i].broj_igraca;
		}
	}
	return br;
}
int main()
{
	struct klub niz[2];
	strcpy(niz[0].naziv,"sa_razmakom");
	strcpy(niz[1].naziv,"bezrazmaka");
	niz[0].broj_igraca=20;
	niz[1].broj_igraca=2;
	printf("%d",f(niz,2));
	
	return 0;
}