//TP 2018/2019: ZSR 3, Zadatak 4
#include <iostream>
#include <functional>
#include <memory>
#include <queue>
#include <vector>
#include <set>
#include <list>
#include <algorithm>

void f(int &a) { std::cout << a + 1 << " "; }
void f(int &&a) { std::cout << a - 1 << " "; }
template <typename T> void g(T f, int &x, int y, int &z) {
 x = f(x); y = f(y); z = f(z); std::cout << x << " " << y << " " << z << " "; }
int main() {
 int a[]{1, 3, 4, 2, 5}, *p = a + 2, x = 3;
 f(x); f(5); f(+x); f(x - 2); f(x += 2); f(a[3]);
 f(*p); f((*p)++); f(++(*p)); f(*p++); f(*++p); std::cout << std::endl;
 for(auto e : a) e *= 5; for(auto &e : a) std::cout << e << " ";
 for(auto &e : a) e *= 5; for(auto e : a) std::cout << e << " ";
 std::cout << std::endl;
 int v = 10, w = 20; g([](int x) { x += 2; return x + 1;}, v, w, v);
 std::cout << v << " " << w << std::endl;
 v = 10; w = 20; g([](int &x) { x += 2; return x + 1;}, w, w, v);
 std::cout << v << " " << w << std::endl; return 0;
}


