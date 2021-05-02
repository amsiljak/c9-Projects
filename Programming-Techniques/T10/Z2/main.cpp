/* 
    TP 16/17 (Tutorijal 10, Zadatak 2)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdexcept>
#define PI atan(1)*4

class Krug
{
	double poluprecnik;
public:
	explicit Krug(double r) {if(r<=0) throw std::domain_error("Neispravan poluprecnik"); poluprecnik=r;};
	void Postavi(double r) {if(r<=0) throw std::domain_error("Neispravan poluprecnik"); *this=Krug(r);};
	double DajPoluprecnik() const{ return poluprecnik;};
	double DajObim() const  {return 2*poluprecnik*PI;}; 
	double DajPovrsinu() const { return poluprecnik*poluprecnik*PI; };
	void Skaliraj(double x) { if(x<=0) throw std::domain_error("Neispravan faktor skaliranja"); poluprecnik*=x; };
	void Ispisi() const{
	std::cout<<"R="<<std::setprecision(5)<<std::fixed<<DajPoluprecnik()<<" ";
	std::cout<<"O="<<DajObim()<<" ";
	std::cout<<"P="<<DajPovrsinu()<<std::endl;
	};
};
	

class Valjak
{
	Krug baza;
	double visina;
public:
	Valjak(double r, double h) : baza(r),visina(h){if(r<0) throw std::domain_error("Neispravan poluprecnik"); if(h<0) throw std::domain_error("Neispravna visina");};
	void Postavi(double r,double h);
	Krug DajBazu() const { return baza;};
	double DajPoluprecnikBaze() { return baza.DajPoluprecnik();};
	double DajVisinu() const { return visina; };
	double DajPovrsinu() const { return baza.DajPovrsinu()*2+baza.DajObim()*visina;};
	double DajZapreminu() const { return baza.DajPovrsinu()*visina;};
	void Skaliraj(double x);
	void Ispisi() const;
};
void Valjak::Postavi(double r,double h)
{
	if(r<0) throw std::domain_error("Neispravan poluprecnik");
	if(h<0) throw std::domain_error("Neispravna visina");
	*this=Valjak(r,h);
}
void Valjak::Skaliraj(double x)
{
	if(x<=0) throw std::domain_error("Neispravan faktor skaliranja");
	baza.Skaliraj(x);
	visina*=x;
}
void Valjak::Ispisi() const
{
	std::cout<<"R="<<baza.DajPoluprecnik()<<" ";
	std::cout<<"H="<<DajVisinu()<<" ";
	std::cout<<"P="<<DajPovrsinu()<<" ";
	std::cout<<"V="<<DajZapreminu()<<" ";
}
int main ()
{
	Krug k1(5);
Valjak v1(1,9);
const Krug k2(k1);                          
const Valjak v2(v1);
k2.Ispisi(); std::cout << std::endl;
v2.Ispisi(); std::cout << std::endl;
	return 0;
}