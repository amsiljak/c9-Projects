#include <stdio.h>
#include <math.h>

#define eps 0.0001
struct Tacka {
	
	int x, y;
};

struct Trougao {
	
	struct Tacka A, B, C;
	
};

double duzina (struct Tacka a, struct Tacka b) {
	
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y - b.y)*(a.y - b.y));
	
} 

int izbaci_pravougle(struct Trougao a[], int vel) {
	
	double AB, BC, CA, max;
	int i, j;
	double PI=4*atan(1);
	
	for(i=0;i<vel;i++) {
		
		AB = duzina(a[i].A, a[i].B);
		BC = duzina(a[i].B, a[i].C);
		CA = duzina(a[i].A, a[i].C);
		
		if(AB > BC && AB > CA)
			max = AB;
		else if(BC > AB && BC > CA)
			max = BC;
		else
			max = CA;
			
		double fi1, fi2, fi3;	
			
		fi1=acos((pow(BC,2)+pow(CA,2)-pow(AB,2))/(2*BC*CA));
		fi2=acos((pow(AB,2)+pow(CA,2)-pow(BC,2))/(2*AB*CA));
		fi3=acos((pow(AB,2)+pow(BC,2)-pow(CA,2))/(2*AB*BC));
		
		fi1=fi1*180/PI;
		fi2=fi2*180/PI;
		fi3=fi3*180/PI;
		
		if(fabs(fi1 - 90) < eps || fabs(fi2 - 90) < eps || fabs(fi3 - 90) < eps) {
			
			for(j=i;j<vel-1;j++)
				a[j] = a[j+1];
			
			vel--;
			i--;// Ovo je kljucno, nemoj zaboraviti da stavis kada treba izbaciti
		}
			
	}	
	
	return vel;
}

int main() {
	struct Trougao trouglovi[3];
int i, vel;
/* Jeste pravougli */ 
trouglovi[0].A.x=0; trouglovi[0].A.y=0; 
trouglovi[0].B.x=1; trouglovi[0].B.y=0; 
trouglovi[0].C.x=0; trouglovi[0].C.y=1; 
/* Jeste pravougli */
trouglovi[1].A.x=0; trouglovi[1].A.y=0; 
trouglovi[1].B.x=1; trouglovi[1].B.y=1; 
trouglovi[1].C.x=0; trouglovi[1].C.y=1; 
/* Nije pravougli */
trouglovi[2].A.x=0; trouglovi[2].A.y=0; 
trouglovi[2].B.x=1; trouglovi[2].B.y=1; 
trouglovi[2].C.x=2; trouglovi[2].C.y=1; 

/* Izbacivanje */
vel = izbaci_pravougle(trouglovi, 3);
for (i=0; i<vel; i++) {
   printf("Trougao %d: (%d,%d)-(%d,%d)-(%d,%d)\n", i, 
   trouglovi[i].A.x, trouglovi[i].A.y, trouglovi[i].B.x, trouglovi[i].B.y, 
   trouglovi[i].C.x, trouglovi[i].C.y);
}

	return 0;
}
