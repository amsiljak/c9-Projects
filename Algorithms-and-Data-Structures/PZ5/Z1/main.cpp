#include <iostream>
int fib2_0(int n, int prosli = 1, int pretprosli = 0) {
    if(n==1) return prosli;
    return fib2_0(n-1, prosli+pretprosli, prosli);
}

int nzd(int x, int y) {
    if(y == 0) return x;
    return nzd(y, x%y);
}
int main() {
    std::cout << fib2_0(20);
    return 0;
}
