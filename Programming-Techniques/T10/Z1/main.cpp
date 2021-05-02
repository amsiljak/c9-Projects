/* 
    TP 16/17 (Tutorijal 10, Zadatak 1)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <stdexcept>

class StedniRacun
{
	double stanjeracuna;
public:
	StedniRacun() {stanjeracuna=0;}
	StedniRacun(double x) {
		if(x<0) throw std::logic_error("Nedozvoljeno pocetno stanje");
		stanjeracuna=x;
	}
	void Ulozi(double x);
	void Podigni(double x);
	double DajStanje() const;
	void ObracunajKamatu(double x);
};
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
	try
	{
		StedniRacun a(500);
	    const StedniRacun b(30);
	    a.Ulozi(50);
	    std::cout<<a.DajStanje()<<std::endl;
	    std::cout<<b.DajStanje()<<std::endl;
	    a.Podigni(20);
	    a.ObracunajKamatu(2);
	    std::cout<<a.DajStanje()<<std::endl;
	}
	catch(std::logic_error e)
	{
		std::cout<<"Izuzetak: "<<e.what();
	}
	return 0;
}