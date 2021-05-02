#include <stdio.h>

int main() {
	int iznos, ostatak;
	float n;
	printf("Unesite iznos: ");
	scanf("%d", &iznos);
	
	/* Novcanice od 50 */
	
		n=(int) iznos/50;
		printf("%.0f novcanica od 50 KM\n", n);
		ostatak=iznos%50;
	
	/* Novcanice od 20 */

		n=ostatak/20;
		printf("%.0f novcanica od 20 KM\n", n);
		ostatak=ostatak%20;
		
	/* Novcanice od 10 */

		n=ostatak/10;
		printf("%.0f novcanica od 10 KM\n", n);
		ostatak=ostatak%10;
		
	/* Novcanice od 5*/
	
		n=ostatak/5;
		printf("%.0f novcanica od 5 KM\n", n);
		ostatak=ostatak%5;
		
	/* Novcanice od 2 */

		n=ostatak/2;
		printf("%.0f novcanica od 2 KM\n", n);

		ostatak=ostatak%2;
		
	/* Novcanice od 1*/


		n=ostatak/1;
		printf("%.0f novcanica od 1 KM\n", n);
	
	return 0;
}
