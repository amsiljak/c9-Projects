/* TP, 2018/2019
*/
#include <iostream>
#include <cmath>
#include <vector> 

void RastavaBroja(int n,int &p, int &q)

{
    try
    {
        p=1;
        q=1;
        int nn=n;
        if(n<=0) throw std::domain_error("Broj koji se rastavlja mora biti prirodan");
        int brbrojaci=n+1;
        std::vector <int> brojaci(brbrojaci);
     
        for(int i=2;i<brbrojaci;i++)
        {
            while(n%i==0)
            {
                brojaci.at(i)++;
                n/=i;
            }    
        }
    
        for(int i=2;i<brbrojaci;i++)
        {
            if(brojaci.at(i)!=0 && brojaci.at(i)%2!=0)
            {
                p*=i;
            }
        }
        q=sqrt(nn/p);
    }
    catch(std::domain_error e)
    {
        throw e;
    }
}    

int main ()
{
    try
    {
        int n,p(1),q(1);
        std::cout<<"Unesite prirodan broj"<<std::endl;
        std::cin>>n;
        RastavaBroja(n,p,q);
        std::cout<<p<<" "<<q;
    }
    catch(std::domain_error e)
    {
        std::cout<<"Izuzetak: "<<e.what()<<"!";
    }
	return 0;
}