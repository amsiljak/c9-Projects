#include <stdio.h>

int main() {
int i, j, n;
printf("Unesite dimenzije:");
scanf("%i", &n);
if(n<6)
{
printf("Dimenzija je premala.");
return 0;
}
for(i=0; i<n; i++)
{
for(j=0; j<n; j++)
{
if(j==0 || j==n-1 || (i==j && i>=n/2) || (j==n-1-
i && i>=n/2))
printf("*");
else printf(" ");
}
printf("\n");
}
	return 0;
}
