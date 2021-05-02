#include <stdio.h>

struct Ocjena{
	char naziv_predmeta[100];
	int ocjena;
};

struct Student {
	char ime[20],prezime[20];
	int br_ocjena;
	struct Ocjena ocjene[100];
};

int top_studenti(struct Student studenti[], int vel) {
	
	int i,j,max;
	float prosjek[1000]={0},suma[1000]={0},temp;
	struct Student temp1;
	
	for(i=0;i<vel;i++) {
		for(j=0;j<studenti[i].br_ocjena;j++) {
			suma[i]+=studenti[i].ocjene[j].ocjena;
		}
		prosjek[i]=suma[i]/studenti[i].br_ocjena;
		//printf("%.2f\n", prosjek[i]);
	}
	
	struct Student* p = studenti;
	for(p=studenti;p<studenti+vel;p++) {
		
	}
	return 0;
}

int main() {
	return 0;
}


