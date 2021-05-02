/* 
    TP 16/17 (Tutorijal 11, Zadatak 4)
	Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: hhasic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <cstring>
#include <iomanip>
#include <stdexcept>
#include <algorithm>

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
	int broj_timova;
	const int max_br_timova;
	Tim **timovi;
public:
	explicit Liga(int velicina_lige):timovi(new Tim*[velicina_lige]),max_br_timova(velicina_lige),broj_timova(0){}
	explicit Liga(std::initializer_list<Tim> lista_timova):max_br_timova(lista_timova.size()),timovi(new Tim*[lista_timova.size()])
	{
		auto vel=lista_timova.size();
		auto iter=lista_timova.begin();
		for(int i=0;i<vel;i++)
		{
			timovi[i]=new Tim(*iter);
			iter++;
		}
		broj_timova=vel;
	};
	~Liga() //destruktor
	{
		for(int i=0;i<max_br_timova;i++) delete timovi[i];
		delete[] timovi;
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
Liga::Liga(const Liga &l):broj_timova(l.broj_timova),max_br_timova(l.max_br_timova),timovi(new Tim*[l.max_br_timova]{})
{
	try
	{
		for(int i=0;i<broj_timova;i++)
		{
			timovi[i]=new Tim(*l.timovi[i]);
		}
	}
	catch(...)
	{
		for(int i=0;i<broj_timova;i++) delete timovi[i];
		delete[] timovi;
	}
}
Liga &Liga::operator =(const Liga &l)
{
	if(l.max_br_timova!=max_br_timova) {throw std::logic_error("Nesaglasni kapaciteti liga");}
	else if(l.broj_timova<broj_timova)
	{
		for(int i=l.broj_timova;i<broj_timova;i++)
		{
			delete timovi[i];
			//timovi[i]=nullptr;
		}
	}
	else                
	{
		try
		{
			for(int i=broj_timova;i<l.broj_timova;i++)
			{
				timovi[i]=new Tim(*l.timovi[i]);
			}
		}
		catch(...)
		{
			for(int i=broj_timova;i<l.broj_timova;i++)
			{
				delete timovi[i];
				//timovi[i]=nullptr;
			}
			throw;
		}
	}
	broj_timova=l.broj_timova;
	for(int i=0;i<broj_timova;i++) *timovi[i]=*l.timovi[i];
	return *this;
}
Liga::Liga(Liga &&l):broj_timova(l.broj_timova),max_br_timova(l.max_br_timova),timovi(new Tim*[l.max_br_timova])
{
	l.broj_timova=0; l.timovi=nullptr;
}
Liga &Liga::operator =(Liga &&l)
{
	if(l.max_br_timova!=max_br_timova) {throw std::logic_error("Nesaglasni kapaciteti liga");}
	std::swap(l.broj_timova,broj_timova);
	std::swap(l.timovi,timovi);
	return *this;
}
void Liga::DodajNoviTim(const char ime_tima[])
{
	if(broj_timova==max_br_timova) throw std::range_error("Liga popunjena");
	auto pok=&ime_tima[0];
	for(int i=0;i<broj_timova;i++) 
	{
		if(std::strcmp(timovi[i]->DajImeTima(),pok)==0) throw std::logic_error("Tim vec postoji");
	}
	timovi[broj_timova]=new Tim(ime_tima);
	broj_timova++;
}
void Liga::RegistrirajUtakmicu(const char tim1[], const char tim2[],int rezultat_1, int rezultat_2)
{
	bool nadjen1(0),nadjen2(0);
	auto pok1=&tim1[0];  auto pok2=&tim2[0];
	int indeks1,indeks2;
	for(int i=0;i<broj_timova;i++) 
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
	std::sort(timovi,timovi+broj_timova,[](Tim *tim1,Tim *tim2){
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
	for(int i=0;i<broj_timova;i++)
	{
		timovi[i]->IspisiPodatke();
	}
}
int main ()
{
	Liga l1{"Borac", "Celik", "Jedinstvo", "Sarajevo", "Zeljeznicar", "Zrinjski"};
	while(1)
	{
		char tim1[20],tim2[20];
		l1.IspisiTabelu();
		std::cout<<std::endl<<"Unesite ime prvog tima (ENTER za kraj): ";
		if(std::cin.peek()=='\n') break;
		std::cin.getline(tim1,sizeof tim1);
		std::cout<<"Unesite ime drugog tima (ENTER za kraj): ";
		if(std::cin.peek()=='\n') break;
		std::cin.getline(tim2,sizeof tim2);
		std::cout<<"Unesite broj postignutih golova za oba tima: ";
		int n,m;
		std::cin>>n>>m;
		try {l1.RegistrirajUtakmicu(tim1,tim2,n,m);}
		catch(std::logic_error e)
		{
			std::cout<<e.what()<<std::endl<<std::endl;
		}
		std::cin.ignore(1000,'\n');
	}
	
	return 0;
}