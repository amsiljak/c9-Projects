/* 
    TP 16/17 (Tutorijal 12, Zadatak 2)
	Autotestove napisao Kerim Hodzic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: khodzic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <set>
#include <utility>
#include <vector>

template <typename tip1,typename tip2>
std::vector<std::pair<tip1,tip2>> operator%(std::set<tip1>s1,std::set<tip2>s2)
{
	std::vector<std::pair<tip1,tip2>>parovi(s1.size()*s2.size());
	int br(0);
	for(auto it1=s1.begin();it1!=s1.end();it1++)
	{
		for(auto it2=s2.begin();it2!=s2.end();it2++)
		{
			parovi[br]=(std::make_pair(*it1,*it2));
			br++;
		}
	}
	return parovi;
}
template <typename tip1,typename tip2>
std::ostream &operator<<(std::ostream &tok,std::vector<std::pair<tip1,tip2>>parovi)
{
	tok<<"{";
	for(int i=0;i<parovi.size();i++)
	{
		tok<<"("<<parovi[i].first<<","<<parovi[i].second<<")";
		if(i!=parovi.size()-1) tok<<",";
	}
	tok<<"}";
	return tok;
}
template <typename tip>
std::set<tip> operator+=(std::set<tip> &s1,std::set<tip> s2)
{
	for(tip x:s2) s1.insert(x);
	return s1;
}
template <typename tip>
std::set<tip> operator*=(std::set<tip> &s1,std::set<tip> s2)
{
	s1=s1*s2;
	return s1;
}

template <typename tip>
std::set<tip> operator+(std::set<tip> s1,std::set<tip> s2)
{
	std::set<tip>s3;
	for(tip x:s1) s3.insert(x);
	for(tip x:s2) s3.insert(x);
	return s3;
}

template <typename tip>
std::set<tip> operator*(std::set<tip>s1,std::set<tip>s2)
{
	std::set<tip>s3;
	for(tip x:s1) {
		if(s2.count(x)==1) s3.insert(x);
	}
	return s3;
}
template <typename tip>
std::ostream &operator<<(std::ostream &tok,std::set<tip>s)
{
	tok<<"{";
	for(auto it=s.begin();it!=s.end();it++)
	{
		if(it!=--s.end())tok<<*it<<",";
		else tok<<*it;
	}
	tok<<"}";
	return tok;
}
int main ()
{
	std::set<double> s1{3.6, 5.1, 1, 2, 8};
  s1 *= std::set<double>{3.6,10,3, 2., 9};
  std::cout << s1 << std::endl;
	return 0;
}