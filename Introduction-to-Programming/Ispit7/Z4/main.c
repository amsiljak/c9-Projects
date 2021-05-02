#include <stdio.h>

struct Planina {
	char naziv[51];
	int visina;
};
int ucitaj() {
	int i;
	struct Planina planine[1000];
	FILE* ulaz=fopen("planine.txt", "r");
	while(i<1000 && fscanf(ulaz, "%s %d\n", &planine[i].naziv, &planine[i]. visina)==2) i++;
	return i;
}
void zapisi(int i) {
	FILE* izlaz=fopen("planine.dat", "wb");
	fwrite(planine, sizeof(struct Planina), i, izlaz);
}
void ispis(int br) {
	int i,j,k;
	for(i=0;i<br;i++) {
		for(j=0;j<)
	}
}

int main() {
	int i;
	i=ucitaj();
	zapisi(i);
	ispis(i);
	
	
	return 0;
}
