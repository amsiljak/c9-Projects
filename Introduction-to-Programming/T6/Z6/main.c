#include <stdio.h>
#define VISINA 100
#define SIRINA 100

    int main () {
        int V, S, i, j;
        float mat[VISINA][SIRINA], suma;


        printf("Unesite dimenzije matrice: ");
            scanf("%d%d", &V, &S);
        printf("Unesite elemente matrice: ");
            for(i=0; i<V; i++){
                for(j=0; j<S; j++) {
                    scanf("%f", &mat[i][j]);
                }
            }

            suma=0;

                for(i=0; i<V; i++) {
                    for(j=0; j<S; j++){
                        if( (i==0 && j!=0 && j!=S-1) || (j!=0 && i==V-1 && j!=S-1) || (i==V-1 && j!=0 && j!=S-1) || ( j==S-1 && i!=V-1));
                   suma+=mat[i][j];
                    }
                }
            printf("Suma elemenata na rubu je %.2f", suma);


    return 0;
    }