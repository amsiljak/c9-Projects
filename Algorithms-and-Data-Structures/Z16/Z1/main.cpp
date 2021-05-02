#include <iostream>
#include <string>
#include <utility>
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
    virtual TipVrijednosti &operator [](const TipKljuca kljuc)=0;
    virtual TipVrijednosti operator [](const TipKljuca kljuc) const=0;
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
        // void obrisi(const TipKljuca& kljuc) {
            
        // }
};

bool Test1() {
    NizMapa<std::string,std::string> mapa;
    mapa["Angelina"]="Jolie";
    NizMapa<std::string,std::string>nova(mapa);
    if(nova.brojElemenata()!=1) return false;
    nova.obrisi("Angelina");
    if(nova.brojElemenata()!=0) return false;
    return true;
}
bool Test2(){
    NizMapa<int,int> mapa;
    mapa[0]=1;
    mapa[1]=2;
    if(mapa.brojElemenata()!=2) return false;
    mapa.obrisi();
    if(mapa.brojElemenata()!=0) return false;
    return true;
}
bool Test3() {
    NizMapa<double,double> mapa;
    mapa[3.4]=3.2;
    mapa[5.666]=2;
    mapa[3.4]=5.5;
    if(mapa[3.4]!=5.5) return false;
    return true;
}
bool Test4() {
    NizMapa<char,char> mapa;
    mapa['A']='B';
    mapa['B']='C';
    mapa['C']='D';
    mapa['D']='E';
    mapa.obrisi('B');
    mapa.obrisi('C');
    if(mapa.brojElemenata()!=2) return false;
    mapa['B']='C';
    if(mapa.brojElemenata()!=3) return false;
    return true;
}
bool Test5() {
    NizMapa<std::string,int>mapa;
    mapa["Travnik"]=10;
    mapa["Sarajevo"]=1;
    mapa["Reykjavik"]=10;
    if(mapa["Travnik"]!=mapa["Reykjavik"] ) return false;
    mapa["Travnik"]=100;
    if(mapa["Travnik"]==mapa["Reykjavik"]) return false;
    return true;
}


int main() {
    // minimalno pet testnih funkcija u kojim testirate osobine NizMape sa različitim tipovima
//ključa i vrijednosti
if(Test1()) std::cout<<"OK"<<std::endl;
else std::cout<<"NIJE OK"<<std::endl;

if(Test2()) std::cout<<"OK" <<std::endl;
else std::cout<<"NIJE OK"<<std::endl;

if(Test3()) std::cout<<"OK"<<std::endl;
else std::cout<<"NIJE OK"<<std::endl;

if(Test4()) std::cout<<"OK"<<std::endl;
else std::cout<<"NIJE OK"<<std::endl;

if(Test5()) std::cout<<"OK"<<std::endl;
else std::cout<<"NIJE OK"<<std::endl;

    return 0;
}
