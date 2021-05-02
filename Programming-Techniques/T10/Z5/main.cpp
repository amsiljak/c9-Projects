/*
    TP 16/17 (Tutorijal 10, Zadatak 5)
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
	int stepeni,minute,sekunde;
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
		stepeni=ugao*180/PI+0.000001;
		minute=(ugao*180/PI-DajStepene())*60+0.000001;
		sekunde=((ugao*180/PI-DajStepene())*60-DajMinute())*60+0.000001;
	}
	void Postavi(int x,int y,int z)
	{
		int nesto=(((DajSekunde()+DajMinute()*60)+DajStepene()*3600)%1296000)%1296000;
		stepeni=nesto/3600;
		minute=(nesto%3600)/60;
		sekunde=nesto%60;
	}
	double DajRadijane() const
	{
		return PI*(stepeni+double(minute)/60+double(sekunde)/3600)/180;
	}
	void OcitajKlasicneJedinice(int &x, int &y, int &z) const{
		x=stepeni;
		y=minute;
		z=sekunde;
	}
	int DajStepene()const
	{
		return stepeni;
	}
	int DajMinute() const
	{
		return minute;
	}
	int DajSekunde() const
	{
		return sekunde;
	};
	void Ispisi() const
	{
		std::cout<<std::setprecision(5)<<std::fixed<<DajRadijane();
	};
	void IspisiKlasicno() const;
	Ugao &SaberiSa(const Ugao &u)
	{
		stepeni+=u.DajStepene();
		minute+=u.DajMinute();
		sekunde+=u.DajSekunde();
		int nesto=((sekunde+minute*60+stepeni*3600)%129600+129600)%129600;
		stepeni=nesto/3600;
		minute=(nesto%3600)/60;
		sekunde=nesto%60;
		return *this;
	};
	Ugao &PomnoziSa(double x)
	{
		stepeni*=x;
		minute*=x;
		sekunde*=x;
		int nesto=((sekunde+minute*60+stepeni*3600)%129600+129600)%129600;
		stepeni=nesto/3600;
		minute=(nesto%3600)/60;
		sekunde=nesto%60;
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
