#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define eps 0.000000001

int izbaci_dvije_decimale(double niz[], int vel) {
    
	double* pok;
	double* pok2;
	int vel1=vel;
    float suma=0, sr_vrijednost;
    int k1,k2,zbir=0, temp,i;
    
    //suma svih clanova
    for(pok=niz;pok<niz+vel;pok++) {
        suma+=*pok;
    }
    //srednja vrijednost svih clanova
    sr_vrijednost=suma/vel;
    //printf("sr_vrijednost:%f\n", sr_vrijednost);

    for(pok=niz;pok<niz+vel;pok++) {
        //zbir dvije decimale
       // *pok=abs(*pok);
        temp=round((*pok)*100);
            k1=temp%10;
            zbir+=k1;
            temp=temp/10;
            k2=temp%10;
            zbir+=k2;
            zbir=abs(zbir);
         //printf("Zbir:%d\n",zbir);
        //clan niza treba izbaciti
        if(zbir-sr_vrijednost>eps) {
            //printf("da\n");
            vel1--;
            for (pok2=pok; pok2<niz+vel-1; pok2++) {
                *pok2 = *(pok2+1);
            }
            vel--;            
            pok--;
        }
        zbir=0;
    }
    return vel1;
}

int main() {
       double niz[] = {-1.234, 10.01, 0, 10.5, -0.22445, 10};
    int vel = izbaci_dvije_decimale(niz, 6);
    int i;
    for (i=0; i<vel; i++)
    	printf("%g ", niz[i]);
	return 0;
}
