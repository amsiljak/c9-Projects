#include <stdio.h>
#define DUZINA 10
int main() {
    double niz[DUZINA],temp;
    int i,j,max;
    /* unos niza */
    for (i=0; i<DUZINA; i++) {
        printf("Unesite %d. realan broj: ", i+1);
        scanf("%lf", &niz[i]);
    }

    for (i=0; i<DUZINA; i++) {
        max=i;
        for (j=i+1; j<DUZINA; j++) {
            if (niz[j] > niz[max])
                max = j;
        }
        temp = niz[i];
        niz[i] = niz[max];
        niz[max] = temp;
    }
    /* ispis niza */
    printf("Sortiran niz:\n");
    for (i=0; i<DUZINA; i++)
        printf("%g ", niz[i]);
    printf("\n");
    return 0;
}
