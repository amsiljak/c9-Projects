//TP 2017/2018: Tutorijal 3, Zadatak 4
#include <iostream>
#include <deque>
#include <cmath>

std::deque<int> IzdvojiElemente(std::deque<int>x,bool t) 
{
    std::deque <int> v;
    if(t) {
        for(int m:x) 
        {
            unsigned int x=abs(m);
            int zbir=0;
            while(1)
            {
                int broj=x%10;
                x=x/10;
                zbir+=broj;

                if(x<1) break;
            }

            if (zbir%2==0) v.push_front(m);
        }
    }
    else 
    {
        for(int n:x)
        {
            unsigned int x=abs(n);
            int zbir=0;
            while(1) 
            {
                int broj=x%10;
                x=x/10;
                zbir+=broj;
                if(x<1) break;
            }
            if(zbir%2!=0) v.push_front(n);
        }
    }
    return v;
}

int main ()
{
    int n;
    std::cout<<"Koliko zelite unijeti elemenata: ";
    std::cin>>n;
    if(n<=0) 
    {
        std::cout<<"Broj elemenata mora biti veci od 0!"<<std::endl;
        return 0;
    } 
    
    std::deque <int> a,b,c;
    std::cout<<"Unesite elemente: ";
    for(int i=0;i<n;i++) {
        int broj;
        std::cin>>broj;
        a.push_back(broj);
    }
    
    std::deque <int> x=IzdvojiElemente(a,true);
    std::deque <int> y=IzdvojiElemente(a,false);

    for(int x:x) b.push_back(x);
    for(int x:y) c.push_back(x);
 
    for(int i=0;i<b.size();i++) 
    {
        if(i==b.size()-1) std::cout<<b[i];
        else std::cout<<b[i]<<",";
    }
    std::cout<<std::endl;
    for(int i=0;i<c.size();i++) 
    {
        if(i==c.size()-1) std::cout<<c[i];
        else std::cout<<c[i]<<",";
    }
	return 0;
}


