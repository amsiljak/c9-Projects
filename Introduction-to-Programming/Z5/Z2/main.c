// stringovi

// unesi
void unesi(char niz[], int velicina) {
	char znak = getchar();
	if (znak == '\n') znak = getchar();
	int i = 0;
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i] = '\0';
}


// string.h
strlen – dužina stringa (broj znakova u stringu)
strcpy – kopira string u drugi string (brišući stari sadržaj)
strcmp – leksikografsko poređenje dva stringa
strcat – spaja dva stringa
strchr – pronalazi karakter u stringu
strstr – pronalazi podstring u stringu


// strlen
int duzina(char* s) {
	int duz=0;
	while (*s++) duz++;
	return duz;
}


//strcmp(-1 ako je prvi string manji od drugog, +1 ako je prvi string veći od drugog, a 0 ako su jednaki)
int strcmp(const char* s1, const char* s2) {
	while (*s1 != '\0' && *s1 == *s2) {		
		s1++; s2++;
	}
	return *s1 - *s2;
}

//koliko puta se znak pojavljuje u stringu
int prebroji(const char* s, char znak) {
	int broj=0;
	if (znak >= 'A' && znak <= 'Z')
		znak += 'a' - 'A';
	while (*s != '\0') {
		char tmp = *s;
		if (tmp >= 'A' && tmp <= 'Z')
			tmp += 'a' - 'A';
		if (tmp == znak) broj++;
		s++;
	}
	return broj;
}

//strcpy
char* spoji(char* s1, const char* s2) {
	char* ret = s1;
	while (*s1++);
	s1--;
	while (*s1++ = *s2++);
	return ret;
}


//strstr/funkcija treba vratiti pokazivač na prvi znak u stringu s1 koji predstavlja početak podstringa
//u suprotnom treba vratiti nul-pokazivač 
const char* podstring(const char* s1, 
								const char* s2) {
	while (*s1 != '\0') {
		const char* p = s1;
		const char* q = s2;
		while (*p++ == *q++)
			if (*q == '\0') return s1;
		s1++;
	}
	return NULL;
}


//trazi_broj
int trazi_broj(const char* s, int broj) {
	int tmp, predznak=1;
	while (*s != '\0') {
		if (*s == '-') predznak = -1;
		else if (*s >= '0' && *s <='9') {
			tmp = 0;
			while (*s >= '0' && *s <= '9') {
				tmp = tmp * 10 + *s - '0';
				s++;
			}
			if (tmp * predznak == broj) return 1;
			s--;
		} 
		else predznak = 1;
		s++;
	}
	return 0;
}


//nadji_rijec1
int trazi_rijec(const char* s1, const char* s2) {
	const char* poc = s1;
	while (*s1 != '\0') {
		const char* p = s1;
		const char* q = s2;
		while (*p++ == *q++)
			if (*q == '\0' && 
				(s1 == poc || *(s1-1) == ' ') &&
				(*p == ' ' || *p == '\0') ) return 1;
		s1++;
	}
	return 0;
}

//prebrojavanje rijeci
int razmak=1, broj_rijeci=0;
while (*s != '\0') {
	if (*s == ' ')
		razmak=1;
	else if (razmak == 1) {
		razmak=0;
		broj_rijeci++;
	}
	s++;
}

//izbacivanje n. rijeci
void izbaci_rijec(char* s, int n) {
	int razmak=1, broj_rijeci=0;
	char* pocetak;
	while (*s != '\0') {
		if (*s == ' ')
			razmak=1;
		else if (razmak == 1) {
			razmak=0;
			broj_rijeci++;
			if (broj_rijeci==n) pocetak=s;
			if (broj_rijeci==n+1) {
				while (*pocetak++ = *s++);
				return;
			}
		}
		s++;
	}
	if (broj_rijeci == n) *pocetak = '\0';
}

//izbacivanje rijeci2
int neslovo=1, broj_rijeci=0;
while (*s != '\0') {
	if ( !(*s >= 'A' && *s <= 'Z' || 
		*s >= 'a' && *s <= 'z') )
		neslovo = 1;
	else if (neslovo == 1) {
		neslovo = 0;
		broj_rijeci++;
		...
	}
	s++;
}

//ubacivanje u string
void zamijeni1(char* s) {
	char tekst[] = "jedan";
	int duzina = strlen(tekst)-1;		
	while (*s != '\0') {
		if (*s == '1') {
			char* kraj = s;
			while (*kraj != '\0') kraj++;
			while (kraj > s) {
				*(kraj+duzina) = *kraj;
				kraj--;
			}
			char* p = tekst;
			while (*p != '\0') *s++ = *p++;
		}
		s++;
	}
}


