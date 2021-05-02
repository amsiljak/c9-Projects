/* TP, 2018/2019
*/
#include <iostream>

long long int StirlingovBroj(int i,int j)
{
    long long int vrijednost;
    if(i==0 && j==0) return 1;
    if(j==0) return 0;
    if(j>i) return 0;
    vrijednost=StirlingovBroj(i-1,j-1)+j*StirlingovBroj(i-1,j);
    return vrijednost;
}

long long int** StirlingoviBrojeviV1(long long int n)
{
    if (n<0) throw std::domain_error("Parametar ne smije biti negativan");
    long long int **pok{};
    try
    {
        pok=new long long int *[n+1]{};
        try
        {
            for(int i=0;i<=n;i++) pok[i]=new long long int[i+1]{};
        }
        catch(...)
        {
            for(int i=0;i<=n;i++) delete[] pok[i];
            delete[] pok;
            throw std::range_error("Parametar prevelik za raspolozivu memoriju");
        }
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<i+1;j++)
            {
                pok[i][j]=StirlingovBroj(i,j);
            }
        }
    }
    catch(std::bad_alloc e)
    {
        if(pok) for(int i=0;i<=n;i++) delete[] pok[i];
        delete[] pok;
        
        throw std::range_error("Parametar prevelik za raspolozivu memoriju");
    }
    catch(std::range_error)
    {
        throw;
    }
    return pok;
}


long long int** StirlingoviBrojeviV2(long long int n)
{
    if (n<0) throw std::domain_error("Parametar ne smije biti negativan");
    long long int **pok{};
    try
    {
        pok=new long long int *[n+1]{};
        long long int brojac(0);
        for(int i=0;i<=n;i++) brojac+=i+1;
        try
        {
            pok[0]=new long long int[brojac];
        }
        catch(...)
        {
            if(pok) delete[] pok[0];
            delete[] pok;
            throw std::range_error("Parametar prevelik za raspolozivu memoriju");
        }
        for(int i=1;i<=n;i++) pok[i]=pok[i-1]+i;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<i+1;j++)
            {
                pok[i][j]=StirlingovBroj(i,j);
            }
        }
    }
    catch(std::bad_alloc e)
    {
        if(pok) delete[] pok[0];
            delete[] pok;
        
        throw std::range_error("Parametar prevelik za raspolozivu memoriju");

    }
    catch(std::range_error)
    {
         throw;
    }
    return pok;
}
    
int main ()
{
    long long int n;
    std::cout<<"Unesite broj redova: ";
    std::cin>>n;
    try
    {
        auto pok1=StirlingoviBrojeviV1(n);
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<i+1;j++)
            {
                std::cout<<pok1[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
        for(int i=0;i<=n;i++) delete[] pok1[i];
        delete[] pok1;
        
        auto pok2=StirlingoviBrojeviV2(n);
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<i+1;j++)
            {
                std::cout<<pok2[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
        delete[] pok2[0];
        delete[] pok2;
    }
    catch(std::domain_error e)
    {
        std::cout<<"Izuzetak: "<<e.what();
    }
    catch(std::range_error e)
    {
        std::cout<<"Izuzetak: "<<e.what();
    }
	return 0;
}