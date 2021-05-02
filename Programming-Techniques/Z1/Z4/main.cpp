/* TP, 2018/2019, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.	
*/
#include <iostream>
#include <vector>
#include <string>
#include <cctype>

bool SlovoILICifra(char c)
{
	c=std::toupper(c);
	if((c>='A' && c<='Z') || (c>='0' && c<='9')) return true;
	else return false;
}
std::vector <std::string> NadjiSimetricneRijeci (std::string s)
{
	std::vector<std::string> v;
	for(int i=0;i<s.size();i++)
	{
		while(SlovoILICifra(s.at(i))==false && i!=s.size()-1) i++; 
		int j=i;
		// j se postavlja na kraj rijeci
		while(1)
		{
			if(j==s.size()-1) break;
			j++;
			if(SlovoILICifra(s.at(j))==false) 
			{
				j--;
				break;
			}
		}
		if(j-i<1) 
		{
			i=j;
			continue;
		} //provjerava da li sadrzi dva znaka
		for(int k=0;k<=(j-i)/2;k++)
		{
			if(std::toupper(s.at(i+k))!=std::toupper(s.at(j-k))) break;
			else if(k==(j-i)/2) 
			{
				std::string tempstring;
				for(int g=i;g<=j;g++)
				{
					tempstring.push_back(s.at(g));
				}
				v.push_back(tempstring);
			}
			else continue;
		}
		i=j;
	}
	return v;
}
int main ()
{
	std::vector <std::string> v;
	std::string recenica;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,recenica);
	v=NadjiSimetricneRijeci(recenica);
	if(v.size()==0) std::cout<<std::endl<<"Recenica ne sadrzi simetricne rijeci!";
	else 
	{
		std::cout<<std::endl<<"Simetricne rijeci unutar recenice su: "<<std::endl;
		for(int i=0;i<v.size();i++)
		{
			std::cout<<v.at(i)<<std::endl;
		}
	}
	return 0;
}