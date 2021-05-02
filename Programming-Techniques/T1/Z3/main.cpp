//TP 2016/2017: Tutorijal 1, Zadatak 3
#include <iostream>
#include <cmath>
#include <iomanip>
int main ()
{
    int a,b;
    std::cout<<"Unesite pocetnu i krajnju vrijednost: ";
    std::cin>>a>>b;
    
    std::cout<<std::endl<<"+---------+----------+----------+-----------+"<<std::endl;
    std::cout<<"| Brojevi | Kvadrati | Korijeni | Logaritmi |"<<std::endl<<"+---------+----------+----------+-----------+"<<std::endl;
    
        while(a<=b)
        {
            std::cout<<"| "<<std::left<<std::setw(8)<<a<<"|"<<std::right<<std::setw(9)<<a*a;
            std::cout<<" |"<<std::setw(9)<<std::fixed<<std::setprecision(3)<<std::sqrt(a)<<" |"<<std::setw(10)<<std::fixed<<std::setprecision(5)<<std::log(a)<<" |"<<std::endl;
            a++;
        }
        
    std::cout<<"+---------+----------+----------+-----------+"<<std::endl;
    
	return 0;
}