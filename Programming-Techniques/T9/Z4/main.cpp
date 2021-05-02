//TP 2018/2019: Tutorijal 8, Zadatak 4
#include <iostream>
#include <iomanip>


class Sat
{
    int sati, minute, sekunde;

public:
    static int Razmak (Sat &s1, Sat &s2);
    void PostaviNormalizirano(int h,int min,int sec);
    static bool DaLiJeIspravno(int h,int min,int sec);
    void Postavi(int h,int min,int sec)
    {
        if(!DaLiJeIspravno(h,min,sec)) throw std::domain_error("Neispravno vrijeme");
        sati=h;
        minute=min;
        sekunde=sec;
    }
    Sat &Sljedeci();
    Sat &Prethodni();
    Sat &PomjeriZa(int vrijednost);
    void Ispisi() const
    {
        std::cout<<std::setw(2)<<std::setfill('0')<<sati<<":"<<std::setw(2)<<minute<<":"<<std::setw(2)<<sekunde;
    }
    int DajSate() const
    {
        return sati;
    }
    int DajMinute() const
    {
        return minute;
    }
    int DajSekunde() const
    {
        return sekunde;
    }
    friend int BrojSekundiIzmedju(Sat &s1, Sat &s2);
};




int Sat::Razmak(Sat &s1, Sat &s2)
{
    return s1.sekunde+s1.minute*60+s1.sati*3600-s2.sekunde-s2.minute*60-s2.sati*3600;
}
int BrojSekundiIzmedju(Sat &s1, Sat &s2)
{
    return s1.sekunde+s1.minute*60+s1.sati*3600-s2.sekunde-s2.minute*60-s2.sati*3600;
}

Sat &Sat::Sljedeci()
{
    PostaviNormalizirano(sati,minute,sekunde+1);
    return *this;
}

Sat &Sat::Prethodni()
{
    PostaviNormalizirano(sati,minute,sekunde-1);
    return *this;
}

Sat &Sat::PomjeriZa(int vrijednost)
{
    PostaviNormalizirano(sati,minute,sekunde+vrijednost);
    return *this;
}

void Sat::PostaviNormalizirano(int h,int min,int sec)
{
    sec=(h*3600+min*60+sec)%86400;
    if(sec<0) sec+=86400;
    sati=sec/3600;
    minute=(sec%3600)/60;
    sekunde=sec%60;
}

bool Sat::DaLiJeIspravno(int h,int min,int sec)
{
    if(h<0 || h>23 || min<0 || min>59 || sec<0 || sec>59) return false;
    return true;
}


int main ()
{
    Sat s;
    s.Postavi(2,2,2);
    if(Sat::DaLiJeIspravno(2,2,2)) std::cout<<"Ispravan unos.";
    s.PomjeriZa(5);
    s.Ispisi();
    s.DajSekunde();
    s.DajMinute();
    s.DajSate();
    
    Sat m;
    m.PostaviNormalizirano(1,1,1);
    Sat::Razmak(s,m);
    BrojSekundiIzmedju(s,m);
    m.Prethodni();
    m.Ispisi();
    m.Sljedeci();
    m.Ispisi();
    

    return 0;
}
