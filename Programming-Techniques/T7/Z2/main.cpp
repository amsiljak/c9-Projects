/* 
    TP 16/17 (Tutorijal 7, Zadatak 2)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
int main ()
{
	int n;
	std::cout<<"Koliko zelite recenica: ";
	std::cin>>n;
	std::cin.ignore(1000, '\n');
	std::cout<<"Unesite recenice: "<<std::endl;
	try
	{
		char** recenica(new char*[n]);
		try
		{
			for(int i=0;i<n;i++)
			{
				char pomocni[1000];
				std::cin.getline(pomocni,1000);
				recenica[i]=new char[std::strlen(pomocni)+1];
				std::strcpy(recenica[i],pomocni);
			}
			std::sort(recenica,recenica+n,[](const char *a, const char *b){return std::strcmp(a,b)<0;});
			std::cout<<"Sortirane recenice: "<<std::endl;
			for(int i=0;i<n;i++)
			{
				std::cout<<recenica[i]<<std::endl;
			}
			for(int i=0;i<n;i++) delete[] recenica[i];
			delete[] recenica;
		}
		catch(...)
		{
			std::cout<<"Problemi s memorijom!";
			for(int i=0;i<n;i++) delete[] recenica[i];
			delete[] recenica;
		}
	}
	catch(...)
	{
		std::cout<<"Problemi s memorijom!";
	}
	return 0;
}