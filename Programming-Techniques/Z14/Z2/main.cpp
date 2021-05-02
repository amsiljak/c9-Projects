//TP 2018/2019: Tutorijal 14, Zadatak 2
#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <string>

class Spremnik
{
public:
    Spremnik(){}
    virtual ~Spremnik(){};
    virtual double DajTezinu() const=0;
    virtual double DajUkupnuTezinu() const=0;
    virtual void Ispisi() const=0;
    virtual Spremnik *DajKopiju() const=0;
};

class Skladiste
{
    int max_kol;
    int kol_robe;
    Spremnik **roba;
public:
    explicit Skladiste(int max):max_kol(max),roba(new Spremnik*[max]{}){}//ne smije koristiti auto pretvorbu??
    Skladiste(const Skladiste &s):max_kol(s.max_kol),kol_robe(s.kol_robe),roba(new Spremnik*[s.max_kol]{})
    {
        try {
            for(int i=0;i<s.kol_robe;i++)
            {
                roba[i]=s.roba[i]->DajKopiju();
            }
        }
        catch(...)
        {
            for(int i=0;i<s.kol_robe;i++) delete roba[i];
            delete [] roba;
            throw;
        }
    }
    Skladiste operator =(const Skladiste &s)
    {
        Spremnik **novi_prostor(new Spremnik*[s.max_kol]);
        try
        {
            for(int i=0;i<kol_robe;i++)
            {
                roba[i]=s.roba[i]->DajKopiju();
            }
        }
        catch(...)
        {
            for(int i=0;i<s.kol_robe;i++) delete roba[i];
            delete [] roba;
            throw;
        }
        for(int i=0;i<kol_robe;i++) delete roba[i];
        delete[] roba;
        roba=novi_prostor; kol_robe=s.kol_robe; max_kol=s.max_kol;
        
        return *this;
    }
    ~Skladiste()
    {
        for(int i=0;i<max_kol;i++) delete roba[i];
        delete [] roba;
    }
    void DodajSanduk(double tezina,const char* ime,int br,double tez_pr);
    void DodajBure(double tezina, const char* ime,double tez_tec);
    Spremnik &DajNajlaksi()
    {
        if(kol_robe==0) throw std::range_error("Skladiste je prazno");
        auto min=roba[0];
        for(int i=0;i<kol_robe;i++)
        {
            if(roba[i]->DajTezinu()<min->DajTezinu())  min=roba[i];
        }
        return *min;
    }
    Spremnik &DajNajtezi()
    {
        if(kol_robe==0) throw std::range_error("Skladiste je prazno");
        auto max=roba[0];
        for(int i=0;i<kol_robe;i++)
        {
            if(roba[i]->DajTezinu()>max->DajTezinu()) max=roba[i];
        }
        return *max;
    }
    int BrojPreteskih(int vrijednost) const
    {
        if(kol_robe==0) throw std::range_error("Skladiste je prazno");
       int broj_preteskih;
       for(int i=0;i<kol_robe;i++)
       {
           if(roba[i]->DajUkupnuTezinu()>vrijednost) broj_preteskih++;
       }
       return broj_preteskih;
    }
    void IzlistajSkladiste() const;
    void UcitajIzDatoteke(const char ime_datoteke[]);
};

void Skladiste::IzlistajSkladiste() const
{
    auto pok=roba;
    std::sort(pok,pok+kol_robe,[](Spremnik *s1, Spremnik *s2){return s1->DajUkupnuTezinu()<s2->DajUkupnuTezinu();});
    for(int i=0;i<kol_robe;i++)
    {
        pok[i]->Ispisi();
    }
}


class Sanduk : public Spremnik
{
    double vl_tezina,tezina_pr;
    int broj_pr;
    char ime_pr[100];
public:
    Sanduk(double tezina,const char* ime,int br,double tez_pr):vl_tezina(tezina),tezina_pr(tez_pr),broj_pr(br)
    {
        std::strcpy(ime_pr,ime);
    }
    Sanduk(const Sanduk &s):vl_tezina(s.vl_tezina),tezina_pr(s.tezina_pr),broj_pr(s.broj_pr)
    {
        std::strcpy(ime_pr,s.ime_pr);
    }
    double DajTezinu() const override {return vl_tezina;}
    double DajUkupnuTezinu() const override {return broj_pr*tezina_pr+vl_tezina;}
    void Ispisi() const override;
    Spremnik *DajKopiju() const override{return new Sanduk(*this);}
};
void Skladiste::DodajSanduk(double tezina,const char* ime,int br,double tez_pr)
{
    if(kol_robe>=max_kol) throw std::domain_error("Popunjeno skladiste");
    roba[kol_robe]=new Sanduk(tezina,ime,br,tez_pr);
    kol_robe++;
}
void Sanduk::Ispisi() const
{
    std::cout<<"Vrsta spremnika: Sanduk"<<std::endl; 
    std::cout<<"Sadrzaj: "<<ime_pr<<std::endl;
    std::cout<<"Vlastita tezina: "<<vl_tezina<<std::endl;
    std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<std::endl;
}


class Bure : public Spremnik
{
    double vl_tezina,tezina_tec;
    char ime_tec[100];
public:
    Bure(double tezina,const char *ime,double tez_tec):vl_tezina(tezina),tezina_tec(tez_tec)
    {
        for(int i=0;i<sizeof(ime);i++) ime_tec[i]=ime[i];
    }
    Bure(const Bure &b):vl_tezina(b.vl_tezina),tezina_tec(b.tezina_tec)
    {
        for(int i=0;i<sizeof(b.ime_tec);i++) ime_tec[i]=b.ime_tec[i];
    }
    double DajTezinu() const override {return vl_tezina;}
    double DajUkupnuTezinu() const override {return tezina_tec+vl_tezina;}
    void Ispisi() const override;
    Spremnik *DajKopiju() const override {return new Bure(*this);}
};
void Skladiste::DodajBure(double tezina,const char* ime,double tez_tec)
{
    if(kol_robe>=max_kol) throw std::domain_error("Popunjeno skladiste");
    roba[kol_robe]=new Bure(tezina,ime,tez_tec);
    kol_robe++;
}
void Bure::Ispisi() const
{
    std::cout<<"Vrsta spremnika: Bure"<<std::endl;
    std::cout<<"Sadrzaj: "<<ime_tec<<std::endl;
    std::cout<<"Vlastita tezina: "<<DajUkupnuTezinu()<<std::endl;
    std::cout<<"Ukupna tezina: "<<DajUkupnuTezinu()<<std::endl;
}
void Skladiste::UcitajIzDatoteke(const char ime_datoteke[])
{
    std::ifstream ulazni_tok(ime_datoteke,std::ios::binary);
    if(!ulazni_tok) throw std::logic_error("Trazena datoteka ne postoji");
    for(int i=0;i<kol_robe;i++) delete roba[i];
    delete[] roba;
    roba=new Spremnik*[max_kol];
    char slovo;
    for(int i=0;i<kol_robe;i++)
    {
        if(slovo=='S')
        {
            char s[100];
            char znak;
            ulazni_tok.read(reinterpret_cast<char*>(&znak),sizeof znak);
            ulazni_tok.read(reinterpret_cast<char*>(&s),sizeof s);
            ulazni_tok.read(reinterpret_cast<char*>(znak),sizeof znak);
            double tez,tezpr;
            int br_predmeta;
            ulazni_tok.read(reinterpret_cast<char*>(&tez),sizeof tez);
            ulazni_tok.read(reinterpret_cast<char*>(&znak),sizeof znak);
            ulazni_tok.read(reinterpret_cast<char*>(&br_predmeta),sizeof br_predmeta);
            ulazni_tok.read(reinterpret_cast<char*>(&tezpr),sizeof tezpr);
            DodajSanduk(tez,s,br_predmeta,tezpr);
            continue;
            if(!ulazni_tok)throw std::logic_error("Datoteka sadrzi besmislene podatke");
        }
        // else if(slovo=='B')
    }
    
    if(!ulazni_tok)
    {
        for(int i=0;i<kol_robe;i++) delete roba[i];
        delete[] roba;
        throw std::logic_error("Problemi pri citanju datoteke");
    }
}
int main ()
{
	return 0;
}