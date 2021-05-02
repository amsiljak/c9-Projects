#include <stdio.h>
#define PI 3.14

int main() {
	int a, b, c, r, H;
	float P, V; 
	printf("Unesi jednu stranicu kvadra");
	scanf("%d", &a);
	printf("Unesi drugu stranicu kvadra");
	scanf("%d", &b);
	printf("unesi trecu stranicu kvadra");
	scanf("%d", &c);
	printf("Unesi poluprecnik valjka");
	scanf("%d", &r);
	printf("Unesi visinu valjka");
	scanf("%d", &H);
	V=(a*b*c)+(r*r*PI*H);
	P=2*(a*b+b*c+a*c)+2*r*PI*H;
	printf("\n Povrsina tijela sa slike je %f cm2", P);
	printf("\n Zapremina tijela sa slike je %f cm3", V);

	return 0;
}
