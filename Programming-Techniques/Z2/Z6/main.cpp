/* TP, 2018/2019
*/
#include <iostream>
#include <string>
#include <algorithm>

bool KriterijSortiranja(std::string s1,std::string s2)
{
    if(s1.size()!=s2.size()) return s1.size()<s2.size();
    else
    {
        for(int i=0;i<s1.size();i++)
        {
            for(int j=0;j<s2.size();j++)
            {
                if(toupper(s1[i])!=toupper(s2[j])) return toupper(s1[i])<toupper(s2[j]);
            }
        }
    }
    return true;
}

void SortirajPoDuzini(std::string *pok,int n)
{
    sort(pok,pok+n,KriterijSortiranja);
}

bool PretraziBinarno(std::string *pok,int n, std::string rijec)
{
    return binary_search(pok,pok+n,rijec);
}
int main ()
{
    int n;
    std::cout<<"Unesite broj rijeci: ";
    std::cin>>n;
    std::string *pok=new std::string[n];
    std::cout<<"Unesite rijeci: ";
    std::string s;
    auto pok1=pok;
    for(int i=0;i<n;i++)
    {
        std::cin>>s;
        *pok1=s;
        pok1++;
    }
    SortirajPoDuzini(pok,n);
    auto pok2=pok;
    std::cout<<"Sortirane rijeci: ";
    for(int i=0;i<n;i++)
    {
        std::cout<<*pok2<<" ";
        pok2++;
    }
    std::cout<<std::endl;
    std::string rijec;
    std::cout<<"Unesite rijec za pretragu: ";
    std::cin>>rijec;
    if(PretraziBinarno(pok,n,rijec)) std::cout<<"Rijec '"<<rijec<<"' se nalazi u nizu.";
    else std::cout<<"Rijec '"<<rijec<<"' se ne nalazi u nizu.";
    delete[] pok;
	return 0;
	
}