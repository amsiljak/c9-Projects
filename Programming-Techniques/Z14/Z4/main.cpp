//TP 2018/2019: Tutorijal 14, Zadatak 4
#include <iostream>
#include <string>
#include <fstream>

IzvrniDatoteku(std::string ime_datoteke)
{
    std::fstream datoteka(ime_datoteke, std::ios::in | std::ios::out | std::ios::binary);
    if(!datoteka) throw std::logic_error("Datoteka ne postoji");
    double broj;
    while(datoteka.read(reinterpret_cast<char*>(&broj),sizeof broj)
    {
        
    }
}
int main ()
{
	return 0;
}