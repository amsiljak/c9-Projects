/*
    TP 16/17 (Tutorijal 10, Zadatak 4)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#define PI (atan(1)*4)

class Ugao
{
	double ugaourad;
public:
	Ugao(double ugao=0)
	{
		Postavi(ugao);
	}
	Ugao(double x,double y,double z)
	{
		Postavi(x,y,z);
	}
	void Postavi(double ugao)
	{
		while(ugao>=2*PI) ugao-=2*PI;
		while (ugao<0) ugao+=2*PI;
		ugaourad=ugao;
	}
	void Postavi(int x,int y,int z)
	{
		ugaourad = PI*(x+double(y)/60+double(z)/3600)/180;
		while(ugaourad>=2*PI) ugaourad-=2*PI;
		while (ugaourad<0) ugaourad+=2*PI;
	}
	double DajRadijane() const
	{
		return ugaourad;
	}
	void OcitajKlasicneJedinice(int &x, int &y, int &z) const{
		x = (ugaourad*180/PI) + 0.000001;
		y = (ugaourad*180/PI-DajStepene())*60 + 0.000001;
		z = ((ugaourad*180/PI-DajStepene())*60-DajMinute())*60+0.000001;
	}
	int DajStepene()const
	{
		return (ugaourad*180/PI) + 0.000001;
	}
	int DajMinute() const
	{
		return (ugaourad*180/PI-DajStepene())*60 + 0.000001;
	}
	int DajSekunde() const
	{
		return ((ugaourad*180/PI-DajStepene())*60-DajMinute())*60+0.000001;
	};
	void Ispisi() const
	{
		std::cout<<std::setprecision(5)<<std::fixed<<ugaourad;
	};
	void IspisiKlasicno() const;
	Ugao &SaberiSa(const Ugao &u)
	{
		Postavi(ugaourad+u.ugaourad);
		while(ugaourad>=2*PI) ugaourad-=2*PI;
		while (ugaourad<0) ugaourad+=2*PI;
		return *this;
	};
	Ugao &PomnoziSa(double x)
	{
		Postavi(ugaourad*x);
		while(ugaourad>=2*PI) ugaourad-=2*PI;
		while (ugaourad<0) ugaourad+=2*PI;
		return *this;
	};
	friend Ugao ZbirUglova(const Ugao &u1,const Ugao &u2);
	friend Ugao ProduktUglaSaBrojem(const Ugao &u,double x);
};

void Ugao::IspisiKlasicno() const
{
	std::cout<<DajStepene()<<"deg "<<DajMinute()<<"min "<<DajSekunde()<<"sec";
}
Ugao ZbirUglova(const Ugao &u1, const Ugao &u2){
	return Ugao(u1.DajRadijane()+u2.DajRadijane());
}
Ugao ProduktUglaSaBrojem(const Ugao &u, double x){
	return Ugao(u.DajRadijane()*x);
}
int main ()
{
	return 0;
}
