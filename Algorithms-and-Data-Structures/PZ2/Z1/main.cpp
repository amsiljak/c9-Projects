#include <iostream>
#include <vector>

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

    NizLista(NizLista &&nl)
    {
        L=nl.L;
        nl.L=nullptr;
        nl.duzina = 0;
        
        kapacitet=nl.kapacitet;
        duzina=nl.duzina;
        tekuci=nl.tekuci;
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
            duzina--;
            for(int i=tekuci; i<duzina ; i++) L[i]=L[i+1];
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
                kapacitet+=78;
                L=new Tip*[kapacitet];
                for(int i=0; i<duzina; i++) L[i]=p[i]; 
                delete[] p;
            }
            for(int i=duzina; i>tekuci+1; i--) L[i]=L[i-1];
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
                kapacitet+=78; //trebalo bi svaki out sve vise dodati npr 100*2
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

template <typename Tip>
class Cvor
{
public:
    Tip x;
    Cvor* pok; //pok na slj element u listi
    Cvor() {}
    Cvor(const Tip &x, Cvor *pok) : x(x), pok(pok) {}
};

template <typename Tip>
class JednostrukaLista : public Lista<Tip>
{
private:
    int duzina;
    Cvor<Tip>* tekuci;
    Cvor<Tip>* prvi;
public:
    JednostrukaLista()
    {
        duzina = 0;
        tekuci = nullptr;
        prvi =nullptr;
    };
    JednostrukaLista(const JednostrukaLista &jl)
    {
        duzina = jl.duzina;
        
        if(jl.duzina == 0) return; //ne treba alocirati tekuci i prvi 
        
        prvi = new Cvor<Tip>(jl.prvi->x, jl.prvi -> pok);
        
        Cvor<Tip>* temp = prvi; //hocu da prvi ostane na svom mjestu, a preko temp gradim ostatak
        
        while (temp -> pok != nullptr) //prolazimo kroz citavu listu
        { //alociramo sve clanove
            temp -> pok = new Cvor<Tip>(*temp -> pok);
            
            //prelazimo na sljedeci clan
            temp = temp -> pok;
        }
    }
    int brojElemenata() const
    {
        return duzina;
    }
    Tip &trenutni() 
    {
        if(duzina == 0) throw "Lista je prazna";
        return tekuci->x;
    } 
    bool prethodni()
    {
        if(duzina==0) throw "Lista je prazna";
        
        if(tekuci==prvi) return false;
        
        Cvor<Tip>*pok1 = prvi;
        while (pok1 -> pok != tekuci) pok1 = pok1 -> pok; //pok1 postaje el prije tekuceg
        tekuci = pok1;
        return true;
    }
    Tip trenutni() const
    {
        if(duzina==0) throw "Lista je prazna";
        return tekuci->x;
    }

    bool sljedeci()
    {
        if(duzina == 0) throw "Lista je prazna";
        
        if(tekuci -> pok == nullptr) return false;
        
        tekuci = tekuci->pok;
        return true;
    }
    void pocetak() {
        if(duzina == 0) throw "Lista je prazna";
        tekuci = prvi;
    }
    
    void obrisi()
    {
        if(duzina == 0) throw "Lista je prazna";
        if(tekuci == prvi)  //ako se brise prvi el
        {
            tekuci = prvi -> pok;
            delete prvi;
            prvi = tekuci;
        }
        else
        {
            Cvor<Tip>* pok1 = prvi;

            while(1) {
                if(pok1 -> pok == tekuci) break;
                pok1 = pok1 -> pok;
            } //dolazi do pred tekuceg
            pok1 -> pok = tekuci -> pok; 
            delete tekuci;
            
            if(pok1 -> pok == nullptr) tekuci = pok1; //ako je obrisani bio zadnji onaj prije njega postae tekuci
            else tekuci = pok1 -> pok;
        }
        duzina--;
    }
    void kraj() {
        if(duzina == 0) throw "Lista je prazna";
        while(tekuci -> pok != nullptr) tekuci = tekuci->pok;
    }
    void dodajIspred(const Tip& el) {

        if(duzina == 0) {
            Cvor<Tip>* temp = new Cvor<Tip>;
            temp -> x = el;
            temp -> pok = prvi;
            prvi = temp;
            tekuci = prvi;
        }
        else if (prvi == tekuci) 
        {
            Cvor<Tip>* temp = new Cvor<Tip>; //smijemo alocirati jer ce kasnije prvi postati on
            temp -> x = el;
            temp -> pok = prvi; //ubacujemo el
            prvi = temp; //stavljamo da je prvi novi el 
        }
        else 
        {
            Cvor<Tip>* prije_trenutnog = prvi;
            Cvor<Tip>* novi_el = new Cvor<Tip>;
            
            novi_el -> x = el;
            
            while(prije_trenutnog -> pok != tekuci) prije_trenutnog = prije_trenutnog -> pok;
            prije_trenutnog -> pok = novi_el;
            novi_el -> pok = tekuci;
            
        }
        duzina++ ;
    }
    void dodajIza(const Tip& el) 
    {
        if(duzina == 0) //ako je lista prazna
        {
            Cvor<Tip>* novi_el = new Cvor<Tip>(el,0);
            
            prvi = novi_el;
            tekuci = novi_el;
        }
        else
        {
            Cvor<Tip>* novi_el = new Cvor<Tip>(el, tekuci->pok);
            
            tekuci -> pok = novi_el;
        }
        duzina++;
    }
    Tip operator [](int indeks) const
    {
        if(indeks<0 || indeks>=duzina) throw "Neispravan indeks";
        Cvor<Tip>* temp = prvi;
        for(int j=0; j<indeks; j++) 
        {
            temp = temp -> pok;
        }
        return temp -> x;
    }
    Tip &operator [](int indeks)
    {
        if(indeks<0 || indeks>=duzina) throw "Neispravan indeks";
        Cvor<Tip>* temp = prvi;
        for(int j=0; j<indeks; j++) 
        {
            temp = temp -> pok;
        }
        return temp -> x;
    }
    ~JednostrukaLista()
    {
        Cvor<Tip>* pok1 = prvi;
        while(1) 
        {
            if(prvi == nullptr) break; //ako je trenutni pok1 bio zadnji
            pok1 = prvi -> pok;
            delete prvi;
            prvi = pok1;
        }
    }
    JednostrukaLista &operator = (const JednostrukaLista &jl)
    {
        if(this == &jl) return *this;
        
        if(jl.duzina != 0) 
        {
            Cvor<Tip>* pok1 = prvi;
            while(1)  
            {
                if(prvi == nullptr) break;
                pok1 = prvi -> pok;
                delete prvi;
                prvi = pok1;
            } 
        
            prvi = new Cvor<Tip>(jl.prvi -> x, jl.prvi -> pok); //iskopiramo prvi
            duzina = jl.duzina;
            
            Cvor<Tip>* temp = prvi;
            while (temp-> pok != nullptr) //prolazimo kroz citavu listu
            { //kopiramo sve clanove
                temp -> pok = new Cvor<Tip>(temp -> pok -> x, temp -> pok -> pok);
                
                //prelazimo na sljedeci clan
                temp = temp -> pok;
            }
        }
        return *this;
    }
    

};

bool Test1() 
{
    NizLista<double>nizlista;
    if(nizlista.brojElemenata()!=0) return false;
    nizlista.dodajIza(3);
    nizlista.dodajIza(8.4);
    if(nizlista.trenutni()!=3) return false;
    nizlista.sljedeci();
    if(nizlista.trenutni()!=8.4) return false;
    return true;
}
bool Test2()
{
    NizLista<int> nizlista;
    nizlista.dodajIza(5);
    nizlista.dodajIza(6);
    nizlista.obrisi();
    if(nizlista[0] != 6) return false;
    nizlista.dodajIspred(2);
    nizlista.prethodni();
    if(nizlista.trenutni()!= 2) return false;
    return true;
}
bool Test3()
{
    NizLista<int>nizlista;
    nizlista.dodajIspred(2);
    nizlista.dodajIspred(3);
    nizlista.dodajIspred(4);
    nizlista.dodajIspred(5);
    nizlista.pocetak();
    if(nizlista.trenutni()!=3) return false;
    nizlista.kraj();
    if(nizlista.trenutni()!=2) return false;
    return true;
}
bool Test4()
{
    JednostrukaLista<int>jednostrukalista;
    jednostrukalista.dodajIspred(2);
    jednostrukalista.dodajIza(3);
    jednostrukalista.sljedeci();
    if(jednostrukalista.trenutni() != 3) return false;
    jednostrukalista.dodajIza(4);
    jednostrukalista.kraj();
    if(jednostrukalista.trenutni() != 4) return false;
    return true;
}
bool Test5() 
{
    JednostrukaLista<int>jednostrukalista;
    jednostrukalista.dodajIspred(2);
    jednostrukalista.dodajIspred(1);
    if(jednostrukalista[0] != 1) return false;
    jednostrukalista.pocetak();
    if(jednostrukalista.trenutni() != 1) return false;
    jednostrukalista.obrisi();
    if(jednostrukalista.trenutni() != 2) return false;
    return true;
}
bool Test6()
{
    JednostrukaLista<double>jednostrukalista;
    jednostrukalista.dodajIza(2);
    jednostrukalista.dodajIspred(3);
    jednostrukalista.prethodni();
    if(jednostrukalista.trenutni() != 3) return false;
    if(jednostrukalista.brojElemenata() != 2) return false;
    return true;
}
int main()
{
    //testovi za nizlistu
    // if(Test1()) std::cout<<"OK"<<std::endl;
    // else std::cout<<"NIJE OK"<<std::endl;
    
    // if(Test2()) std::cout<<"OK"<<std::endl;
    // else std::cout<<"NIJE OK"<<std::endl;
    
    // if(Test3()) std::cout<<"OK"<<std::endl;
    // else std::cout<<"NIJE OK"<<std::endl;
    
    // //testovi za jednostruku
    // if(Test4()) std::cout<<"OK"<<std::endl;
    // else std::cout<<"NIJE OK"<<std::endl;
    
    // if(Test5()) std::cout<<"OK"<<std::endl;
    // else std::cout<<"NIJE OK"<<std::endl;

    // if(Test6()) std::cout<<"OK"<<std::endl;
    // else std::cout<<"NIJE OK"<<std::endl;
    
    JednostrukaLista<int> lista;
    for(int i= 1;i<=5;i++) lista.dodajIspred(i);
    JednostrukaLista<int>lista2(lista);
    JednostrukaLista<int>lista3;
    lista3=lista;
    lista3.trenutni()=2;
    lista.obrisi();
    return 0;
}
