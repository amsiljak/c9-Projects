/* TP, 2018/2019
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <deque> 
#include <cmath>

template <typename Tip1,typename Tip2>
bool ZaSve(Tip1 p1,Tip1 p2, Tip2 Kriterij)
{
    auto pok1=p1;
    
    while(pok1!=p2)
    {
        if(std::count_if(pok1,p2,Kriterij)<p2-pok1) return false;
        pok1++;
    }
    return true;
}

template <typename Tip1,typename Tip2>
bool MakarJedan(Tip1 p1,Tip1 p2,Tip2 Kriterij)
{
    auto pok1=p1;
    
    while(pok1!=p2)
    {
        if(std::count_if(pok1,p2,Kriterij)<1) return false;
        pok1++;
    }
    return true;
}

template <typename Tip1>
auto Akumuliraj(Tip1 p1,Tip1 p2,decltype(*p1+*p1) funkcija(decltype(*p1+*p1),decltype(*p1+*p1)),int a0=0) -> decltype(*p1+*p1)
{
    if(p1==p2) return a0;
    while(p1!=p2)
    {
        a0=funkcija(a0,*p1);
        p1++;
    }
    return a0;
}

int main ()
{
    std::cout<<"Unesite string: ";
    std::string s;
    std::cin>>s;
    if(ZaSve(s.begin(),s.end(), [](char s){if(!(toupper(s)>='A' && toupper(s)<='Z' || s>='0' && s<='9')) return false; else return true;})) {
        std::cout<<"Uneseni string sadrzi samo slova i cifre"<<std::endl;
    }
    else std::cout<<"Uneseni string sadrzi i druge znakove osim slova i cifara"<<std::endl;
    
    
    int niz[10];
    std::cout<<"Unesite niz od 10 brojeva: ";
    std::for_each(niz,niz+10, [](int &a){std::cin>>a;});
    if(MakarJedan(niz,niz+10,[](int a)->bool{
        int sumacifara(0);
        auto djelilac=abs(a);
        while(1)
        {
            
            if(djelilac<1) break;
            sumacifara+=djelilac%10;
            djelilac/=10;
        }
        if(a%sumacifara==0) return true;
        return false;
        
    })) std::cout<<"U nizu nema brojeva djeljivih sa sumom svojih cifara"<<std::endl;
    else std::cout<<"U nizu ima brojeva djeljivih sa sumom svojih cifara"<<std::endl;
    
    
    std::deque<double>dek(10);
    std::cout<<"Unesite dek od 10 elemenata: "<<std::endl;
    std::for_each(dek.begin(),dek.end(), [](double &a){std::cin>>a;});
    std::cout<<"Suma deka: "<<Akumuliraj(dek.begin(),dek.end(),[](double a,double b){return a+b;})<<std::endl;
    std::cout<<"Produkt deka: "<<Akumuliraj(dek.begin(),dek.end(),[](double a,double b){return a*b;},1)<<std::endl;
    std::cout<<"Najveci elemenat deka: "<<Akumuliraj(dek.begin(),dek.end(),[](double a,double b){if(a>b) return a; return b;})<<std::endl;
    std::cout<<"Najmanji elemenat deka: "<<Akumuliraj(dek.begin(),dek.end(),[](double a,double b){if(a<b) return a; return b;})<<std::endl;

	return 0;
}