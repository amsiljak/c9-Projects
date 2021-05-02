//TP 2016/2017: Tutorijal 1, Zadatak 1
#include <iostream>
#include <cmath>
int main ()
{
    int duzina, sirina, dubina, plocica, broj;
    std::cout<<"Unesite duzinu, sirinu i dubinu bazena u metrima: ";
    std::cin>>duzina>>sirina>>dubina;
    std::cout<<"Unesite sirinu plocice u centimetrima: ";
    std::cin>>plocica;
    
    duzina*=100;
    sirina*=100;
    dubina*=100;
    
    if(!(duzina%plocica==0 && sirina%plocica==0 && dubina%plocica==0)) 
    {
        std::cout<<std::endl<<"Poplocavanje bazena dimenzija "<<duzina/100<<"x"<<sirina/100<<"x"<<dubina/100
        <<"m sa plocicama dimenzija "<<plocica<<"x"<<plocica<<"cm"<<std::endl<<"nije izvodljivo bez lomljenja plocica!";
    }
    
    else
    {
        broj=(duzina/plocica)*(sirina/plocica)+2*(dubina/plocica)*(sirina/plocica)+2*(dubina/plocica)*(duzina/plocica);
        std::cout<<std::endl<<"Za poplocavanje bazena dimenzija "<<duzina/100<<"x"<<sirina/100<<"x"<<dubina/100
        <<"m sa plocicama dimenzija "<<plocica<<"x"<<plocica<<"cm"<<std::endl<<"potrebno je "<<broj<<" plocica.";
    }
	return 0;
}