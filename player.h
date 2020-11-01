#ifndef PLAYER_H
#define PLAYER_H

#include "boolean.h"

/**************KUMPULAN ADT******************/
typedef struct {
	POSITION P; //posisi pemain
	DETAILS D; //detail pemain (berisi nama dan sumber daya gitu
} PLAYER;

typedef struct {
	int x; //absis
	int y; //ordinat
} POSITION;

typedef struct {
	char Nama[100]; //nama pemain
} DETAILS;
/*******************************************/

/***********SELEKTOR************************/
#define Nama(P, i) PLAYER.DETAILS.Nama[i]

/***********FUNGSI-FUNGSI******************/
void CreatePlayer(PLAYER *P); //membuat pemain di halaman awal saat new game
void ShowPlayer(PLAYER P);	//menampilkan detail player di user interface





#endif
