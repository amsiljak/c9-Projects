#include <iostream>
#include <list>
#include <vector>
using namespace std;
 
template <typename TipOznake>
class Cvor;

template <typename TipOznake>
class GranaIterator;

template <typename TipOznake>
class Grana;

template <typename TipOznake>
class MatricaGraf;

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
    virtual TipOznake dajOznakuCvora(int cv) = 0;
    virtual void postaviOznakuGrane(int pol, int dol, TipOznake oznaka) = 0;
    virtual TipOznake dajOznakuGrane(int pol, int dol) = 0;
    virtual Grana<TipOznake> dajGranu(int pol, int dol) = 0;
    virtual Cvor<TipOznake> dajCvor(int br) = 0;
    virtual GranaIterator<TipOznake> dajGranePocetak() = 0;
    virtual GranaIterator<TipOznake> dajGraneKraj() = 0;
};   
template <typename TipOznake>
class MatricaGraf : public UsmjereniGraf<TipOznake> {
protected:
    vector<vector<Grana<TipOznake>*>> matrica;
    vector<Cvor<TipOznake>*> cvorovi ;
    int brPosjecenih = 0;
public:
    MatricaGraf(int brCvorova) {
        cvorovi.resize(brCvorova, nullptr);
        for(int i = 0; i<brCvorova; i++) cvorovi[i] = new Cvor<TipOznake>(TipOznake(),i,this);
        
        matrica.resize(brCvorova);
        for(int i = 0; i<brCvorova; i++) matrica[i].resize(brCvorova, nullptr);
    }
    void dodajGranu(int pol, int dol, float t) {
        if(!(cvorovi.size() < dol || matrica[pol][dol] != nullptr || cvorovi.size() < pol)) 
            matrica[pol][dol] = new Grana<TipOznake>(t, TipOznake(), cvorovi[pol], cvorovi[dol]);
        else throw "Greska";
    }
    void obrisiGranu(int pol, int dol) {
        if(!(cvorovi.size() < dol || matrica[pol][dol] == nullptr || cvorovi.size() < pol)) {
            delete matrica[pol][dol];
            matrica[pol][dol] = nullptr;
        }
        else throw "Greska";
    }
    float dajTezinuGrane(int pol, int dol) {
        if(!(cvorovi.size() < dol || matrica[pol][dol] == nullptr || cvorovi.size() < pol)) 
            return matrica[pol][dol]->dajTezinu();
        else throw "Greska";
    }
    void postaviTezinuGrane(int pol, int dol, float t) {
        if(!(cvorovi.size() < dol || matrica[pol][dol] == nullptr || cvorovi.size() < pol)) 
            matrica[pol][dol]->postaviTezinu1(t);
        else throw "Greska";
    }
    TipOznake dajOznakuGrane(int pol, int dol) {
        if(!(cvorovi.size() < dol || matrica[pol][dol] == nullptr || cvorovi.size() < pol)) 
            return matrica[pol][dol]->dajOznaku();
        throw "Greska";
    }
    void postaviOznakuGrane(int pol, int dol, TipOznake oznaka) {
        if(!(cvorovi.size() < dol || matrica[pol][dol] == nullptr || cvorovi.size() < pol)) 
            matrica[pol][dol] -> postaviOznaku1(oznaka);
        else throw "Greska";
    }
    Grana<TipOznake> dajGranu(int pol, int dol) {
        if(!(cvorovi.size() < dol || matrica[pol][dol] == nullptr || cvorovi.size() < pol)) 
            return *matrica[pol][dol];
        throw "Greska";
    }
    int dajBrojCvorova() {
        return cvorovi.size();
    }
    Cvor<TipOznake> dajCvor(int br) {
        if(cvorovi[br] != nullptr) return *cvorovi[br];
        throw "Greska";
    }
    void postaviOznakuCvora(int br, TipOznake oznaka) {
        if(cvorovi[br] != nullptr) cvorovi[br]->postaviOznaku1(oznaka);
        else throw "Greska";
    }
    TipOznake dajOznakuCvora(int br) {
        if(cvorovi[br] != nullptr) return cvorovi[br]->dajOznaku();
        throw "Greska";
    }
    void postaviBrojCvorova(int br) {
        if(cvorovi.size() > br) throw "Greska";
        
        int pom = cvorovi.size();
        cvorovi.resize(br, nullptr);
        for(int i = pom; i < br; i++) cvorovi[i] = new Cvor<TipOznake>(TipOznake(),i,this);
        
        matrica.resize(br);
        for(int i = 0; i < br; i++) matrica[i].resize(br, nullptr);
    }
    ~MatricaGraf() {
        for(int i = 0; i < cvorovi.size(); i++) delete cvorovi[i];
        for(int i = 0; i < matrica.size(); i++) {
            for(int j = 0; j < matrica.size(); j++) delete matrica[i][j];
        }
    }
    bool postojiGrana(int pol, int dol) {
        if(!(cvorovi.size() < dol || cvorovi.size() < pol)) return matrica[pol][dol];
        return false;
    }
    virtual GranaIterator<TipOznake> dajGranePocetak() {
        for(int i = 0; i < matrica.size(); i++) {
            for(int j = 0; j < matrica.size(); j++) if(matrica[i][j] != nullptr) return GranaIterator<TipOznake>(this,i,j);
        }
        return GranaIterator<TipOznake>(this,0,0);
    }
    virtual GranaIterator<TipOznake> dajGraneKraj() {
        for(int i = matrica.size() - 1; i > 0; i--) {
            for(int j = matrica.size() - 1; j > 0; j--) {
                if(matrica[i][j] != nullptr) {
                    if(matrica.size() - 1 > j) return GranaIterator<TipOznake>(this,i, j+1);
                    else return GranaIterator<TipOznake>(this,i+1,0);
                }
            }
        }
        return GranaIterator<TipOznake>(this, matrica.size() - 1, matrica.size() - 1);
    }
    
    template <typename TipOznake1>
    friend void dfs(UsmjereniGraf<TipOznake1>*gr, std::vector<Cvor<bool>>&o,Cvor<TipOznake1>cv);
    
    template <typename TipOznake1>
    friend void bfs(UsmjereniGraf<TipOznake1>*gr, vector<Cvor<bool>>&o, Cvor<TipOznake1> cv, int slj);
    
    friend class GranaIterator<TipOznake>;
 };
template <typename TipOznake1>
class Cvor {
    TipOznake1 oznaka;
    int redni_broj;
    UsmjereniGraf<TipOznake1> *pok;
public:    
    Cvor() : oznaka(TipOznake1()), redni_broj(0),pok(nullptr)  {}
    Cvor(TipOznake1 oznaka1, int redni_broj1, UsmjereniGraf<TipOznake1> *pok1) : oznaka(oznaka1), redni_broj(redni_broj1), pok(pok1) {}
    int dajRedniBroj() {
        return redni_broj;
    }
    TipOznake1 dajOznaku() {
        return oznaka;
    }
    void postaviOznaku(TipOznake1 oznaka1) {
        pok -> postaviOznakuCvora(redni_broj, oznaka1);
    }
    void postaviOznaku1(TipOznake1 oznaka1) {
        oznaka = oznaka1;
    }
    friend class Grana<TipOznake1>;
};
template <typename TipOznake1>
class Grana {
    float tezina;    
    TipOznake1 oznaka;
    Cvor<TipOznake1> *pol;
    Cvor<TipOznake1> *dol;
public:
    Grana(float tezina1, TipOznake1 oznaka1, Cvor<TipOznake1> *pol1, Cvor<TipOznake1>* dol1) : tezina(tezina1),  oznaka(oznaka1),pol(pol1), dol(dol1) {}
    Grana() :  tezina(0), oznaka(TipOznake1()),pol(nullptr), dol(nullptr) {}
    Cvor<TipOznake1> dajPolazniCvor() {
        return *pol;
    }
    Cvor<TipOznake1> dajDolazniCvor() {
        return *dol;
    }
    TipOznake1 dajOznaku() {
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
    void postaviOznaku(TipOznake1 oznaka) {
        pol->pok->postaviOznakuGrane(pol->dajRedniBroj(), dol->dajRedniBroj(), oznaka);
    }
    void postaviOznaku1(TipOznake1 oznaka1) {
        oznaka = oznaka1;
    }
};
template <typename TipOznake1>
void bfs(UsmjereniGraf<TipOznake1> *gr, vector<Cvor<bool>> &o, Cvor<TipOznake1> cv, int slj = 0) {
    MatricaGraf<TipOznake1> *matrica1 = dynamic_cast<MatricaGraf<TipOznake1>*>(gr);
    auto p = TipOznake1();
    if(matrica1->dajBrojCvorova() == matrica1->brPosjecenih ) {
        matrica1->brPosjecenih = 0;
        return;
    }
    if(p != matrica1->cvorovi[cv.dajRedniBroj()]->dajOznaku()) {
        o.push_back(cv);
        matrica1->cvorovi[cv.dajRedniBroj()]->postaviOznaku(p);
        matrica1->brPosjecenih++;
    }
    for(int i = 0; i < matrica1->dajBrojCvorova(); i++) {
        if(matrica1->matrica[cv.dajRedniBroj()][i]->dajDolazniCvor().dajOznaku() != p && matrica1->matrica[cv.dajRedniBroj()][i] != nullptr) {
            matrica1->cvorovi[i]->postaviOznaku(p);
            o.push_back(matrica1->matrica[cv.dajRedniBroj()][i]->dajDolazniCvor());
            matrica1->brPosjecenih++;
        }
    }
    bfs(gr, o, o[++slj], slj);
}
template <typename TipOznake1>
void dfs(UsmjereniGraf<TipOznake1> *gr, vector<Cvor<bool>> &o, Cvor<TipOznake1> cv) {
    MatricaGraf<TipOznake1> *matrica1 = dynamic_cast<MatricaGraf<TipOznake1>*>(gr);
    auto p = TipOznake1(1);//!!!
    o.push_back(cv);
    matrica1->cvorovi[cv.dajRedniBroj()]->postaviOznaku(p);
    matrica1->brPosjecenih++;
    
    for(int i = 0; i < matrica1->dajBrojCvorova(); i++) {
        if(matrica1->matrica[cv.dajRedniBroj()][i]->dajDolazniCvor().dajOznaku() != p && matrica1->matrica[cv.dajRedniBroj()][i]!= nullptr)
        dfs(gr, o, matrica1->matrica[cv.dajRedniBroj()][i]->dajDolazniCvor());
    }
    if(matrica1->dajBrojCvorova() > matrica1->brPosjecenih) {
        for(int i = 0; i < matrica1->dajBrojCvorova(); i++) {
            for(int j = 0; j < matrica1->dajBrojCvorova(); j++) {
                if(matrica1->matrica[i][j]->dajDolazniCvor().dajOznaku()!=p &&
                matrica1->matrica[i][j] != nullptr) {
                    if(matrica1->cvorovi[i]->dajOznaku() != p) {
                        matrica1->cvorovi[i]->postaviOznaku(p);
                        o.push_back(*matrica1->cvorovi[i]);
                    }
                    dfs(gr, o, matrica1->matrica[i][j]->dajDolazniCvor());
                }
            }
        }
    }
    if(matrica1->dajBrojCvorova() == matrica1->brPosjecenih) matrica1->brPosjecenih=0;
}
template <typename TipOznake>
class GranaIterator {
    MatricaGraf<TipOznake> *matrica;
    int pol;
    int dol;
public:
    GranaIterator(MatricaGraf<TipOznake> *pok, int pol1, int dol1) : matrica(pok) {
        pol=pol1;
        dol = dol1;
    }
    bool operator != (const GranaIterator &i) const {
        if(i.pol == pol && i.dol == dol && i.matrica == matrica) return false;
        return true;
    }
    bool operator == (const GranaIterator &i) const {
        if(i.pol == pol && i.dol == dol && i.matrica == matrica) return true;
        return false;
    }
    Grana<TipOznake> operator *() {
        if(matrica->matrica[pol][dol])
        return *(matrica->matrica[pol][dol]);
        throw "Greska";
    }
    GranaIterator& operator ++() {
        if(matrica->matrica.size() - 1 == dol && matrica->matrica.size() == pol) throw "Greska";
        GranaIterator<TipOznake> pom = matrica->dajGraneKraj();
        int a = pom.pol;
        int b = pom.dol;
        
        bool x = false;
        
        for(int i = 0; i < matrica->matrica.size(); i++) {
            for(int j = 0; j < matrica->matrica.size(); j++) {
                if(matrica->matrica[i][j] != nullptr && (pol < i || (pol == i && dol < j))) {
                    x = true;
                    dol = j;
                    pol = i;
                    break;
                }
                else if(b == j && a == i) {
                    dol = b;
                    pol = a;
                    return *this;
                }
            }
            if(x) break;
        }
        return *this;
    }
    GranaIterator operator ++(int) {
        if(matrica->matrica.size() - 1 == dol && matrica->matrica.size() == pol) throw "Greska";
        GranaIterator<TipOznake> pom = matrica->dajGraneKraj();
        int a = pom.pol;
        int b = pom.dol;
        GranaIterator<TipOznake> o(matrica, pol, dol);
        
        bool x = false;
        
        for(int i = 0; i < matrica->matrica.size(); i++) {
            for(int j = 0; j < matrica->matrica.size(); j++) {
                if(matrica->matrica[i][j] != nullptr && (pol < i || (pol == i && dol < j))) {
                    x = true;
                    dol = j;
                    pol = i;
                    break;
                }
                else if(b == j && a == i) {
                    o.dol = b;
                    o.pol = a;
                    return o;
                }
            }
            if(x) break;
        }
        return o;
    }
};
int main() {
   return 0;
}