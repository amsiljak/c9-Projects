/* 
    TP 16/17 (Tutorijal 13, Zadatak 4)
	Autotestove pisala Ivona Ivkovic. Sva pitanja, sugestije, prijave gresaka
	slati na mail iivkovic2@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class ApstraktniStudent
{
protected:
	std::string ime, prezime;
	int br_indeksa,br_polozenih;
	double prosj_ocjena;
public:
	ApstraktniStudent(std::string i,std::string p,int ind):ime(i),prezime(p),br_indeksa(ind),br_polozenih(0),prosj_ocjena(5){};
	virtual ~ApstraktniStudent(){};
	std::string DajIme(){return ime;};
	std::string DajPrezime(){return prezime;};
	int DajBrojIndeksa(){return br_indeksa;};
	int DajBrojPolozenih(){return br_polozenih;};
	double DajProsjek(){return prosj_ocjena;};
	void RegistrirajIspit(int ocjena);
	void PonistiOcjene(){br_polozenih=0;prosj_ocjena=5;};
	virtual void IspisiPodatke() const=0;
	virtual ApstraktniStudent* DajKopiju()const=0;
};
void ApstraktniStudent::RegistrirajIspit(int ocjena)
{
	if(ocjena<5 || ocjena>10) throw std::domain_error("Neispravna ocjena");
	else if(ocjena!=5)
	{
		br_polozenih++;
		prosj_ocjena=((prosj_ocjena*(br_polozenih-1))+ocjena)/br_polozenih;
	}
}
class StudentBachelor:public ApstraktniStudent
{
public:
	StudentBachelor(std::string i,std::string p,int ind):ApstraktniStudent(i,p,ind){};
	ApstraktniStudent *DajKopiju() const override {return new StudentBachelor(*this);};
	void IspisiPodatke() const override
	{
		std::cout<<"Student bachelor studija "<<ime<<" "<<prezime<<", sa brojem indeksa "<<
		br_indeksa<<","<<std::endl<<"ima prosjek "<<prosj_ocjena<<"."<<std::endl;
	}
};
class StudentMaster:public ApstraktniStudent
{
	int god_zavrsetka;
public:
	StudentMaster(std::string i,std::string p,int ind,int god):ApstraktniStudent(i,p,ind),god_zavrsetka(god){};
	ApstraktniStudent *DajKopiju()const override{return new StudentMaster(*this);};
	void IspisiPodatke() const override
	{
		std::cout<<"Student master studija "<<ime<<" "<<prezime<<", sa brojem indeksa "<<
		br_indeksa<<","<<std::endl<<"zavrsio bachelor studij godine "<<god_zavrsetka<<",ima prosjek "<<prosj_ocjena<<"."<<std::endl;
	}
};

class Student
{
	ApstraktniStudent* student;
	void Test() const
	{
		if(!student) throw std::logic_error("Nespecificiran lik!");
	}
public:
	Student():student(nullptr){};
	~Student(){delete student;};
	Student(const Student &s)
	{
		if(s.student==nullptr) student=nullptr;
		else student=s.student->DajKopiju();
	}
	Student(const ApstraktniStudent &s):student(s.DajKopiju()){};
	Student(Student &&s)
	{
		student=s.student; s.student=nullptr;	
	}
	Student &operator =(const Student &s)
	{
		delete student;
		if(s.student==nullptr) student=nullptr;
		else student=s.student->DajKopiju();
		return *this;
	}
	Student &operator =(Student &&s)
	{
		std::swap(s.student,student);
		return *this;
	}
	std::string DajIme(){Test(); return student->DajIme();};
	std::string DajPrezime(){Test(); return student->DajPrezime();};
	int DajBrojIndeksa(){Test(); return student->DajBrojIndeksa();};
	int DajBrojPolozenih(){Test(); return student->DajBrojPolozenih();};
	double DajProsjek(){Test(); return student->DajProsjek();};
	void RegistrirajIspit(int ocjena){Test(); student->RegistrirajIspit(ocjena);};
	void PonistiOcjene(){Test(); student->PonistiOcjene();};
	void IspisiPodatke() const{Test(); student->IspisiPodatke();}
	ApstraktniStudent* DajKopiju()const{Test(); return student->DajKopiju();}
};
int main ()
{
	return 0;
}