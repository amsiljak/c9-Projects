//TP 2017/2018: Tutorijal 2, Zadatak 2
#include <iostream>
#include <vector>

bool TestPerioda(std::vector<double> v, int p)
{
    if(p>=1 && p<v.size()) {
        for(int i=0;i<v.size()-p;i++) {
            if(v.at(i)!=v.at(i+p)) return false;
        }
    }
    else return false;
    return true;
}

int OdrediOsnovniPeriod(std::vector<double> v)
{
    for(int i=0;i<v.size();i++) 
    {
        if(TestPerioda(v,i)) return i;
    }
    return 0;
} 

int main ()
{
    std::vector<double> v;
    float n;
    std::cout<<"Unesite slijed brojeva (0 za kraj): ";
    for(;;)
    {
        std::cin>>n;
        if(n==0.f) break;
        v.push_back(n);
    }
    
    if(OdrediOsnovniPeriod(v)) std::cout<<"Slijed je periodican sa osnovnim periodom "<<OdrediOsnovniPeriod(v)<<".";
    else std::cout<<"Slijed nije periodican!";
    
	return 0;
}
