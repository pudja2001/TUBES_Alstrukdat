#include "mesinkata.h"

void BacaKata(KATA *X){
	int i;
	
	i = 0;
	(*X).length = 0;
	while ( (i < 10) && (KATA(*X,i-1) != '\n' )){ //Memasukkan Command ke variabel KATA atau nulis apapund deh
		scanf("%c", &KATA(*X, i) );
		(*X).length = (*X).length + 1;
		i = i + 1;
	}
}

void TulisKata(KATA X){
	int i;
	i = 0;
	while(i < X.length-1){
		printf("%c", KATA(X, i) );
		i = i + 1;
	}
	printf("\n");
}

boolean IsKataSama(KATA X, KATA Y){
	int i;
	boolean sama;
	sama = true;
	i = 0;
	while( (i < 10) && (sama==true)){
		if (KATA(X, i) != KATA(Y,i) ){
			sama = false;
		}
		i = i + 1;
	}
	return sama;
}
