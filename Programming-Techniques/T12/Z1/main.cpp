/* 
    TP 16/17 (Tutorijal 12, Zadatak 1)
	Autotestove napisao Kerim Hodzic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: khodzic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <iomanip>

class Sat
{
    int sati, minute, sekunde;

public:
    Sat():sati(0),minute(0),sekunde(0){};
    Sat(int h,int m,int s){PostaviNormalizirano(h,m,s);};
    void PostaviNormalizirano(int h,int min,int sec);
    static bool DaLiJeIspravno(int h,int min,int sec);
    void Postavi(int h,int min,int sec)
    {
        if(!DaLiJeIspravno(h,min,sec)) throw std::domain_error("Neispravno vrijeme");
        sati=h;
        minute=min;
        sekunde=sec;
    }
    Sat &operator ++();
    Sat &operator --();
    Sat &operator +=(int vrijednost);
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
    Sat operator+(int n)
    {
        return Sat(sati,minute,sekunde+n);
    }
    Sat operator -(int n)
    {
        return Sat(sati,minute,sekunde-n);
    }
    friend int operator -(Sat &s1, Sat &s2);
    friend Sat operator ++(Sat &s,int);
    friend Sat operator --(Sat &s,int);
    friend Sat operator -=(Sat &s,int n);
    friend std::ostream &operator <<(std::ostream &tok,const Sat &s);
};
std::ostream &operator <<(std::ostream &tok,const Sat &s)
{
    return tok<<std::setw(2)<<std::setfill('0')<<s.sati<<":"<<std::setw(2)<<s.minute<<":"<<std::setw(2)<<s.sekunde;
}
int operator -(Sat &s1, Sat &s2)
{
    return s1.sekunde+s1.minute*60+s1.sati*3600-s2.sekunde-s2.minute*60-s2.sati*3600;
}
Sat operator --(Sat &s,int)
{
    Sat pomocni(s);
    --s;
    return pomocni;
}
Sat operator ++(Sat &s,int)
{
    Sat pomocni(s);
    ++s;
    return pomocni;
}
inline Sat operator -=(Sat &s,int n)
{
    return s+=(-n);
}


Sat &Sat::operator ++()
{
    PostaviNormalizirano(sati,minute,sekunde+1);
    return *this;
}

Sat &Sat::operator --()
{
    PostaviNormalizirano(sati,minute,sekunde-1);
    return *this;
}

Sat &Sat::operator +=(int vrijednost)
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
    // Sat s;
    // s.Postavi(2,2,2);
    // if(Sat::DaLiJeIspravno(2,2,2)) std::cout<<"Ispravan unos.";
    // ++s;
    // s++;
    // std::cout<<s;
    Sat s1(11, 4, 39);
  std::cout << s1 << std::endl;
  Sat s2(25, 150, 1000);
  std::cout << s2 << std::endl;
  std::cout << s1 - s2 << std::endl;
	return 0;
}