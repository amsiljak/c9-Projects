#include <stdio.h>

// nizovi i matrice

// izbacivanje clana iz niza,neocuvan redoslijed
for (i=0; i<n; i++) {
		if (niz[i] % 2 != 0) {
			niz[i] = niz[n-1];
			n--;            
			i--;
		}
	}

// izbacivanje, ocuvan
for (i=0; i<n; i++) {
		if (niz[i] % 2 != 0) {
			for (j=i; j<n-1; j++) {
				niz[j] = niz[j+1];
			}
			n--;            
			i--;
		}
	}


// prebrojavanje clanova niza
maxi = 0;
	mini = -1;
	for (i=0; i<=100; i++) {
		if (brojaci[i] > brojaci[maxi]) {
			maxi = i;
		}
		if (brojaci[i] > 0 && (mini == -1 || brojaci[i] < brojaci[mini]) {
			mini = i;
		}
	}

// selection sort
for (i=0; i<n; i++) {
	min=i;
	for (j=i+1; j<n; j++) {
		if (niz[j] < niz[min])
			min = j;
	}
	temp = niz[i];
	niz[i] = niz[min];
	niz[min] = temp;
}

// izbacivanje kolone
for (i=0; i<V; i++)
		matrica[i][maxk] = matrica[i][S-1];
	S--;
