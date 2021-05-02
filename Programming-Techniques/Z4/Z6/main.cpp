//TP 2018/2019: Zadaća 4, Zadatak 6
#include <iostream>
#include <iostream>
#include <string>
#include <map>
#include <memory>




class Student 
{
    int br_indeksa;
    std::string godina,ime_prez,adresa,broj_tel;
    bool ProvjeraGodine(std::string &god);
    bool ProvjeraTelefona(std::string broj_tel);
    void IgnorisiRazmake(std::string &i_p);
public:
    Student(int br,std::string god,std::string i_p,std::string adr,std::string br_tel)
    {
        if(br>99999 || br<1000 || !ProvjeraGodine(god) || !ProvjeraTelefona(br_tel)) throw std::domain_error("Neispravni parametri");
        IgnorisiRazmake(i_p);
        br_indeksa=br; broj_tel=br_tel; godina=god; ime_prez=i_p; adresa=adr;
    }
    int DajIndeks() const{return br_indeksa;}
    std::string DajGodinuStudija()const{return godina;}
    std::string DajImePrezime()const{return ime_prez;}
    std::string DajAdresu()const{return adresa;}
    std::string DajTelefon()const{return broj_tel;}
    void Ispisi()const;
};


void Student::IgnorisiRazmake(std::string &i_p)
{
    for(int i=0;i<i_p.length();i++)
    {
        if(i_p.at(0)==' ')
        {
            while(i_p.at(i)==' ' && i!=i_p.length()-1){i_p.at(i)=*(i_p.erase(i_p.begin()+i)); }
        }
        int br(0);
        while(i_p.at(i)==' ')
        {
            if(i==i_p.length()-1 )
            {
                while(i_p.at(i)==' ')
                {
                    i_p.erase(i_p.begin()+i); 
                    i--;
                }
                return;
            }
            if(br>0) i_p.erase(i_p.begin()+i); 
            else i++; 
            br++;
            
        }
    }
}

bool Student::ProvjeraGodine(std::string &god)
{
    if(god=="1" || god=="2" || god=="3") {god+="/B"; return true;}
    if(god=="1/B" || god=="2/B" || god=="3/B" || god=="1/M" || god=="2/M" || god=="1/D" || god=="2/D" || god=="3/D") return true;
    return false;
}

bool Student::ProvjeraTelefona(std::string broj_tel)
{
    for(int i=0;i<broj_tel.length();i++)
    {
        if(broj_tel.at(0)<48 || broj_tel.at(0)>57) return false; //ako prvi nije broj
        //ide kroz petlju dok ne naidje na '/''
        if(broj_tel.at(i)=='/' && i!=broj_tel.length()-1)
        {
            i++;
            if(broj_tel.at(i)<48 || broj_tel.at(i)>57) return false; //da li je poslije '/' broj
            while(broj_tel.at(i)>=48 && broj_tel.at(i)<=57) i++; //ide do '-'
            if(broj_tel.at(i)=='-' && i!=broj_tel.length()-1)
            {
                i++;
                if(broj_tel.at(i)>=48 && broj_tel.at(i)<=57) return true;
            }
            return false; 
        }
    }
    return false;
}

void Student::Ispisi()const
{
    std::cout<<"Broj indeksa: "<<DajIndeks()<<std::endl;
    std::cout<<"Godina studija: "<<DajGodinuStudija()<<std::endl;
    std::cout<<"Ime i prezime: "<<DajImePrezime()<<std::endl;
    std::cout<<"Adresa: "<<DajAdresu()<<std::endl;
    std::cout<<"Telefon: "<<DajTelefon()<<std::endl;
}




class Laptop
{
    int ev_broj;
    std::string naziv,karakteristike;
    Student *pok;
public:
    Laptop(int a,std::string b,std::string c);
    int DajEvidencijskiBroj()const{return ev_broj;}
    std::string DajNaziv()const{return naziv;}
    std::string DajKarakteristike()const{return karakteristike;}
    void Zaduzi(Student &s);
    void Razduzi(){if(pok!=nullptr) pok=nullptr;}
    bool DaLiJeZaduzen()const{if(pok!=nullptr) return true; 
    return false;}
    Student &DajKodKogaJe(){if(pok==nullptr) throw std::domain_error("Laptop nije zaduzen"); return (*pok);}
    Student *DajPokKodKogaJe()const{if(pok==nullptr) return nullptr; return pok;}
    void Ispisi()const;
};

void Laptop::Ispisi()const
{
    std::cout<<"Evidencijski broj: "<<ev_broj<<std::endl<<"Naziv: "<<naziv<<std::endl<<"Karakteristike: "<<karakteristike<<std::endl;
}

void Laptop::Zaduzi(Student &s)
{
    if(pok!=nullptr) throw std::domain_error("Laptop vec zaduzen");
    pok=&s;
}

Laptop::Laptop(int a,std::string b,std::string c)
{
    if(a<0) throw std::domain_error("Neispravni parametri");
    pok=nullptr;
    ev_broj=a; naziv=b; karakteristike=c;
}


class Administracija
{
    std::map<int,std::shared_ptr<Student>> studenti;
    std::map<int,std::shared_ptr<Laptop>> laptopi;
public: 
    Administracija(){}; 
    Administracija(const Administracija &adm);
    Administracija(Administracija &&adm);
    Administracija &operator =(Administracija &&adm);
    Administracija &operator =(const Administracija &adm);
    // ~Administracija()
    // {
    //     for(auto it=studenti.begin();it!=studenti.end();it++)
    //     {
    //         delete it->second;
    //     }
    //     for(auto it=laptopi.begin();it!=laptopi.end();it++)
    //     {
    //         delete it->second;
    //     }
    // };
    void RegistrirajNovogStudenta(int br,std::string god,std::string i_p,std::string adr,std::string br_tel);
    void RegistrirajNoviLaptop(int ev_broj,std::string naziv,std::string karakt);
    Student &NadjiStudenta(int indeks);
    Laptop &NadjiLaptop(int ev_broj);
    void IzlistajStudente()const;
    void IzlistajLaptope()const;
    void ZaduziLaptop(int br_indeksa,int ev_broj);
    int NadjiSlobodniLaptop()const;
    void RazduziLaptop(int ev_broj);
    void PrikaziZaduzenja()const;
};

void Administracija::PrikaziZaduzenja() const
{
    bool ima(0);
    for(auto it=laptopi.begin();it!=laptopi.end();it++)
    {
        if(it->second->DaLiJeZaduzen())
        {
            ima=1;
            Student s=it->second->DajKodKogaJe();
            std::cout<<"Student "<<s.DajImePrezime()<<" ("<<s.DajIndeks()<<") zaduzio/la laptop broj "<<it->first<<std::endl;
        }
    }
    if(!ima)std::cout<<"Nema zaduzenja";
}

void Administracija::RazduziLaptop(int ev_broj)
{
   
    if(!laptopi.count(ev_broj)) throw std::domain_error("Laptop nije nadjen");
    if(!laptopi[ev_broj]->DaLiJeZaduzen()) throw std::domain_error("Laptop nije zaduzen");
    laptopi[ev_broj]->Razduzi();
}
int Administracija::NadjiSlobodniLaptop()const
{
    for(auto it=laptopi.begin();it!=laptopi.end();it++)
    {
        if(!(it->second->DaLiJeZaduzen())) return it->first;
    }
    throw std::domain_error("Nema slobodnih laptopa");
}

void Administracija::ZaduziLaptop(int br_indeksa,int ev_broj)
{
    bool imalaptop(0),imastudent(0),zaduzen(0);
    for(auto it=studenti.begin();it!=studenti.end();it++)
    {
        if(it->first==br_indeksa) imastudent=1;
    }
    if(!imastudent) throw std::domain_error("Student nije nadjen");
    for(auto it=laptopi.begin();it!=laptopi.end();it++)
    {
        if(it->first==ev_broj) imalaptop=1;
        if(it->second->DaLiJeZaduzen() && it->second->DajKodKogaJe().DajIndeks()==br_indeksa) zaduzen=1; 
    }
    if(!imalaptop) throw std::domain_error("Laptop nije nadjen");
    if(laptopi[ev_broj]->DaLiJeZaduzen())throw std::domain_error("Laptop vec zaduzen");
    if(zaduzen) throw std::domain_error("Student je vec zaduzio laptop");
    
    auto l=*studenti[br_indeksa];
    auto s=*laptopi[ev_broj];
    laptopi[ev_broj]->Zaduzi(*studenti[br_indeksa]);
}

void Administracija::IzlistajLaptope()const
{
    for(auto it=laptopi.begin();it!=laptopi.end();it++)
    {
        (*(it->second)).Ispisi();
        if((it->second)->DaLiJeZaduzen()) 
        {
            auto s=it->second->DajKodKogaJe();
            std::cout<<"Zaduzio(la): "<<s.DajImePrezime()<<" ("<<s.DajIndeks()<<") ";
        }
        std::cout<<std::endl;
    }
}
void Administracija::IzlistajStudente()const
{
    for(auto it=studenti.begin();it!=studenti.end();it++)
    {
        (*(it->second)).Ispisi();
        std::cout<<std::endl;
    }
}

Laptop &Administracija::NadjiLaptop(int ev_broj)
{
    auto it=laptopi.find(ev_broj);
    if(it!=laptopi.end()) return*(it->second);
    throw std::domain_error("Laptop nije nadjen");
}

Student &Administracija::NadjiStudenta(int indeks)
{
    auto it=studenti.find(indeks);
    if(it!=studenti.end()) return *(it->second);
    throw std::domain_error("Student nije nadjen");
}

void Administracija::RegistrirajNoviLaptop(int ev_broj,std::string naziv,std::string karakt)
{
    auto it=laptopi.begin();
    while(it!=laptopi.end())
    {
        if(it->second->DajEvidencijskiBroj()==ev_broj) throw std::domain_error("Laptop s tim evidencijskim brojem vec postoji");
        it++;
    }
    laptopi.insert({ev_broj,std::make_shared<Laptop>(ev_broj,naziv,karakt)});
}
void Administracija::RegistrirajNovogStudenta(int br,std::string god,std::string i_p,std::string adr,std::string br_tel)
{
    Student s(br,god,i_p,adr,br_tel);
    auto it=studenti.begin();
    while (it!=studenti.end()) {
        if(it->second->DajIndeks()==br) throw std::domain_error("Student s tim indeksom vec postoji");
        it++;
    }
    studenti.insert({br,std::make_shared<Student>(br,god,i_p,adr,br_tel)});
}

Administracija::Administracija( Administracija &&adm)
{
    for(auto it=adm.studenti.begin();it!=adm.studenti.end();it++)
    {
        studenti.insert({it->first,std::make_shared<Student>(it->second->DajIndeks(),it->second->DajGodinuStudija(),it->second->DajImePrezime(),
        it->second->DajAdresu(),it->second->DajTelefon())});
        it->second=nullptr;
    }
    for(auto it=adm.laptopi.begin();it!=adm.laptopi.end();it++)
    {
        laptopi.insert({it->first,std::make_shared<Laptop>(it->second->DajEvidencijskiBroj(),it->second->DajNaziv(),it->second->DajKarakteristike())});
    }
}

Administracija &Administracija::operator =(const Administracija &adm)
{
    auto it1=adm.studenti.begin();
    auto it2=adm.laptopi.begin();
    if(!studenti.count(it1->first)) studenti.insert({it1->first,std::make_shared< Student>(it1->second->DajIndeks(),
    it1->second->DajGodinuStudija(),it1->second->DajImePrezime(),it1->second->DajAdresu(),it1->second->DajTelefon())}); 
    if(!laptopi.count(it2->first)) laptopi.insert({it2->first,std::make_shared< Laptop>(it2->second->DajEvidencijskiBroj(),
    it2->second->DajNaziv(),it2->second->DajKarakteristike())});
    
    auto it3=studenti.begin();
    auto it4=laptopi.begin();
    if(!adm.studenti.count(it3->first)) studenti.erase(it3);
    if(!adm.laptopi.count(it4->first)) laptopi.erase(it4);
        
    return *this;
}
Administracija::Administracija(const Administracija &adm)
{
    for(auto it=adm.studenti.begin();it!=adm.studenti.end();it++)
    {
        studenti.insert({it->first,std::make_shared<Student>(it->second->DajIndeks(),it->second->DajGodinuStudija(),it->second->DajImePrezime(),
        it->second->DajAdresu(),it->second->DajTelefon())});
    }
    for(auto it=adm.laptopi.begin();it!=adm.laptopi.end();it++)
    {
        laptopi.insert({it->first,std::make_shared<Laptop>(it->second->DajEvidencijskiBroj(),it->second->DajNaziv(),it->second->DajKarakteristike())});
    }
}


int main ()
{
	return 0;
}