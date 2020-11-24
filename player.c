#include "player.h"
#include "mesinkata.h"

void CreatePlayer(PLAYER *P){
	KATA Name;
	int i;
	
	//MEMBACA NAMA PEMAIN
	printf("Gomen onii-chan! Masukin (nama) onii-chan: ");
	BacaKata(&Name);
	i = 0;
	while(i < Name.length){
		(*P).Det.Nama[i] = KATA(Name, i);
		i = i + 1;
	}
	(*P).Det.panjangnama = Name.length;
	
}

void ShowPlayer(PLAYER P){
	int i;
	i = 0;
	printf("Nama onii-chan	: ");
	while(i < P.Det.panjangnama){
		printf("%c", P.Det.Nama[i]);
		i = i + 1;
	}
	printf("\n");
}
