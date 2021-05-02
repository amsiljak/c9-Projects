#include <stdio.h>

int main() {
	srand(0);
	random=2*(rand() & 1) - 1;
	t=t*random;
	return 0;
}
