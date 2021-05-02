//TP 2018/2019: Tutorijal 8, Zadatak 4
#include <iostream>
#include <string>
#include <map>

std::string ZamijeniPremaRjecniku(std::string s,std::map<std::string,std::string> m)
{
    std::string novi;
    
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==' ')
        {
            novi.push_back(s[i]);
            continue;
        }
        auto j=i;
        while(j!=s.size() && s[j]!=' ') j++;
        
        std::string word;
        while(i!=j)
        {
            word.push_back(s[i]);
            i++;
        }
        
        auto it=m.find(word);
        
        if(it==m.end())
        {
            i-=word.size();
            while(i!=j)
            {
                novi.push_back(s[i]);
                i++;
            }
        }
        else{
        
        auto temp =it->second;
        for(auto i=0;i<temp.size();i++)
        {
            novi.push_back(temp[i]);
        }
        }
        
        if(i==s.size()-1) break;
        i--;
    }
    return novi;
}

int main ()
{
    std::map<std::string, std::string> moj_rjecnik{{"jabuka", "apple"},
{"da", "yes"}, {"kako", "how"}, {"ne", "no"}, {"majmun", "monkey"}};
std::cout << ZamijeniPremaRjecniku("kako da ne", moj_rjecnik);
	return 0;
}