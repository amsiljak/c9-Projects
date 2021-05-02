#include <stdio.h>

int matrica_sadrzana(int A[100][100], int V1, int S1, int B[100][100], int V2, int S2)
{
	int i,j,k,l,n;

	/* i i j prolaze kroz clanove matrice A dok ne dodju do posljednjeg potencijalnog pocetka matrice B*/
	for(i=0; i<=V1-V2; i++)
		{
			for(j=0; j<=S1-S2; j++)
				{

					/* dok se ne pojavi clan jednak prvom clanu matrice B*/
					if(A[i][j]!=B[0][0]) continue;

					n=j;

					/* prolazi se kroz sve elemente matrice B i porede se s matricom A od kolone n */
					for(k=0; k<V2; k++)
						{
							for(l=0; l<S2; l++)
								{
									/* Ako se pronadju razliciti elementi matrica na istoj poziciji vraca se nula */
									if(A[i][j]!=B[k][l]) return 0;
									j++;
								}
							j=n;
							i++;
						}
					/* U suprotnom se vraca 1 */
					return 1;
				}
		}
	/* Prvi clan matrice B nije nadjen u matrici A pa vracamo 0*/
	return 0;
}

int main()
{
	int A[100][100] = {{1,2,2,5,4}, {6,7,7,8,9}};
	int B[100][100] = {{2,5,4}, {7,8,9}};

	printf("%d ", matrica_sadrzana(A, 2, 5, B, 3, 3));
	return 0;
}
