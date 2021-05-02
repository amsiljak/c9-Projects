/* 
    TP 2018/2019: Tutorijal 5, Zadatak 4
	
	Autotestove pisala Nina Slamnik. Prijave gresaka, sugestije i pitanja
	mozete slati na mail nslamnik1@etf.unsa.ba.
	
	NAPOMENA: Tutorijal 5 sadrzi veliki broj ZABRANA, tipa zabrana
			  da se koristi indeksiranje niz[i] ili simulacija indeksiranja
			  npr. *(niz + i); dalje, da su zabranjene for petlje i slicno.
			  
			  To ce tutori rucno pregledati u toku tutorijala te ako
			  student bude PREKRSIO BAREM JEDNU ZABRANU, smatrace se da
			  za taj zadatak NIJE PROSAO NITI JEDAN AUTOTEST!
*/
#include <iostream>
#include <deque> 
#include <algorithm>
#include <cmath>
void Unos(int &n)
{
	std::cin>>n;
}
bool potpunkvadrat(int n)
{
	return int(sqrt(n))==sqrt(n);
}
bool pravilo(int n,int m)
{
	return int(log10(abs(n)))<int(log10(abs(m)));
}
bool Trocifreni(int n)
{
	return int(log10(abs(n))+1)==3;
}
void Ispis(int n)
{
	std::cout<<" "<<n;
}
int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata: ";
	std::cin>>n;
	std::deque<int>niz(n);
	std::cout<<"Unesite elemente: ";
	std::for_each(niz.begin(),niz.end(),Unos);
	std::cout<<"Najveci element deka je "<<*std::max_element(niz.begin(),niz.end())<<" "<<std::endl;
	std::cout<<"Najmanji element deka se pojavljuje "<<std::count(niz.begin(),niz.end(),*std::min_element(niz.begin(),niz.end()))<<" puta u deku"<<std::endl;
	std::cout<<"U deku ima "<<std::count_if(niz.begin(),niz.end(), potpunkvadrat)<<" brojeva koji su potpuni kvadrati"<<std::endl;
	std::cout<<"Prvi element sa najmanjim brojem cifara je "<<*std::min_element(niz.begin(),niz.end(),pravilo)<<std::endl;
	std::cout<<"Elementi koji nisu trocifreni su:";
	std::deque<int>trocifreni(1000);
	auto kraj=std::remove_copy_if(niz.begin(),niz.end(),trocifreni.begin(),Trocifreni);
	std::for_each(trocifreni.begin(),kraj,Ispis);
	return 0;
}