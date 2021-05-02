#include <stdio.h>


// Ovaj zadnji autotest pada  zato sto je string sa kojim moramo zamijeniti manji od onoga string koji trazimo u pocetnom string
// Odnosno s3 < s2, ovo zahtjeva jos bruka uslova ja msm, ali ne znam kako treba
char *ZamijeniTekst (char *str, const char *sta, const char *sa_cim, int cs) {
	
	char *s1=str, *s2=sta, *s3=sa_cim;
	
	char c1, c2;
	
	while(*s3 != '\0')
		s3++;
	
	while(*s2 != '\0')
		s2++;
	
	int velicina=s3-sa_cim, brojac=0, velicina1=s2-sta;
	
	s3 = sa_cim;
	s2 = sta;
	
	while(*s1 != '\0') {
		
		
		c1 = *s1;
		c2 = *s2;
		
		if(cs == 0) {
			
			if(c1 >= 'A' && c1 <= 'Z') c1 += 32;
			if(c1 >= 'A' && c1 <= 'Z') c1 += 32;
		}
		
		char *pomjeraj=s1; // Pamtim gdje se nalazi s1, tako da kada budem radio prosirivanja, znat cu dokle da idem
		
		if(c1 == c2) {
			// Provjerava je li se string s2 stvarno nalazi u stringu s1
			while(*s1 != '\0' && *s2 != '\0') {
				
				c1 = *s1;
				c2 = *s2;
				if(cs == 0) {
					
					if(c1 >= 'A' && c1 <= 'Z') c1 += 32;
					if(c1 >= 'A' && c1 <= 'Z') c1 += 32;
				}
				if(c1 != c2)
					break;
				s1++;
				s2++;
				brojac++;
			}
			// Ako je broj rijeci koje su jednake, jednak broju rijeci koje se nalaze u string s2 onda smo ga nasli u stringu s1
			if(brojac == velicina1) {
				// Guramo sada s1 do kraja kako bi kasnije mogli da prosirimo
				while(*s1 != '\0')
					s1++;
					// Sada vrsimo prosirivanje, za onliko mjesta koliko je s3 vece od s2
				while(s1 >= pomjeraj) {
					// Ovo dole nece valjati u slucaju da je string sa kojim mijenjamo manji od string koji trazimo
					// Ne znam sta treba uvrstiti da se to ne desi
					*(s1+(velicina-velicina1)) = *s1; // Posto se vracamo unazad, ispadne kao da citamo unazad string, pa se svi znakovi do pomjeraj pomjere za nekoliko mjesta
					s1--; // Vraca pokazivac unazad mjesto po mjesto
					// Ovo je sablonski ubacivanje, a ima i sablonsko izbacivanje
					
				}
				s1++; // E ovo ne kontam zasto treba da bude tu, ali znam da program nece raditi kako treba ako ga nema
				
				// Sada kada smo napravili dovoljno mjesta, mi izjednacavamo ono sto se nalazi u s1 sa onim sto se nalazi u s3
				while(*s3 != '\0') {
					
					*s1 = *s3;
					s1++;
					s3++;
					
				}
				
			}
			
		}
		// Vraca vrijednosti, u slucaju da vise puta moramo mijenjati stringove
		s1 = pomjeraj;
		s2 = sta;
		s3 = sa_cim;
		brojac = 0; // Sada opet mozemo brojati broj karaktera koji je jednak
		s1++;
	}
	// Vracamo pocetni pokazivac, nismo ga pomjerali pa je ostao na pocetku stringa koji smo primili
	return str;
	
}

int main() {
	printf("ZSR 10, Zadatak 6\n");
	
	char tekst[100] = "CAJ";
ZamijeniTekst (tekst, "caj", "mlijeko", 0); //cs = 0
printf ("'%s'", tekst);
	return 0;
}
