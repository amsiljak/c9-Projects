/* 
    TP 16/17 (Tutorijal 11, Zadatak 3)
	Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: hhasic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <cstring>
#include <iomanip>

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
int main ()
{
	Tim t("ja");
	t.IspisiPodatke();
	return 0;
}