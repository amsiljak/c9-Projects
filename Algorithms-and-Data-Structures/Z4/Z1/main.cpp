#include <iostream>
#include <utility>
#include <chrono>
using namespace std;

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
class AVLStabloMapa : public Mapa<TipKljuca,TipVrijednosti> {
    
    private:
    
    int brElemenata;
    struct Cvor {
        std::pair<TipKljuca, TipVrijednosti> par; 
        Cvor* lijevi;
        Cvor* desni;
        Cvor* roditelj;
        Cvor(const std::pair<TipKljuca, TipVrijednosti> &par/*, Cvor* lijevi, Cvor* desni, Cvor* roditelj*/) : par(par)/* lijevi(lijevi), desni(desni),
        roditelj(roditelj) */{};
        int balans = 0;
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
            c = new Cvor(par);
            return c;
        }
        else if(par.first == c->par.first) return c;
        else if(par.first < c->par.first) return dodaj(par, c->lijevi, c);
        else return dodaj(par, c->desni, c);
    }
    void kopirajElemente(Cvor*& novi, Cvor* stari, Cvor* roditelj) {
        if(stari == 0) return;
        novi = new Cvor(stari->par);
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
    
    AVLStabloMapa() : brElemenata(0), korijen(0) {}
    ~AVLStabloMapa() {
        obrisiElemente(korijen);
    }
    AVLStabloMapa(const AVLStabloMapa<TipKljuca,TipVrijednosti> &bn) {
        brElemenata = 0;
        korijen = 0;
        kopirajElemente(korijen, bn.korijen, 0);
        
    }
    AVLStabloMapa<TipKljuca,TipVrijednosti> &operator = (const AVLStabloMapa<TipKljuca,TipVrijednosti> &bn) {
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
    

    return 0;
}
