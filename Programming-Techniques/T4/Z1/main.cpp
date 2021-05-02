//TP 2018/2019: Tutorijal 4, Zadatak 1
#include <iostream>
#include <cmath>

int Cifre(long long int n,int &c_min, int &c_max)
{
    // long long int broj=abs(n);
    // int brojcifara(0);
    // if(broj==0) {
    //     brojcifara++;
    //     c_min=0;
    //     c_max=0;
    //     return brojcifara;
    // }
    // int max=broj%10;
    // int min=broj%10;
    // broj=broj/10;
    // while(1)
    // {
    //     brojcifara++;
    //     if(broj<1) break;
    //     int x=broj%10;
    //     if(x<min) min=x;
    //     if(x>max) max=x;
    //     broj/=10;
    // }    
    c_min = 9;
    c_max = 0;
    int brojcifara = 0;
    do {
        int cifra = abs(n % 10);
        
        if(cifra > c_max) {
            c_max = cifra;
        }
        
        if(cifra < c_min) {
            c_min = cifra;
        }
        n /= 10;
        brojcifara++;
    }while(n != 0);

    return brojcifara;
}

int main()
{
    int a,b;
     long long int n;
    std::cout<<"Unesite broj: ";
     std::cin>>n;
    int brojcifara=Cifre(n,a,b);
     std::cout<<"Broj "<<n<<" ima "<<brojcifara<<" cifara, najveca je "<<b<<" a najmanja "<<a<<".";
  
    return 0;
}