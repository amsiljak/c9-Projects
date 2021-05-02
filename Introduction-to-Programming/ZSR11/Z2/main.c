#include <stdio.h>
//ZSR 11,zad 2

struct Tacka {
	double x,y;
};
struct Pravougaonik {
	struct Tacka dolje_lijevo;
	struct Tacka gore_desno;
};

struct Pravougaonik min_pravougaonik(struct Tacka* t, int vel) {
	int i;
	// struct Tacka* pok;
	struct Tacka xmax,xmin,ymax,ymin;
	struct Pravougaonik p;
	for(i=0;i<vel;i++) {
		if(i==0) {
			xmax=t[i]; 
			xmin=t[i];
			ymax=t[i]; 
			ymin=t[i];
		}
		else {
			if(t[i].x>xmax.x) xmax=t[i];
			if(t[i].x<xmin.x) xmin=t[i];
			if(t[i].y>ymax.y) ymax=t[i];
			if(t[i].y<ymin.y) ymin=t[i];
		}
	}
	p.dolje_lijevo.x=xmin.x;
	p.dolje_lijevo.y=ymin.y;
	p.gore_desno.x=xmax.x;
	p.gore_desno.y=ymax.y;
	
	return p;
}

int main() {
	int vel,i;
	struct Tacka t;
	struct Tacka* pok=&t;
	struct Pravougaonik p;
	printf("Unesite broj tacaka: ");
	scanf("%d", &vel);
	for(i=0;i<vel;i++) {
		printf("Unesite koordinate x i y tacke %d: ", i+1);
		scanf("%lf %lf", &pok[i].x, &pok[i].y);
	}
	
	p=min_pravougaonik(pok,vel);
	printf("Minimalni pravougaonik za ove tacke ima uglove: (%g,%g) - (%g,%g)", p.dolje_lijevo.x, p.dolje_lijevo.y,p.gore_desno.x, p.gore_desno.y);
	
	return 0;
}
