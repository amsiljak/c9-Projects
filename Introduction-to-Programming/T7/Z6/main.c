#include <stdio.h>

int pascal(int x, int y){
    if(y>x) return 0;
    if(x==1 || y==1) return 1;
    return pascal(x-1, y)+pascal(x-1,y-1);
}

int main() {
    int n,i,j;
    printf("Unesite n: \n");
    scanf("%d", &n);
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++) {
            if(i>=j) printf("%-3d ", pascal(i, j));
        }
        printf("\n");
    }
    
	return 0;
}
