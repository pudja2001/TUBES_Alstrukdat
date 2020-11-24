#ifndef PLAYER_H
#define PLAYER_H

#include "boolean.h"

/**************KUMPULAN ADT******************/

typedef struct {
	int x; //absis
	int y; //ordinat
} POSITION;

typedef struct {
	char Nama[100]; //nama pemain
	int panjangnama; //hahaha buat nyatet doang sih
} DETAILS;

typedef struct {
	POSITION Pos; //posisi pemain
	DETAILS Det; //detail pemain (berisi nama dan sumber daya gitu)
} PLAYER;

/*******************************************/

/***********SELEKTOR************************/


/***********FUNGSI-FUNGSI******************/
void CreatePlayer(PLAYER *P); //membuat pemain di halaman awal saat new game
void ShowPlayer(PLAYER P);	//menampilkan detail player di user interface





#endif
