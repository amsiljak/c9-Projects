#include <iostream>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <list>

using namespace std;

template<typename tip1, typename tip2>
class Mapa
{
public:
    Mapa() {}
    virtual tip2 operator[] (tip1 vrijednost) const = 0;
    virtual tip2& operator[] (tip1 vrijednost)  = 0;
    virtual int brojElemenata() const = 0;
    virtual void obrisi() = 0;
    virtual void obrisi(const tip1& kljuc) = 0;
    virtual ~Mapa() {};
};

template<typename tip1, typename tip2>
class HashMapaLan : public Mapa<tip1, tip2>
{
    vector<list<pair<tip1, tip2>>*> elementi;
    int broj_Elemenata;
    unsigned int (*pokNaFun)(tip1, unsigned int);
public:
    HashMapaLan() : elementi(1000), broj_Elemenata(0), pokNaFun(nullptr) {}

    HashMapaLan(const HashMapaLan<tip1, tip2> &novaMapa) : elementi(novaMapa.elementi.size()), broj_Elemenata(novaMapa.broj_Elemenata), pokNaFun(novaMapa.pokNaFun)
    {
        for(int i = 0; i < elementi.size(); i++) {
            if(novaMapa.elementi[i])
                elementi[i] = new list<pair<tip1,tip2>>(*novaMapa.elementi[i]);  
        }
    }

    HashMapaLan& operator=(const HashMapaLan<tip1, tip2> &novaMapa)
    {
        if(this != &novaMapa) {
            this->obrisi();
            elementi.resize(novaMapa.elementi.size(), nullptr);
            broj_Elemenata = novaMapa.broj_Elemenata;
            pokNaFun = novaMapa.pokNaFun;
            for(int i = 0; i < elementi.size(); i++) {
                if(novaMapa.elementi[i])
                  elementi[i] = new list<pair<tip1,tip2>>(*novaMapa.elementi[i]);  
            }
        }
        return *this;
    }

    tip2 operator[] (tip1 vrijednost) const
    {
        if(!pokNaFun) throw "Nema hash funkcije, postavite hash funkciju";
        unsigned int indeks = pokNaFun(vrijednost, elementi.size());
        if(elementi[indeks]) {
            for(auto it1 = elementi[indeks]->begin(); it1 != elementi[indeks]->end(); it1++) {
                if(it1->first == vrijednost) return it1->second;
            }
        }
        return tip2{};
    }

    tip2& operator[] (tip1 vrijednost)
    {
        if(!pokNaFun) throw "Nema hash funkcije, postavite hash funkciju";
        unsigned int indeks = pokNaFun(vrijednost, elementi.size());
        if(elementi[indeks] == nullptr) {
            elementi[indeks] = new list<pair<tip1,tip2>>{pair<tip1, tip2>(vrijednost, tip2{})};
            broj_Elemenata++;
            auto it = elementi[indeks]->begin();
            return it->second;
        } else {
            auto it = elementi[indeks]->begin();
            for(auto it1 = elementi[indeks]->begin(); it1 != elementi[indeks]->end(); it1++) {
                if(it1->first == vrijednost) 
                    return it1->second;
            }
            while(it != elementi[indeks]->end() && it->first < vrijednost) it++;
            broj_Elemenata++;
            return (elementi[indeks]->insert(it, pair<tip1,tip2>(vrijednost, tip2{})))->second;
        }
    }

    int brojElemenata() const
    {
        return broj_Elemenata;
    }

    void obrisi()
    {
        for(int i = 0; i < elementi.size(); i++) {
            delete elementi[i];
            broj_Elemenata = 0;
            elementi[i] = nullptr;   
        }
    }

    void obrisi(const tip1& kljuc)
    {
        if(!pokNaFun) throw "Nema hash funkcije, postavite hash funkciju";
        unsigned int indeks = pokNaFun(kljuc, elementi.size());
        if(elementi[indeks] != nullptr) {
           auto it1 = elementi[indeks]->begin();
           for(; it1 != elementi[indeks]->end(); it1++) {
                if(it1->first == kljuc) {
                    elementi[indeks]->erase(it1);
                    if(elementi[indeks]->empty()) {
                        delete elementi[indeks];
                        elementi[indeks] = nullptr;
                    }
                    broj_Elemenata--;
                    return;
                }
            }
        }
        throw "Nije pronadjen element";
    }

    void definisiHashFunkciju(unsigned int (*pokNaFun1)(tip1, unsigned int))
    {
        pokNaFun = pokNaFun1;
    }

    ~HashMapaLan()
    {
        for(int i = 0; i < elementi.size(); i++)
            delete elementi[i];
    }

};

template <typename TipOznake>
class Grana;
template <typename TipOznake>
class Cvor;
template <typename TipOznake>
class GranaIterator;
template <typename TipOznake>
class ListaGraf;


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
    bool daLiSuIsti(int polazn, int dolazn) {
        return(polazn == polazni->dajRedniBroj() && dolazn == dolazni->dajRedniBroj());
    }
    
 };

template<typename TipOznake>
class ListaGraf : public UsmjereniGraf<TipOznake> {
protected:
    vector<vector<Grana<TipOznake>*>> lista;
    vector<Cvor<TipOznake>*> cvorovi;
    int brojPosjecenih = 0;
public:
    ListaGraf(int brojCvorova) {
        lista.resize(brojCvorova);
        cvorovi.resize(brojCvorova, nullptr);
        for(int i = 0; i < brojCvorova; i++) {
            cvorovi[i] = new Cvor<TipOznake>(TipOznake{}, i, this);
        }
    }

    ~ListaGraf() {
        for(int i = 0; i < lista.size(); i++) {
            for(int j = 0; j < lista[i].size(); j++) {
                delete lista[i][j];
            }
        }
        for(int i = 0; i < cvorovi.size(); i++) {
            delete cvorovi[i];
        }
    }

    int dajBrojCvorova() { return cvorovi.size(); }

    void postaviBrojCvorova(int brCvorova) {
        if(brCvorova < cvorovi.size()) throw("Ne moze se smanjiti broj cvorova");
        lista.resize(brCvorova);
        int staraVel = cvorovi.size();
        cvorovi.resize(brCvorova, nullptr);
        for(int i = staraVel; i < brCvorova; i++) {
            cvorovi[i] = new Cvor<TipOznake>(TipOznake{}, i, this);
        }
    }

    void dodajGranu(int polazni, int dolazni, float tezina) {
        if(polazni > cvorovi.size()) throw("Losi podaci");
        lista[polazni].push_back(new Grana<TipOznake>(tezina, TipOznake{}, cvorovi[polazni], cvorovi[dolazni]));
    }

    void obrisiGranu(int polazni, int dolazni) {
        if(polazni > cvorovi.size() || dolazni > cvorovi.size()) throw("Ne postoji grana");
        for(int i = 0; i < lista[polazni].size(); i++) {
                if(lista[polazni][i]->daLiSuIsti(polazni, dolazni)) {
                    delete lista[polazni][i];
                    lista[polazni].erase(lista[polazni].begin()+i);
                    return;
                }
            }
         throw("Ne postoji grana");
    }

    void postaviTezinuGrane(int polazni, int dolazni, float tezina) {
        if(polazni > cvorovi.size() || dolazni > cvorovi.size()) throw("Ne postoji grana");
        for(int i = 0; i < lista[polazni].size(); i++) {
                if(lista[polazni][i]->daLiSuIsti(polazni, dolazni)) {
                    lista[polazni][i]->postaviTezinu2(tezina);
                    return;
                }
            }
         throw("Ne postoji grana");
    }

    float dajTezinuGrane(int polazni, int dolazni) {
        if(polazni > cvorovi.size() || dolazni > cvorovi.size()) throw("Ne postoji grana");
        for(int i = 0; i < lista[polazni].size(); i++) {
                if(lista[polazni][i]->daLiSuIsti(polazni, dolazni)) {
                    return lista[polazni][i]->dajTezinu();
                }
            }
         throw("Ne postoji grana");
    }

    bool postojiGrana(int polazni, int dolazni) {
        if(polazni > cvorovi.size() || dolazni > cvorovi.size()) return false;
        for(int i = 0; i < lista[polazni].size(); i++) {
                if(lista[polazni][i]->daLiSuIsti(polazni, dolazni)) {
                    return true;
                }
            }
         return false;
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
        if(polazni > cvorovi.size() || dolazni > cvorovi.size()) throw("Ne postoji grana");
        for(int i = 0; i < lista[polazni].size(); i++) {
                if(lista[polazni][i]->daLiSuIsti(polazni, dolazni)) {
                    lista[polazni][i]->postaviOznaku2(oznaka);
                    return;
                }
            }
         throw("Ne postoji grana");
    }

    TipOznake dajOznakuGrane(int polazni, int dolazni) {
        if(polazni > cvorovi.size() || dolazni > cvorovi.size()) throw("Ne postoji grana");
        for(int i = 0; i < lista[polazni].size(); i++) {
                if(lista[polazni][i]->daLiSuIsti(polazni, dolazni)) {
                    return lista[polazni][i]->dajOznaku();
                }
            }
         throw("Ne postoji grana");
    }

    Grana<TipOznake> dajGranu(int polazni, int dolazni) {
        if(polazni > cvorovi.size() || dolazni > cvorovi.size()) throw("Ne postoji grana");
        for(int i = 0; i < lista[polazni].size(); i++) {
                if(lista[polazni][i]->daLiSuIsti(polazni, dolazni)) {
                    return *lista[polazni][i];
                }
            }
         throw("Ne postoji grana");
    }

    Cvor<TipOznake> dajCvor(int broj) {
        if(cvorovi[broj] == nullptr) throw "Ne postoji cvor";
        return *cvorovi[broj];
    }
    virtual GranaIterator<TipOznake> dajGranePocetak()  {
        for(int i = 0; i < lista.size(); i++) {
            for(int j = 0; j < lista[i].size(); j++) {
                if(lista[i][j] != nullptr) return GranaIterator<TipOznake>(this, i, j);
            }
        }
        return GranaIterator<TipOznake>(this, 0, 0);
    }
    virtual GranaIterator<TipOznake> dajGraneKraj() {
        for(int i = lista.size() - 1; i > 0; i--) {
            for(int j = lista[i].size() - 1; j > 0; j--) {
                if(lista[i][j] != nullptr) {
                    if(j < lista[i].size() - 1)
                        return GranaIterator<TipOznake>(this, i, j + 1);
                    else return GranaIterator<TipOznake>(this, i + 1, 0);
                }
            }
        }
        return GranaIterator<TipOznake>(this, lista.size() - 1, lista[lista.size() - 1].size() - 1);
    }

    friend class GranaIterator<TipOznake>;

    template<typename TipOznake1>
    friend void dfs(UsmjereniGraf<TipOznake1> *graf, vector<Cvor<bool>> &obilazak, Cvor<TipOznake1> cvor);

    template<typename TipOznake1>
    friend void bfs(UsmjereniGraf<TipOznake1> *graf, vector<Cvor<bool>> &obilazak, Cvor<TipOznake1> cvor, int sljedeci);

};

template<typename TipOznake1>
void dfs(UsmjereniGraf<TipOznake1> *graf, vector<Cvor<bool>> &obilazak, Cvor<TipOznake1> cvor) {
    ListaGraf<TipOznake1> *mat = dynamic_cast<ListaGraf<TipOznake1>*>(graf);
    auto posjecen = TipOznake1(1);
    mat->cvorovi[cvor.dajRedniBroj()]->postaviOznaku(posjecen);
    obilazak.push_back(cvor);
    mat ->brojPosjecenih++;
    for(int j = 0; j < mat->lista[cvor.dajRedniBroj()].size(); j++) {
        if(mat->lista[cvor.dajRedniBroj()][j]->dajDolazniCvor().dajOznaku() != posjecen) {
            dfs(graf, obilazak, mat->lista[cvor.dajRedniBroj()][j]->dajDolazniCvor());
        }
    }
    if(mat->brojPosjecenih < mat->dajBrojCvorova()) {
        for(int i = 0; i < mat->lista.size(); i++) {
            for(int j = 0; j < mat->lista[i].size(); j++) {
                if(mat->lista[i][j] != nullptr && mat->lista[i][j]->dajDolazniCvor().dajOznaku() != posjecen) {
                    if(mat->cvorovi[i]->dajOznaku() != posjecen) {
                        mat->cvorovi[i]->postaviOznaku(posjecen);
                        obilazak.push_back(*mat->cvorovi[i]);
                    }
                    dfs(graf, obilazak, mat->lista[i][j]->dajDolazniCvor());
                }
            }
        }
    }
    if(mat->brojPosjecenih == mat->dajBrojCvorova()) mat->brojPosjecenih = 0;
}

template<typename TipOznake1>
void bfs(UsmjereniGraf<TipOznake1> *graf, vector<Cvor<bool>> &obilazak, Cvor<TipOznake1> cvor, int sljedeci = 0) {
    ListaGraf<TipOznake1> *mat = dynamic_cast<ListaGraf<TipOznake1>*>(graf);
    if(mat ->brojPosjecenih == mat->dajBrojCvorova()) {
        mat->brojPosjecenih = 0;
        return;
    }
    auto posjecen = TipOznake1(1);
    if(mat->cvorovi[cvor.dajRedniBroj()]->dajOznaku() != posjecen) {
        mat->cvorovi[cvor.dajRedniBroj()]->postaviOznaku(posjecen);
        obilazak.push_back(cvor);
        mat ->brojPosjecenih++;
    }
    for(int i = 0; i < mat->lista[cvor.dajRedniBroj()].size(); i++) {
        if(mat->lista[cvor.dajRedniBroj()][i]->dajDolazniCvor().dajOznaku() != posjecen) {
            obilazak.push_back(mat->lista[cvor.dajRedniBroj()][i]->dajDolazniCvor());
            mat->lista[cvor.dajRedniBroj()][i]->dajDolazniCvor().postaviOznaku(posjecen);
            mat ->brojPosjecenih++;
        }
    }
    bfs(graf, obilazak, obilazak[++sljedeci], sljedeci);
}

template <typename TipOznake>
class GranaIterator {
    ListaGraf<TipOznake> *lista;
    int polazni, y;//koordinata u listi
public:
    GranaIterator(ListaGraf<TipOznake> *pok,int polazni,int  dolazni) : lista(pok), polazni(polazni), y(dolazni) {}
    
    Grana<TipOznake> operator*() {
        return *lista->lista[polazni][y];
         throw("Nema vise");
    }
    
    bool operator==(const GranaIterator &iter) const {
        return(lista == iter.lista && polazni == iter.polazni && y == iter.y);
    }
    
    bool operator!=(const GranaIterator &iter) const {
        return !(lista == iter.lista && polazni == iter.polazni && y == iter.y);
    }
    
    GranaIterator& operator++() {
        if(polazni == lista->lista.size() - 1 && y == lista->lista[lista->lista.size() - 1].size() - 1) return *this;
        if(y != lista->lista[polazni].size() - 1){
            y++;
        } else {
            y = 0;
            polazni++;
        }
        return *this;
    }
    
    GranaIterator operator++(int) {
        GranaIterator<TipOznake> stari(lista, polazni, y);
        if(polazni == lista->lista.size() - 1 && y == lista->lista[lista.size() - 1].size() - 1) return *this;
        if(y != lista->lista[polazni].size() - 1){
            y++;
        } else {
            y = 0;
            polazni++;
        }
        return stari;
    }
};

int main() {
UsmjereniGraf<bool> *g = new ListaGraf<bool>(6);
    g->dodajGranu(0, 1, 2.5);
    g->dodajGranu(1, 2, 1.2);
    g->dodajGranu(1, 3, 0.1);
    g->dodajGranu(2, 4, 3.14);
    g->dodajGranu(2, 3, 2.73);
    g->dodajGranu(3, 5, 1);
    g->dodajGranu(5, 2, -5.0);
    std::vector<Cvor<bool> > dfs_obilazak;
    bfs(g, dfs_obilazak, g->dajCvor(0));
    for (int i = 0; i < dfs_obilazak.size(); i++)
      cout << dfs_obilazak[i].dajRedniBroj() << ",";
  delete g;


    return 0;
}