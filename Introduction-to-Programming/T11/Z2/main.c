#include <stdio.h>
#include <math.h>
#define PI 3.14159265359
/* Definicija tacke i kruznice */
struct Tacka {
	double x,y;
};
struct Kruznica {
	struct Tacka centar;
	double poluprecnik;
};

/* Funkcije za unos */
struct Tacka unos_tacke() {
	struct Tacka t;
	printf ("Unesite koordinate tacke (x, y): ");
	scanf ("%lf,%lf", &t.x, &t.y);
	return t;
}

struct Kruznica unos_kruznice() {
	struct Kruznica k;
	printf ("Unesite centar kruznice:\n");
	k.centar = unos_tacke();
	printf ("\nUnesite poluprecnik kruznice: ");
	scanf("%lf", &k.poluprecnik);
	return k;
}

/* Funkcija za udaljenost izmedju dvije tacke */
float udaljenost(struct Tacka t1, struct Tacka t2) {
	return sqrt( (t1.x-t2.x)*(t1.x-t2.x) + (t1.y-t2.y)*(t1.y-t2.y) );
}

float obim_kruznice(struct Kruznica k) {
	float obim;
	obim=k.poluprecnik*2*PI;
	return obim;
}

float povrsina_kruznice(struct Kruznica k) {
	float povrsina;
	povrsina=k.poluprecnik*k.poluprecnik*PI;
	return povrsina;
}

/* Glavni program: Da li je tacka unutar kruznice */
int main() {
	struct Kruznica k;
	struct Tacka t;
	double d;
	printf ("Unesite kruznicu:\n");
	k = unos_kruznice();
	printf ("\nUnesite neku tacku:\n");
	t = unos_tacke();

	/* Tacka se nalazi unutar kruznice ako je udaljenost tacke od centra
	kruznice manja od poluprecnika kruznice */
	d = udaljenost(t, k.centar);
	if (d<k.poluprecnik)
		printf("\nTacka je unutar kruznice.");
	else if (d==k.poluprecnik)
		printf("\nTacka je na kruznici.");
	else
		printf("\nTacka je izvan kruznice.");
	
	printf("\nObim kruznice: %.3f", obim_kruznice(k));
	printf("\nPovrsina kruznice: %.3f", povrsina_kruznice(k));

	return 0;
}
