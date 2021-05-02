#include <stdio.h>

struct Grad {
	char naziv[20];
	int br_stanovnika;
};

struct Drzava {
	char naziv[50];
	struct Grad glavni;
};

struct Regija {
	char naziv[50];
	struct Grad glavni;
};

int main() {
	printf("ZSR 13, Zadatak 4");
	return 0;
}
