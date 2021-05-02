#include <stdio.h>

int prost(int x) {
    int i;
    if(x==1) return 0;
    for(i=2; i<=x/2; i++) {
        if(x%i==0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int i;
    for(i=1; i<=100; i++) {
        if(prost(i)) printf("%d\n", i);
    }
	return 0;
}
