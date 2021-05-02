// TP 2017/2018: Tutorijal 3, Zadatak 7
#include <iostream>
#include <iomanip>
#include <vector> 
#include <cmath>
#include <exception>

typedef std::vector<std::vector<int>> Matrica;

int NajvecaSirina(Matrica m)
{
    Matrica brojaci=m;
    for(int i=0;i<m.size();i++) 
    {
        for(int j=0;j<m[i].size();j++) 
        {
            brojaci[i][j]=0;
        }
    }
    for(int i=0;i<m.size();i++)
    {
        for(int j=0;j<m[i].size();j++) 
        {
            int broj;
            if(m[i][j]<0) brojaci[i][j]++;
            broj=abs(m[i][j]);
            while(1)
            {
                if(broj<1) break;
                brojaci[i][j]++;
                broj=broj/10;
            }
        }
    }
    int max=brojaci[0][0];
    for(int i=0;i<m.size();i++) 
    {
        for(int j=0;j<m[i].size();j++)
        {
            if(brojaci[i][j]>max) max=brojaci[i][j];
        }
    }
    return max;
}

Matrica PascalovTrougao(int n)
{
    if(n<0) throw std::domain_error("Broj redova ne smije biti negativan");
    Matrica m(n);
    if(n==0) return m;
    else 
    {
        for(int i=0;i<n;i++) m[i]=std::vector<int>(i+1);
        for(int i=0;i<m.size();i++) 
        {
            for(int j=0;j<m[i].size();j++)
            {
                if(j==0 || i==j) m[i][j]=1;
                else if(j!=0) m[i][j]=m[i-1][j]+m[i-1][j-1];
            }
        }
        return m;
    }
}

int main ()
{   
    int n;
    std::cout<<"Unesite broj redova: ";
    std::cin>>n;
    std::cout<<std::endl;
    
    Matrica m=PascalovTrougao(n);
    int NS=NajvecaSirina(m);
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m[i].size();j++)
        {
            std::cout<<std::setw(NS+1)<<std::right<<m[i][j];
        }
        std::cout<<std::endl;
    }
	return 0;
}
