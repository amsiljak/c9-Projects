#include <stdio.h>

int obrnut(int x) {
    int broj=0;
    do{
        broj=x%10+broj*10;
        x=x/10;
    } while(x>0);
    return broj;
}
    

int main () {
    int x;
    printf("Unesite cijeli broj: ");
    scanf("%d", &x);
    printf("Obrnut broj glasi: %d", obrnut(x));
	return 0;
}