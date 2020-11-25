#include "jam.h"

void ShowJam(JAM J){
	printf("Time: ");
	
	if ( divx(J.minutes,60) < 10){
		printf("0%d : ", divx(J.minutes,60) );
	}
	else{
		printf("%d : ", divx(J.minutes,60) );
	}
	
	
	
	if (J.minutes%60 < 10){
		printf("0%d",J.minutes%60);
	}
	else{
		printf("%d", J.minutes%60);
	}
	
	printf("\n");
}

int divx(int a, int b){
	float hasil;
	hasil = 0;
	if (a >= b){
		float c;
		c = a % b;
		a = a - c;
		hasil = (float)a/(float)b;
	}
	hasil = (int)hasil;
	return hasil;
}
