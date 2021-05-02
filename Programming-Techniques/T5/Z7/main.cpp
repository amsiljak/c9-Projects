/* 
    TP 2018/2019: Tutorijal 5, Zadatak 7
	
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
template <typename Tip>
auto SumaBloka(Tip m, Tip n) ->decltype(*m+*m)
{
	if(m==n) throw std::range_error("Blok je prazan");
	decltype(*m+*m) Suma{};
	while(m!=n)
	{
		Suma+=*m;
		m++;
	}
	return Suma;
}
int main ()
{
	return 0;
}