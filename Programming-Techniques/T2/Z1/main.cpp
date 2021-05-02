//TP 2017/2018: Tutorijal 2, Zadatak 1
#include <iostream>
#include <vector> 
#include <cmath>

bool DaLiJeProst(int n) {
    if (n<=1) return false;
    for(int i=2;i<=sqrt(n);i++) {
        if(n%i==0) return false;
    }
    return true;
}

std::vector<int> ProstiBrojeviUOpsegu(int a,int b) {
    std::vector<int> v;
    if(a<0) a=2;
    for(int i=a;i<=b && i>0;i++) {
        if(DaLiJeProst(i)) v.push_back(i);
    }
    return v;

}
int main ()
{
    int a,b;
    std::cout<<"Unesite pocetnu i krajnju vrijednost: ";
    std::cin>>a>>b;
    std::vector<int> v=ProstiBrojeviUOpsegu(a,b);
    if(v.size()==0) 
    {
        std::cout<<"Nema prostih brojeva u rasponu od "<<a<<" do "<<b<<"!";
        return 0;
    }
    std::cout<<"Prosti brojevi u rasponu od "<<a<<" do "<<b<<" su: ";
    for(int i=0;i<v.size();i++) 
    {
        if(i==v.size()-1) std::cout<<v[i]<<std::endl;
        else std::cout<<v[i]<<", ";
    }
	return 0;
}
