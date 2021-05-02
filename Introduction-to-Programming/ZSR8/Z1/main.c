/* Zadatak u ZSR 10, Zadatak 11
   U predavanjima ima dato trazenje najveceg broja u stringu*/

void izbaci_maxbroj(char *s) {
    int max=0, broj=0, predznak=1;
    char* p=NULL, *k;

    /* Trazimo neki broj */
    while(*s != '\0') {
        if (*s == '-') predznak=-1;
        else if (*s >= '0' && *s <= '9') {
            while (*s >= '0' && *s <= '9') {
                broj = broj * 10 + *s - '0';
                s++;
            }
            broj *= predznak;
            if (p == NULL || broj > max) {
                max = broj;
                /* Postavljamo pokazivace p i k na pocetak i kraj */
                k = s;
                p = s-1;
                /* Idemo unazad da nadjemo pocetak broja */
                while (*p >= '0' && *p <= '9') p--;
                /* Ako tu ima minus treba i njega izbaciti */
                if (*p != '-') p++;
            }
            broj = 0;
        }
        else predznak=1;
        s++;
    }

    /* U stringu se ne nalazi niti jedan broj */
    if (p==NULL) return;

    /* Izbacivanje podstringa - dato u predavanjima */
    while(*k != '\0') *p++ = *k++;
    *p='\0';
}
