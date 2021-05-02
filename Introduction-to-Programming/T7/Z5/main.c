#include <stdio.h>
#include <math.h>
int faktorijel(int x) {
		if(x==1 || x==0) return 1;
		return x*faktorijel(x-1);
	}
	
float sinus(float x, int n) {
	int i;
	float suma=0;
		for(i=1; i<=n; i++) {
			suma+=pow(-1,(1-i))*(pow(x,2*i-1))/faktorijel(2*i-1);
		}
		
	return suma;
}

int main () {
	float x;
	int n;
	
	printf("Unesite x: \n");
	scanf("%f", &x);
	printf("Unesite n: \n");
	scanf("%d", &n);
		
	printf("sin(x)=%f\n", sin(x));
	printf("sinus(x)=%f\n", sinus(x,n));
	printf("Razlika: %.6f (%.2f%%).", fabs(sinus(x,n)-sin(x)), fabs(sinus(x,n)-sin(x))/sin(x));
	return 0;
}
