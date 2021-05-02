/* 
    TP 16/17 (Tutorijal 11, Zadatak 2)
	Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: hhasic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <stdexcept>

class StedniRacun
{
	double stanjeracuna;
	static int *pnb;
	static int aktivni;
public:
	static int DajBrojKreiranih() {return aktivni;}
	static int DajBrojAktivnih() {return *pnb;}
	StedniRacun() {stanjeracuna=0; (*pnb)++; aktivni++;}
	StedniRacun(double x)
	{
		if(x<0) throw std::logic_error("Nedozvoljeno pocetno stanje");
		stanjeracuna=x;
		(*pnb)++;
		aktivni++;
	}
	StedniRacun(const StedniRacun &s){(*pnb)++; aktivni++;}
	~StedniRacun(){(*pnb)--;}
	void Ulozi(double x);
	void Podigni(double x);
	double DajStanje() const;
	void ObracunajKamatu(double x);
};
int *StedniRacun::pnb=new int(0);
int StedniRacun::aktivni(0);
void StedniRacun::Ulozi(double x)
{
	if(stanjeracuna+x<0) throw std::logic_error("Transakcija odbijena");
	stanjeracuna+=x;
}
void StedniRacun::Podigni(double x)
{
	if (x>stanjeracuna) throw std::logic_error("Transakcija odbijena");
	stanjeracuna-=x;
}
double StedniRacun::DajStanje() const
{
	return stanjeracuna;
}
void StedniRacun::ObracunajKamatu(double x)
{
	if(x<0) throw std::logic_error("Nedozvoljena kamatna stopa");
	x/=100;
	stanjeracuna+=stanjeracuna*x;
}

int main ()
{
	StedniRacun s1(0),s2;
	{StedniRacun s3;}
	StedniRacun s4(s1);
	std::cout<<StedniRacun::DajBrojKreiranih()<<StedniRacun::DajBrojAktivnih();
	return 0;
}