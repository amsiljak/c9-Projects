/* 
    TP 16/17 (Tutorijal 6, Zadatak 6)
	
	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja 
	i sugestije saljite na mail: khodzic2@etf.unsa.ba
	
	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak
	
*/
#include <iostream>
#include <vector>
#include <deque>

template <typename tip>
auto KreirajDinamickuKopiju2D(tip matrica) -> typename std::remove_reference<decltype(matrica[0][0])>::type**
{
	auto nova=new decltype(matrica[0][0]+matrica[0][0]) *[matrica.size()] {};
	try
		{
			int br_el(0);
			for(int i=0; i<matrica.size(); i++)
				{
					br_el+=matrica[i].size();
				}
			nova[0]=new typename std::remove_reference<decltype(matrica[0][0])>::type [br_el];
			int pred_velicina=matrica[0].size();
			for(int i=1;i<matrica.size();i++)
			{
				nova[i]=nova[i-1]+pred_velicina;
				pred_velicina=matrica[i].size();
			}
			for(int i=0; i<matrica.size(); i++)
				{
					for(int j=0; j<matrica[i].size(); j++)
						{
							nova[i][j]=matrica[i][j];
						}
				}
			return nova;
		}
	catch(std::bad_alloc e)
		{
			if(nova)
				{
					delete[] nova[0];
				}
			delete[] nova;
			throw e;
		}
}

int main ()
{
	int n;
	std::cout<<"Unesite broj redova kvadratne matrice: ";
	std::cin>>n;
	try
		{
			std::vector<std::deque<int>> v(n);
			std::cout<<"Unesite elemente matrice: ";
			for(int i=0; i<n; i++)
				{
					v.at(i).resize(n);
					for(int j=0; j<n; j++)
						{
							std::cin>>v.at(i).at(j);
						}
				}

			auto nova=KreirajDinamickuKopiju2D(v);
			for(int i=0; i<n; i++)
				{
					for(int j=0; j<n; j++)
						{
							if(i==n && j==n) std::cout<<nova[i][j];
							else std::cout<<nova[i][j]<<" ";
						}
					std::cout<<std::endl;
				}
			delete[] nova[0];
			delete[] nova;
		}
	catch(std::bad_alloc)
		{
			std::cout<<"Nedovoljno memorije";
		}
	return 0;
}
