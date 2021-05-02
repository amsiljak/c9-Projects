#include <iostream>

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
class Cvor
{
public:
    Tip x;
    Cvor<Tip>* pok ; //pok na slj element u listi
    Cvor<Tip>* pred ;
    Cvor<Tip>() {
        pok = nullptr;
        pred = nullptr;
    }
    Cvor<Tip>(const Cvor<Tip> &c) {
        x = c.x;
        pok = c.pok;
        pred = c.pred;
    }
};
template <typename Tip>
class DvostrukaLista : public Lista<Tip>
{
private:
   
    int duzina;
    Cvor<Tip>* tekuci;
    Cvor<Tip>* prvi;
    Cvor<Tip>* krajnji;
public:
    DvostrukaLista()
    {
        duzina = 0;
        tekuci = nullptr;
        prvi = nullptr;
        krajnji = nullptr;
    };
    DvostrukaLista(const DvostrukaLista &jl)
    {
        duzina = jl.duzina;
        
        if(jl.duzina == 0) return; 
        
        prvi = new Cvor<Tip> (*jl.prvi);
        
        Cvor<Tip>* temp = prvi; //hocu da prvi ostane na svom mjestu, a preko temp gradim ostatak
        
        while (temp -> pok != nullptr) //prolazimo kroz citavu listu
        { //alociramo sve clanove
            temp -> pok = new Cvor<Tip> (*temp -> pok);
            
            //prelazimo na sljedeci clan
            temp = temp -> pok;
        }
        krajnji = temp;
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
        if(duzina == 0) throw "Lista je prazna";

        if(tekuci -> pred == nullptr) return false;
        tekuci = tekuci -> pred;
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
            Cvor<Tip>* pok1 = prvi -> pok;
            delete prvi;
            prvi = pok1;
            tekuci = pok1;
            // ne treba provjeriti je li tekuci bio posljednji jer svakako nema el prije njega
        }
        else
        {
            Cvor<Tip>* pok1 = tekuci -> pred;
            
            pok1 -> pok = tekuci -> pok;
            if(tekuci -> pok != nullptr)
            tekuci -> pok -> pred = pok1;

            //pok1 je el prije tekuceg ciji pok pokazuje na el poslije tekuceg
            delete tekuci;
            
            if(pok1 -> pok == nullptr) tekuci = pok1; //ako je obrisani bio zadnji onaj prije njega postae tekuci
            else tekuci = pok1 -> pok;
        }
        duzina--;
    }
    void kraj() {
        if(duzina == 0) throw "Lista je prazna";
        tekuci = krajnji;
    }
    void dodajIspred(const Tip& el) {

        if(duzina == 0) { //prazna lista
            Cvor<Tip>* temp = new Cvor<Tip>;
            temp -> x = el;
            prvi = temp;
            tekuci = temp;
            krajnji = temp;
        }
        else if (tekuci == prvi) 
        {
            Cvor<Tip>* temp = new Cvor<Tip>;
            temp -> pok = tekuci;
            temp -> x = el;
            
            tekuci -> pred = temp;
            prvi = temp;
        }
        else 
        {
            Cvor<Tip>* temp = new Cvor<Tip>;
            temp -> x = el;
            temp -> pok = tekuci;
            temp -> pred = tekuci -> pred;
            
            tekuci -> pred -> pok = temp;
            tekuci -> pred = temp;
            
            //ide prije_trenutnog, novi el, trenutni
        }  
        duzina++;
    }
    void dodajIza(const Tip& el) 
    {
        if(duzina == 0) //ako je lista prazna
        {
            Cvor<Tip>* temp = new Cvor<Tip>;
            temp -> x = el;
            prvi = temp;
            tekuci = prvi;
            krajnji = temp;
        }
        else
        { //ima elemenata
            Cvor<Tip>* temp = new Cvor<Tip>;
            temp -> x = el;
            temp -> pred = tekuci;
            temp -> pok = tekuci -> pok;
            
            tekuci -> pok = temp;
            
            if(tekuci == krajnji) krajnji = tekuci -> pok;
            if(temp -> pok != nullptr) {
                temp -> pok -> pred = temp;
            }
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
    ~DvostrukaLista()
    {
        Cvor<Tip>* pok1 = prvi;
        while(1) 
        {
            if(prvi == nullptr) break; //ako je trenutni zadnji
            pok1 = prvi -> pok;
            delete prvi;
            prvi = pok1;
        }
    }
    DvostrukaLista &operator = (const DvostrukaLista &jl)
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
        
            prvi = new Cvor<Tip>(*jl.prvi); //iskopiramo prvi
            duzina = jl.duzina;
            
            Cvor<Tip>* temp = prvi;
            while (temp-> pok != nullptr) //prolazimo kroz citavu listu
            { //kopiramo sve clanove
                temp -> pok = new Cvor<Tip>(*temp -> pok);
                
                //prelazimo na sljedeci clan
                temp = temp -> pok;
            }
        }
        else {
            prvi = nullptr;
            krajnji = nullptr;
            tekuci = nullptr;
        }
        return *this;
    }
};
template<typename Tip>
Tip dajMaksimum(const Lista<Tip>& n) {
    DvostrukaLista<Tip> l = DvostrukaLista<Tip>(*((DvostrukaLista<Tip>*)(&n)));
    
    Tip maksimum;
    l.pocetak();
    maksimum = l.trenutni();
    do {
        if(l.trenutni() > maksimum) maksimum = l.trenutni();
    } while(l.sljedeci());
    
    return maksimum;
}
bool Test1() {
    DvostrukaLista<int> dl;
    for(int i=0;i<5;i++) dl.dodajIspred(i);
    if(dl.trenutni() == 0) return true;
    return false;
}

bool Test2() {
    DvostrukaLista<int> dl;
    for(int i=0;i<5;i++) dl.dodajIza(i);
    dl.sljedeci();
    if(dl.trenutni() == 4) return true;
    return false;
}

bool Test3() {
    DvostrukaLista<int>dl;
    dl.dodajIspred(2);
    dl[0] = 1;
    if(dl.trenutni() == 1) return true;
    return false;
}
bool Test4() {
    DvostrukaLista<int> dl;
    for(int i=0;i<6;i++) dl.dodajIspred(i);
    dl.kraj();
    dl.trenutni() = 2;
    if(dl.trenutni() == 2) return true;
    return false;
}
bool Test5() {
    DvostrukaLista<int> dl;
    for(int i = 0;i<3;i++) dl.dodajIspred(i);
    dl.prethodni();
    dl.prethodni();
    dl.obrisi();
    dl.pocetak();
    if(dl.trenutni() == 2) return true;
    return false;
}
bool Test6() {
    DvostrukaLista<int> dl;
    for(int i = 0;i<5;i++) dl.dodajIspred(i);
    DvostrukaLista<int>dl2(dl);
    if(dl2.brojElemenata() == 5) return true;
    return false;
}
bool Test7() {
    DvostrukaLista<int>dl;
    for(int i = 0;i<5; i++) dl.dodajIza(i);
    if(dajMaksimum(dl) == 4) return true;
    return false;
}
int main() {
    if(Test1()) std::cout<<"OK"<<std::endl;
    else std::cout<<"NIJE OK"<<std::endl;
    
    if(Test2()) std::cout<<"OK"<<std::endl;
    else std::cout<<"NIJE OK"<<std::endl;
    
    if(Test3()) std::cout<<"OK"<<std::endl;
    else std::cout<<"NIJE OK"<<std::endl;
    
    if(Test4()) std::cout<<"OK"<<std::endl;
    else std::cout<<"NIJE OK"<<std::endl;
    
    if(Test5()) std::cout<<"OK"<<std::endl;
    else std::cout<<"NIJE OK"<<std::endl;
    
    if(Test6()) std::cout<<"OK"<<std::endl;
    else std::cout<<"NIJE OK"<<std::endl;
    
    if(Test7()) std::cout<<"OK"<<std::endl;
    else std::cout<<"NIJE OK"<<std::endl;
    return 0;
}
