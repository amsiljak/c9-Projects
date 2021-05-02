#include <stdio.h>
#include <stdlib.h>

struct Vrijeme {
	int sati,minute,sekunde;
};


int proteklo(struct Vrijeme v1, struct Vrijeme v2) {
	int a1;
	int a2;
	a1=v1.sati*3600+v1.minute*60+v1.sekunde;
	a2=v2.sati*3600+v2.minute*60+v2.sekunde;
	return abs(a1-a2);
}

int main() {
	struct Vrijeme v1,v2;
	printf("\nUnesite prvo vrijeme (h m s): ");
	scanf("%d %d %d", &v1.sati, &v1.minute, &v1.sekunde);
	printf("\nUnesite drugo vrijeme (h m s): ");
	scanf("%d %d %d", &v2.sati, &v2.minute, &v2.sekunde);
	printf("\nIzmedju dva vremena je proteklo %d sekundi.", proteklo(v1,v2));
	return 0;
}
