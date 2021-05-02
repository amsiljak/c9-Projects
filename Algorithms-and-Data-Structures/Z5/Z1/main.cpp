#include <iostream>
#include <vector>
#include <utility>
#include <list>
using namespace std;

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
class HashMapaLan : public Mapa<TipKljuca,TipVrijednosti> {
    std::vector<std::list<pair<TipKljuca,TipVrijednosti>>*> elements;
    int brElemenata;
    unsigned int (*pok)(TipKljuca, unsigned int);
public:
    HashMapaLan(const HashMapaLan<TipKljuca,TipVrijednosti> &hml) : elements(hml.elements.size()) {
        brElemenata = hml.brElemenata;
        pok = hml.pok;
        
        for(int i = 0; i < elements.size(); i++) {
            if(hml.elements[i] != nullptr) elements[i] = new std::list<pair<TipKljuca,TipVrijednosti>> (*hml.elements[i]);
        }
    }
    HashMapaLan() : elements(5000) {
        brElemenata = 0;
        pok = nullptr;
    }
    ~HashMapaLan() {
        for(int i = 0; i < elements.size(); i++) {
            delete elements[i];
        }
    }
    HashMapaLan& operator = (const HashMapaLan<TipKljuca,TipVrijednosti> &hml) {
        if(this == &hml) return *this;
        
        this -> obrisi();
        brElemenata = hml.brElemenata;
        pok = hml.pok;
        elements.resize(hml.elements.size(), nullptr);
        
        for(int i = 0; i < elements.size(); i++) 
            if(hml.elements[i] != nullptr) elements[i] = new std::list<pair<TipKljuca,TipVrijednosti>>(*hml.elements[i]);
        return *this;
    }
    int brojElemenata() const {
        return brElemenata;
    }
    void obrisi() {
        for(int i = 0; i < elements.size(); i++) {
            delete elements[i];
            elements[i] = nullptr;
        }
        brElemenata = 0;
        //!!!!!!!!
    }
    void obrisi(const TipKljuca& kljuc) {
        if(pok == nullptr) throw "Greska";
        unsigned int indeks = pok(kljuc, elements.size());
        if(elements[indeks] == nullptr) throw "Nije pronadjen";
        
        for (auto i = elements[indeks] -> begin(); i != elements[indeks]->end(); i++) {
            if(i -> first == kljuc) {
                elements[indeks] -> erase(i);
                
                if(elements[indeks] -> empty()) {
                    delete elements[indeks];
                    elements[indeks] = nullptr;
                }
                brElemenata--;
                return;
            }
        }
        throw "Nije pronadjen";
    }
    TipVrijednosti operator [] (TipKljuca kljuc) const {
        if(pok == nullptr) throw "Greska";
        unsigned int indeks = pok(kljuc, elements.size());
        if(elements[indeks] == nullptr) return TipVrijednosti();
        for(auto i = elements[indeks] -> begin(); i != elements[indeks] -> end(); i++) if(i -> first == kljuc) return i -> second;
        return TipVrijednosti();
    }
    TipVrijednosti& operator [](TipKljuca kljuc) {
        if(pok == nullptr) throw "Greska";
        unsigned int indeks = pok(kljuc, elements.size());
        if(elements[indeks] != nullptr)  {
            auto i = elements[indeks]->begin();
            for(; i != elements[indeks]->end(); i++) if(i -> first == kljuc) return i->second;
            while (i->first < kljuc && i != elements[indeks]->end()) i++;
            brElemenata++;
            return(elements[indeks]->insert(i, pair<TipKljuca,TipVrijednosti>(kljuc, TipVrijednosti())))->second;
        }
        else {
            elements[indeks] = new std::list<pair<TipKljuca,TipVrijednosti>>{pair<TipKljuca,TipVrijednosti>(kljuc,TipVrijednosti())} ;
            brElemenata++;
            return elements[indeks]->begin()->second;
        }
    }
    void definisiHashFunkciju(unsigned int (*pokk)(TipKljuca, unsigned int)) {
        pok = pokk;
    }
};

template<typename TipOznake> 
class Grana;
template<typename TipOznake>
class Cvor;
template <typename TipOznake> 
class ListaGraf;
template <typename TipOznake>
class GranaIterator;

template <typename TipOznake>
class UsmjereniGraf {
    public:
    virtual ~UsmjereniGraf(){}
    virtual int dajBrojCvorova() = 0;
    virtual void postaviBrojCvorova(int broj_cvorova) = 0;
    virtual void dodajGranu(int pol, int dol, float weight) = 0;
    virtual void obrisiGranu(int pol, int dol) = 0;
    virtual void postaviTezinuGrane(int pol, int dol, float weight) = 0;
    virtual float dajTezinuGrane(int pol, int dol) = 0;
    virtual bool postojiGrana(int pol, int dol) = 0;
    virtual void postaviOznakuCvora(int br, TipOznake oznaka) = 0;
    virtual TipOznake dajOznakuCvora(int br) = 0;
    virtual void postaviOznakuGrane(int pol, int dol, TipOznake oznaka) = 0;
    virtual TipOznake dajOznakuGrane(int pol, int dol) = 0;
    virtual Grana<TipOznake> dajGranu(int pol, int dol) = 0;
    virtual Cvor<TipOznake> dajCvor(int br) = 0;
    virtual GranaIterator<TipOznake> dajGranePocetak() = 0;
    virtual GranaIterator<TipOznake> dajGraneKraj() = 0;
};   
template <typename TipOznake>
class Cvor {
    TipOznake oznaka;
    int redni_broj;
    UsmjereniGraf<TipOznake> *pok;
public:    
    Cvor() : oznaka(TipOznake()), pok(nullptr), redni_broj(0) {}
    Cvor(TipOznake oznaka, int redni_broj, UsmjereniGraf<TipOznake> *pok) : oznaka(oznaka), redni_broj(redni_broj),pok(pok) {}
    int dajRedniBroj() {
        return redni_broj;
    }
    TipOznake dajOznaku() {
        return oznaka;
    }
    void postaviOznaku(TipOznake oznaka1) {
        pok -> postaviOznakuCvora(redni_broj, oznaka1);
    }
    void postaviOznaku1(TipOznake oznaka1) {
        oznaka = oznaka1;
    }
    friend class Grana<TipOznake>;
};
template <typename TipOznake>
class Grana {
    float tezina;
    TipOznake oznaka;
    
    Cvor<TipOznake> *pol;
    Cvor<TipOznake> *dol;
public:
    Grana(float tezina, TipOznake oznaka, Cvor<TipOznake> *pol, Cvor<TipOznake>* dol) :  tezina(tezina), oznaka(oznaka),pol(pol), dol(dol) {}
    Grana() : oznaka(TipOznake()), tezina(0), pol(nullptr), dol(nullptr) {}
    Cvor<TipOznake> dajPolazniCvor() {
        return *pol;
    }
    Cvor<TipOznake> dajDolazniCvor() {
        return *dol;
    }
    TipOznake dajOznaku() {
        return oznaka;
    }
    float dajTezinu() {
        return tezina;
    }
    void postaviTezinu(float tezina1) {
        pol->pok->postaviTezinuGrane(pol->dajRedniBroj(), dol->dajRedniBroj(), tezina1);
    }
    void postaviTezinu1(float tezina1) {
        tezina = tezina1;
    }
    void postaviOznaku(TipOznake oznaka) {
        pol->pok->postaviOznakuGrane(pol->dajRedniBroj(), dol->dajRedniBroj(), oznaka);
    }
    void postaviOznaku1(TipOznake oznaka1) {
        oznaka = oznaka1;
    }
    bool isti(int pol1, int dol1) {
        if(dol1 == dol->dajRedniBroj() && pol1 == pol->dajRedniBroj()) return true;
        return false;
    }
};


template <typename TipOznake>
class ListaGraf : public UsmjereniGraf<TipOznake> {
protected:
    std::vector<vector<Grana<TipOznake>*>> lista;
    std::vector<Cvor<TipOznake>*> cvorovi;
    int brPosjecenih = 0;
public:
    ListaGraf(int brCvorova) {
        lista.resize(brCvorova);     
        cvorovi.resize(brCvorova, nullptr);

        for(int i = 0; i < brCvorova; i++) cvorovi[i] = new Cvor<TipOznake>(TipOznake(), i, this);
    }
    ~ListaGraf() {
        for(int i = 0; i< cvorovi.size(); i++) {
            delete cvorovi[i];
        }
        for(int i = 0; i < lista.size(); i++) {
            for(int j = 0; j < lista[i].size(); j++) delete lista[i][j];
        }
    }
    Grana<TipOznake> dajGranu(int pol, int dol) {
        if(!(dol > cvorovi.size() || pol > cvorovi.size())) {
            for(int i = 0; i < lista[pol].size(); i++) {
                if(lista[pol][i] -> isti(pol, dol)) return *lista[pol][i];
            }
        }
        throw "Greska";
    }
    Cvor<TipOznake> dajCvor(int br) {
        if(cvorovi[br] != nullptr) return *cvorovi[br];
        throw "Ne postoji cvor";
    }
    TipOznake dajOznakuGrane(int pol, int dol) {
        if(!(dol > cvorovi.size() || pol > cvorovi.size())) {
            for(int i = 0; i < lista[pol].size(); i++) 
                if(lista[pol][i] -> isti(pol,dol)) return lista[pol][i]->dajOznaku();
        }
        throw "Ne postoji grana";
    }
    TipOznake dajOznakuCvora(int br) {
        if(cvorovi[br] != nullptr) return cvorovi[br]->dajOznaku();
        throw "Ne postoji cvor";
    }
    float dajTezinuGrane(int pol, int dol) {
        if(!(dol > cvorovi.size() || pol > cvorovi.size())) {
            for(int i = 0; i < lista[pol].size(); i++) 
                if(lista[pol][i] -> isti(pol,dol)) return lista[pol][i]->dajTezinu();
        }
        throw "Ne postoji grana";
    }
    int dajBrojCvorova() {
        return cvorovi.size();
    }
    void postaviBrojCvorova(int br) {
        if(cvorovi.size() > br) throw "Ne moze se smanjiti";
        int brCv = cvorovi.size();
        cvorovi.resize(br, nullptr);
        for(int i = brCv; i < br; i++)  cvorovi[i] = new Cvor<TipOznake>(TipOznake(), i, this);
        lista.resize(br);
    }
    void postaviTezinuGrane(int pol, int dol, float tezina) {
        if(!(dol > cvorovi.size() || pol > cvorovi.size())) {
            for(int i = 0; i < lista[pol].size(); i++) 
                if(lista[pol][i] -> isti(pol,dol)) {
                    lista[pol][i]->postaviTezinu1(tezina);
                    return;
                }
        }
        throw "Ne postoji grana";
    }
    void postaviOznakuCvora(int br, TipOznake oznaka) {
        if(cvorovi[br] != nullptr) {cvorovi[br]->postaviOznaku1(oznaka);
        return;}
        throw "Ne postoji cvor";
    }
    void postaviOznakuGrane(int pol, int dol, TipOznake oznaka) {
        if(!(dol > cvorovi.size() || pol > cvorovi.size())) {
            for(int i = 0; i < lista[pol].size(); i++) 
                if(lista[pol][i] -> isti(pol,dol)) {
                    lista[pol][i]->postaviOznaku1(oznaka);
                    return;
                }
        }
        throw "Ne postoji grana";
    }
    void dodajGranu(int pol, int dol, float tezina) {
        if(cvorovi.size() < pol) throw "Greska";
        lista[pol].push_back(new Grana<TipOznake>(tezina, TipOznake(), cvorovi[pol],cvorovi[dol]));
    }
    void obrisiGranu(int pol, int dol) {
        if(!(dol > cvorovi.size() || pol > cvorovi.size())) {
            for(int i = 0; i < lista[pol].size(); i++) 
                if(lista[pol][i] -> isti(pol,dol)) {
                    delete lista[pol][i];
                    lista[pol].erase(lista[pol].begin()+i);
                    return;
                }
        }
        throw "Ne postoji grana";
    }
    bool postojiGrana(int pol, int dol) {
         if(!(dol > cvorovi.size() || pol > cvorovi.size())) {
            for(int i = 0; i < lista[pol].size(); i++) 
                if(lista[pol][i] -> isti(pol,dol)) {
                    return true;
                }
        }
        return false;   
    }
    virtual GranaIterator<TipOznake> dajGraneKraj() {
        for(int i = lista.size() - 1; i > 0; i--) {
            for(int j = lista[i].size() - 1; j > 0; j--) {
                if(lista[i][j] != nullptr) {
                    if(lista[i].size() - 1 > j) return GranaIterator<TipOznake>(this,i, j+1);
                    else return GranaIterator<TipOznake>(this,i+1,0);
                }
            }
        }
        return GranaIterator<TipOznake>(this, lista.size() - 1, lista[lista.size() - 1].size() - 1);
    }
    virtual GranaIterator<TipOznake> dajGranePocetak() {
        for(int i = 0; i < lista.size(); i++) {
            for(int j = 0; j < lista[i].size(); j++) {
                if(lista[i][j] != nullptr) return GranaIterator<TipOznake>(this, i, j);
            }
        }
        return GranaIterator<TipOznake>(this, 0, 0);
    }
    template <typename TipOznake1>
    friend void dfs(UsmjereniGraf<TipOznake1>*gr, std::vector<Cvor<bool>> &o, Cvor<TipOznake1> cv);
    
    template <typename TipOznake1>
    friend void bfs(UsmjereniGraf<TipOznake1>*gr, std::vector<Cvor<bool>> &o, Cvor<TipOznake1> cv, int slj);
    
    friend GranaIterator<TipOznake>;
};
template <typename TipOznake1>
void bfs(UsmjereniGraf<TipOznake1> *gr, vector<Cvor<bool>> &o, Cvor<TipOznake1> cv, int slj = 0) {
    ListaGraf<TipOznake1> *matrica1 = dynamic_cast<ListaGraf<TipOznake1>*>(gr);
    auto p = TipOznake1(1);
    if(matrica1->dajBrojCvorova() == matrica1->brPosjecenih ) {
        matrica1->brPosjecenih = 0;
        return;
    }
    if(p != matrica1->cvorovi[cv.dajRedniBroj()]->dajOznaku()) {
        o.push_back(cv);
        matrica1->cvorovi[cv.dajRedniBroj()]->postaviOznaku(p);
        matrica1->brPosjecenih++;
    }
    for(int i = 0; i < matrica1->lista[cv.dajRedniBroj()].size(); i++) {
        if(matrica1->lista[cv.dajRedniBroj()][i]->dajDolazniCvor().dajOznaku() != p) {
            matrica1->lista[cv.dajRedniBroj()][i]->dajDolazniCvor().postaviOznaku(p);
            o.push_back(matrica1->lista[cv.dajRedniBroj()][i]->dajDolazniCvor());
            matrica1->brPosjecenih++;
        }
    }
    bfs(gr, o, o[++slj], slj);
}
template <typename TipOznake1>
void dfs(UsmjereniGraf<TipOznake1> *gr, vector<Cvor<bool>> &o, Cvor<TipOznake1> cv) {
    ListaGraf<TipOznake1> *matrica1 = dynamic_cast<ListaGraf<TipOznake1>*>(gr);
    auto p = TipOznake1(1);//!!!
    o.push_back(cv);
    matrica1->cvorovi[cv.dajRedniBroj()]->postaviOznaku(p);
    matrica1->brPosjecenih++;
    
    for(int i = 0; i < matrica1->lista[cv.dajRedniBroj()].size(); i++) {
        if(matrica1->lista[cv.dajRedniBroj()][i]->dajDolazniCvor().dajOznaku() != p)
        dfs(gr, o, matrica1->lista[cv.dajRedniBroj()][i]->dajDolazniCvor());
    }
    if(matrica1->dajBrojCvorova() > matrica1->brPosjecenih) {
        for(int i = 0; i < matrica1->lista.size(); i++) {
            for(int j = 0; j < matrica1->lista[i].size(); j++) {
                if(matrica1->lista[i][j]->dajDolazniCvor().dajOznaku()!=p && matrica1->lista[i][j] != nullptr) {
                    if(matrica1->cvorovi[i]->dajOznaku() != p) {
                        matrica1->cvorovi[i]->postaviOznaku(p);
                        o.push_back(*matrica1->cvorovi[i]);
                    }
                    dfs(gr, o, matrica1->lista[i][j]->dajDolazniCvor());
                }
            }
        }
    }
    if(matrica1->dajBrojCvorova() == matrica1->brPosjecenih) matrica1->brPosjecenih=0;
}
template <typename TipOznake>
class GranaIterator {
    ListaGraf<TipOznake> *lista;
    int pol;
    int dol;
public:
    GranaIterator(ListaGraf<TipOznake> *pok, int pol1, int dol1) : lista(pok){
        pol = pol1;
        dol = dol1;
    }
    bool operator != (const GranaIterator &i) const {
        if(i.pol == pol && i.dol == dol && i.lista == lista) return false;
        return true;
    }
    bool operator == (const GranaIterator &i) const {
        if(i.pol == pol && i.dol == dol && i.lista == lista) return true;
        return false;
    }
    Grana<TipOznake> operator *() {
        return *lista->lista[pol][dol];
        throw "Greska";
    }
    GranaIterator operator ++(int) {
        GranaIterator<TipOznake> a(lista,pol, dol);
        if(dol == lista->lista[lista.size()-1] && pol==lista->lista.size()-1) { return *this;
        }
        if(dol == lista->lista[pol].size()-1) {
            dol = 0;
            pol++;
        }
        else dol++;
        return a;
    }
    GranaIterator& operator ++() {
        if(dol == lista->lista[lista->lista.size()-1].size()-1 && pol == lista->lista.size()-1) return *this; 
        if(dol == lista->lista[pol].size()-1) {
            dol = 0;
            pol ++;
        }
        else dol++;
        return *this;
    }
};
int main() {
    UsmjereniGraf<bool> *g = new ListaGraf<bool>(6);
    g->dodajGranu(0, 1, 2.5);
    g->dodajGranu(1, 0, 1.2);
    g->dodajGranu(1, 2, 0.1);
    g->dodajGranu(0, 0, 3.14);
    for (GranaIterator<bool> iter = g->dajGranePocetak();
         iter != g->dajGraneKraj(); ++iter)
      cout << "(" << (*iter).dajPolazniCvor().dajRedniBroj() << ","
           << (*iter).dajDolazniCvor().dajRedniBroj() << ") -> "
           << (*iter).dajTezinu() << "; ";
  delete g;
    return 0;
}
