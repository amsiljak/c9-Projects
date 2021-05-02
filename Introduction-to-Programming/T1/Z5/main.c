#include <stdio.h>

int main() {
	
	float VT, MT, CVT, CMT, P, I, UVT, UMT;
	
	/*unos vrijednosti*/
	
	printf("Unesi veliku tarifu");
	scanf("%f", &VT);
	
	printf("Unesi cijenu velike tarife");
	scanf("%f", &CVT);
	
	
	printf("Unesi malu tarifu");
	scanf("%f", &MT);
	
	printf("Unesi cijenu male tarife");
	scanf("%f", &CMT);
	
	/*ispis*/
	
	P=VT+MT;
	
	UVT=(VT/P)*100;
	UMT=(MT/P)*100;
	
	I=VT*CVT+MT*CMT;
	
	printf("\n Ukupna potrosnja je %.2f KWh", P);
	printf("\n Udio velike tarife u ukupnoj potrosnji je %2.0f%%", UVT);
	printf("\n Udio male tarife u ukupnoj potrosnji je %2.0f%%", UMT);
	printf("\n Iznos racuna je %.2f KM", I);
	
	
	return 0;
}
