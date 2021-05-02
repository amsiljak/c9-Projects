//TP 2018/2019: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector> 

std::set<int> NadjiRijec(std::string rijec,std::string s)
{
    std::vector<int> v;
    std::set<int> pozicije;
    auto iter=s.begin();
    int br1(0);
    while(iter!=s.end())
    {
        //--------------
        int br2(0);
        if(*iter==*rijec.begin()) 
        {
            auto iter1=rijec.begin();
            while(*iter==*iter1)
            { 
                if(iter==s.end() || iter1==rijec.end()) break;
                //----------
                iter++; iter1++; br1++; br2++;
            }
            if(iter1==rijec.end() || iter==s.end()) {
                //-----------
                pozicije.insert(br1-br2);
                v.push_back(br1-br2);
            }
        }
        if(iter==s.end()) break;
        iter++;
        br1++;
    }
    return pozicije;
}

std::set<int> PretraziIndeksPojmova(std::string rijec,std::map<std::string,std::set<int>>indeks)
{
    if(!indeks.count(rijec)) throw std::logic_error("Unesena rijec nije nadjena!");
    else return indeks[rijec];
}

std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string s)
{
    std::map<std::string,std::set<int>> indeks;
    auto it=s.begin();
    std::vector<std::string> rijeci;
    while(it!=s.end()) {if(*it>='A' && *it<='Z') (*it)+=32; it++;};
    it=s.begin();
    int brojac(0);
    
    //odvajanje rijeci u vektor
    while(it!=s.end())
    {
        std::string rijec;
        if(it==s.begin() || *it==' ')
        {
            rijeci.resize(rijeci.size()+1);
            if(*it==' ') it++;
            auto it1=it;
            while(it!=s.end() && *it!=' ') it++;
            while(it1!=it) {rijec.push_back(*it1); it1++;}
            if(it==s.end()) rijec.push_back(*it);
            rijeci[brojac]=rijec; brojac++;
        }
        else it++;
    }
    for(int i=0;i<brojac;i++)
    {
        bool postoji=false;
        auto skup=NadjiRijec(rijeci[i], s);
        auto iter=indeks.begin();
        for(int j=0; j<indeks.size(); j++) {
            std::string a= rijeci[i];
            std::string b=iter->first;
            if(a.compare(b)==0)
                postoji=true;
            iter++;
        }
        if(!postoji)
            indeks.insert({rijeci[i],skup});
        
    }
    return indeks;
}

void IspisiIndeksPojmova(std::map<std::string,std::set<int>> indeks)
{
    auto it=indeks.begin();
    while(it!=indeks.end())
    {
        std::cout<<it->first<<": ";
        for(int x:it->second) std::cout<<x<<",";
        it++;
        std::cout<<std::endl;
    }
}
int main ()
{
    std::cout<<"Unesite tekst: ";
    // std::cin.ignore();
    std::string s;
    std::getline(std::cin,s);
    auto mapa=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(mapa);
    std::string rijec;
    while(1)
    {
        std::cout<<"Unesite rijec: ";
        std::cin>>rijec;
        if(*rijec.c_str()=='.') break;
        auto skup=PretraziIndeksPojmova(rijec,mapa);
        for(int x:skup) std::cout<<x<<" ";
        std::cout<<std::endl;
    }
	return 0;
}