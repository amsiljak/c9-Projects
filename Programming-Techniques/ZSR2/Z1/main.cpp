//TP 2018/2019: ZSR 2, Zadatak 1
#include <iostream>

int main ()
{
    for(int i=0;i<s.size();i++) 
    {
        if(!(toupper(s[i])>='A' && toupper(s[i])<='Z' || s[i]>='0' && s[i]<='9') return false; 
        else return true;
        
    }
	return 0;
}