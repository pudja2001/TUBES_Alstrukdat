#include "player.h"
#include "mesinkata.h"

void CreatePlayer(PLAYER *P){
	KATA Name;
	int i;
	
	//MEMBACA NAMA PEMAIN
	printf("Gomen onii-chan! Demo, anata no namaewa nan desuka onii-chan: ");
	BacaKata(&Name);
	i = 0;
	while(i < Name.length-1){
		(*P).Det.Nama[i] = KATA(Name, i);
		i = i + 1;
	}
	(*P).Det.panjangnama = Name.length;
	
}

void ShowPlayer(PLAYER P){
	int i;
	i = 0;
	while(i < P.Det.panjangnama-1){
		printf("%c", P.Det.Nama[i]);
		i = i + 1;
	}
	printf("\n");
}
