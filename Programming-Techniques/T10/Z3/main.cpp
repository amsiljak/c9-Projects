/* 
    TP 16/17 (Tutorijal 10, Zadatak 3)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <cmath>
class Vektor3d
{
    mutable int broj_ispisa;
    static void PovecajBrojIspisa();
    double x, y, z;
public:
	Vektor3d():broj_ispisa(0){x=0;y=0;z=0;};
	Vektor3d(int a,int b,int c) :x(a),y(b),z(c),broj_ispisa(0){};
	Vektor3d(const Vektor3d &g){
	    x = g.x;
	    y=g.y;
	    z=g.z;
	    broj_ispisa=0;
	    
	}
    void Postavi(double x, double y, double z)
    {
        Vektor3d::x = x;
        Vektor3d::y = y;
        Vektor3d::z = z;
    }
    void Ocitaj(double &x, double &y, double &z) const
    {
        x = Vektor3d::x;
        y = Vektor3d::y;
        z = Vektor3d::z;
    }
    void Ispisi() const
    {
        std::cout << "{" << x << "," << y << "," << z << "}";
        broj_ispisa++;
    }
    double DajX() const
    {
        return x;
    }
    double DajY() const
    {
        return y;
    }
    double DajZ() const
    {
        return z;
    }
    double DajDuzinu() const
    {
        return sqrt(x * x + y * y + z * z);
    }
    int DajBrojIspisa() const 
    {
        return broj_ispisa;
    }
    void PostaviX(double novi)
    {
        x=novi;
    }
    void PostaviY(double novi)
    {
        y=novi;
    }
    void PostaviZ(double novi)
    {
        z=novi;
    }
    Vektor3d &PomnoziSaSkalarom(double s)
    {
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }
    Vektor3d &SaberiSa(const Vektor3d &v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }
    friend Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2);
};


Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2)
{
    Vektor3d v3;
    v3.x=v1.x+v2.x; v3.y=v1.y+v2.y; v3.z=v1.z+v2.z;
    return v3;
}
int main ()
{
    Vektor3d v1(1, 1, 1);
for(int i=0;i<3;i++) {v1.Ispisi();std::cout<<" ";}
std::cout<<std::endl;
const Vektor3d v2(v1);
v2.Ispisi(); std::cout << std::endl;
std::cout << v2.DajBrojIspisa() << std::endl;
const Vektor3d v3(v2);
std::cout << v3.DajBrojIspisa();
	return 0;
}