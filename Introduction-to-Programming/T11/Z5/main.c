#include <stdio.h>
#include <stdlib.h>

struct Vrijeme {
	int sati,minute,sekunde;
};

struct Vrijeme proteklo(struct Vrijeme v1, struct Vrijeme v2) {
	int s1,s2,s3;
	s1=v1.sati*3600+v1.minute*60+v1.sekunde;
	s2=v2.sati*3600+v2.minute*60+v2.sekunde;
	s2=abs(s1-s2);
	struct Vrijeme v3;
	v3.sati=s3/3600;
	s3=s3%3600;
	v3.minute=s3/60;
	s3=s3%60;
	v3.sekunde=s3;
	return v3;
}

int main() {
	struct Vrijeme v1,v2;
	struct Vrijeme v3;
	printf("\nUnesite prvo vrijeme (h m s): \n");
	scanf("%d %d %d", &v1.sati, &v1.minute, &v1.sekunde);
	printf("\nUnesite drugo vrijeme (h m s): \n");
	scanf("%d %d %d", &v2.sati, &v2.minute, &v2.sekunde);
	v3=proteklo(v1,v2);
	printf("\nIzmedju dva vremena je proteklo %d sati, %d minuta i %d sekundi.", v3.sati, v3.minute, v3.sekunde);
	return 0;
}
