#include <iostream>
#include <string>
#include <fstream>
#include <chrono>

using namespace std;
template <typename Tip>
void selection_sort(Tip* niz, int vel) {
    for(int j = 0; j < vel - 1; j++) {
        Tip minimum = niz[j];
        int indeks = j;
        for(int k = j + 1; k < vel; k++) {
            if(niz [k] < minimum) {
                minimum = niz[k];
                indeks = k;
            }
        }
        niz[indeks] = niz [j];
        niz[j] = minimum;
    }        
}
template <typename Tip>
void bubble_sort(Tip* niz, int vel) {
    for(int i = vel-1; i >= 1; i--) {
        for(int j = 1; j <= i; j++) {
            if(niz[j-1] > niz[j]) {
                Tip pom = niz[j-1];
                niz[j-1] = niz[j];
                niz[j] = pom;
            }
        }
    }
}
template <typename Tip>
int pomocna2(Tip *niz, int prvi, int zadnji) {
    Tip pivot = niz[zadnji];
    int indeks = prvi - 1;
    
    while(prvi<zadnji) {
        
        if(niz[prvi] < pivot) {
            indeks++;
            Tip temp = niz[indeks];
            niz[indeks] = niz[prvi];
            niz[prvi] = temp;
        }
        prvi++;
    }
    Tip temp = niz[indeks+1];
    niz[indeks + 1] = niz[zadnji];
    niz[zadnji] = temp;
    return indeks + 1;
}
template <typename Tip> 
void pomocna1(Tip *niz, int prvi, int zadnji) {
    if(prvi<zadnji) {
        int partition = pomocna2(niz, prvi,zadnji);
        pomocna1(niz,prvi,partition - 1);
        pomocna1(niz,partition + 1,zadnji);
    }
}

template <typename Tip>
void quick_sort(Tip* niz, int vel) {
    pomocna1(niz, 0, vel - 1);
}

template <typename Tip>
void pomocna_merge_2(Tip *niz, int prvi, int pom, int zadnji) {
    Tip *niz2 = new Tip[zadnji-prvi+1];
    
    int a = prvi;
    int b = pom +1;
    int c = 0;
    while(a <= pom && b<=zadnji) {
        // if break;
        if(niz[a] <= niz[b]) {
            niz2[c] = niz[a];
            a++; 
            c++;
        }
        else {
            niz2[c] = niz[b];
            b++;
            c++;
        }
    }
    while(a<=pom) {
        // if() break;
        niz2[c] = niz[a];
        c++;
        a++;
    }
    while (b <= zadnji) {
        // if() break;
        niz2[c] = niz[b];
        c++;
        b++;
    }
    c = 0;
    a = prvi;
    while(a <= zadnji) {
        niz[a] = niz2[c];
        a++;
        c++;
    }
    delete[] niz2;
}
template <typename Tip>
void pomocna_merge_1(Tip* niz, int prvi, int zadnji) {
    int pom;
    if(prvi < zadnji) {
        pom = (prvi + zadnji) / 2;
        
        pomocna_merge_1(niz, prvi, pom);
        pomocna_merge_1(niz, pom + 1, zadnji);
        pomocna_merge_2(niz, prvi, pom, zadnji);
    }
}
template <typename Tip>
void merge_sort(Tip* niz, int vel) {
    pomocna_merge_1(niz, 0, vel - 1);
}

void ucitaj(std::string filename, int*& niz, int &vel) {
    std::ifstream ulazni(filename);
    if(!ulazni) {std::cout<<"Greska"<<std::endl; return;}
    else {
        int x, i=0;
        while (ulazni>>x) {
            vel++;
        }
        ulazni.close();
        ulazni.open(filename);
        niz = new int[vel];
        while(ulazni>>x) {
            niz[i] = x;
            i++;
        }
        
    }
    if(!ulazni.eof()) std::cout<<"Greska"<<std::endl;
    ulazni.close();
}

void generisi(std::string filename, int vel) {
    std::ofstream izlazni(filename);
    for(int a = 0; a < vel; a++) {
        izlazni<<std::rand()<<" ";
    }
    izlazni.close();
}




void izbor(std::string filename) {
    generisi(filename,5);
    int* niz;
    int vel=0, izbor;
    ucitaj(filename,niz,vel);
   std::cout<<("Izaberite algoritam sortiranja: (0 za bubble sort, 1 za selection sort, 2 za quick sort, 3 za merge sort): ")<<std::endl;
   std::cin>>izbor;
  
    auto t1 = std::chrono::high_resolution_clock::now();
    switch(izbor) {
        case 0 : 
            bubble_sort(niz,vel);
            break;
         
        case 1: 
            
            selection_sort(niz,vel);
            
            break;
        
        case 2: 
            quick_sort(niz,vel);
            break;
        
        case 3: 
            merge_sort(niz,vel);
            break;
        
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count();
    std::cout<<"Duzina trajanja u mikrosekundama: "<<duration<<std::endl;
    
    bool sortiran = true;    
    for(int i = 0; i < vel - 1; i++) {
        if(niz[i] > niz[i+1]) {sortiran = false;}
    }
    if(sortiran) std::cout<<"Sortiran"<<std::endl;
    else std::cout<<"Nije sortiran"<<std::endl;
    
    std::ofstream izlaz;
    izlaz.open("izlaz.txt");
    for(int i=0;i<vel;i++) {
        izlaz<<niz[i];
        izlaz<<" ";
    }
    izlaz.close();
    delete[] niz;
}
int main() {
     
    izbor("neki.txt");
    return 0;
}
