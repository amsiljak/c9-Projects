#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <cmath>
using namespace std;


int dajMax(vector<int> &a, int n) {
    int max = a[0], brojac = 0;
    for(int i = 1; i < n; i++) {
        if(a[i] > max) max = a[i];
    }
    while(max != 0) {
        max /= 10;
        brojac++;
    }
    return brojac;
}

void radixSort(vector<int> &a) {
    list<int> lista[10];
    int vel = a.size();
    int max = dajMax(a, vel);
    int x, y = 1, pom, indeks, brojac = 0;
    
    for(int i = 0; i < max; i++) {
        x = pow(10, i+1);
        y = pow(10, i);
        for(int j = 0; j < vel; j++) {
            pom = a[j] % x;
            indeks = pom/y;
            lista[indeks].push_back(a[j]);
        }
        brojac = 0;
        for(int j = 0; j < 10; j++) {
            while(!lista[j].empty()) {
                a[brojac] = *(lista[j].begin());
                lista[j].erase(lista[j].begin());
                brojac++;
            }
        }
    }
}



bool prior(int x, int y) {return x>y;}
int lijevoDijete(int i )  {
    return 2*i + 1;
}
int desnoDijete(int i)  {
    return 2*i + 2;
}
int roditelj(int i) {
    return (i - 1)/2;
}
void popraviDolje(int i, std::vector<int> &a) {
    int vel = a.size();
    while(!(i >= vel/2) && i<vel) {
        int bigger = lijevoDijete(i);
        int desno_dijete = desnoDijete(i);
        if(desno_dijete < vel && prior(a[desno_dijete], a[bigger]))
            bigger = desno_dijete;
        if(prior(a[i], a[bigger])) return;
        int tmp = a[i];
        a[i] = a[bigger];
        a[bigger] = tmp;
        i = bigger;
    }
}
void popraviGore(int i, vector<int> &a) {
    while(i != 0 && prior(a[i], a[roditelj(i)])) {
        int x = roditelj(i);
        int tmp = a[i];
        a[i] = a[x];
        a[x] = tmp;
        
        i = x;
    }
}
void umetniUGomilu(vector<int> &a, int umetnuti, int &velicina) {
    a.push_back(umetnuti);
    velicina++;
    popraviGore(velicina - 1, a);
}
void stvoriGomilu(vector<int> &a) {
    int vel = a.size();
    for(int i = vel/2; i >= 0; i--) {
        popraviDolje(i, a);
    }
}



int izbaciPrvi(vector<int> &a, int &velicina) {
    if(a.size() == 0) throw;
    velicina--;
    int tmp = a[0];
    a[0] = a[velicina];
    a[velicina] = tmp;
    
    std::vector<int> vektor(velicina);
    for(int i = 0; i < vektor.size(); i++) vektor[i] = a[i];
    stvoriGomilu(vektor);
    for(int i = 0; i < vektor.size(); i++) a[i] = vektor[i];
    return tmp;
}



void gomilaSort(vector<int> &a) {
   stvoriGomilu(a);
   int velicina = a.size();
   for(int i = 0; i < a.size() - 1; i++) {
       izbaciPrvi(a, velicina);
   }
}
int main() {
    
    return 0;
}
