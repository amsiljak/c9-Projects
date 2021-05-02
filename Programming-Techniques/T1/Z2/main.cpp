//tutorijal 1, zadatak 2
#include <iostream>
#include <cmath>
#include <iomanip>

int main ()
{
    double a,b,c;
    std::cout<<"Unesite tri broja: ";
    std::cin>>a>>b>>c;
    if(!(a>0 && b>0 && c>0 && a+b>c && a+c>b && c+b>a))
    {
        std::cout<<"Ne postoji trougao cije su duzine stranica "<<a<<", "<<b<<" i "<<c<<"!";
    }
    else
    {
        std::cout<<"Obim trougla sa duzinama stranica "<<a<<", "<<b<<" i "<<c<<" iznosi "<<a+b+c<<"."<<std::endl;
        
        double s=(a+b+c)/2;
        double f=s*(s-a)*(s-b)*(s-c);
        std::cout<<"Njegova povrsina iznosi "<<std::sqrt(f)<<"."<<std::endl;
        
        double gama=std::acos((a*a+b*b-c*c)/(2*a*b));
        double alfa=std::acos((b*b+c*c-a*a)/(2*b*c));
        double beta=std::acos((a*a+c*c-b*b)/(2*a*c));
        
        double min;
        if(alfa<=gama && alfa<=beta) min=alfa;
        if(gama<=alfa && gama<=beta) min=gama;
        if(beta<=gama && beta<=alfa) min=beta;

        const double radijan=180/(4*atan(1));
        
        int sek=(min*radijan*3600);
        std::cout<<"Njegov najmanji ugao ima "<<sek/3600<<" stepeni, "<<std::abs(sek%3600)/60<<" minuta i "<<sek%60<<" sekundi"<<".";
        }
    return 0;
}