//TP 2018/2019: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <stdexcept>

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> vektor_imena,int k)
{
    if(k<1 || k>vektor_imena.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::vector<std::set<std::string>> timovi(k);
    std::list<std::string> lista_imena;

    int n=vektor_imena.size(); //broj djece
    for(int i=0; i<n; i++) lista_imena.push_back(vektor_imena[i]);



    int a=n%k; //broj timova koji ima c clanova
    int c=n/k+1;

    auto it1=lista_imena.begin();
    //prvih a timova
    for(int i=0; i<a; i++)
        {
            for(int j=0; j<c; j++)
                {
                    timovi[i].insert(*it1);
                    int broj_slova1=0;
                    for(auto x : *it1)
                        if((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9')) broj_slova1++;
                    it1=lista_imena.erase(it1);
                    if(it1==lista_imena.end()) it1=lista_imena.begin();
                    if(lista_imena.size()==0) return timovi;

                    int br1(1); // 1 zato sto je iterator vec pomjeren za jedan sa erase
                    while(br1!=broj_slova1)
                        {
                            it1++;
                            if(it1==lista_imena.end()) it1=lista_imena.begin();
                            br1++;
                        }
                }
        }
    // ostali timovi
    for(int i=a; i<k; i++)
        {
            for(int j=0; j<n/k; j++)
                {
                    timovi[i].insert(*it1);
                    int broj_slova2=0;
                    for(auto x : *it1)
                        if((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9')) broj_slova2++;
                    it1=lista_imena.erase(it1);
                    if(it1==lista_imena.end()) it1=lista_imena.begin();

                    if(lista_imena.size()==0) return timovi;

                    int br2(1);
                    while(br2!=broj_slova2)
                        {
                            it1++;
                            if(it1==lista_imena.end()) it1=lista_imena.begin();
                            br2++;
                        }
                }
        }


    return timovi;
}

int main ()
{
    try
        {
            int n;
            std::cout<<"Unesite broj djece: ";
            std::cin>>n;
            std::cout<<"Unesite imena djece: ";
            std::vector<std::string> v(n);
            std::cin.ignore(1000, '\n');
            for(int i=0; i<n; i++) std::getline(std::cin, v[i]);
            int m;
            std::cout<<"\nUnesite broj timova: ";
            std::cin>>m;

            auto timovi=Razvrstavanje(v,m);
            for(int i=0; i<m; i++)
                {
                    std::cout<<"Tim "<<i+1<<": ";
                    auto tim=timovi[i];
                    for(auto x = tim.begin(); x != tim.end(); x++) 
                        if(x!=--tim.end())
                        std::cout<<*x<<", ";
                        else
                        std::cout<<*x;
                    std::cout<<std::endl;

                }
        }
    catch(std::logic_error e)
        {
            std::cout<<"Izuzetak: "<<e.what();
        }
    return 0;
}
