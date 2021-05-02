#include <iostream>
#include <utility>
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
    virtual TipVrijednosti &operator [](const TipKljuca& kljuc)=0;
    virtual TipVrijednosti operator [](const TipKljuca& kljuc) const=0;
    virtual int brojElemenata() const =0;
    virtual void obrisi() = 0;
    virtual void obrisi(const TipKljuca& kljuc)=0;
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
        TipVrijednosti &operator [](const TipKljuca &kljuc) {
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
        TipVrijednosti operator [](const TipKljuca &kljuc) const {
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
    TipVrijednosti &operator [] (const TipKljuca& kljuc) {
        std::pair<TipKljuca,TipVrijednosti> par;
        par.first = kljuc;
        par.second = TipVrijednosti();
        Cvor* c = dodaj(par, korijen, 0);
        return c -> par.second;
    }
    TipVrijednosti operator [](const TipKljuca& kljuc) const {
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
int main() {
    
    BinStabloMapa<int,int>m;
    srand(time(NULL));
    
    auto t1 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i<5000; i++) {
        int random = rand()%1000 + 1;
        m[i] = random;
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count();
    std::cout<<"Prosjecna duzina dodavanja novog elementa u ms u BinStabloMapi iznosi "<<duration/5000<<std::endl;

    auto a1 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i<5000; i++) {
        m[i];
    }
    auto a2 = std::chrono::high_resolution_clock::now();
    auto durationa1 = std::chrono::duration_cast<std::chrono::microseconds>(a2-a1).count();
    std::cout<<"Prosjecna duzina pristupa postojecem elementu u ms u BinStabloMapi iznosi "<<durationa1/5000<<std::endl;
    
    
    
    
    
    NizMapa<int,int>nm;
    
    auto t3 = std::chrono::high_resolution_clock::now();
    
    for(int i = 0; i<5000; i++) {
        int random = rand()%1000 + 1;
        nm[i] = random;
    }
    auto t4 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(t4-t3).count();
    std::cout<<"Prosjecna duzina dodavanja novog elementa u ms u NizMapu iznosi "<<duration2/5000<<std::endl;
    
    
    auto a3 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i<5000; i++) {
        nm[i];
    }
    auto a4 = std::chrono::high_resolution_clock::now();
    auto durationa2 = std::chrono::duration_cast<std::chrono::microseconds>(a4-a3).count();
    std::cout<<"Prosjecna duzina pristupa postojecem elementu u ms u NizMapu iznosi "<<durationa2/5000<<std::endl;

// U jednom izvršenju programa je dodavanje u BinStabloMapu iznosilo 418 ms, a pristup 414 ms, dok je
//u NizMapi dodavanje iznosilo 494 ms, a pristup 488 ms. Vidimo u ovom primjeru da na 5000 elemenata 
//NizMapa otpirlike u dodavanju troši 76 ms više nego BinStabloMapa, što je oko 18% više vremena. Također, pristup 
//postojećem elementu troši 74 ms više, što je također oko 18% više, pa zaključujemo
//da su performanse BinStabloMape dosta bolje nego performanse NizMape.
    return 0;
}
