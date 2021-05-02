#include <iostream>

template <typename Tip> 
class Cvor {
public:
    Tip x;
    Cvor<Tip>* pok;
    Cvor<Tip>*pred;
    Cvor() {pok = nullptr; pred= nullptr;}
    Cvor (const Tip &x, Cvor<Tip> *pok, Cvor<Tip>*pred) : x(x), pok(pok), pred(pred) {}
};
template <typename Tip>
class DvostraniRed {
private:
    Cvor<Tip>* prvi;
    Cvor<Tip>* krajnji;
    int duzina;
public: 
    DvostraniRed()
    {
        duzina = 0;
        prvi = nullptr;
        krajnji = nullptr;
    };
    DvostraniRed(const DvostraniRed &jl)
    {
        duzina = jl.duzina;
        
        if(jl.duzina == 0) return; 
        
        prvi = new Cvor<Tip> (*jl.prvi);
        
        Cvor<Tip>* temp = prvi; //hocu da prvi ostane na svom mjestu, a preko temp gradim ostatak
        Cvor <Tip>* predhodni = nullptr;
        while (temp -> pok != nullptr) //prolazimo kroz citavu listu
        { //alociramo sve clanove
            temp -> pok = new Cvor<Tip> (*temp -> pok);
            temp -> pred = predhodni;
            predhodni = temp;
            //prelazimo na sljedeci clan
            temp = temp -> pok;
        }
        krajnji = temp;
    }
    int brojElemenata() {
        return duzina;
    }
    ~DvostraniRed()
    {
        Cvor<Tip>* pok1 = prvi;
        while(1) 
        {
            if(prvi == nullptr) {krajnji = nullptr; break;} //ako je trenutni zadnji
            pok1 = prvi -> pok;
            delete prvi;
            prvi = pok1;
        }
    }
    DvostraniRed &operator = (const DvostraniRed &jl)
    {
        if(this == &jl) return *this;
        
       
        Cvor<Tip>* pok1 = prvi;
        while(1)  
        {
            if(prvi == nullptr) {krajnji = nullptr; break;}
            pok1 = prvi -> pok;
            delete prvi;
            prvi = pok1;
        }  
        duzina = jl.duzina;

        if(jl.duzina != 0) 
        {
            prvi = new Cvor<Tip>(*jl.prvi); //iskopiramo prvi
            
            Cvor<Tip>* temp = prvi;
            Cvor<Tip>* predhodni = nullptr;
            while (temp-> pok != nullptr) //prolazimo kroz citavu listu
            { //kopiramo sve clanove
                temp -> pok = new Cvor<Tip>(*temp -> pok);
                temp -> pred = predhodni;
                predhodni = temp; 
                //prelazimo na sljedeci clan
                temp = temp -> pok;
            }
            krajnji = temp;
        }
        else {
            prvi = nullptr;
            krajnji = nullptr;
        }
        return *this;
    }
    void staviNaCelo(const Tip &el) {
        Cvor<Tip>* temp = new Cvor<Tip>;
        temp -> x = el;
        if(duzina == 0) {
            prvi = temp;
            krajnji = temp;
        }
        else {
            krajnji -> pok = temp;
            temp -> pred = krajnji;
            krajnji = temp;
        }
        duzina++;
    }
    Tip skiniSaCela() {
        if(duzina == 0) throw "Red je prazan";
        Tip el = krajnji -> x;
        Cvor<Tip> *temp = krajnji;
        
        krajnji = krajnji -> pred;
        if(krajnji == nullptr) prvi = nullptr;    

        delete temp;
        if(krajnji != nullptr) krajnji -> pok = nullptr;
        duzina--;
        return el;
    }
    void staviNaVrh(const Tip &el) {
        Cvor<Tip>* temp = new Cvor<Tip>;
        temp -> x = el;
        if(duzina == 0) {
            prvi = temp;
            krajnji = temp;
        }
        else {
            prvi -> pred = temp;
            temp -> pok = prvi;
            prvi = temp;
        }
        duzina++;
        // if(prvi -std::cout<<prvi -> x;
    }
    Tip skiniSaVrha() {
        if(duzina == 0) throw "Red je prazna";
        Tip el = prvi -> x;
        
        Cvor<Tip> * temp = prvi;

        prvi = prvi -> pok;
        if(prvi == nullptr) krajnji = nullptr;
        
        delete temp;
        temp = nullptr;
        duzina--;
        return el;
    }
    Tip& vrh() {
        if(duzina == 0) throw "Red je prazan";
        return krajnji -> x;
    }
    Tip& celo() {
        if(duzina == 0) throw "Red je prazan";
        return prvi -> x;
    }
    void brisi() {
        if(duzina == 0) return;
        Cvor<Tip>* pok1 = prvi;
        
        while(1) {
            if(prvi == nullptr) break;
            pok1 = prvi -> pok;
            delete prvi;
            prvi = pok1;
        }
        duzina = 0;
    }
};
int main() {
    DvostraniRed<int> dr;
    for(int i=10;i<=50;i+=10)
    dr.staviNaVrh(i);
    // dr.vrh();
    // dr.brojElemenata();
    // dr.brisi();
    // for(int i = 10;i<=50;i+=10) 
    // dr.staviNaCelo(i);
    // dr.brojElemenata();
    // for(int i=0;i<5;i++) 
    // dr.skiniSaCela();
    // DvostraniRed<int> dr2(dr);
    DvostraniRed<int>dr3(dr);
    // dr3.staviNaVrh(150);
    // (dr3=dr);
    // (dr=dr).brojElemenata();
    // dr.skiniSaVrha();
    for(int i=0;i<dr.brojElemenata();i++) 
    std::cout<<dr.skiniSaVrha()<<"da";   
    std::cout << "Zadaća 2, Zadatak 1";

    return 0;
}
