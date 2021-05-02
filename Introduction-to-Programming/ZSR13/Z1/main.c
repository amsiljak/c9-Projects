#include <stdio.h>
// prvi rok,prvi zad
//dva niza tipa int jedan je prazan, iz prvog treba taj u prazni prebaciti sve brojeve
//kod kojih je zbir cifara prost broj

int main() {
    int vel,zbir=0,brprostih=0,i,j,broj,prost=1,x;
    int niz1[100];
    int niz2[100];
    int nizprostih[100];
    printf("Unesite velicinu niza: ");
    scanf("%d",&vel);
    printf("Unesite clanove niza: ");
    for(i=0;i<vel;i++) scanf("%d", &niz1[i]);
    for(i=0;i<vel;i++)
    {
        x=niz1[i];
        do {
            broj=x%10;
            x/=10;
            zbir+=broj;
        } while(x!=0);
        for(j=2;j<=zbir/2;j++)
        {
            if(zbir%j==0) {prost=0; break;}
        }
        if(prost==1) {
            nizprostih[brprostih]=niz1[i];
            brprostih++;
        }
        zbir=0;
        prost=1;
    }
    for(i=0;i<brprostih;i++)
    {
        niz2[i]=nizprostih[i];
    }
    for(i=0;i<brprostih;i++) printf("%d", nizprostih[i]);
	return 0;
}
