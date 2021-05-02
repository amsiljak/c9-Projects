/* 
    TP 16/17 (Tutorijal 11, Zadatak 5)
	Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: hhasic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <cstring>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <memory>

class Tim
{
	char ime_tima[20];
	int broj_odigranih;
	int broj_pobjeda;
	int broj_nerijesenih;
	int broj_poraza;
	int broj_datih;
	int broj_primljenih;
	int broj_poena;
public:
	Tim(const char ime[]);
	void ObradiUtakmicu(int broj_datih, int broj_primljenih);
	const char *DajImeTima() const{return &ime_tima[0];};
	int DajBrojPoena() const{return broj_poena;};
	int DajGolRazliku() const{return broj_datih-broj_primljenih;};
	void IspisiPodatke() const;
};
	Tim::Tim(const char ime[])
	{
		if(strlen(ime)>19) throw std::range_error("Predugacko ime tima");
		std::strcpy(ime_tima,ime);
		broj_datih=0; broj_nerijesenih=0; broj_odigranih=0;
		broj_pobjeda=0; broj_poena=0; broj_poraza=0; broj_primljenih=0;
	}
	void Tim::ObradiUtakmicu(int broj_datih,int broj_primljenih)
	{
		if(broj_datih<0 || broj_primljenih<0) throw std::range_error("Neispravan broj golova");
		Tim::broj_datih+=broj_datih;
		Tim::broj_primljenih+=broj_primljenih;
		broj_odigranih++; 
		if(broj_datih>broj_primljenih) 
		{
			broj_pobjeda++;
			broj_poena+=3;
		}
		else if(broj_datih<broj_primljenih) broj_poraza++;
		else {broj_poena+=1; broj_nerijesenih+=1;}
	}
	void Tim::IspisiPodatke() const
	{
		std::cout<<std::setw(20)<<std::left<<ime_tima;
		std::cout<<std::setw(4)<<std::right<<broj_pobjeda+broj_nerijesenih+broj_poraza<<std::setw(4)<<std::right<<broj_pobjeda;
		std::cout<<std::setw(4)<<std::right<<broj_nerijesenih<<std::setw(4)<<std::right<<broj_poraza<<std::setw(4)<<std::right;
		std::cout<<std::setw(4)<<std::right<<broj_datih<<std::setw(4)<<std::right<<broj_primljenih<<std::setw(4)<<std::right<<broj_poena<<std::endl;
	}
	
	
class Liga
{
	std::vector<std::shared_ptr<Tim>> timovi;
public:
	explicit Liga(){}
	explicit Liga(std::initializer_list<Tim> lista_timova)
	{
		timovi.resize(lista_timova.size());
		auto vel=lista_timova.size();
		auto iter=lista_timova.begin();
		for(int i=0;i<vel;i++)
		{
			timovi[i]=std::make_shared<Tim>(*iter);
			iter++;
		}
	};
	~Liga() //destruktor
	{
		for(int i=0;i<timovi.size();i++)  timovi[i]=nullptr;
	}
	Liga(const Liga &l); //kopirajuci konstruktor
	Liga(Liga &&l);//pomjerajuci kontr
	Liga &operator =(const Liga &l);//kopirajuci operator dodjele
	Liga &operator =(Liga &&l);//pomjerajuci operator dod
	void DodajNoviTim(const char ime_tima[]);
	void RegistrirajUtakmicu(const char tim1[], const char tim2[],
	 int rezultat_1, int rezultat_2);
	void IspisiTabelu();
};
Liga::Liga(const Liga &l)
{
	timovi.resize(l.timovi.size());
	try
	{
		for(int i=0;i<timovi.size();i++)
		{
			timovi[i]=std::make_shared<Tim>(*l.timovi[i]);
		}
	}
	catch(...)
	{
		for(int i=0;i<timovi.size();i++) timovi[i]==nullptr;
	}
}
Liga &Liga::operator =(const Liga &l)
{
	if(l.timovi.size()<timovi.size())
	{
		for(int i=l.timovi.size();i<timovi.size();i++)
		{
			timovi[i]=nullptr;
		}
		timovi.resize(l.timovi.size());
	}
	else if(l.timovi.size()>timovi.size())               
	{
		int n=timovi.size();
		timovi.resize(l.timovi.size());
		try
		{
			for(int i=n;i<timovi.size();i++)
			{
				timovi[i]=std::make_shared <Tim>(*l.timovi[i]);
			}
		}
		catch(...)
		{
			for(int i=n;i<l.timovi.size();i++)
			{
				timovi[i]=nullptr;
			}
			throw;
		}
	}
	for(int i=0;i<timovi.size();i++) *timovi[i]=*l.timovi[i];
	return *this;
}
Liga::Liga(Liga &&l)
{
	timovi=l.timovi;
	l.timovi.resize(0);
}
Liga &Liga::operator =(Liga &&l)
{
	timovi=l.timovi;
	l.timovi.resize(0);
	return *this;
}
void Liga::DodajNoviTim(const char ime_tima[])
{
	auto pok=&ime_tima[0];
	for(int i=0;i<timovi.size();i++) 
	{
		if(std::strcmp(timovi[i]->DajImeTima(),pok)==0) throw std::logic_error("Tim vec postoji");
	}
	timovi[timovi.size()]=std::make_shared<Tim>(ime_tima);
}
void Liga::RegistrirajUtakmicu(const char tim1[], const char tim2[],int rezultat_1, int rezultat_2)
{
	bool nadjen1(0),nadjen2(0);
	auto pok1=&tim1[0];  auto pok2=&tim2[0];
	int indeks1,indeks2;
	for(int i=0;i<timovi.size();i++) 
	{
		if(std::strcmp(timovi[i]->DajImeTima(),pok1)==0) {nadjen1=1; indeks1=i; }
		if(std::strcmp(timovi[i]->DajImeTima(),pok2)==0) {nadjen2=1; indeks2=i; }
	}
	if(!nadjen1 || !nadjen2) throw std::logic_error("Tim nije nadjen");
	timovi[indeks1]->Tim::ObradiUtakmicu(rezultat_1,rezultat_2);
	timovi[indeks2]->Tim::ObradiUtakmicu(rezultat_2,rezultat_1);
}
void Liga::IspisiTabelu()
{
	std::sort(timovi.begin(),timovi.end(),[](std::shared_ptr<Tim> tim1,std::shared_ptr<Tim> tim2){
		if(tim1->DajBrojPoena()>tim2->DajBrojPoena()) return true;
		else if(tim1->DajBrojPoena()<tim2->DajBrojPoena()) return false;
		else
		{
			if(tim1->DajGolRazliku()>tim2->DajGolRazliku()) return true;
			else if(tim1->DajGolRazliku()<tim2->DajGolRazliku()) return false;
			else
			{
				if(strcmp(tim1->DajImeTima(),tim2->DajImeTima())<0) return true;
				else return false;
			}
		}

	});
	for(int i=0;i<timovi.size();i++)
	{
		timovi[i]->IspisiPodatke();
	}
}
int main ()
{
	Liga l1{"NK Zeljeznicar", "HSK Zrinjski", "FK Sarajevo", "FK Sloboda", "FK Krupa", "FK Radnik Bijeljina"};
l1.RegistrirajUtakmicu("FK Sloboda", "HSK Zrinjski",1,1);
	
Liga l2{"NK Zeljeznicar", "HSK Zrinjski", "FK Sarajevo"};
Liga l3{"NK Zeljeznicar", "HSK Zrinjski", "FK Sarajevo","NK Zeljeznicar", "HSK Zrinjski", "FK Sarajevo","NK Zeljeznicar", "HSK Zrinjski", "FK Sarajevo"};
	
l3 = std::move(l1);
l2 = l1;
	
std::cout << "Liga 1:" << std::endl;
l1.IspisiTabelu();
std::cout << std::endl  << "Liga 2:" << std::endl;
l2.IspisiTabelu();
std::cout << std::endl  << "Liga 3:" << std::endl;
l3.IspisiTabelu();
	return 0;
}