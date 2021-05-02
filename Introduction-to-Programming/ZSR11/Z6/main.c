#include <stdio.h>
#include <math.h>

struct Tacka {
	
	double x, y;
};

struct Kruznica {
	
	 struct Tacka centar;
	 double poluprecnik;
};

double duzina(struct Tacka a, struct Tacka b) {
	
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
	
}

void ispis_kruznice(struct Kruznica k) {
	
	printf("(%.2lf,%.2lf) %.2lf", k.centar.x, k.centar.y, k.poluprecnik);
	
	
}

struct Kruznica obuhvat(struct Tacka* niz, int vel) {
	
	
	
	double max=0;
	int i, j;
	struct Kruznica k;
	struct Tacka k1;
	struct Tacka k2;
	
	if(vel == 1) {
		
		k.centar.x = niz[0].x;
		k.centar.y = niz[0].y;
		k.poluprecnik = 0;
		return k;
		
	} 
	
	for(i=0;i<vel;i++) {
		for(j=i;j<vel;j++) {
			
			if(max < duzina(niz[i], niz[j])) {
				max = duzina(niz[i], niz[j]);
				
				k1.x = niz[i].x;
				k1.y = niz[i].y;
				k2.x = niz[j].x;
				k2.y = niz[j].y;
			}
			
		}
		
	}
	k.poluprecnik = max/2;
	k.centar.x = (k1.x + k2.x)/2;
	k.centar.y = (k1.y + k2.y)/2;
	
	return k;
}

int main() {
	printf("ZSR 11, Zadatak 6");
	return 0;
}
