//stvari za ispit 

void unesi(char niz[], int velicina) {
	char znak = getchar();
	if (znak == '\n') znak=getchar();
	int i = 0;
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}
/* fputc('A',ulaz);
fgets(string, br_znakova,ulaz); ucitace br_znakova-1 ili do oznake \n
fputs(string,ulaz);

while(fscanf(ulaz,"%d %d %s\n", &siria, %duz,ime)==3)
fseek(ulaz, 0, SEEK_SET/SEEK_END/SEEK_CURR);
ftell(ulaz);

long pos=ftell(ulaz);
fseek(ulaz,0,SEEK_END); - na kaj dat upis
fseek(ulaz,pos,SEEK_SET);

int ucitano=fread(imenik,sizeof(struct Osoba),KAPACITET,ulaz);
