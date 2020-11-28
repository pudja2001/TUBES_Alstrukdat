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
	
	(*P).Det.uang = 1000;
	(*P).Det.besi = 10;
	(*P).Det.kayu = 100;
	(*P).Det.batu = 50;
}

void ShowPlayer(PLAYER P){
	//PRINT NAMA SAMA STAT (UANG DLL)
	int i;
	i = 0;
	while(i < P.Det.panjangnama){
		printf("%c", P.Det.Nama[i]);
		i = i + 1;
	}
	printf(" onii-chan ^^");
	printf("\n");
	printf("Uang: %d\n", P.Det.uang);
	printf("Kayu: %d | Batu: %d | Besi: %d\n",P.Det.kayu,P.Det.batu,P.Det.besi);
}
