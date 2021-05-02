#include <stdio.h>

struct Student {
	char ime[20];
	char prezime[20];
};

struct Ocjena {
	struct Student s;
	char predmet[100];
	int ocjena;
};

struct Predmet {
	int id;
	char naziv[100];
	float prosjek;
};

int main() {
	printf("ZSR 13, Zadatak 2");
	return 0;
}
