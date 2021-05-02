/* 
    TP 16/17 (Tutorijal 6, Zadatak 4)
	
	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja 
	i sugestije saljite na mail: khodzic2@etf.unsa.ba
	
	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak
	
*/
#include <iostream>
int **KreirajTrougao(int n)
{
	if(n<=0) throw std::domain_error("Broj redova mora biti pozitivan");
	int **a(new int*[n]{}); // u mainu se hvata izuzetak ako ne uspije??
	try
	{
		int broj_el(0);
		for(int i=0;i<n;i++) broj_el+=(i+1)*2-1; 
		a[0]=new int[broj_el]{};
		for(int i=1;i<n;i++) 
		{
			a[i]=a[i-1]+i*2-1;
		}
		for(int i=0;i<n;i++) 
		{
			for(int j=0;j<(i+1)*2-1;j++)
			{
				if(j<i) a[i][j]=i+1-j;
				else if (j==i) a[i][j]=1;
				else a[i][j]=1+j-i;
			}
		}
		return a;
	}
	catch(std::domain_error)
	{
		throw;
	}
	catch(...)
	{
		if(a)
		{
			delete[] a[0];
			delete[] a;
		}
		throw;
	}
}

int main ()
{
	try
	{
		int n;
		std::cout<<"Koliko zelite redova: ";
		std::cin>>n;
		auto a=KreirajTrougao(n);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<(i+1)*2-1;j++)
			{
				std::cout<<a[i][j]<<" ";
			}
			std::cout<<std::endl;
		}
		delete[] a[0];
		delete[] a;
	}
	catch(std::domain_error e)
	{
		std::cout<<"Izuzetak: "<<e.what();
	}
	catch(...)
	{
		std::cout<<"Izuzetak: "<<"Nedovoljno memorije!";
	}
	return 0;
}