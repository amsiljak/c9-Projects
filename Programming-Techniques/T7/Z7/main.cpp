/* 
    TP 16/17 (Tutorijal 7, Zadatak 7)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <set>

template <typename tip>
std::set<tip>Unija(std::set<tip> s1,std::set<tip> s2)
{
	std::set<tip>s3;
	for(tip x:s1) s3.insert(x);
	for(tip x:s2) s3.insert(x);
	return s3;
}

template <typename tip>
std::set<tip> Presjek(std::set<tip>s1,std::set<tip>s2)
{
	std::set<tip>s3;
	for(tip x:s1) {
		if(s2.count(x)==1) s3.insert(x);
	}
	return s3;
}

int main ()
{
	std::set<std::string> s1;
	std::set<std::string>s2;
	auto set1=Unija(s1,s2);
	std::cout<<"Unija skupova je: ";
	for(std::string x:set1) std::cout<<"x ";
	std::cout<<"Presjek skupova je: ";
	return 0;
}