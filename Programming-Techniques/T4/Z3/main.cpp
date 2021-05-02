//TP 2018/2019: Tutorijal 4, Zadatak 3
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cctype> 

void IzdvojiKrajnjeRijeci(std::vector <std::string> t, std::string &s1, std::string &s2)
{
    std::vector <std::string> v=t;
    if(v.size()==0) return;
    
    else 
    {
        s1=v.at(0);
        s2=v.at(0);
        for(int i=1;i<v.size();i++)
        {
            int j=0;
            while(j<v.at(i).length() && j<s1.length()){
                char znak1=v.at(i).at(j);
                char znak2=s1.at(j);
                if(znak1>='A' && znak1<='Z')znak1+='a'-'A';
                if(znak2>='A' && znak2<='Z')znak2+='a'-'A';
                if(znak1<znak2){
                    s1=v.at(i);
                    break;
                }else if(znak1>znak2){
                    break;
                }
                j++;
            }if(j==v.at(i).length()) s1=v.at(i);
            j=0;
            while(j<v.at(i).length() && j<s2.length()){
                char znak1=v.at(i).at(j);
                char znak2=s2.at(j);
                if(znak1>='A' && znak1<='Z')znak1+='a'-'A';
                if(znak2>='A' && znak2<='Z')znak2+='a'-'A';
                if(znak1>znak2){
                    s2=v.at(i);
                    break;
                }
                else if(znak1<znak2)
                {
                    break;
                }
                j++;
            }if(j==v.at(i).length()) s2=v.at(i);
            
        }
       /* std::string prvarijec=v[0];
        std::string posljrijec=v[0];
        for(int i=0;i<v.size();i++)
        {
            if(v[i].compare(prvarijec)<0) prvarijec=v[i];
            if(v[i].compare(posljrijec)>0) posljrijec=v[i];
        }
        s1=prvarijec;
        s2=posljrijec;*/
    }
}

void ZadrziDuplikate(std::vector <std::string> &v)
{
   /* std::vector <std::string> kopija;*/
    for(int i=0;i<v.size();i++)
    {   bool ponavlja=false;
        for(int j=i+1;j<v.size();j++)
        {
            if(v[i].compare(v[j])==0){
               /* kopija.push_back(v[i]);*/
                for(int k=j; k<v.size()-1; k++){
                    v.at(k)=v.at(k+1);
                }ponavlja=true;
                j--;
                v.resize(v.size()-1);
            } 
        }if(ponavlja==false){
            for(int k=i; k<v.size()-1; k++){
                    v.at(k)=v.at(k+1);
                }i--;
                v.resize(v.size()-1);
        }
    }
   // v=kopija;
}

int main ()
{
    int n;
    std::string s1;
    std::string s2;
    std::cout<<"Koliko zelite unijeti rijeci: ";
    std::cin>>n;
    std::vector <std::string> v(n);
    std::cout<<"Unesite rijeci: ";
    for(int i=0;i<n;i++)
    {
        std::cin>>v.at(i); 
    }
    IzdvojiKrajnjeRijeci(v,s1,s2);
    std::cout<<std::endl<<"Prva rijec po abecednom poretku je: "<<s1<<std::endl;
    std::cout<<"Posljednja rijec po abecednom poretku je: "<<s2;
    std::cout<<std::endl<<"Rijeci koje se ponavljaju su:";
    ZadrziDuplikate(v);
    for(int i=0;i<v.size();i++)
    {
        std::cout<<" "<<v[i];
    }
	return 0;
}