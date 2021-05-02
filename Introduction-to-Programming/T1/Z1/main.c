#include <stdio.h>
#define PI 3.14

int main()
{
    float R, P, V;
    
    /*Unos popuprecnika sa tastature i izracunavanje*/ 
    
printf("Unesite poluprecik");
scanf("%f", &R);
P=R*R*PI;
V=(4/3)*R*R*R*PI;

/*Ispis na monitoru*/

printf("\n Povrsina kruga sa poluprecnikom %2f iznosi %.2f", R, P);
printf("\n Povrsina kugle sa poluprecnikom %2f je %.2f", R, V);
    return 0;
}

