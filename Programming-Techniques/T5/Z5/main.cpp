/* 
    TP 2018/2019: Tutorijal 5, Zadatak 5
	
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
#include <cmath>
#include <iomanip>
#define pi atan(1)*4

double TrapeznoPravilo(double fun(double),double a,double b,int n)
{
	double rezultat=0;
	rezultat+=fun(a)/2;
	rezultat+=fun(b)/2;
	for(int i=1;i<n;i++) rezultat+=fun(a+(b-a)*i/n);
	rezultat*=(b-a)/n;
	return rezultat;
}

int main ()
{
	int n;
	std::cout<<"Unesite broj podintervala: ";
	std::cin>>n;
	std::cout<<"Za taj broj podintervala priblizne vrijednosti integrala iznose: "<<std::endl;
	std::cout<<"- Za funkciju sin x na intervalu (0,pi): "<<std::fixed<<std::setprecision(5)<<TrapeznoPravilo([](double x){return sin(x);},0,pi,n)<<std::endl;
	std::cout<<"- Za funkciju x^3 na intervalu (0,10): "<<std::setprecision(2)<<TrapeznoPravilo([](double x){return x*x*x;},0,10,n)<<std::endl;
	std::cout<<"- Za funkciju 1/x na intervalu (1,2): "<<std::setprecision(5)<<TrapeznoPravilo([](double x){return 1/x;},1,2,n)<<std::endl;
	return 0;
}