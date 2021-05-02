#include <stdio.h>
#include <stdlib.h>

void oduzmi_cifre(int niz[], int br)
{
	int* p=niz;
	int broj=0, n=1;
	int d; /* Desna cifra od koje se oduzima*/
	int l; /* Lijeva cifra koja se oduzima*/
	int i;

	for(i=0; i<br; i++)
		{

			/* Ako je broj jednocifren */
			if(*(p+i)<10 && *(p+i)>-10)
				{
					*(p+i)=0;
					continue;
				}

			/* Ako je broj negativan */
			*(p+i)=abs(*(p+i));

			while(1)
				{
					if(*(p+i)<10 && *(p+i)>-10) break; /* Ako smo dosli do zadnje cifre s desna*/
					d=*(p+i)%10;
					*(p+i)=*(p+i)/10;
					l=*(p+i)%10;
					broj+=abs(d-l)*n;
					n*=10;
				}

			/* Zamjena unesenog broja za modifikovani*/
			*(p+i)=broj;

			n=1, broj=0;
		}
}

int main()
{
	int br, i, niz[1000];

	printf("Unesi broj:");
	scanf("%d", &br);

	printf("Unesi niz: ");
	for(i=0; i<br; i++)
		{
			scanf("%d", &niz[i]);
		}

	oduzmi_cifre(niz,br);

	for(i=0; i<br; i++)
		{
			printf("%d ", niz[i]);
		}

	return 0;
}
