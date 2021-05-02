#include <stdio.h>

int drugi(int niz[], int vel){
	int* pok;
	int* prvi;
	int* drugi;
	pok=niz;
	prvi=pok;
	drugi=pok;
	for(pok=niz; pok<niz+vel; pok++){
		if( *prvi < *pok){
			prvi = pok;
		}
	}
	for(pok=niz; pok<niz+vel; pok++){
		if( *prvi == *drugi){ //pokriva situaciju u kojoj je max prvi el
			drugi = pok;
		}
		else if ( (*pok>*drugi) && (*pok != *prvi) ){
			drugi = pok;
		}
	}
	if ( *prvi == *drugi ) return -1;
	return drugi-niz;
}

int main() {
	int vel=0;
	int niz[100];
	printf("Unesite niz brojeva: ");
	do{
		scanf("%d", &niz[vel]);
	}while(niz[vel++]!=-1);
	vel--;
	printf("Indeks drugog po velicini je: %d", drugi(niz,vel));
	return 0;
}