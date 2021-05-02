#include <stdio.h>

void uvecajOsmi(int *niz, int vel) { 
 int i = 0; 
 while(i != vel) { 
  niz[8] += niz[i]; 
  i++; 
 	}	 
} 
int main() { 
 int niz[100]; 
 int n; 
int i = 0;
 printf("Unesite velicinu: "); 
 scanf("%d", &n); 
 if(n > 7 && n < 100) { 
  printf("Unesite clanove niza: "); 
  while(i<n) { 
   int x; 
   scanf("%d", &x); 
   niz[i] = x; 
   i++;
  } 
  uvecajOsmi(niz, n); 
 } 
 else 
     printf("Velicina mora biti između 7 i 100"); 
  
 	return 0; 
} 
