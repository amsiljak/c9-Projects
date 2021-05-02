//TP 2017/2018: Tutorijal 2, Zadatak 5
#include <iostream>
#include <vector>
#include <complex>

const double pi=4*atan(1);

int main ()
{
    int n;
    std::cout<<"Unesi broj elemenata:";
    std::cin>>n;
    
    double fi, p;
    std::complex<double> z,zbir;

    for(int i=0;i<n;i++) {
        
        std::cout<<std::endl<<"Z"<<i+1<<" = ";
        std::cin>>p;
        
        std::cout<<"fi"<<i+1<<" = ";
        std::cin>>fi;
        
        z=std::polar(p,fi*pi/180);
        
        
        zbir+=1./z;
        
    }
    std::complex<double>Impedansa=1./zbir;

    std::cout <<std::endl<< "Paralelna veza ovih elemenata ima Z = " <<abs(Impedansa)<<" i fi = "<<arg(Impedansa)*180/pi<<".";
	return 0;
}
