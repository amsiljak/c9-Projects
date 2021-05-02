/* 
    TP 16/17 (Tutorijal 13, Zadatak 1)
	Autotestove pisala Ivona Ivkovic. Sva pitanja, sugestije, prijave gresaka
	slati na mail iivkovic2@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <cmath>
#include <memory>
#include <vector>

class Lik
{
public:
	virtual ~Lik(){}
	virtual void IspisiSpecificnosti() const=0;
	virtual double DajObim() const=0;
	virtual double DajPovrsinu() const=0;
	void Ispisi()
	{
		IspisiSpecificnosti();
		std::cout<<"Obim: "<<DajObim()<<" Povrsina: "<<DajPovrsinu()<<std::endl;
	}
};
class Krug: public Lik
{
	double poluprecnik;
	static constexpr double PI=3.14159265353589793;
public:
	Krug(double r)
	{
		if(r<=0) throw std::domain_error("Neispravni parametri");
		poluprecnik=r;
	}
	void IspisiSpecificnosti() const override 
	{
		std::cout<<"Krug poluprecnika "<<poluprecnik<<std::endl;
	}
	double DajObim() const override
	{
		return 2*poluprecnik*PI;
	}
	double DajPovrsinu() const override
	{
		return poluprecnik*poluprecnik*PI;
	}
};
class Pravougaonik: public Lik
{
	double a,b;
public:
	Pravougaonik(double str1,double str2)	{
		a=str1; b=str2;
		if(a<=0 || b<=0) throw std::domain_error("Neispravni parametri");
	};
	void IspisiSpecificnosti() const override 
	{
		std::cout<<"Pravougaonik sa stranicama duzine "<<a<<" i "<<b<<std::endl;
	}
	double DajObim() const override
	{
		return 2*a+2*b;
	}
	double DajPovrsinu() const override
	{
		return a*b;
	}
};
class Trougao: public Lik
{
	int a,b,c;
public:
	Trougao(double str1,double str2,double str3):a(str1),b(str2),c(str3)
	{
		if(a<=0 || b<=0 || c<=0 || a+b <= c || a+c <= b || b+c <= a|| abs(a-b)>=c || abs(b-c)>=a || abs(a-c)>=b) throw std::domain_error("Neispravni parametri");
	}
	void IspisiSpecificnosti() const override 
	{
		std::cout<<"Trougao sa stranicama duzine "<<a<<", "<<b<<" i "<<c<<std::endl;
	}
	double DajObim() const override
	{
		return a+b+c;
	}
	double DajPovrsinu() const override
	{ 
		double s=DajObim()/2;
		return sqrt(s*(s-a)*(s-b)*(s-c));
	}
};
int main ()
{
	std::cout<<"Koliko zelite likova: ";
	int n;
	std::cin>>n;j
	std::vector<std::shared_ptr<Lik>>vek(n);
	
	for(int i=0;i<n;i++)
	{
		std::cout<<"Lik "<<i+1<<": ";
		std::cin.ignore(1000,'\n');
	
		switch(std::cin.get())
		{
			case 'K':
				double r;
				std::cin>>r;
				if(std::cin && std::cin.peek()=='\n')
				{
					try{vek[i]=std::make_shared<Krug>(r);}
					catch(std::domain_error e){std::cout<<"Pogresni podaci, ponovite unos!"<<std::endl; std::cin.clear(); i--;}
				}
				else 
				{
					std::cout<<"Pogresni podaci, ponovite unos!"<<std::endl; std::cin.clear();  i--;
				}
				break;
			case 'P':
				double a,b; char znak;
				std::cin>>a>>znak>>b;
				if(std::cin && znak==',' && std::cin.peek()=='\n')
				{
					try{vek[i]=std::make_shared<Pravougaonik>(a,b);}
					catch(std::domain_error e){std::cout<<"Pogresni podaci, ponovite unos!"<<std::endl; std::cin.clear(); i--;}
				}
				else 
				{
					std::cout<<"Pogresni podaci, ponovite unos!"<<std::endl; std::cin.clear();  i--;
				}
				break;
			case 'T':
				double c,d,e;
				char znak1,znak2;
				std::cin>>c>>znak1>>d>>znak2>>e;
				if(std::cin && znak1==',' && znak2==',' &&std::cin.peek()=='\n')
				{
					try{vek[i]=std::make_shared<Trougao>(c,d,e);}
					catch(std::domain_error e){std::cout<<"Pogresni podaci, ponovite unos!"<<std::endl; std::cin.clear(); i--;}
				}
				else 
				{
					std::cout<<"Pogresni podaci, ponovite unos!"<<std::endl; std::cin.clear();  i--;
				}
				break;
			default:
				std::cout<<"Pogresni podaci, ponovite unos!"<<std::endl; std::cin.clear();  i--; break;
		}
	}
	std::cout<<std::endl;
		for(int i=0;i<n;i++)
	{
		vek[i]->Ispisi();
	}


	return 0;
}