#include <stdio.h>
#include <math.h> 
int Farey(double* niz, int n) {
	int i,j,uslov=1,k,br=0,min,l;
	double temp;
	
	*niz=0;
	niz++;
	for(i=1;i<n;i++) {
		for(j=i+1;j<n;j++) {
			for(k=2;k<=sqrt(i);k++) {
				if(i%k==0 && j%k==0) {uslov=0; break;}
				uslov=1;
			}
			
			for(l=0;l<br;l++) if(niz[l]==(double)i/j) uslov=0;
			if(uslov) {
				
				niz[br]=(double)i/j; 
				br++;
				if(br==99) {j=n+1; i=n+1;}
			}
		}
	}
	niz[br]=1;
	br++;
	for(i=0;i<br;i++) {
		min=i;
		for(j=i+1;j<br;j++) {
			if(niz[j]<niz[min]) 
			min=j;
		}
		temp=niz[i];
		niz[i]=niz[min];
		niz[min]=temp;
	}
	return br;
}
int main() {
	double niz[100];
	int vel = Farey(niz, 7);
	int i;
	for (i=0; i<vel; i++) printf("%.3f ", niz[i]);
	return 0;
}
