#include <stdio.h>

float maxtemp(float p[],int brmr) {
    float* pok, max;
    for(pok=p;pok<p+brmr;pok++) {
        if(pok==p) max=*pok;
        if (*pok>max) max=*pok;
    }
    return max;
}

float prtemp(float p[], int brmr) {
    float* pok;
    float suma=0;
    for(pok=p;pok<p+brmr;pok++) {
        suma+=*pok;
    }
    return suma/brmr;
}


int main() {
    float p[100];
    int i, brmr;
    
    printf("Unesite broj mjerenja: ");
    scanf("%d", &brmr);
    printf("Unesite temperature: ");
    for(i=0; i<brmr;i++) {
        scanf("%f", &p[i]);
    }
    
    printf("Maksimalna temperatura: %.1f\n", maxtemp(p,brmr));
    printf("Prosjecna temperatura: %.1f", prtemp(p,brmr));
	return 0;
}
