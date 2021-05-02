/* 
    TP 16/17 (Tutorijal 6, Zadatak 1)
	
	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja 
	i sugestije saljite na mail: khodzic2@etf.unsa.ba
	
	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak
	
*/
#include <iostream>
#include <cmath>
#include <new>
#include <stdexcept>
#include <limits>
template <typename TipNiza>
TipNiza *GenerirajStepeneDvojke(int n)
{
	try {
		TipNiza *p;
		if(n<=0) throw std::domain_error("Broj elemenata mora biti pozitivan");
		p=new TipNiza[n];
		for(int i=0;i<n;i++)
		{
			if(powl(2,i)>(std::numeric_limits<TipNiza>::max())) 
			{
				delete[] p;
				throw std::overflow_error("Prekoracen dozvoljeni opseg");
			}
			p[i]=powl(2,i);
			
		}
		return p;
	}
	catch (std::bad_alloc) {
		throw std::runtime_error("Alokacija nije uspjela");
	}
	catch(std::domain_error)
	{
		throw;
	}
	catch(std::overflow_error)
	{
		throw;
	}
}
int main ()
{
	try{
		int n;
		std::cout<<"Koliko zelite elemenata: ";
		std::cin>>n;
		if(n<=0) throw std::domain_error("Broj elemenata mora biti pozitivan");
		auto a=GenerirajStepeneDvojke<int>(n);
		for(int i=0;i<n;i++)
		{
			std::cout<<a[i]<<" ";
		}
		delete[] a;
	}
	catch(std::domain_error e)
	{
		std::cout<<"Izuzetak: "<<e.what()<<std::endl;
	}
	catch(std::overflow_error e)
	{
		std::cout<<"Izuzetak: "<<e.what()<<std::endl;
	}
	catch(std::bad_alloc e)
	{
		std::cout<<"Izuzetak: "<<e.what()<<std::endl;
	}
	return 0;
}