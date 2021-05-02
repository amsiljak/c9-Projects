/* TP, 2018/2019, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.	
*/
#include <iostream>
#include <cmath>
#include <vector>

std::vector<int> PalindromskaOtpornost (std::vector<int> v)
{
	int x, novibroj=0,n,broj;
	std::vector <int>brojaci(v.size());
	for(int i=0;i<v.size() && i>=0;i++) 
	{
		n=abs(v.at(i));
		while (1) {
			
			broj=n;
			novibroj=0;
			while(1)
			{
				x=broj%10;
				novibroj=x+10*novibroj;
				broj=broj/10;
				if(broj<1) break;
			}
			
			if(novibroj==n) 
			{
				break;
			}
			
			else
			{
				n+=novibroj;
				brojaci[i]++;
			}
		}
	}
	return brojaci;
}
	
	
int main()
{
	std::cout<<"Koliko zelite unijeti elemenata: ";
	int brojelemenata;
	std::cin>> brojelemenata;
	std::cout<<"Unesite elemente: ";
	std::vector<int>v(brojelemenata);
	for(int i=0;i<brojelemenata && i>=0;i++)
	{
		int n;
		std::cin>>n;
		v.at(i)=n;
	}
	
	std::vector<int> brojaci=PalindromskaOtpornost(v);
		
	for(int i=0;i<brojelemenata && i>=0;i++)
	{
		std::cout<<"Palindromska otpornost broja "<<v.at(i)<<" iznosi "<<brojaci.at(i)<<std::endl;
	}
	

	return 0;
}