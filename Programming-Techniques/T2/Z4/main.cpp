//TP 2017/2018: Tutorijal 2, Zadatak 4
#include <iostream>
#include <vector>
#include <complex>

int main ()
{
    int n;
    std::cout<<"Unesite broj elemenata: ";
    std::cin>>n;
    
    double c, p;
    std::complex<double> z,zbir;

    for(int i=0;i<n;i++) {
        
        std::cout<<std::endl<<"R"<<i+1<<" = ";
        std::cin>>p;
        
        std::cout<<"X"<<i+1<<" = ";
        std::cin>>c;
        
        z={p,c};
        
        zbir+=1./z;
        
    }
    std::complex<double>Impedansa=1./zbir;

    std::cout <<std::endl<< "Paralelna veza ovih elemenata ima R = " <<Impedansa.real()<<" i X = "<<Impedansa.imag()<<".";
	return 0;
}
