#include <stdio.h>
#include <math.h>

#define eps 0.000001

int main() {
	float a, b, c, d;
	printf("Unesite brojeve a,b,c,d: ");
	scanf("%f%f%f%f", &a, &b, &c, &d);
	
	if (b-a>0 && d-c>0) {
		
		if (fabs(a-c)<eps && fabs(b-d)<eps) {
		printf("Rezultatni interval je [%g,%g].", a, b);
		}
		
		else if ((fabs(a-c)<eps && d-b>0) || (fabs(b-d)<eps && c-a>0)) {
			printf("Rezultantni interval je [%g,%g].", c, b);
		}
		
		else if (b-d>0 && a-c>0 && d-a>0) {
			printf("Rezultantni interval je [%g,%g].", a, d);
		}
		
		else if(d-b>0 && c-a>0 && b-c>0) {
			printf("Rezultantni interval je [%g,%g].", c, b);
		}
		
		else if(c-a>0 && b-d>0) {
			printf("Rezultantni interval je [%g,%g].", c, d);
		}
		
		else if(a-c>0 && d-b>0) {
			printf("Rezultantni interval je [%g,%g].", a, b);
		}
		
		else {
			printf("Skupovi se ne sijeku.");
		}
	}
	else {
		printf("Skupovi se ne sijeku.");
	}
	return 0;
}
