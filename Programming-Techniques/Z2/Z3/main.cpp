/* TP, 2018/2019
*/
#include <iostream>
#include <deque>
#include <vector> 
#include <algorithm>

template <typename tip1,typename tip2, typename tip3>

auto SimetricnaRazlikaBlokova(tip1 poc1,tip1 izakraja1,tip2 poc2,tip2 izakraja2,tip3 poc_novog) -> tip3
{
    std::vector<decltype(*poc1+*poc1)> prvi;
    std::vector<decltype(*poc2+*poc2)> drugi;
    std::vector<decltype(*poc1+*poc1)> treci;
    
    //kreiram blokove
    while(poc1!=izakraja1)
    {
        prvi.push_back(*poc1);
        poc1++;
    }
    while(poc2!=izakraja2)
    {
        drugi.push_back(*poc2);
        poc2++;
    }
    
    //stavljam ponavljajuce elemente u treci
    for(int i=0;i<prvi.size();i++)
    {
        for(int j=0;j<prvi.size();j++)
        {
            if(i!=j)
            {
                if(prvi.at(i)==prvi.at(j)) prvi.erase(prvi.begin()+i);
            }
        }
    }
    for(int i=0;i<drugi.size();i++)
    {
        for(int j=0;j<drugi.size();j++)
        {
            if(i!=j)
            {
                if(drugi.at(i)==drugi.at(j)) drugi.erase(drugi.begin()+i);
            }
        }
    }
    
    //stavljam u treci vektor sve elemente koji su zajednicki
    for(int i=0;i<prvi.size();i++)
    {
        for(int j=0;j<drugi.size();j++)
        {
            if(prvi.at(i)==drugi.at(j))
            {
                treci.push_back(prvi.at(i));
            }
        }
    }
    bool jel=true;
    int brojelnovog=0;
    //stavljam el. prvog vektora u zavrsni 
    for(int i=0;i<prvi.size();i++)
    {
        for(int j=0;j<treci.size();j++)
        {
            if(prvi.at(i)==treci.at(j))
            {
                jel=false;
            }
        }
        if (jel==true)
        {
            *poc_novog=prvi.at(i);
            poc_novog++;
            brojelnovog++;
        }
        jel=true;
    }
    for(int i=0;i<drugi.size();i++)
    {
        for(int j=0;j<treci.size();j++)
        {
            if(drugi.at(i)==treci.at(j))
            {
                jel=false;
            }
        }
        if(jel==true)
        {
            *poc_novog=drugi.at(i);
            poc_novog++;
            brojelnovog++;
        }
        jel=true;
    }
    return poc_novog;
}

int main ()
{
    int n,m,p;
    int niz[100]{};
    std::deque<int> d;
    std::cout<<"Unesite broj elemenata niza"<<std::endl;
    std::cin>>n;
    std::cout<<"Unesite elemente niza"<<std::endl;
    for(int i=0;i<n;i++)
    {
        std::cin>>niz[i];
    }
    std::cout<<"Unesite broj elemenata deka"<<std::endl;
    std::cin>>m;
    std::cout<<"Unesite elemente deka"<<std::endl;
    for(int i=0;i<m;i++)
    {
        std::cin>>p;
        d.push_back(p);
    }
    std::vector <int> v(200);
    auto kraj_novog=SimetricnaRazlikaBlokova(niz,niz+n,d.begin(),d.end(),v.begin());
    v.resize(kraj_novog-v.begin());
    if(v.begin()==kraj_novog) std::cout<<"Blokovi nemaju simetricnu razliku";
    else
    {
        std::cout<<"Simetricna razlika blokova je:";
        for(int i=0;i<v.size();i++)
        {
            std::cout<<" "<<v.at(i);
        }
    }
	return 0;
}