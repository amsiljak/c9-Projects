#include <iostream>
#include <utility>
#include <tuple>
#include <string>
#include <chrono>
using namespace std;

template <typename Tip>
class Lista
{
    public:
    virtual ~Lista(){} 
    virtual Tip &operator [](int indeks) = 0;
    virtual Tip operator [] (int indeks) const= 0;
    virtual int brojElemenata() const= 0;
    virtual Tip &trenutni()  = 0;
    virtual Tip trenutni() const = 0;
    virtual bool prethodni() = 0; //da
    virtual bool sljedeci() = 0; //da
    virtual void pocetak() = 0; //da
    virtual void kraj() = 0; //da
    virtual void obrisi() = 0; //da
    virtual void dodajIspred(const Tip& el) = 0;
    virtual void dodajIza(const Tip& el) = 0;    
   
};

template <typename Tip>
class NizLista : public Lista<Tip>
{
private:
    int kapacitet;
    int duzina;
    int tekuci; //indeks trenutnog
    Tip** L;
public:
    NizLista()
    {
        kapacitet = 78;
        duzina=0;
        tekuci=0;
        L=nullptr;
    }

    NizLista(const NizLista &nl)
    {
        kapacitet=nl.kapacitet;
        duzina=nl.duzina;
        tekuci=nl.tekuci;
        L=new Tip*[kapacitet];
        for(int i=0; i<nl.duzina; i++) L[i]=new Tip(*nl.L[i]);
    }

    ~NizLista()
    {
        if(L!=nullptr) for(int i=0; i<duzina; i++) delete L[i];
        delete[] L;
    }
    int brojElemenata() const
    {
        return duzina;
    }  
    Tip &trenutni()
    {
        if(duzina == 0) throw "Lista je prazna";
        return *L[tekuci];
    } 
    bool prethodni()
    {
        if(duzina==0) throw "Lista je prazna";
        if(tekuci==0) return false;
        tekuci--;
        return true;
    }  
    Tip trenutni() const
    {
        if(duzina==0) throw "Lista je prazna";
        return *L[tekuci];
    }
  
    void pocetak()
    {
        if(duzina==0) throw "Lista je prazna";
        tekuci=0;
    }
    bool sljedeci()
    {
        if(duzina==0) throw "Lista je prazna";
        if(tekuci==duzina-1) return false;
        tekuci++;
        return true;
    }
 
    void kraj()
    {
        if(duzina==0) throw "Lista je prazna";
        tekuci=duzina-1;
    }
    void obrisi()
    {
        if(duzina==0) throw "Lista je prazna";

        else 
        {
            delete L[tekuci];
            
            for(int i=tekuci; i<duzina-1 ; i++) L[i]=L[i+1];
            duzina--;
            if(tekuci==duzina) tekuci--; //obrisan je posljednji el, pa tekuci postaje onaj prije njega
        }
        if (duzina == 0) 
        {
            delete[] L;
            L = nullptr;
        }
    }
   
    NizLista &operator = (const NizLista &nl)
    {
        if(this==&nl) return *this;
        if(duzina != 0)
        {
            for(int i=0; i<duzina; i++) delete L[i];
        }
        delete[] L;
        
        kapacitet=nl.kapacitet;
        duzina=nl.duzina;
        tekuci=nl.tekuci;
        L=new Tip* [kapacitet];
        for(int i=0; i<duzina; i++) L[i]=new Tip(*nl.L[i]);
        return *this;
    }
    void dodajIza(const Tip& el )
    {

        if(duzina==0)
        {
            tekuci=0;
            L=new Tip*[kapacitet];
            L[0]=new Tip(el);
        }
        else
        {
            if(duzina==kapacitet)
            {
                Tip**p=L;
                kapacitet+=kapacitet/2;
                L=new Tip*[kapacitet];
                for(int i=0; i<duzina; i++) L[i]=p[i]; 
                delete[] p;
            }
            for(int i=duzina-1; i>tekuci; i--) L[i+1]=L[i];
            L[tekuci+1]=new Tip(el);
        }
        duzina++;
    }
    void dodajIspred(const Tip& el)
    {
        if(duzina==0)
        {
            tekuci=0;
            L=new Tip*[kapacitet];
            L[0]=new Tip(el);
        }
        else
        {
            if(duzina==kapacitet) // treba povecati kapacitet
            {
                Tip**p=L;
                kapacitet+=kapacitet/2; //trebalo bi svaki out sve vise dodati npr 100*2
                L=new Tip*[kapacitet];
                for(int i=0; i<duzina; i++) L[i]=p[i]; //u p smijestamo ono sto smo imali, onda povecamo kapacitet i vratimo iz p
                delete[] p;
            }
            for(int i=duzina; i>tekuci; i--) L[i]=L[i-1]; //pravimo prostor za novi el
            L[tekuci]=new Tip(el);
            tekuci++;
        }
        duzina++;
    }
    
    Tip &operator [](int indeks)
    {
        if(indeks<0 || indeks>=duzina) throw "Neispravan indeks";
        return *L[indeks];
    }
    Tip operator [] (int indeks) const
    {
        if(indeks<0 || indeks>=duzina) throw "Neispravan indeks";
        return *L[indeks];
    }
   

};

template <typename TipKljuca,typename TipVrijednosti>
class Mapa {
    public:
    virtual ~Mapa(){};
    virtual TipVrijednosti &operator [](TipKljuca kljuc)=0;
    virtual TipVrijednosti operator [](TipKljuca kljuc) const=0;
    virtual int brojElemenata() const =0;
    virtual void obrisi() = 0;
    virtual void obrisi(const TipKljuca& kljuc)=0;
};
template <typename TipKljuca, typename TipVrijednosti>
class HashMapa : public Mapa<TipKljuca,TipVrijednosti> {
private:
    int maks, brojEl;
    unsigned int (*pok_na_fun)(TipKljuca, unsigned int);
    std::tuple<TipKljuca,TipVrijednosti, bool> **L;
public:
    HashMapa(const HashMapa<TipKljuca,TipVrijednosti> &hm) {
        L = new std::tuple<TipKljuca,TipVrijednosti,bool>*[hm.maks] {};
        brojEl = hm.brojEl;
        maks = hm.maks;
        pok_na_fun = hm.pok_na_fun;
        
        for(int i = 0; i < maks; i++) {
            if(hm.L[i] != nullptr) {
            L[i] = new tuple<TipKljuca,TipVrijednosti,bool>(*hm.L[i]);
            }
        }
    }
    HashMapa() {
        brojEl = 0;
        maks = 5000;
        pok_na_fun = nullptr;
        L = new tuple<TipKljuca,TipVrijednosti,bool>*[5000] {};
    }
    HashMapa& operator =(const HashMapa<TipKljuca,TipVrijednosti>&hm) {
        if(this == &hm) return *this;
        obrisi();
        delete[] L;
        L = new tuple<TipKljuca,TipVrijednosti,bool>*[hm.maks] {};
        for(int i = 0; i < hm.maks; i++) {
            if(hm.L[i] != nullptr) {
            L[i] = new tuple<TipKljuca,TipVrijednosti,bool>(*hm.L[i]);
            }
        }
        brojEl = hm.brojEl;
        maks = hm.maks;
        pok_na_fun = hm.pok_na_fun;
        return *this;
    }
    int brojElemenata() const {
        return brojEl;
    }
    void obrisi() {
        brojEl = 0;
        for(int i = 0; i < maks; i++) {
            delete L[i];
            L[i] = nullptr;
        }
    }
    void obrisi(const TipKljuca& kljuc) {
        if(!pok_na_fun) throw;
        
        int i = 0;
        unsigned int indeks = pok_na_fun(kljuc, maks);
        
        do {
            if(!(L[indeks] != nullptr && get<0>(*L[indeks]) == kljuc && !get<2>(*L[indeks]))) {
                i++;
                indeks = (indeks + 1) % maks;
            }
            else {
                get<2>(*L[indeks]) = true;
                brojEl--;
                return;
            }
        }while(!(L[indeks] == nullptr) && i != maks);
        
        throw "Nije pronadjeno";
    }
    ~HashMapa() {
        for(int i = 0; i < maks; i++) {
            delete L[i];
            L[i] = nullptr;
        }
        delete[] L;
    }
    TipVrijednosti operator [](TipKljuca kljuc) const {
        if(!pok_na_fun) throw;
        int i = 0;
        unsigned int indeks = pok_na_fun(kljuc, maks);
        do{
            if(!(L[indeks] != nullptr && get<0>(*L[indeks]) == kljuc && !get<2>(*L[indeks]))) {
                indeks = (indeks + 1) % maks;
                i++;
            }
            else {
                return get<1>(*L[indeks]);
            }
        }while(!(L[indeks] == nullptr) && i != maks);
        return TipVrijednosti();
    }
    TipVrijednosti& operator [](TipKljuca kljuc) {
        if(pok_na_fun == nullptr) throw "Greska";
        int i = 0;
        unsigned int indeks = pok_na_fun(kljuc, maks);
        do {
            if(!(L[indeks] != nullptr && get<0>(*L[indeks]) == kljuc && !get<2>(*L[indeks]))) {
                i++;
                indeks = (indeks + 1) % maks;
            }
            else {
                return get<1>(*L[indeks]);
            }
        }while(!(L[indeks] == nullptr) && i != maks);
        
        if(brojEl < maks) {
            i = 0;
            int j = pok_na_fun(kljuc, maks);
            do{
                
                if(!(!L[j] || get<2>(*L[j]))) {
                    i++;
                    j = (j + 1) % maks;
                }
                else {
                    
                    delete L[j];
                    L[j] = new tuple<TipKljuca,TipVrijednosti,bool>(kljuc,TipVrijednosti(), false);
                    brojEl++;
                    return get<1>(*L[j]);
                }
            }while(i < maks);
            
        }
        else {
            tuple<TipKljuca,TipVrijednosti,bool> **nL = new tuple<TipKljuca,TipVrijednosti,bool>*[maks*3] {};
            for(int i = 0; i < maks; i++) {
                if(L[i] != nullptr) {
                int k = 0;
                int j = pok_na_fun(get<0>(*L[i]), maks * 3);
                do {
                    if(nL) {
                        j = (j + 1) % (maks * 3);
                        k++;
                    }
                    else {
                        nL[j] = new tuple<TipKljuca,TipVrijednosti,bool>(get<0>(*L[i]), TipVrijednosti(), false);
                        break;
                    }
                }while( k < maks * 3) ;
                
                delete L[i];
                L[i] = nullptr;
                }
            }
            delete[] L;
            L = nL;
            maks = maks * 3;
            int vraca = pok_na_fun(kljuc, maks);
            i = 0;
            do {
                if(!(!L[vraca] || get<2>(*L[vraca]))) {
                    i++;
                    vraca = (vraca + 1) % maks;
                }
                else {
                    delete L[vraca];
                    L[vraca] = new tuple<TipKljuca,TipVrijednosti,bool>(kljuc,TipVrijednosti(),false);
                    brojEl++;
                    return get<1>(*L[vraca]);
                }
            }while(i < maks);
            
        }
        
    }
    void definisiHashFunkciju(unsigned int (*pok_na_fun1)(TipKljuca, unsigned int)) {
        pok_na_fun = pok_na_fun1;
    }
};
template <typename TipKljuca, typename TipVrijednosti>
class NizMapa : public Mapa<TipKljuca,TipVrijednosti>{
    private:
        NizLista<pair<TipKljuca,TipVrijednosti>> niz;
    public:
        NizMapa() {};
        ~NizMapa(){};
        NizMapa(const NizMapa &nm) {
            niz=nm.niz;
        }
        TipVrijednosti &operator [](TipKljuca kljuc) {
            int i;
            for(i=0;i<niz.brojElemenata();i++) {
                if(niz[i].first== kljuc) return niz[i].second;
            }
            int broj= niz.brojElemenata();
           
            pair <TipKljuca,TipVrijednosti> p =pair<TipKljuca,TipVrijednosti>(kljuc,TipVrijednosti());
            //  std::cout<<"da"<<std::endl; 
            if(broj!=0) niz.kraj();
            
            niz.dodajIza(p);
            
            
            return niz[broj].second;
            
        }
        TipVrijednosti operator [](TipKljuca kljuc) const {
            for(int i=0;i<niz.brojElemenata();i++) {
                if(niz[i].first == kljuc) return niz[i].second;
            }
            return TipVrijednosti();
        }
        int brojElemenata  () const{
            return niz.brojElemenata();
        }
        void obrisi() {
            
            int brojEl=niz.brojElemenata();
            if(brojEl==0)return;
            for(int i=0;i<brojEl;i++) niz.obrisi();
        }
        void obrisi(const TipKljuca& kljuc) {
            niz.pocetak();
            bool nema=true;
            for(int i =0;i<niz.brojElemenata();i++ ) {
                if(niz.trenutni().first==kljuc) {
                    nema = false;
                    niz.obrisi();
                    return;
                }
                niz.sljedeci();
            }
            if(nema) throw "Ne postoji taj kljuc";
        }
};

template <typename TipKljuca, typename TipVrijednosti>
class BinStabloMapa : public Mapa<TipKljuca, TipVrijednosti> {
    
    private:
    
    int brElemenata;
    struct Cvor {
        std::pair<TipKljuca, TipVrijednosti> par; 
        Cvor* lijevi;
        Cvor* desni;
        Cvor* roditelj;
        Cvor(const std::pair<TipKljuca, TipVrijednosti> &par, Cvor* lijevi, Cvor* desni, Cvor* roditelj) : par(par), lijevi(lijevi), desni(desni),
        roditelj(roditelj) {};
    };
    Cvor* korijen;
    Cvor* trazi (const TipKljuca& kljuc, Cvor* c) const {
        if(c == 0) return 0; //kljuc se ne nalazi u stablu
        if(kljuc == c->par.first) return c;
        if(kljuc < c->par.first) return trazi(kljuc, c->lijevi);
        return trazi(kljuc, c->desni);
        
    }
    Cvor* dodaj(const std::pair<TipKljuca,TipVrijednosti> &par, Cvor*& c, Cvor* roditelj) {
        if(c == 0) {
            brElemenata++;
            c = new Cvor(par, 0, 0, roditelj);
            return c;
        }
        else if(par.first == c->par.first) return c;
        else if(par.first < c->par.first) return dodaj(par, c->lijevi, c);
        else return dodaj(par, c->desni, c);
    }
    void kopirajElemente(Cvor*& novi, Cvor* stari, Cvor* roditelj) {
        if(stari == 0) return;
        novi = new Cvor(stari->par, 0, 0, roditelj);
        kopirajElemente(novi->lijevi, stari->lijevi, novi);
        kopirajElemente(novi->desni, stari->desni, novi);
        brElemenata++;
    }
    void obrisiElemente(Cvor* c)  {
        if(c == 0) return;
        obrisiElemente(c->lijevi);
        obrisiElemente(c->desni);
        delete c;
        brElemenata--;
    }
    
    public: 
    
    BinStabloMapa() : brElemenata(0), korijen(0) {}
    ~BinStabloMapa() {
        obrisiElemente(korijen);
    }
    BinStabloMapa(const BinStabloMapa<TipKljuca,TipVrijednosti> &bn) {
        brElemenata = 0;
        korijen = 0;
        kopirajElemente(korijen, bn.korijen, 0);
        
    }
    BinStabloMapa<TipKljuca,TipVrijednosti> &operator = (const BinStabloMapa<TipKljuca,TipVrijednosti> &bn) {
        if(this == &bn) return *this;
        obrisiElemente(korijen);
        korijen = 0;
        kopirajElemente(korijen, bn.korijen, 0);
        return *this;
    }
    int brojElemenata() const{
        return brElemenata;
    }
    TipVrijednosti &operator [] (TipKljuca kljuc) {
        std::pair<TipKljuca,TipVrijednosti> par;
        par.first = kljuc;
        par.second = TipVrijednosti();
        Cvor* c = dodaj(par, korijen, 0);
        return c -> par.second;
    }
    TipVrijednosti operator [](TipKljuca kljuc) const {
        Cvor* cvor = trazi(kljuc, korijen);
        if(cvor != 0) return cvor->par.second;
        else return TipVrijednosti();
    }
    void obrisi() {
        obrisiElemente(korijen);
        korijen = 0;
    }
    void obrisi(const TipKljuca& kljuc) {
        Cvor* cvor = trazi(kljuc, korijen);
        obrisiPom(cvor);
    }
    private:
    void obrisiPom(Cvor* cvor) {
        if(cvor == 0) return;
        if(cvor->lijevi != 0 && cvor->desni !=0) {
            //trazimo najveci el u lijevom podstablu
            Cvor* pom = cvor->lijevi;
            while(pom->desni != 0) pom = pom->desni;
            cvor->par.first = pom->par.first;
            cvor->par.second = pom->par.second;
            
            obrisiPom(pom);
        }
        else if(cvor->lijevi == 0 && cvor->desni == 0) {
            if(cvor->roditelj != 0) {
                if(cvor == cvor->roditelj->desni) {
                    cvor->roditelj->desni = 0;
                }
                else cvor->roditelj->lijevi = 0;
            }
            else cvor->roditelj = 0;
            delete cvor;
        }
        else {
            //odredjujemo gdje se nalazi dijete
            Cvor* dijete = cvor->desni;
            if(dijete == 0) dijete = cvor->lijevi;
            
            //povezemo roditelja i dijete
            if(cvor->roditelj != 0) {
                if(cvor == cvor->roditelj->desni) {
                    cvor->roditelj->desni = dijete;
                }
                else cvor->roditelj->lijevi = dijete;
                //povezemo dijete i roditelja
                dijete->roditelj = cvor->roditelj;
            }
            else korijen = dijete;
            
            //konacno brisemo cvor
            delete cvor;
        }
        brElemenata--;

    }
};

unsigned int djbhash(int ulaz, unsigned int max) {
    unsigned int suma = 5381;
    suma = suma*33 + ulaz;
    return suma % max;
}
int main() {
     BinStabloMapa<int,int>m;
    srand(time(NULL));
    
    auto t1 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i<1000; i++) {
        int random = rand()%1000 + 1;
        m[i] = random;
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count();
    std::cout<<"Prosjecna duzina dodavanja novog elementa u ms u BinStabloMapi iznosi "<<duration/1000<<std::endl;

    auto a1 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i<1000; i++) {
        m[i];
    }
    auto a2 = std::chrono::high_resolution_clock::now();
    auto durationa1 = std::chrono::duration_cast<std::chrono::microseconds>(a2-a1).count();
    std::cout<<"Prosjecna duzina pristupa postojecem elementu u ms u BinStabloMapi iznosi "<<durationa1/1000<<std::endl;
    
    
    auto b1 = std::chrono::high_resolution_clock::now();
    m.obrisi();
    auto b2 = std::chrono::high_resolution_clock::now();
    auto durationb1 = std::chrono::duration_cast<std::chrono::microseconds>(b2-b1).count();
    std::cout<<"Prosjecna brisanja elemenata u ms u BinStabloMapi iznosi "<<durationb1/1000<<std::endl;
    
    
    
    NizMapa<int,int>nm;
    
    auto t3 = std::chrono::high_resolution_clock::now();
    
    for(int i = 0; i<1000; i++) {
        int random = rand()%1000 + 1;
        nm[i] = random;
    }
    auto t4 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(t4-t3).count();
    std::cout<<"Prosjecna duzina dodavanja novog elementa u ms u NizMapu iznosi "<<duration2/1000<<std::endl;
    
    
    auto a3 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i<1000; i++) {
        nm[i];
    }
    auto a4 = std::chrono::high_resolution_clock::now();
    auto durationa2 = std::chrono::duration_cast<std::chrono::microseconds>(a4-a3).count();
    std::cout<<"Prosjecna duzina pristupa postojecem elementu u ms u NizMapu iznosi "<<durationa2/1000<<std::endl;


    auto b3 = std::chrono::high_resolution_clock::now();
    nm.obrisi();
    auto b4 = std::chrono::high_resolution_clock::now();
    auto durationb2 = std::chrono::duration_cast<std::chrono::microseconds>(b4-b3).count();
    std::cout<<"Prosjecna brisanja elemenata u ms u NizMapi iznosi "<<durationb2/1000<<std::endl;
    
    
    

HashMapa<int,int> hm;
hm.definisiHashFunkciju(djbhash);
auto t5 = std::chrono::high_resolution_clock::now();

for(int i = 0; i< 1000; i++) {
    int random = rand()%100 + 1;
    hm[i] = random;
}

auto t6 = std::chrono::high_resolution_clock::now();
auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(t6-t5).count();
std::cout<<"Prosjecna duzina dodavanja novog elementa u ms u HashMapu iznosi "<<duration3/1000<<std::endl;

auto a5 = std::chrono::high_resolution_clock::now();
for(int i = 0; i< 1000; i++) {
    hm[i];
}
auto a6 = std::chrono::high_resolution_clock::now();
auto durationa3 = std::chrono::duration_cast<std::chrono::microseconds>(a6-a5).count();
std::cout<<"Prosjecna duzina pristupa elementu u ms u HashMapu iznosi "<<durationa3/1000<<std::endl;

auto b5 = std::chrono::high_resolution_clock::now();
    nm.obrisi();
    auto b6 = std::chrono::high_resolution_clock::now();
    auto durationb3 = std::chrono::duration_cast<std::chrono::microseconds>(b6-b5).count();
    std::cout<<"Prosjecna brisanja elemenata u ms u NizMapi iznosi "<<durationb3/1000<<std::endl;
    
//BinStabloMapu i NizMapu smo poredili u predhodnoj zadaci, 
//pa cu u ovoj akcenat staviti na HashMapu.
//Iz rezultata maina vidimo da ona ima daleko bolje performanse od BinStabloMape i NizMape, a to se 
//najbolje vidi kod dodavanja elementa i pristupa elementu, gdje je vrijeme izvršavanja na 1000 elemenata i do 10 puta manje u odnosu na 
//BinStabloMapu. Kod brisanja i ne mozemo vidjeti preveliku razliku jer je ovo premali broj elemenata za to,
//ali ipak mozemo vidjeti da kod HashMape ono ne traje ni jednu ms, a kod ostalih traje oko 2.

    return 0;
}
