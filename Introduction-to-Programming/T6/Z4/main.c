#include <stdio.h>

int main() {
    int i, j, niz[10],x,y,br=0;
    
    printf("Unesite elemente niza: ");
    for(i=0;i<10;i++) {
        scanf("%d", &x);
        if(x==-1) break;
        niz[i]=x;
        br++;
    }
    
    printf("Unesite element koji treba izbaciti: ");
    scanf("%d", &y);
 
    for(i=0; i<br; i++) {
        if(niz[i]==y) {
            for(j=i; j<br-1;j++) {
                niz[j]=niz[j+1];
            }
            br--;
            i--;
        } 
    }
    
    printf("Novi niz glasi: ");
    for(i=0; i<br; i++) {
        if(i==br-1) printf("%d", niz[i]);
        else printf("%d,", niz[i]);
    }
	return 0;
}
