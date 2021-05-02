//TP 2018/2019: Zadaća 4, Zadatak 1
#include <iostream>
#include <cmath>
#include <algorithm>
#include <memory>
#include <vector>
const double PI=atan(1)*4;
typedef std::pair<double,double> Tacka;



class Trougao
{
    Tacka tjeme[4];
    
    void ProvjeraIndeksa(int indeks) const
    { 
        if(indeks!=3 && indeks!=2 && indeks!=1) throw std::range_error("Nekorektan indeks");
    }
    
    std::pair<int,int>DajIndekse(int indeks) const
    {
        std::pair<int,int> indeksi;
        Tacka t1,t2;
        if(indeks==1) {indeksi.first=2; indeksi.second=3;}
        else if(indeks==2) {indeksi.first=1; indeksi.second=3;}
        else  {indeksi.first=1; indeksi.second=2;}
        return indeksi;
    }
    
    static int Racun(const Tacka &t1,const Tacka &t2,const Tacka &t3) 
    {
        return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
    }
    
public:
    Trougao(const Tacka &t1,const Tacka &t2,const Tacka &t3);
    
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        tjeme[1]=t1; tjeme[2]=t2; tjeme[3]=t3;
    }
    
    void Postavi(int indeks, const Tacka &t){
        ProvjeraIndeksa(indeks);
        tjeme[indeks]=t;
    };
    
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    
    Tacka DajTjeme(int indeks) const
    {
        ProvjeraIndeksa(indeks);
        return tjeme[indeks];
    };
    
    double DajStranicu(int indeks) const
    {
        ProvjeraIndeksa(indeks);
        auto indeksi=DajIndekse(indeks);
        Tacka t1=tjeme[indeksi.first];
        Tacka t2=tjeme[indeksi.second];
        return sqrt((t2.first-t1.first)*(t2.first-t1.first)+(t2.second-t1.second)*(t2.second-t1.second));
    }
    
    double DajUgao(int indeks) const;
    
    Tacka DajCentar() const;
    
    double DajObim() const;
    
    double DajPovrsinu() const{return abs(Racun(tjeme[1],tjeme[2],tjeme[3]))/double(2);};
    
    bool DaLiJePozitivnoOrijentiran() const;
    
    bool DaLiJeUnutra(const Tacka &t) const;
    
    void Ispisi() const {
        std::cout<<"(("<<tjeme[1].first<<","<<tjeme[1].second<<"),(";
        std::cout<<tjeme[2].first<<","<<tjeme[2].second<<"),("<<tjeme[3].first<<","<<tjeme[3].second<<"))";
    }
    
    void Transliraj(double delta_x, double delta_y);
    
    void Centriraj(const Tacka &t);
    
    void Rotiraj(const Tacka &t, double ugao);
    
    void Skaliraj(const Tacka &t, double faktor);
    
    void Rotiraj(double ugao); //nije napravljena
    
    void Skaliraj(double faktor);
    
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};



bool Trougao::DaLiJeUnutra(const Tacka &t) const
 {
     auto p1=tjeme[1]; auto p2=tjeme[2]; auto p3=tjeme[3];
      double povrsina=(0.5*(-p2.second*p3.first + p1.second*(-p2.first+p3.first)+p1.first*(p2.second-p3.second)+p2.first*p3.second));
    double a=1/(2*povrsina)*(p1.second*p3.first - p1.first*p3.second + (p3.second-p1.second)*t.first + (p1.first-p3.first)*t.second);
    double b=1/(2*povrsina)*(p1.first*p2.second - p1.second*p2.first + (p1.second-p2.second)*t.first + (p2.first-p1.first)*t.second);
    if(a>0 && b>0 && (1-a-b)>0) return true;
    return false;
}
bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2)
{
    auto tacka=t1;
    if(t1.Orijentacija(tacka.tjeme[1],tacka.tjeme[2],tacka.tjeme[3])!=t2.Orijentacija(t2.tjeme[1],t2.tjeme[2],t2.tjeme[3])) std::swap(tacka.tjeme[1],tacka.tjeme[2]);
    int prva(0);
    for(int j=1;j<=3;j++)
    {
        int a=1;int b=j;
        while (tacka.DajUgao(a)==t2.DajUgao(b)) {a++; b++; prva++; if(b==4) b=1; if(prva==3) return true;}
    }
    return false;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2)
{
    auto tacka=t1;
    if(t1.Orijentacija(tacka.tjeme[1],tacka.tjeme[2],tacka.tjeme[3])!=t2.Orijentacija(t2.tjeme[1],t2.tjeme[2],t2.tjeme[3])) std::swap(tacka.tjeme[1],tacka.tjeme[2]);
    int prva(0);
    for(int j=1;j<=3;j++)
    {
        int a=1; int b=j;
        while(tacka.DajStranicu(a)==t2.DajStranicu(b)) {a++; b++; prva++; if(b==4) b=1; if(prva==3) return true;} 
    }
    return false;
}

bool DaLiSuIdenticni(const Trougao &t1,const Trougao &t2)
{
    int prva(0);
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(t1.tjeme[i]==t2.tjeme[j]) prva++;
        }
    }
    if(prva==3)return true;
    return false;
}
void Trougao::Skaliraj(double faktor)
{
    if(faktor==0) throw std::domain_error("Nekorektan faktor skaliranja");
    auto t=DajCentar();
    for(int i=1;i<=3;i++)
    {
        tjeme[i].first=t.first+faktor*(tjeme[i].first-t.first);
        tjeme[i].second=t.second+faktor*(tjeme[i].second-t.second);
    }
}
void Trougao::Skaliraj(const Tacka &t,double faktor)
{
    if(faktor==0) throw std::domain_error("Nekorektan faktor skaliranja");
    for(int i=1;i<=3;i++)
    {
        tjeme[i].first=t.first+faktor*(tjeme[i].first-t.first);
        tjeme[i].second=t.second+faktor*(tjeme[i].second-t.second);
    }
}
void Trougao::Rotiraj(const Tacka &t, double ugao)
{
    for(int i=1;i<=3;i++)
    {
        auto a=tjeme[i].first;
        auto b=tjeme[i].second;
        a=t.first+(tjeme[i].first-t.first)*cos(ugao)-(tjeme[i].second-t.second)*sin(ugao);
        b=t.second+(tjeme[i].first-t.first)*sin(ugao)+(tjeme[i].second-t.second)*cos(ugao);
        tjeme[i].first=a; tjeme[i].second=b;
    }
}
void Trougao::Rotiraj(double ugao)
{
    auto t=DajCentar();
    for(int i=1;i<=3;i++)
    {
        auto a=tjeme[i].first;
        auto b=tjeme[i].second;
        a=t.first+(tjeme[i].first-t.first)*cos(ugao)-(tjeme[i].second-t.second)*sin(ugao);
        b=t.second+(tjeme[i].first-t.first)*sin(ugao)+(tjeme[i].second-t.second)*cos(ugao);
        tjeme[i].first=a; tjeme[i].second=b;
    }
}
void Trougao::Centriraj(const Tacka &t)
{
    double delta_x=t.first-DajCentar().first;
    double delta_y=t.second-DajCentar().second;
    Transliraj(delta_x,delta_y);
}

void Trougao::Transliraj(double delta_x,double delta_y)
{
    for(int i=1;i<=3;i++){ tjeme[i].first+=delta_x; tjeme[i].second+=delta_y;};
}

bool Trougao::DaLiJePozitivnoOrijentiran() const
{
    if(Orijentacija(tjeme[1],tjeme[2],tjeme[3])==-1) return false;
    return true;
}

double Trougao::DajObim() const
{
    return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
}

Tacka Trougao::DajCentar() const
{
    Tacka t;
    t.first=(tjeme[1].first+tjeme[2].first+tjeme[3].first)/3;
    t.second=(tjeme[1].second+tjeme[2].second+tjeme[3].second)/3;
    return t;
}

double Trougao::DajUgao(int indeks) const
{
    ProvjeraIndeksa(indeks);
    auto indeksi=DajIndekse(indeks);
    auto a=DajStranicu(indeksi.first); auto b=DajStranicu(indeksi.second); auto c=DajStranicu(indeks);
    return (acos((a*a+b*b-c*c) / (2*a*b)) );
}

Trougao::Trougao(const Tacka &t1,const Tacka &t2,const Tacka &t3)
{
    if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
    tjeme[1]=t1; tjeme[2]=t2; tjeme[3]=t3;
}

int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    auto n=Racun(t1,t2,t3);
    if(n>0) return 1;
    else if(n<0) return -1;
    else return 0;
}
void Ispis(Trougao v1,Trougao v2)
{
    v1.Ispisi();
    std::cout<<" i ";
    v2.Ispisi();
    std::cout<<std::endl;
}

int main ()
{
    int n;
    std::cout<<"Koliko zelite kreirati trouglova: ";
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>> v(n);
    Tacka t[3];
    for(int i=0;i<n;i++)
    {
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin>>t[0].first>>t[0].second>>t[1].first>>t[1].second>>t[2].first>>t[2].second;
        try
        {
            v[i]=std::make_shared<Trougao>(t[0],t[1],t[2]);
        }
        catch(std::domain_error e)
        {
            std::cout<<e.what()<<", ponovite unos!"<<std::endl;
            i--;
        }
    }
    double dx,dy;
    std::cout<<"Unesite vektor translacije (dx dy): ";
    std::cin>>dx>>dy;
    
    double ugao;
    std::cout<<"Unesite ugao rotacije: ";
    std::cin>>ugao;

    double faktor;
    std::cout<<"Unesite faktor skaliranja: ";
    std::cin>>faktor;
    std::transform(v.begin(),v.end(),v.begin(),[dx,dy,faktor,ugao](std::shared_ptr<Trougao> t){
        t->Transliraj(dx,dy);
        t->Rotiraj(ugao);
        t->Skaliraj(t->DajTjeme(1),faktor);
        return t;
    });
    std::sort(v.begin(),v.end(),[](std::shared_ptr<Trougao>t1,std::shared_ptr<Trougao>t2){
        return t1->DajPovrsinu()<t2->DajPovrsinu();
    });
    std::cout<<"Trouglovi nakon obavljenih transformacija: "<<std::endl;
    std::for_each(v.begin(),v.end(),[](std::shared_ptr<Trougao> t)
    {
        t->Ispisi();
        std::cout<<std::endl;
    });
    std::cout<<"Trougao sa najmanjim obimom: ";
    auto it=std::min_element(v.begin(),v.end(),[](std::shared_ptr<Trougao> t1,std::shared_ptr<Trougao> t2){if(t1->DajObim()<t2->DajObim()) return true; return false;});
    (*it)->Ispisi();
    std::cout<<std::endl;
    bool id(false);
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(i!=j)
            {
                if(DaLiSuIdenticni(*v[i],*v[j])) 
                {
                    if(id==false) std::cout<<"Parovi identicnih trouglova: "<<std::endl;
                    Ispis(*v[i],*v[j]); id=true;
                }
            }
        }
    }
    if(!id) std::cout<<"Nema identicnih trouglova!"<<std::endl;
    
    bool pod(false);
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(i!=j && DaLiSuPodudarni(*v[i],*v[j])) 
            {
                if(pod==false) std::cout<<"Parovi podudarnih trouglova: "<<std::endl;
                Ispis(*v[i],*v[j]); pod=true;
            }
        }
    }
    if(!pod) std::cout<<"Nema podudarnih trouglova!"<<std::endl;
    
    
    bool sluc(false);
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(i!=j && DaLiSuSlicni(*v[i], *v[j])) 
            {
                if(sluc==false) std::cout<<"Parovi slicnih trouglova: "<<std::endl;
                Ispis(*v[i],*v[j]); sluc=true;}
        }
    }
    if(!sluc) std::cout<<"Nema slicnih trouglova!"<<std::endl;
	return 0;
}