#include <stdio.h>
#include <math.h>
#define PI 3.1415926
/* Definicija tacke i kruznice */
struct Tacka {
	double x,y;
};
struct Kruznica {
	struct Tacka centar;
	double poluprecnik;
};

struct Pravougaonik {
	struct Tacka gore_desno;
	struct Tacka dole_lijevo;
};

/* Funkcije za unos */
struct Tacka unos_tacke() {
	struct Tacka t;
	printf ("Unesite koordinate tacke (x, y):\n");
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

double povrsina_kruznice(struct Kruznica k) {
	return k.poluprecnik*k.poluprecnik*PI;
}

double obim_kruznice(struct Kruznica k) {
	return 2*k.poluprecnik*PI;
}

double obim_pravougaonika(struct Pravougaonik p) {
	double a,b;
	a=p.gore_desno.x-p.dole_lijevo.x;
	b=p.gore_desno.y-p.dole_lijevo.y;
	return 2*(a+b);
}

double povrsina_pravougaonika(struct Pravougaonik p) {
	double a,b;
	a=p.gore_desno.x-p.dole_lijevo.x;
	b=p.gore_desno.y-p.dole_lijevo.y;
	return a*b;
}

int tacka_u_pravougaoniku(struct Tacka t, struct Pravougaonik p ) {
	if(t.x>=p.dole_lijevo.x && t.x<=p.gore_desno.x && t.y>=p.dole_lijevo.y && t.y<=p.gore_desno.y) return 1;
	return 0;
}

/* Funkcija za udaljenost izmedju dvije tacke */
float udaljenost(struct Tacka t1, struct Tacka t2) {
	return sqrt( (t1.x-t2.x)*(t1.x-t2.x) + (t1.y-t2.y)*(t1.y-t2.y) );
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
		printf("Tacka je unutar kruznice.\n");
	else if (d==k.poluprecnik)
		printf("Tacka je na kruznici.\n");
	else
		printf("Tacka je izvan kruznice.\n");
		
	printf("Obim kruznice: %.3lf\n", obim_kruznice(k));
	printf("Povrsina kruznice: %.3lf\n", povrsina_kruznice(k));



}
