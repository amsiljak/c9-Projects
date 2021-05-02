#include <stdio.h>

int main() {
	int i, j;
	printf("  X |");
	for(i=0; i<10; i++) {
		printf("%4d", i+1);
		}
	printf("\n");
	printf("----+");
	for(i=0; i<10; i++)
	printf("----");
	 printf("\n");
	  
	  for(i=0; i<10; i++) {
	  	
	  printf("%3d |", i+1);
	   for(j=0; j<10; j++) {
	   	printf("%4d", (i+1)*(j+1));
	   }
	  
	 	printf("\n");
	 	

	 }
	return 0;
}