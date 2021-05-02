//TP 2018/2019: Zadaća 5, Zadatak 3
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

class Spremnik
{
protected:
    double tezina;
    std::string naziv;
public:
    Spremnik(double tezina,std::string naziv):tezina(tezina),naziv(naziv){}
    virtual ~Spremnik(){}
    virtual double DajTezinu() const=0;
    virtual double DajUkupnuTezinu() const=0;
    virtual void Ispisi() const=0;
    virtual Spremnik* DajKopiju() const=0;
};

class Sanduk:public Spremnik
{
    std::vector<int>tezine_predmeta;
public:
    Sanduk(double tezina,std::string naziv_predmeta,std::vector<int>tezine_predmeta):Spremnik(tezina,naziv_predmeta),
    tezine_predmeta(tezine_predmeta){}
    double DajTezinu() const override{return tezina;}
    double DajUkupnuTezinu() const override 
    {
        double ukupna_tezina(tezina);
        for(int x:tezine_predmeta) ukupna_tezina+=x;
        return ukupna_tezina;
    }
    void Ispisi() const override;
    Spremnik *DajKopiju() const override{return new Sanduk(*this);}
};
class Vreca:public Spremnik
{
    double tezina_materije;
public:
    Vreca(double tezina,std::string naziv_materije,double tezina_materije):Spremnik(tezina,naziv_materije),
    tezina_materije(tezina_materije){}
    double DajTezinu() const override{return tezina;}
    double DajUkupnuTezinu() const override{return tezina+tezina_materije;}
    void Ispisi() const override;
    Spremnik *DajKopiju() const override{return new Vreca(*this);}
};
class Bure:public Spremnik
{
    double tezina_tecnosti;
    double zapremina_tecnosti;
public:
    Bure(double tezina,std::string naziv_tecnosti,double tezina_tecnosti,double zapremina_tecnosti):
    Spremnik(tezina,naziv_tecnosti),tezina_tecnosti(tezina_tecnosti),zapremina_tecnosti(zapremina_tecnosti){}
    double DajTezinu() const override { return tezina;}
    double DajUkupnuTezinu() const override{return tezina+tezina_tecnosti;}
    void Ispisi() const override;
    Spremnik *DajKopiju() const override{return new Bure(*this);}
};

void Bure::Ispisi() const 
{
    std::cout<<"Vrsa spremnika: Bure"<<std::endl<<"Sadrzaj: "<<naziv<<std::endl<<"Vlastita tezina: "<<DajTezinu()<<std::endl;
    std::cout<<"Specificna tezina tecnosti: "<<tezina_tecnosti<<" (kg/m^3)"<<std::endl;
    std::cout<<"Zapremina tecnosti: "<<zapremina_tecnosti<<" (l)"<<std::endl;
    std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
}
void Sanduk::Ispisi() const
{
    std::cout<<"Vrsta spremnika: Sanduk"<<std::endl<<"Sadrzaj: "<<naziv<<std::endl<<"Tezine predmeta: ";
    for(int x:tezine_predmeta) std::cout<<x<<" ";
    std::cout<<"(kg)"<<std::endl<<"Vlastita tezina: "<<DajTezinu()<<" (kg)"<<std::endl;
    std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
}
void Vreca::Ispisi() const
{
    std::cout<<"Vrsta spremnika: Vreca"<<std::endl<<"Sadrzaj: "<<naziv<<std::endl<<"Vlastita tezina: "<<DajTezinu();
    std::cout<<std::endl<<" (kg)"<<"Tezina pohranjene materije: "<<DajUkupnuTezinu()<<" (kg)";
    std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<" (kg)"<<std::endl;
}



class Skladiste
{
    std::vector<std::shared_ptr<Spremnik>> roba;
public:
    Skladiste(){}
    Skladiste(const Skladiste &s)
    {
        roba.resize(s.roba.size());
        for(int i=0;i<s.roba.size();i++) roba[i]=std::shared_ptr<Spremnik>(s.roba.at(i)->DajKopiju());
    }
    Skladiste &operator =(Skladiste s)
    {
        std::swap(roba,s.roba);
        return *this;
    }
    Spremnik* DodajSanduk(double tezina,std::string naziv_predmeta,std::vector<int>tezine_predmeta)
    {
        auto adresa=std::make_shared<Sanduk>(tezina,naziv_predmeta,tezine_predmeta);
        roba.push_back(adresa);
        return adresa.get();
    }
    Spremnik *DodajBure(double tezina,std::string naziv_tecnosti,double tezina_tecnosti,double zapremina_tecnosti)
    {
        auto adresa=std::make_shared<Bure>(tezina,naziv_tecnosti,tezina_tecnosti,zapremina_tecnosti);
        roba.push_back(adresa);
        return adresa.get();
    }
    Spremnik *DodajVrecu(double tezina,std::string naziv_materije,double tezina_materije)
    {
        auto adresa=std::make_shared<Vreca>(tezina,naziv_materije,tezina_materije);
        roba.push_back(adresa);
        return adresa.get();
    }
    std::shared_ptr<Spremnik> DodajSpremnik(Spremnik *s,bool da)
    {
        if(!da)
        {
            auto adresa=std::shared_ptr<Spremnik>(s->DajKopiju());
            roba.push_back(adresa);
            return adresa;
        }
        else {roba.push_back(std::shared_ptr<Spremnik>(s)); return std::shared_ptr<Spremnik>(s);}
    }
    void IzlistajSkladiste()
    {
        auto s(*this);
        std::sort(s.roba.begin(),s.roba.end(),[](std::shared_ptr<Spremnik> r1,std::shared_ptr<Spremnik>r2)
        {
            return r1->DajTezinu()>r2->DajTezinu();
        });
        for(auto it=s.roba.begin();it!=s.roba.end();it++) (*it)->Ispisi();
    }
};
int main ()
{
	return 0;
}