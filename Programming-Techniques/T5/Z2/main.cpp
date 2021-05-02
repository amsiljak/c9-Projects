/* 
    TP 2018/2019: Tutorijal 5, Zadatak 2
	
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
template <typename Tip1, typename Tip2>
Tip2 RazmijeniBlokove(Tip1 poc, Tip1 kraj, Tip2 novi)
{
	while(poc<kraj)
	{
		auto temp=*poc;
		*poc=*novi;
		*novi=temp;
		poc++;
		novi++;
		
	}
	return novi;
}

int main ()
{
	int a[]{1, 2, 3, 4, 5}, b[]{6, 7, 8, 9, 10};
	RazmijeniBlokove(std::begin(a), std::end(a), std::begin(b));
	std::cout << "Prvi niz: ";
	for(int x : a) std::cout << x << " ";
	std::cout << "\nDrugi niz: ";
	for(int x : b) std::cout << x << " ";
	return 0;
}