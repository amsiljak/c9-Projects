#include <stdio.h>

struct Tacka {
	int x,y;
};

struct Pravougaonik {
	struct Tacka gore_lijevo;
	int duzina;
	int sirina;
};

int CrtajPravougaonike(struct Pravougaonik *niz, int velicina) {
	int i,j,k;
	for(i=0;i<velicina;i++) {
		for(j=niz[i].gore_lijevo.x; j<=niz[i].sirina;j++) {
			for(k=niz[i].gore_lijevo.y;k<=niz[i].duzina;k++) {
				if((j==niz[i].sirina || j==niz[i].gore_lijevo.x)
				|| (k==niz[i].duzina || k==niz[i].gore_lijevo.y) ) printf("*");
				else printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
}

int main() {
	struct Pravougaonik niz[3] ={{{1, 1}, 5, 3}, {{3, 3}, 7, 6}, 
	{{ 5, 7}, 5, 3}};
	CrtajPravougaonike(niz, 3);

	return 0;
}
