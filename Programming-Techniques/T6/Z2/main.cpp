/* 
    TP 16/17 (Tutorijal 6, Zadatak 2)
	
	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja 
	i sugestije saljite na mail: khodzic2@etf.unsa.ba
	
	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak
	
*/
#include <iostream>
#include <vector> 
#include <type_traits>
template <typename tip>
auto KreirajIzvrnutiNiz(tip pocetak,tip kraj) -> typename std::remove_reference<decltype(*pocetak)>::type*
{
	typename std::remove_reference<decltype(*pocetak)>::type *n = nullptr;
	try
	{
		auto p1=pocetak;
		int br_el=0;
		do
		{
			p1++;
			br_el++;
		} while(p1!=kraj);
		
		n=new typename std::remove_reference<decltype(*pocetak)>::type[br_el]{};
		for(int i=br_el-1;i>=0;i--)
		{
			n[i]=*pocetak++;
		}
		return n;
	}
	catch(std::bad_alloc)
	{
		if(n) delete[] n;
		throw;
	}
}

int main ()
{
	int n;
	std::cout<<"Koliko zelite elemenata: ";
	std::cin>>n;
	try
	{
		std::vector<double> v(n);
		std::cout <<"Unesite elemente: ";
		for(int i=0;i<n;i++)
		{
			std::cin>>v.at(i);
		}
		std::cout<<"Kreirani niz: ";
		auto a=KreirajIzvrnutiNiz(v.begin(),v.end());
		for(int i=0;i<n;i++)
		{
			std::cout<<a[i]<<" ";
		}
		delete[] a;
	}
	catch(std::bad_alloc)
	{
		std::cout<<"Nedovoljno memorije!";
	}
	return 0;
}