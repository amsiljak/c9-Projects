//TP 2016/2017: Tutorijal 1, Zadatak 4
#include <iostream>
#include <cmath>
int main ()
{
    while (1) {
        double n;
        std::cout<<"Unesite prirodan broj ili 0 za kraj: ";
        
        while(!(std::cin>>n) || n<0 || n!=int(n)) 
        {
            std::cout<<"Niste unijeli prirodan broj!"<<std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout<<"Unesite prirodan broj ili 0 za kraj: ";
            continue;
        }
        if(n==0) 
        {
            std::cout<<"Dovidjenja!";
            break;
        }
        
        else
        {
            int suma=0,i;
            for(i=1; i<n;i++) {
                if(int(n)%i==0) suma+=i;
            }
            if(suma==n) std::cout<<"Broj "<<n<<" je savrsen!"<<std::endl;
            else if(suma<n) std::cout<<"Broj "<<n<<" je manjkav!"<<std::endl;
            else std::cout<<"Broj "<<n<<" je obilan!"<<std::endl;
            suma=0;
        }
        
    }
	return 0;
}