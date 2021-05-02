#include <stdio.h>

int main() {
    int i, C[20], br=0, br1=0, x;
    printf("Unesite elemente niza A: ");
    for(i=0;i<10;i++) {
        scanf("%d", &x);
        if(x==-1) break;
       
        C[i]=x;
        br++;
    }
    
    printf("Unesite elemente niza B: ");
    for(i=0;i<10;i++) {
        scanf("%d", &x);
        if(x==-1) break;
      
        C[i+br]=x;
        br1++;
    }
    
    
    printf("Niz C glasi: ");
    for(i=0; i<br+br1; i++)
    if (i==br+br1-1) printf("%d", C[i]);
    else printf("%d,", C[i]);
	return 0;
}
