//TP 2017/2018: Tutorijal 3, Zadatak 6
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

int NajvecaSirina(std::vector<std::vector<int>> m)
{
    std::vector<std::vector<int>> brojaci=m;
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

std::vector<std::vector<int>> KroneckerovProizvod(std::vector<int> v1,std::vector<int> v2)
{
    std::vector<std::vector<int>>m(v1.size());
    for(int i=0;i<v1.size();i++)
    {
        m.resize(v2.size());
    }
    for(int i=0;i<v1.size();i++) 
    {
        for(int j=0;j<v2.size();j++)
        {
            m[i][j]=v1[i]*v2[j];
        }
    }
    return m;
}
int main ()
{
    int n,m;
    std::cout<<"Unesite broj elemenata prvog vektora: ";
    std::cin>>n;
    std::cout<<"Unesite elemente prvog vektora: ";
    std::vector<int>v1(n);
    for(int i=0;i<n;i++) 
    {
        std::cin>>v1[i];
    }
    std::cout<<"Unesite broj elemenata drugog vektora: ";
    std::cin>>m;
    std::vector <int>v2(m);
    for(int i=0;i<m;i++) 
    {
        std::cin>>v2[i];
    }
    
    std::vector<std::vector<int>>mat=KroneckerovProizvod(v1,v2);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            std::cout<<std::setw(NajvecaSirina(KroneckerovProizvod(v1,v2)))<<std::right<<mat[i][j];
        }
        std::cout<<std::endl;
    }
    
    
	return 0;
}
