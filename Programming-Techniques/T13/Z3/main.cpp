/* 
    TP 16/17 (Tutorijal 13, Zadatak 3)
	Autotestove pisala Ivona Ivkovic. Sva pitanja, sugestije, prijave gresaka
	slati na mail iivkovic2@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class ApstraktniStudent
{
protected:
	std::string ime, prezime;
	int br_indeksa,br_polozenih;
	double prosj_ocjena;
public:
	ApstraktniStudent(std::string i,std::string p,int ind):ime(i),prezime(p),br_indeksa(ind),br_polozenih(0),prosj_ocjena(5){};
	virtual ~ApstraktniStudent(){};
	std::string DajIme(){return ime;};
	std::string DajPrezime(){return prezime;};
	int DajBrojIndeksa(){return br_indeksa;};
	int DajBrojPolozenih(){return br_polozenih;};
	double DajProsjek(){return prosj_ocjena;};
	void RegistrirajIspit(int ocjena);
	void PonistiOcjene(){br_polozenih=0;prosj_ocjena=5;};
	virtual void IspisiPodatke() const=0;
	virtual ApstraktniStudent* DajKopiju()const=0;
};
void ApstraktniStudent::RegistrirajIspit(int ocjena)
{
	if(ocjena<5 || ocjena>10) throw std::domain_error("Neispravna ocjena");
	else if(ocjena!=5)
	{
		br_polozenih++;
		prosj_ocjena=((prosj_ocjena*(br_polozenih-1))+ocjena)/br_polozenih;
	}
}
class StudentBachelor:public ApstraktniStudent
{
public:
	StudentBachelor(std::string i,std::string p,int ind):ApstraktniStudent(i,p,ind){};
	ApstraktniStudent *DajKopiju() const override {return new StudentBachelor(*this);};
	void IspisiPodatke() const override
	{
		std::cout<<"Student bachelor studija "<<ime<<" "<<prezime<<", sa brojem indeksa "<<
		br_indeksa<<","<<std::endl<<"ima prosjek "<<prosj_ocjena<<"."<<std::endl;
	}
};
class StudentMaster:public ApstraktniStudent
{
	int god_zavrsetka;
public:
	StudentMaster(std::string i,std::string p,int ind,int god):ApstraktniStudent(i,p,ind),god_zavrsetka(god){};
	ApstraktniStudent *DajKopiju()const override{return new StudentMaster(*this);};
	void IspisiPodatke() const override
	{
		std::cout<<"Student master studija "<<ime<<" "<<prezime<<", sa brojem indeksa "<<
		br_indeksa<<","<<std::endl<<"zavrsio bachelor studij godine "<<god_zavrsetka<<",ima prosjek "<<prosj_ocjena<<"."<<std::endl;
	}
};

class Fakultet
{
	std::vector<ApstraktniStudent*> kolekcija;
public:
	Fakultet(){};
	~Fakultet(){for(int i=0;i<kolekcija.size();i++) delete kolekcija[i]; };
	Fakultet(const Fakultet &f)
	{
		for(int i=0;i<f.kolekcija.size();i++)
		{
			kolekcija.push_back(f.kolekcija[i]->DajKopiju());
		}
	}
	Fakultet(Fakultet &&f)
	{
		kolekcija=f.kolekcija; f.kolekcija.resize(0);
	}
	Fakultet &operator =(const Fakultet &f)
	{
		for(int i=0;i<kolekcija.size();i++) delete kolekcija[i]; 
		kolekcija.resize(0);
		for(int i=0;i<f.kolekcija.size();i++) kolekcija.push_back(f.kolekcija[i]->DajKopiju());
		return *this;
	}
	Fakultet &operator =(Fakultet &&f)
	{
		for(int i=0;i<kolekcija.size();i++) delete kolekcija[i]; 
		kolekcija.resize(0);
		std::swap(kolekcija,f.kolekcija);
		return *this;
	}
	void UpisiStudenta(std::string ime,std::string prezime,int indeks)
	{
		for(int i=0;i<kolekcija.size();i++)
		{
			if(kolekcija[i]->DajBrojIndeksa()==indeks) throw std::logic_error("Student sa zadanim brojem indeksa vec postoji");
		}
		kolekcija.push_back(new StudentBachelor(ime,prezime,indeks));
	}
	void UpisiStudenta(std::string ime,std::string prezime,int indeks,int god)
	{
		for(int i=0;i<kolekcija.size();i++)
		{
			if(kolekcija[i]->DajBrojIndeksa()==indeks) throw std::logic_error("Student sa zadanim brojem indeksa vec postoji");
		}
		kolekcija.push_back(new StudentMaster(ime,prezime,indeks,god));
	}
	void ObrisiStudenta(int ind)
	{
		for(int i=0;i<kolekcija.size();i++)
		{
			if(kolekcija[i]->DajBrojIndeksa()==ind) 
			{
				delete kolekcija[i];
				kolekcija.erase(find(kolekcija.begin(),kolekcija.end(),kolekcija[i]));
				return;
			}
		}
		throw std::logic_error("Student sa zadanim brojem indeksa ne postoji");
	}
	const ApstraktniStudent &operator [](int ind) const
	{
		for(int i=0;i<kolekcija.size();i++)
		{
			if(kolekcija[i]->DajBrojIndeksa()==ind) return *kolekcija[i];
		}
		throw std::logic_error("Student sa zadanim brojem indeksa ne postoji");
	}
	 ApstraktniStudent &operator [](int ind) 
	{
		for(int i=0;i<kolekcija.size();i++)
		{
			if(kolekcija[i]->DajBrojIndeksa()==ind) return *kolekcija[i];
		}
		throw std::logic_error("Student sa zadanim brojem indeksa ne postoji");
	}
	void IspisiSveStudente() const
	{
		auto temp=kolekcija;
		std::sort(temp.begin(),temp.end(),[](ApstraktniStudent *a,ApstraktniStudent *b)
		{
			if(a->DajProsjek()!=b->DajProsjek()) return a->DajProsjek()>b->DajProsjek();
			else return a->DajBrojIndeksa()<b->DajBrojIndeksa();
		});
		for(int i=0;i<temp.size();i++)
		{
			temp[i]->IspisiPodatke();
		}
	}
};
int main ()
{
	Fakultet f1;
	f1.UpisiStudenta("Ibro", "Ibric", 3124, 2015);
    f1[3412].RegistrirajIspit(7);
	return 0;
}