//TP 2018/2019: Tutorijal 4, Zadatak 4
#include <iostream>
#include <string>

template <typename TipBroja>
void UnosBroja(std::string unos,std::string greska,TipBroja &broj)
{
    int provjera(0);
    do
    {
        std::cout<<unos;
        if(!(std::cin>>broj) || std::cin.peek()!='\n')
        {
            std::cout<<std::endl<<greska;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
        }
        else provjera=1;
        std::cout<<std::endl;
    } while(!provjera);
}

int main ()
{
    double baza, suma(1);
    int eksponent;
    UnosBroja("Unesite bazu: ","Neispravan unos, pokusajte ponovo...",baza);
    std::cout<<std::endl;
    UnosBroja("Unesite cjelobrojni eksponent: ", "Neispravan unos, pokusajte ponovo...",eksponent);
    std::cout<<std::endl;
    if(eksponent<0)
    {
        for(int i=0;i<eksponent*-1;i++) suma*=1./baza;
    }
    else
    {
        for(int i=0;i<eksponent;i++) suma*=baza;
    }
    std::cout<<baza<<" na "<<eksponent<<" iznosi "<<suma;
	return 0;
}