//TP 2018/2019: Tutorijal 4, Zadatak 2
#include <iostream>
#include <string>
#include <cstring>

void IzvrniString(std::string &s)
{
    int duzina=s.size();
    char temp;
    for(int i=0;i<duzina/2;i++)
    {
        temp=s[i];
        s[i]=s[duzina-1-i];
        s[duzina-1-i]=temp;
    }
}

int main ()
{
    std::string tekst;
    std::cout<<"Unesi string: ";
    std::getline(std::cin,tekst);
    IzvrniString(tekst);
    std::cout<<"Izvrnuti string je: "<<tekst;
	return 0;
}