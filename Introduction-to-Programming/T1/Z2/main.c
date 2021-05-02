#include <stdio.h>
#define PI 3.14

int main()
{
    float R, P, V, N;

    /* Unos poluprecnika sa tastature i izracunavanje */

    printf ("Unesite poluprecnik");
    scanf ("%f", &R);
    P=(R*R)*PI;
    V=(4/3.)*R*R*R*PI;
    N=(4*R*PI);

    /* Ispis na monitoru*/
    printf("\n Povrsina kruga sa poluprecnikom %2f je %.2f", R,P);
    printf("\n Zapremina kugle sa poluprecnikom %2f je %.2f", R,V);
    printf("\n Povrsina lopte sa poluprecnikom %2f je %.2f", R, N);
    return 0;
}

