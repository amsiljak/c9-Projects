/* 
    TP 2018/2019: Tutorijal 5, Zadatak 6
	
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
#include <vector>
#include <algorithm>
#include <cmath>
void Unos(int &a)
{
	std::cin>>a;
}
void Ispis(int a)
{
	std::cout<<" "<<a;
}

int SumaCifara (int a)
{
	if(a==0) return 0;
	return abs(a)%10+SumaCifara(abs(a)/10);
}
bool Kriterij(int a,int b)
 {
 	if(SumaCifara(a)<SumaCifara(b)) return true;
 	if(SumaCifara(b)<SumaCifara(a)) return false;
 	return a<b;
 }

int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata: ";
	std::cin>>n;
	std::cout<<"Unesite elemente: ";
	std::vector<int>v(n);
	std::for_each(v.begin(),v.end(),Unos);
	std::cout<<"Niz sortiran po sumi cifara glasi:";
	std::vector<int>novi(n);
	std::partial_sort_copy(v.begin(),v.end(),novi.begin(), novi.end(),Kriterij);
	std::for_each(novi.begin(),novi.end(),Ispis);
	std::cout<<std::endl;
	std::cout<<"Unesite broj koji trazite: ";
	int m;
	std::cin>>m;
	if(std::binary_search(novi.begin(), novi.end(),m,Kriterij)) 
	{
		std::cout<<"Trazeni broj nalazi se na poziciji "<<std::find(novi.begin(),novi.end(),m)-novi.begin()<<std::endl;
	}
	else std::cout<<"Trazeni broj ne nalazi se u nizu!"<<std::endl;
	return 0;
}