#include <stdio.h>

#include <stdlib.h>

int main() {
	float t;
	int random;
		t=0.1;
	srand(0);
	random=2*(rand() & 1) - 1;
	t=t*random;
	printf("%f", t);
	return 0;
}
