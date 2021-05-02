#include <iostream>

template <typename Tip>
class Stek 
{
private: 
    Tip* elementi;
    int kapacitet;
    int vrhic;
    int brojac = 1;
    Tip &operator [](int indeks) {return elementi[indeks];}
public:
    Stek() {
        kapacitet = 10;
        elementi = new Tip[kapacitet];
        vrhic = -1;
    }
    ~Stek()
    {
        delete[] elementi;
    }
    Stek &operator =(const Stek &stek)
    {
        if(this == &stek) return *this;
        
        delete[] elementi;
        
        kapacitet = stek.kapacitet;
        vrhic = stek.vrhic;
        elementi = new Tip[kapacitet];
        
        
        for(int i = 0;i<=vrhic; i++) elementi[i] = stek.elementi[i];
        
        return *this;
    }
    Stek (const Stek &stek)
    {
        kapacitet = stek.kapacitet;
        vrhic = stek.vrhic;
        elementi = new Tip[kapacitet];
        
        for(int i=0;i<=vrhic;i++) elementi[i] = stek.elementi[i];
    }
    int brojElemenata()
    {
        return vrhic + 1;
    }
    Tip &vrh() 
    {
        if(brojElemenata() == 0) throw std::domain_error("Stek je prazan");
        return elementi[vrhic];
    }
    Tip skini()
    {
        if(brojElemenata() == 0) throw std::domain_error("Stek je prazan");
        return elementi[vrhic--];
    }
    void stavi(const Tip& element)
    {
        if(brojElemenata() == kapacitet)
        {
            kapacitet += 10 * brojac;
            brojac *= 2;
            Tip* pok = elementi;
            elementi =  new Tip [kapacitet];
            for(int i = 0;i<brojElemenata();i++)
                elementi[i] = pok[i];
            delete[] pok;
        }
        elementi[++vrhic] = element;
    }
    void brisi()
    {
        vrhic = -1;
    }
};
bool Test1()
{
    Stek<int> s;
    if(s.brojElemenata() != 0) return false;
    s.stavi(3);
    s.stavi(4);
    if(s.brojElemenata() != 2) return false;
    return true;
}
bool Test2()
{
    Stek<int> s;
    s.stavi(2);
    Stek<int>s2 = s;
    if(s2.vrh() != 2) return false;
    return true;
}
bool Test3()
{
    Stek<int>s;
    s.stavi(6);
    s.stavi(7);
    s.stavi(8);
    if(s.skini() != 8) return false;
    if(s.vrh() != 7) return false;
    return true;
}
bool Test4()
{
    Stek<int>s;
    s.stavi(5);
    s.stavi(8);
    Stek<int>s2 = s;
    s2.brisi();
    try {
        int x = s2.vrh();
        return false;
    }
    catch(...) {}
    return true;
}
int main() {
    if(Test1()) std::cout<<"OK"<<std::endl;
    else std::cout<<"NIJE OK"<<std::endl;
    
    if(Test2()) std::cout<<"OK"<<std::endl;
    else std::cout<<"NIJE OK"<<std::endl;
    
    if(Test3()) std::cout<<"OK"<<std::endl;
    else std::cout<<"NIJE OK"<<std::endl;
    
    if(Test4()) std::cout<<"OK"<<std::endl;
    else std::cout<<"NIJE OK"<<std::endl;
    
    return 0;
}
