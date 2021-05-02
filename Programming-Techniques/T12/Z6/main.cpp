/*
    TP 16/17 (Tutorijal 12, Zadatak 6)
	Autotestove napisao Kerim Hodzic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: khodzic2@etf.unsa.ba.

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
template <typename TipEl>
class Matrica
{
	int br_redova, br_kolona;
	TipEl **elementi;
	char ime_matrice;
	static TipEl **AlocirajMemoriju(int br_redova, int br_kolona);
	static void DealocirajMemoriju(TipEl **elementi, int br_redova);
	void KopirajElemente(TipEl **elementi);
public:
	Matrica(int br_redova, int br_kolona, char ime = 0);
	Matrica(const Matrica &m);
	Matrica(Matrica &&m);
	~Matrica()
	{
		DealocirajMemoriju(elementi, br_redova);
	}
	Matrica &operator =(const Matrica &m);
	Matrica &operator =(Matrica &&m);
	template <typename Tip2>
	friend Matrica<Tip2> operator +(const Matrica<Tip2> &m1,const Matrica<Tip2> &m2);
	
	template <typename Tip1>
	friend Matrica<Tip1> operator -(const Matrica<Tip1> &m1,const Matrica<Tip1> &m2);
	
	template <typename Tip1>
	friend Matrica<Tip1> operator *(const Matrica<Tip1> &m1,const Matrica<Tip1> &m2);
	template <typename Tip1>
	friend Matrica<Tip1> operator *(const Matrica<Tip1> &m1,Tip1 br);
	template <typename Tip1>
	inline friend Matrica<Tip1> operator *(Tip1 br,const Matrica<Tip1> &m1);
	template <typename Tip1>
	Matrica<Tip1> operator +=(const Matrica<Tip1> &m2)
	{
		if(br_redova != m2.br_redova || br_kolona != m2.br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");
		for(int i = 0; i < br_redova; i++)
			for(int j = 0; j < br_kolona; j++)
				elementi[i][j] +=m2.elementi[i][j];
		return *this;
	}
	template <typename Tip1>
	Matrica<Tip1> operator -=(const Matrica<Tip1> &m2)
	{
		if(br_redova != m2.br_redova || br_kolona != m2.br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");
		for(int i = 0; i < br_redova; i++)
			for(int j = 0; j < br_kolona; j++)
				elementi[i][j] -=m2.elementi[i][j];
		return *this;
	}
	template <typename Tip1>
	Matrica<Tip1> operator *=(const Matrica<Tip1> &m2)
	{
		if(br_redova != m2.br_redova || br_kolona != m2.br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");
		for(int i = 0; i < br_redova; i++)
			for(int j = 0; j < br_kolona; j++)
			{
				Tip1 a=0;
				for(int k=0;k<br_kolona;k++) a+=elementi[i][k]*m2.elementi[k][j];
				elementi[i][j]=a;
			}
		return *this;
	}
	template <typename Tip1>
	Matrica<Tip1> operator *=(Tip1 br)
	{
		for(int i = 0; i < br_redova; i++)
			for(int j = 0; j < br_kolona; j++)
				elementi[i][j]*=br;
		return *this;
	}
	
	TipEl* operator [](int n) const 
	{
		return elementi[n];
	}
	TipEl* operator [](int n) 
	{
		return elementi[n];
	}
	
	TipEl operator ()(int a,int b) const
	{
		if(a>br_kolona || b>br_kolona) throw std::range_error("Neispravan indeks");
		return elementi[a-1][b-1];
	}
	TipEl operator ()(int a,int b) 
	{
		if(a>br_kolona || b>br_kolona) throw std::range_error("Neispravan indeks");
		return elementi[a-1][b-1];
	}
	
	friend std::istream &operator >>(std::istream &tok,Matrica<TipEl>mat);
	
	friend std::ostream &operator <<(std::ostream &tok,Matrica<TipEl>mat);
};


	
	template <typename Tip1>
	inline Matrica<Tip1> operator *(Tip1 br,const Matrica<Tip1> &m1)
	{
		return m1*br;
	}
	
	template <typename Tip1>
	Matrica<Tip1> operator *(const Matrica<Tip1> &m1,Tip1 br)
	{
		Matrica<Tip1>m3(m1); m3*=br;
		return m3;
	}

	template <typename Tip1>
	Matrica<Tip1> operator *(const Matrica<Tip1> &m1,const Matrica<Tip1> &m2)
	{
		Matrica<Tip1>m3(m1); m3*=m2; return m3;
	}
	template <typename Tip1>
	Matrica<Tip1> operator -(const Matrica<Tip1> &m1,const Matrica<Tip1> &m2)
	{
		Matrica<Tip1> m3(m1);
		m3+=m2;
		return m3;
	}



template <typename TipEl>
std::istream &operator >>(std::istream &tok,Matrica<TipEl>mat)
{
	for(int i = 0; i < mat.br_redova; i++)
		for(int j = 0; j < mat.br_kolona; j++)
			{
				std::cout << mat.ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
				tok >> mat.elementi[i][j];
			}
	return tok;
}

template <typename TipEl>
std::ostream &operator <<(std::ostream &tok,Matrica<TipEl>mat) 
{
	int sirina_ispisa=tok.width();
	for(int i = 0; i < mat.br_redova; i++)
		{
			for(int j = 0; j < mat.br_kolona; j++)
				std::cout << std::setw(sirina_ispisa) << mat.elementi[i][j];
			std::cout << std::endl;
		}
		return tok;
}

template <typename TipEl>
TipEl ** Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona)
{
	TipEl **elementi = new TipEl*[br_redova] {};
	try
		{
			for(int i = 0; i < br_redova; i++) elementi[i] = new TipEl[br_kolona];
		}
	catch(...)
		{
			DealocirajMemoriju(elementi, br_redova);
			throw;
		}
	return elementi;
}

template <typename TipEl>
void Matrica<TipEl>::DealocirajMemoriju(TipEl **elementi, int br_redova)
{
	for(int i = 0; i < br_redova; i++) delete[] elementi[i];
	delete[] elementi;
}

template <typename TipEl>
Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime) :
	br_redova(br_redova), br_kolona(br_kolona), ime_matrice(ime),
	elementi(AlocirajMemoriju(br_redova, br_kolona)) {}
	
template <typename TipEl>
void Matrica<TipEl>::KopirajElemente(TipEl **elementi)
{
	for(int i = 0; i < br_redova; i++)
		for(int j = 0; j < br_kolona; j++)
			Matrica::elementi[i][j] = elementi[i][j];
}

template <typename TipEl>
Matrica<TipEl>::Matrica(const Matrica<TipEl> &m) : br_redova(m.br_redova),
	br_kolona(m.br_kolona), ime_matrice(m.ime_matrice),
	elementi(AlocirajMemoriju(m.br_redova, m.br_kolona))
{
	KopirajElemente(m.elementi);
}

template <typename TipEl>
Matrica<TipEl>::Matrica(Matrica<TipEl> &&m) : br_redova(m.br_redova),
	br_kolona(m.br_kolona), elementi(m.elementi), ime_matrice(m.ime_matrice)
{
	m.br_redova = 0;
	m.elementi = nullptr;
}

template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(const Matrica<TipEl> &m)
{
	if(br_redova < m.br_redova || br_kolona < m.br_kolona)
		{
			TipEl **novi_prostor = AlocirajMemoriju(m.br_redova, m.br_kolona);
			DealocirajMemoriju(elementi, br_redova);
			elementi = novi_prostor;
		}
	else if(br_redova > m.br_redova)
		for(int i = m.br_redova; i < br_redova; i++) delete elementi[i];
	br_redova = m.br_redova;
	br_kolona = m.br_kolona;
	ime_matrice = m.ime_matrice;
	KopirajElemente(m.elementi);
	return *this;
}

template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(Matrica<TipEl> &&m)
{
	std::swap(br_redova, m.br_redova);
	std::swap(br_kolona, m.br_kolona);
	std::swap(ime_matrice, m.ime_matrice);
	std::swap(elementi, m.elementi);
	return *this;
}

template <typename TipEl>
Matrica<TipEl> operator +(const Matrica<TipEl> &m1,
                           const Matrica<TipEl> &m2)
{
	Matrica<TipEl>m3(m1); m3+=m2; return m3;
}

int main ()
{
	return 0;
}
