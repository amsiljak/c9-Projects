#include <stdio.h>
#include <stdlib.h>

int main()
{
	double t, t1, t2, t3, cz, cs, cn;
	double knov, kuk, z, s, n, procenat, k1, k2;
	int random, kz, ks, kn, izbor, matkup, kolkup, matpro, kolpro;
	kz=0;
	ks=0;
	kn=0;
	knov=100000;
	kuk=100000;
	cz=1200;
	cs=15;
	cn=70;
	t=0.1;
	t1=0.00000001;
	t2=0;
	t3=0;
	procenat=0;

	/* Prva sedmica */
	srand(0); /* Samo jedan seed za sve randove */

	random=2*(rand() & 1) - 1;
	t1=t*random+t1;
	random=2*(rand() & 1) - 1;
	t2=t*random+t2;
	random=2*(rand() & 1) - 1;
	t3=t*random+t3;

	cz=cz+cz*t1/100;
	cs=cs+cs*t2/100;
	cn=cn+cn*t3/100;
	printf("PON: Zlato $%.2f (%+.1f) Srebro $%.2f (%+.1f) Nafta $%.2f (%+.1f)", cz, t1, cs, t2, cn, t3);

	random=2*(rand() & 1) - 1;
	t1=t*random+t1;
	random=2*(rand() & 1) - 1;
	t2=t*random+t2;
	random=2*(rand() & 1) - 1;
	t3=t*random+t3;

	cz=cz+cz*t1/100;
	cs=cs+cs*t2/100;
	cn=cn+cn*t3/100;
	printf("\nUTO: Zlato $%.2f (%+.1f) Srebro $%.2f (%+.1f) Nafta $%.2f (%+.1f)", cz, t1, cs, t2, cn, t3);

	random=2*(rand() & 1) - 1;
	t1=t*random+t1;
	random=2*(rand() & 1) - 1;
	t2=t*random+t2;
	random=2*(rand() & 1) - 1;
	t3=t*random+t3;

	cz=cz+cz*t1/100;
	cs=cs+cs*t2/100;
	cn=cn+cn*t3/100;
	printf("\nSRI: Zlato $%.2f (%+.1f) Srebro $%.2f (%+.1f) Nafta $%.2f (%+.1f)", cz, t1, cs, t2, cn, t3);

	random=2*(rand() & 1) - 1;
	t1=t*random+t1;
	random=2*(rand() & 1) - 1;
	t2=t*random+t2;
	random=2*(rand() & 1) - 1;
	t3=t*random+t3;

	cz=cz+cz*t1/100;
	cs=cs+cs*t2/100;
	cn=cn+cn*t3/100;
	printf("\nCET: Zlato $%.2f (%+.1f) Srebro $%.2f (%+.1f) Nafta $%.2f (%+.1f)", cz, t1, cs, t2, cn, t3);

	random=2*(rand() & 1) - 1;
	t1=t*random+t1;
	random=2*(rand() & 1) - 1;
	t2=t*random+t2;
	random=2*(rand() & 1) - 1;
	t3=t*random+t3;

	cz=cz+cz*t1/100;
	cs=cs+cs*t2/100;
	cn=cn+cn*t3/100;
	printf("\nPET: Zlato $%.2f (%+.1f) Srebro $%.2f (%+.1f) Nafta $%.2f (%+.1f)\n", cz, t1, cs, t2, cn, t3);

	while(1) {

pocetak:
		/* Kolicine */
		
		z=kz*cz;
		s=ks*cs;
		n=kn*cn;
		kuk=z+s+n+knov;
		printf("\nImate:\nZlata: %d ($%.2f) Srebra: %d ($%.2f) Nafte: %d ($%.2f) Novca: $%.2f\nUKUPNO: $%.2f ($%+.2f)", kz, z, ks, s, kn, n, knov, kuk, procenat);


		printf("\n\nUnesite izbor (1 - Kupi, 2 - Prodaj, 3 - Sljedeca sedmica, 0 - Kraj igre): ");
		scanf("%d", &izbor);

		if(izbor==0) {
			return 0;
		} else if (izbor==3) {
			goto naredna_sedmica;
		} else if (izbor==2) {
			goto prodaja;
		} else if (izbor==1) {
			goto kupovina;
		} else {
			printf("Pogresan izbor!\n");
			goto pocetak;
		}

naredna_sedmica:
        k1=kuk;
		random=2*(rand() & 1) - 1;
		t1=t*random+t1;
		random=2*(rand() & 1) - 1;
		t2=t*random+t2;
		random=2*(rand() & 1) - 1;
		t3=t*random+t3;

		cz=cz+cz*t1/100;
		cs=cs+cs*t2/100;
		cn=cn+cn*t3/100;
		printf("\nPON: Zlato $%.2f (%+.1f) Srebro $%.2f (%+.1f) Nafta $%.2f (%+.1f)", cz, t1, cs, t2, cn, t3);

		random=2*(rand() & 1) - 1;
		t1=t*random+t1;
		random=2*(rand() & 1) - 1;
		t2=t*random+t2;
		random=2*(rand() & 1) - 1;
		t3=t*random+t3;

		cz=cz+cz*t1/100;
		cs=cs+cs*t2/100;
		cn=cn+cn*t3/100;
		printf("\nUTO: Zlato $%.2f (%+.1f) Srebro $%.2f (%+.1f) Nafta $%.2f (%+.1f)", cz, t1, cs, t2, cn, t3);

		random=2*(rand() & 1) - 1;
		t1=t*random+t1;
		random=2*(rand() & 1) - 1;
		t2=t*random+t2;
		random=2*(rand() & 1) - 1;
		t3=t*random+t3;

		cz=cz+cz*t1/100;
		cs=cs+cs*t2/100;
		cn=cn+cn*t3/100;
		printf("\nSRI: Zlato $%.2f (%+.1f) Srebro $%.2f (%+.1f) Nafta $%.2f (%+.1f)", cz, t1, cs, t2, cn, t3);

		random=2*(rand() & 1) - 1;
		t1=t*random+t1;
		random=2*(rand() & 1) - 1;
		t2=t*random+t2;
		random=2*(rand() & 1) - 1;
		t3=t*random+t3;

		cz=cz+cz*t1/100;
		cs=cs+cs*t2/100;
		cn=cn+cn*t3/100;
		printf("\nCET: Zlato $%.2f (%+.1f) Srebro $%.2f (%+.1f) Nafta $%.2f (%+.1f)", cz, t1, cs, t2, cn, t3);

		random=2*(rand() & 1) - 1;
		t1=t*random+t1;
		random=2*(rand() & 1) - 1;
		t2=t*random+t2;
		random=2*(rand() & 1) - 1;
		t3=t*random+t3;

		cz=cz+cz*t1/100;
		cs=cs+cs*t2/100;
		cn=cn+cn*t3/100;
		printf("\nPET: Zlato $%.2f (%+.1f) Srebro $%.2f (%+.1f) Nafta $%.2f (%+.1f)\n", cz, t1, cs, t2, cn, t3);
		z=kz*cz;
		s=ks*cs;
		n=kn*cn;
		kuk=z+s+n+knov;
		procenat=procenat+(kuk-k1);
		
		continue;

kupovina:
		printf("Sta kupujete (1 - Zlato, 2 - Srebro, 3 - Naftu): ");
		scanf("%d", &matkup);
  
		if(matkup==1) {
			printf("Koliko? ");
		    scanf("%d", &kolkup);
		    if (cz*kolkup>knov) {
		    	printf("Nemate toliko novca!");
		    	goto pocetak; }
			kz=kz+kolkup;
			z=z+cz*kolkup;
			knov=knov-cz*kolkup;
		} else if(matkup==2) {
			printf("Koliko? ");
		    scanf("%d", &kolkup);
		    if (cs*kolkup>knov) {
		    	printf("Nemate toliko novca!");
		    	goto pocetak; }
			ks=ks+kolkup;
			s=s+cs*kolkup;
			knov=knov-cs*kolkup;
		} else if(matkup==3) {
			printf("Koliko? ");
		    scanf("%d", &kolkup);
		    if (cn*kolkup>knov) {
		    	printf("Nemate toliko novca!");
		    	goto pocetak; }
			kn=kn+kolkup;
			n=n+cn*kolkup;
			knov=knov-cn*kolkup;
		} else {
			printf("Pogresan izbor.\n");
			goto kupovina;
		} 
		
		continue;

prodaja:
			printf("Sta prodajete (1 - Zlato, 2 - Srebro, 3 - Naftu): ");
			scanf("%d", &matpro);

            
			if (matpro==1) {
				printf("Koliko? ");
			    scanf("%d", &kolpro);
			    if(kolpro>kz) {
			    	printf("Nemate toliko zlata!");
			    	goto pocetak;
			    }
				kz=kz-kolpro;
				z=z-cz*kolpro;
				knov=knov+cz*kolpro;
			} else if(matpro==2) {
				printf("Koliko? ");
			    scanf("%d", &kolpro);
			    if(kolpro>ks) {
			    	printf("Nemate toliko srebra!");
			    	goto pocetak;
			    }
				ks=ks-kolpro;
				s=s-cs*kolpro;
				knov=knov+cs*kolpro;
			} else if (matpro==3) {
				printf("Koliko? ");
			    scanf("%d", &kolpro);
			    if(kolpro>kn) {
			    	printf("Nemate toliko nafte!");
			    	goto pocetak;
			    }
				kn=kn-kolpro;
				n=n-cn*kolpro;
				knov=knov+cn*kolpro;
			} else {
				printf("Pogresan izbor.\n");
				goto prodaja;
			} 
			continue;
		}


		return 0;
	}
