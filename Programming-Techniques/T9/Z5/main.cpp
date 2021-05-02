//TP 2018/2019: Tutorijal 8, Zadatak 5
#include <iostream>
#include <iomanip>


class Sat
{
    int sekunde;

public:
    static int Razmak (Sat &s1, Sat &s2);
    void PostaviNormalizirano(int h,int min,int sec);
    static bool DaLiJeIspravno(int h,int min,int sec);
    void Postavi(int h,int min,int sec)
    {
        if(!DaLiJeIspravno(h,min,sec)) throw std::domain_error("Neispravno vrijeme");
        sekunde=sec+min*60+h*3600;
    }
    Sat &Sljedeci();
    Sat &Prethodni();
    Sat &PomjeriZa(int vrijednost);
    void Ispisi() const;

    int DajSate() const
    {
        int sati=sekunde/3600;
        return sati;
    }
    int DajMinute() const
    {
        int minute=(sekunde%3600)/60;
        return minute;
    }
    int DajSekunde() const
    {
        int sec=sekunde%60;
        return sec;
    }
    friend int BrojSekundiIzmedju(Sat &s1, Sat &s2);
};


void Sat::Ispisi() const 
    {
        int sati=sekunde/3600;
        int minute=(sekunde%3600)/60;
        int sec=sekunde%60;
        if(sati==24) sati-=24;
        std::cout<<std::setw(2)<<std::setfill('0')<<sati<<":"<<std::setw(2)<<minute<<":"<<std::setw(2)<<sec;
    }

int Sat::Razmak(Sat &s1, Sat &s2)
{
    return s1.sekunde-s2.sekunde;
}
int BrojSekundiIzmedju(Sat &s1, Sat &s2)
{
    return s1.sekunde-s2.sekunde;
}

Sat &Sat::Sljedeci()
{
    Sat::sekunde++;
    return *this;
}

Sat &Sat::Prethodni()
{
    sekunde--;
    if(sekunde<0) sekunde+=86400;
    return *this;
}

Sat &Sat::PomjeriZa(int vrijednost)
{
    sekunde+=vrijednost;
    if(sekunde<0) sekunde+=86400;
    return *this;
}

void Sat::PostaviNormalizirano(int h,int min,int sec)
{
    sekunde=(h*3600+min*60+sec)%86400;
    if(sekunde<0) sekunde+=86400;
}

bool Sat::DaLiJeIspravno(int h,int min,int sec)
{
    if(h<0 || h>23 || min<0 || min>59 || sec<0 || sec>59) return false;
    return true;
}


int main ()
{
    Sat s;
    s.Postavi(10,15,30);
    s.Ispisi();
    return 0;
}
