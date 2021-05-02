/* TP, 2018/2019, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.	
*/
#include <iostream>
#include <vector> 
#include <iomanip>
#include <stdexcept>

typedef std::vector <std::vector<int>> Matrica;

int NajvecaSirina(std::vector<std::vector<int>> m)
{
    std::vector<std::vector<int>> brojaci=m;
    for(int i=0;i<m.size();i++) 
    {
        for(int j=0;j<m.at(i).size();j++) 
        {
            brojaci.at(i).at(j)=0;
        }
    }
    for(int i=0;i<m.size();i++)
    {
        for(int j=0;j<m.at(i).size();j++) 
        {
            int broj;
            if(m.at(i).at(j)<0) brojaci.at(i).at(j)++;
            broj=abs(m.at(i).at(j));
            while(1)
            {
                if(broj<1) break;
                brojaci.at(i).at(j)++;
                broj=broj/10;
            }
        }
    }
    int max=brojaci[0][0];
    for(int i=0;i<m.size();i++) 
    {
        for(int j=0;j<m[i].size();j++)
        {
            if(brojaci[i][j]>max) max=brojaci[i][j];
        }
    }
    return max;
}

Matrica KroneckerovProizvod(Matrica A, Matrica B)
{
	Matrica prazna(0,std::vector <int>(0));
	if(A.size()==0 || B.size()==0) return prazna;
	int m1=A.size();
	int m2=B.size();
	int n1=A.at(0).size();
	int n2=B.at(0).size();
	int prva(0),druga(0);
	for(int i=1;i<m1;i++)
	{
		if(n1!=A.at(i).size()) prva=1;
	}
	for(int i=1;i<m2;i++)
	{
		if(n2!=B.at(i).size()) druga=1;
	}
	if(prva && druga) throw std::domain_error("Parametri nemaju formu matrice");
	else if(prva) throw std::domain_error("Prvi parametar nema formu matrice");
	else if(druga) throw std::domain_error("Drugi parametar nema formu matrice");
	Matrica M(m1*m2, std::vector<int>(n1*n2));
	for(int i=0;i<m1;i++)
	{
		for(int j=0;j<n1;j++)
		{
			for(int k=0;k<m2;k++)
			{
				for(int l=0;l<n2;l++)
				{
					M.at(i*m2+k).at(j*n2+l)=A.at(i).at(j)*B.at(k).at(l);
				}
			}
		}
	}
	return M;
}

int main ()
{
	try
	{
		int n1,n2,m1,m2;
		Matrica M;
		std::cout<<"Unesite dimenzije prve matrice: ";
		std::cin>>n1>>n2;
		Matrica mat1(n1, std::vector <int>(n2));
		std::cout<<std::endl<<"Unesite elemente prve matrice: ";
		for(int i=0;i<n1;i++)
		{
			for(int j=0;j<n1;j++)
			{
				std::cin>>mat1.at(i).at(j);
			}
		}
		std::cout<<std::endl<<"Unesite dimenzije druge matrice:";
		std::cin>>m1>>m2;
		Matrica mat2(m1, std::vector <int>(m2));
		std::cout<<std::endl<<"Unesite elemente druge matrice:";
		for(int i=0;i<m1;i++)
		{
			for(int j=0;j<m2;j++)
			{
				std::cin>>mat2.at(i).at(j);
			}
		}
		std::cout<<std::endl<<"Njihov Kroneckerov proizvod glasi: "<<std::endl;
		M=KroneckerovProizvod(mat1,mat2);
		for(int i=0;i<m1*n1;i++)
		{
			for(int j=0;j<m2*n2;j++)
			{
				std::cout<<std::setw(NajvecaSirina(M)+1)<<M.at(i).at(j);
			}
			std::cout<<std::endl;
		}
	}
	catch(std::domain_error Izuzetak)
	{
		std::cout<<std::endl<<Izuzetak.what();
	}
	return 0;
}