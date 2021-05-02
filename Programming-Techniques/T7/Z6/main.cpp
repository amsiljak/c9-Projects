/* 
    TP 16/17 (Tutorijal 7, Zadatak 6)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <list>
template <typename tip>
std::list<tip>SortirajListu(std::list<tip> l)
{
	std::list<tip> novalista;
	typename std::list <tip>::iterator it(l.begin());
	while(it!=l.end())
	{
		auto j=it;
		while(j!=l.end())
		{
			if(*it>*j) {
				auto temp=it;
				it=j;
				j=temp;
			}
		}
		it++;
	}
	return l;
	
}
int main ()
{
	std::list<int> lista;
	int n;
	std::cout<<"Koliko ima elemenata: ";
	std::cin>>n;
	std::cout<<"Unesite  elemente: ";
	for(int i=0;i<n;i++)
	{
		int m;
		std::cin>>m;
		lista.push_back(m);	
	}
	std::cout<<"Sortirana lista: ";
	auto novalista=SortirajListu(lista);
	auto it=novalista.begin();
	while(it!=novalista.end())
	{
		std::cout<<*it;
		it++;
	}
	return 0;
}