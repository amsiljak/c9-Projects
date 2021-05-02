//TP 2017/2018: Tutorijal 2, Zadatak 3
#include <iostream>
#include <vector>
#include <complex>

int main ()
{
    int n;
    std::cout<<"Unesite broj elemenata: "<<std::endl;
    std::cin>>n;
    
    std::complex<double> c, zbir;
    for(int i=0;i<n;i++) {
        std::cout<<"Z_"<<i+1<<" = ";
        std::cin>>c;
        zbir+=1./c;
    }
    std::complex<double>Impedansa=1./zbir;
    std::cout <<std::endl<< "Paralelna veza ovih elemenata ima impedansu Z_ = " <<Impedansa<<".";
	return 0;
}
