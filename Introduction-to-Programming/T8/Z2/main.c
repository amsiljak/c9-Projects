#include <stdio.h>

float maxtemp(float p[8]) {
    float* pok, max;
    for(pok=p;pok<p+8;pok++) {
        if(pok==p) max=*pok;
        if (*pok>max) max=*pok;
    }
    return max;
}

float prtemp(float p[8]) {
    float* pok;
    float suma=0;
    for(pok=p;pok<p+8;pok++) {
        suma+=*pok;
    }
    return suma/8;
}


int main() {
    float p[8];
    int i;
    
    printf("Unesite temerature: ");
    for(i=0; i<8;i++) {
        scanf("%f", &p[i]);
    }
    
    printf("Maksimalna temperatura: %.1f\n", maxtemp(p));
    printf("Prosjecna temperatura: %.1f", prtemp(p));
	return 0;
}
