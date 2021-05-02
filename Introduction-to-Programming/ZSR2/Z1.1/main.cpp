#include <iostream>
#include <vector>

using namespace std;

template <typename TipOznake>
class Grana;
template <typename TipOznake>
class Cvor;
template <typename TipOznake>
class GranaIterator;
template <typename TipOznake>
class MatricaGraf;


template<typename TipOznake>
class UsmjereniGraf {
public:
    UsmjereniGraf() = default;
    virtual ~UsmjereniGraf() {}
    virtual int dajBrojCvorova() = 0;
    virtual void postaviBrojCvorova(int brCvorova) = 0;
    virtual void dodajGranu(int polazni, int dolazni, float tezina) = 0;
    virtual void obrisiGranu(int polazni, int dolazni) = 0;
    virtual void postaviTezinuGrane(int polazni, int dolazni, float tezina) = 0;
    virtual float dajTezinuGrane(int polazni, int dolazni) = 0;
    virtual bool postojiGrana(int polazni, int dolazni) = 0;
    virtual void postaviOznakuCvora(int broj, TipOznake oznaka) = 0;
    virtual TipOznake dajOznakuCvora(int cvot) = 0;
    virtual void postaviOznakuGrane(int polazni, int dolazni, TipOznake oznaka) = 0;
    virtual TipOznake dajOznakuGrane(int polazni, int dolazni) = 0;
    virtual Grana<TipOznake> dajGranu(int polazni, int dolazni) = 0;
    virtual Cvor<TipOznake> dajCvor(int broj) = 0;
    virtual GranaIterator<TipOznake> dajGranePocetak() = 0;
    virtual GranaIterator<TipOznake> dajGraneKraj() = 0;
};

template<typename TipOznake>
class Cvor {
    TipOznake oznaka;
    int redniBroj;
    UsmjereniGraf<TipOznake> *pokNaGraf;
public:
    Cvor(TipOznake oznaka, int redni, UsmjereniGraf<TipOznake> *pokNaGraf) : oznaka(oznaka), redniBroj(redni), pokNaGraf(pokNaGraf) {}
    Cvor() : oznaka(TipOznake{}), redniBroj(0), pokNaGraf(nullptr) {}
    TipOznake dajOznaku() { return oznaka; }
    void postaviOznaku(TipOznake oz) {
        pokNaGraf->postaviOznakuCvora(redniBroj, oz);
    }
    void postaviOznaku2(TipOznake oz) {
        oznaka = oz;
    }
    int dajRedniBroj() { return redniBroj; }
    friend class Grana<TipOznake>;
};

template<typename TipOznake>
class Grana {
    float tezina;
    TipOznake oznaka;
    Cvor<TipOznake> *polazni, *dolazni;
public:
    Grana() : tezina(0), oznaka(TipOznake{}), polazni(nullptr), dolazni(nullptr) {}
    Grana(float tezina, TipOznake oznaka, Cvor<TipOznake> * polaz, Cvor<TipOznake> * dolaz) : tezina(tezina), oznaka(oznaka), polazni(polaz), dolazni(dolaz) {}
    float dajTezinu() { return tezina; }
    void postaviTezinu(float t) { polazni->pokNaGraf->postaviTezinuGrane(polazni->dajRedniBroj(), dolazni->dajRedniBroj(), t); }
    void postaviTezinu2(float t) { tezina = t;}
    TipOznake dajOznaku() { return oznaka; }
    void postaviOznaku(TipOznake oz) { polazni->pokNaGraf->postaviOznakuGrane(polazni->dajRedniBroj(), dolazni->dajRedniBroj(), oz);  }
    void postaviOznaku2(TipOznake oz) { oznaka = oz; }
    Cvor<TipOznake> dajPolazniCvor() { return *polazni; }
    Cvor<TipOznake> dajDolazniCvor() { return *dolazni; }
};

template<typename TipOznake>
class MatricaGraf : public UsmjereniGraf<TipOznake> {
protected:
    vector<vector<Grana<TipOznake>*>> matrica;
    vector<Cvor<TipOznake>*> cvorovi;
    int brojPosjecenih = 0;
public:
    MatricaGraf(int brojCvorova) {
        matrica.resize(brojCvorova);
        for(int i = 0; i < brojCvorova; i++) matrica[i].resize(brojCvorova, nullptr);
        cvorovi.resize(brojCvorova, nullptr);
        for(int i = 0; i < brojCvorova; i++) {
            cvorovi[i] = new Cvor<TipOznake>(TipOznake{}, i, this);
        }
    }

    ~MatricaGraf() {
        for(int i = 0; i < matrica.size(); i++) {
            for(int j = 0; j < matrica.size(); j++) {
                delete matrica[i][j];
            }
        }
        for(int i = 0; i < cvorovi.size(); i++) {
            delete cvorovi[i];
        }
    }

    int dajBrojCvorova() { return cvorovi.size(); }

    void postaviBrojCvorova(int brCvorova) {
        if(brCvorova < cvorovi.size()) throw("Ne moze se smanjiti broj cvorova");
        matrica.resize(brCvorova);
        for(int i = 0; i < brCvorova; i++) matrica[i].resize(brCvorova, nullptr);
        int staraVel = cvorovi.size();
        cvorovi.resize(brCvorova, nullptr);
        for(int i = staraVel; i < brCvorova; i++) {
            cvorovi[i] = new Cvor<TipOznake>(TipOznake{}, i, this);
        }
    }

    void dodajGranu(int polazni, int dolazni, float tezina) {
        if(matrica[polazni][dolazni] != nullptr || polazni > cvorovi.size() || dolazni > cvorovi.size()) throw("Losi podaci");
        matrica[polazni][dolazni] = new Grana<TipOznake>(tezina, TipOznake{}, cvorovi[polazni], cvorovi[dolazni]);
    }

    void obrisiGranu(int polazni, int dolazni) {
        if(matrica[polazni][dolazni] == nullptr || polazni > cvorovi.size() || dolazni > cvorovi.size()) throw("Ne postoji grana");
        delete matrica[polazni][dolazni];
        matrica[polazni][dolazni] = nullptr;
    }

    void postaviTezinuGrane(int polazni, int dolazni, float tezina) {
        if(matrica[polazni][dolazni] == nullptr || polazni > cvorovi.size() || dolazni > cvorovi.size()) throw("Losi podaci");
        matrica[polazni][dolazni]->postaviTezinu2(tezina);
    }

    float dajTezinuGrane(int polazni, int dolazni) {
        if(matrica[polazni][dolazni] == nullptr || polazni > cvorovi.size() || dolazni > cvorovi.size()) throw("Losi podaci");
        return matrica[polazni][dolazni]->dajTezinu();
    }

    bool postojiGrana(int polazni, int dolazni) {
        if(polazni > cvorovi.size() || dolazni > cvorovi.size()) return false;
        return matrica[polazni][dolazni];
    }

    void postaviOznakuCvora(int broj, TipOznake oznaka) {
        if(cvorovi[broj] == nullptr) throw "Ne postoji cvor";
        cvorovi[broj]->postaviOznaku2(oznaka);
    }

    TipOznake dajOznakuCvora(int broj) {
        if(cvorovi[broj] == nullptr) throw "Ne postoji cvor";
        return cvorovi[broj]->dajOznaku();
    }

    void postaviOznakuGrane(int polazni, int dolazni,TipOznake oznaka) {
        if(matrica[polazni][dolazni] == nullptr || polazni > cvorovi.size() || dolazni > cvorovi.size()) throw("Losi podaci");
        matrica[polazni][dolazni]->postaviOznaku2(oznaka);
    }

    TipOznake dajOznakuGrane(int polazni, int dolazni) {
        if(matrica[polazni][dolazni] == nullptr || polazni > cvorovi.size() || dolazni > cvorovi.size()) throw("Losi podaci");
        return matrica[polazni][dolazni]->dajOznaku();
    }

    Grana<TipOznake> dajGranu(int polazni, int dolazni) {
        if(matrica[polazni][dolazni] == nullptr || polazni > cvorovi.size() || dolazni > cvorovi.size()) throw("Losi podaci");
        return *matrica[polazni][dolazni];
    }

    Cvor<TipOznake> dajCvor(int broj) {
        if(cvorovi[broj] == nullptr) throw "Ne postoji cvor";
        return *cvorovi[broj];
    }
    virtual GranaIterator<TipOznake> dajGranePocetak()  {
        for(int i = 0; i < matrica.size(); i++) {
            for(int j = 0; j < matrica.size(); j++) {
                if(matrica[i][j] != nullptr) return GranaIterator<TipOznake>(this, i, j);
            }
        }
        return GranaIterator<TipOznake>(this, 0, 0);
    }
    virtual GranaIterator<TipOznake> dajGraneKraj() {
        for(int i = matrica.size() - 1; i > 0; i--) {
            for(int j = matrica.size() - 1; j > 0; j--) {
                if(matrica[i][j] != nullptr) {
                    if(j < matrica.size() - 1)
                        return GranaIterator<TipOznake>(this, i, j + 1);
                    else return GranaIterator<TipOznake>(this, i + 1, 0);
                }
            }
        }
        return GranaIterator<TipOznake>(this, matrica.size() - 1, matrica.size() - 1);
    }

    friend class GranaIterator<TipOznake>;

    template<typename TipOznake1>
    friend void dfs(UsmjereniGraf<TipOznake1> *graf, vector<Cvor<bool>> &obilazak, Cvor<TipOznake1> cvor);

    template<typename TipOznake1>
    friend void bfs(UsmjereniGraf<TipOznake1> *graf, vector<Cvor<bool>> &obilazak, Cvor<TipOznake1> cvor, int sljedeci);

};
template <typename TipOznake1>
void bfs(UsmjereniGraf<TipOznake1> *gr, vector<Cvor<bool>> &o, Cvor<TipOznake1> cv, int slj = 0) {
    MatricaGraf<TipOznake1> *matrica1 = dynamic_cast<MatricaGraf<TipOznake1>*>(gr);
    auto p = TipOznake1();
    if(matrica1->dajBrojCvorova() == matrica1->brojPosjecenih ) {
        matrica1->brojPosjecenih = 0;
        return;
    }
    if(p != matrica1->cvorovi[cv.dajRedniBroj()]->dajOznaku()) {
        o.push_back(cv);
        matrica1->cvorovi[cv.dajRedniBroj()]->postaviOznaku(p);
        matrica1->brojPosjecnih++;
    }
    for(int i = 0; i < matrica1->dajBrojCvorova(); i++) {
        if(matrica1->matrica[cv.dajRedniBroj()][i]->dajDolazniCvor().dajOznaku() != p && matrica1->matrica[cv.dajRedniBroj()][i] != nullptr) {
            matrica1->cvorovi[i]->postaviOznaku(p);
            o.push_back(matrica1->matrica[cv.dajRedniBroj()][i]->dajDolazniCvor());
            matrica1->brojPosjecenih++;
        }
    }
    bfs(gr, o, o[++slj], slj);
}
template <typename TipOznake1>
void dfs(UsmjereniGraf<TipOznake1> *gr, vector<Cvor<bool>> &o, Cvor<TipOznake1> cv) {
    MatricaGraf<TipOznake1> *matrica1 = dynamic_cast<MatricaGraf<TipOznake1>*>(gr);
    auto p = TipOznake1();//!!!
    o.push_back(cv);
    matrica1->cvorovi[cv.dajRedniBroj()]->postaviOznaku(p);
    matrica1->brPosjecnih++;
    
    for(int i = 0; i < matrica1->dajBrojCvorova(); i++) {
        if(matrica1->matrica[cv.dajRedniBroj()][i]->dajDolazniCvor().dajOznaku() != p && matrica1->matrica[cv.dajRedniBroj()][i]!= nullptr)
        dfs(gr, o, matrica1->matrica[cv.dajRedniBroj()][i]->dajDolazniCvor());
    }
    if(matrica1->dajBrojCvorova() > matrica1->brPosjecnih) {
        for(int i = 0; i < matrica1->dajBrojCvorova(); i++) {
            for(int j = 0; j < matrica1->dajBrojCvorova(); j++) {
                if(matrica1->matrica[i][j]->dajDolazniCvor().dajOznaku()!=p) {
                    if(matrica1->cvorovi[i]->dajOznaku() != p) {
                        matrica1->cvorovi[i]->postaviOznaku(p);
                        o.push_back(*matrica1->cvorovi[i]);
                    }
                    dfs(gr, o, matrica1->matrica[i][j]->dajDolazniCvor());
                }
            }
        }
    }
    if(matrica1->dajBrojCvorova() == matrica1->brojPosjecenih) matrica1->brojPosjecenih=0;
}

template <typename TipOznake>
class GranaIterator {
    MatricaGraf<TipOznake> *matrica;
    int polazni, dolazni;
public:
    GranaIterator(MatricaGraf<TipOznake> *pok,int polazni,int  dolazni) : matrica(pok), polazni(polazni), dolazni(dolazni) {}
    Grana<TipOznake> operator*() {
        if(matrica->matrica[polazni][dolazni])
            return *(matrica->matrica[polazni][dolazni]);
        throw "Nema vise";
    }
    bool operator==(const GranaIterator &iter) const {
        return(matrica == iter.matrica && polazni == iter.polazni && dolazni == iter.dolazni);
    }
    bool operator!=(const GranaIterator &iter) const {
        return !(matrica == iter.matrica && polazni == iter.polazni && dolazni == iter.dolazni);
    }
    GranaIterator& operator++() {
        if(polazni == matrica->matrica.size() - 1 && dolazni == matrica->matrica.size() - 1) throw "kraj";
        bool prekini(false);
        GranaIterator<TipOznake> tmp = matrica->dajGraneKraj();
        int x(tmp.polazni),y(tmp.dolazni);
        for(int i = 0; i < matrica->matrica.size(); i++) {
            for(int j = 0; j < matrica->matrica.size(); j++) {
                if(i == x && j == y) {
                    polazni = x; dolazni = y;
                    return *this;
                }
                else if(((i == polazni && j > dolazni) || i > polazni) && matrica->matrica[i][j] != nullptr) {
                    polazni = i; dolazni = j;
                    prekini = true;
                    break;
                }
            }
            if(prekini) break;
        }
        return *this;
    }
    GranaIterator operator++(int) {
        GranaIterator<TipOznake> stari(matrica, polazni, dolazni);
        if(polazni == matrica->matrica.size() - 1 && dolazni == matrica->matrica.size() - 1) throw "kraj";
        bool prekini(false);
        GranaIterator<TipOznake> tmp = matrica->dajGraneKraj();
        int x(tmp.polazni),y(tmp.dolazni);
        for(int i = 0; i < matrica->matrica.size(); i++) {
            for(int j = 0; j < matrica->matrica.size(); j++) {
                if(i == x && j == y) {
                    stari.polazni = x; stari.dolazni = y;
                    return stari;
                }
                else if(((i == polazni && j > dolazni) || i > polazni) && matrica->matrica[i][j] != nullptr) {
                    polazni = i; dolazni = j;
                    prekini = true;
                    break;
                }
            }
            if(prekini) break;
        }
        return stari;
    }
};

int main() {
    return 0;
}