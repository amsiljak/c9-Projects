/* 
    TP 2018/2019: Tutorijal 5, Zadatak 3
	
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
#include <algorithm>
#include <cmath>
bool potpunkvadrat(int n)
{
	return int(sqrt(n))==sqrt(n);
}
bool pravilo(int n,int m)
{
	return log10(abs(n))<log10(abs(m));
}
bool Trocifreni(int n)
{
	return int(log10(abs(n))+1)==3;
}
void Ispis(int n)
{
	std::cout<<" "<<n;
}
void Unos(int &n)
{
	std::cin>>n;
}
int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata (max. 1000): ";
	std::cin>>n;
	int niz[1000];
	std::cout<<"Unesite elemente: ";
	std::for_each(niz,niz+n,Unos);
	
	std::cout<<"Najveci element niza je "<<*std::max_element(niz,niz+n)<<" "<<std::endl;
	std::cout<<"Najmanji element niza se pojavljuje "<< std::count(niz,niz+n,*std::min_element(niz,niz+n)) <<" puta u nizu"<<std::endl;
	std::cout<<"U nizu ima "<<std::count_if(niz,niz+n,potpunkvadrat) <<" brojeva koji su potpuni kvadrati"<<std::endl;
	std::cout<<"Prvi element sa najmanjim brojem cifara je "<<*std::min_element(niz,niz+n,pravilo)<<std::endl;
	std::cout<<"Elementi koji nisu trocifreni su:";
	int trocifreni[1000];
	auto kraj=std::remove_copy_if(niz,niz+n,trocifreni,Trocifreni);
	std::for_each(trocifreni,kraj,Ispis);
	return 0;
}