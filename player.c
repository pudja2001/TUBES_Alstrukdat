#include "player.h"

void CreatePlayer(PLAYER *P){
	int i;
	i = 0;
	while (i < 100){
		scanf("%c", Nama(*P,i) );
		i = i + 1;
	}
}

void ShowPlayer(PLAYER P){
	int i;
	i = 0;
	while( (i < 100) && (PLAYER.D.Nama[i] != ' ')){
		printf("%c", PLAYER.D.Nama[i]);
		i = i + 1;
	}
}

/***NOTE****/
/*
INI BUAT AKHIR NAMA ATAU COMMAND.. NANTI DIBENERIN PAKE MESIN KATA...
*/
