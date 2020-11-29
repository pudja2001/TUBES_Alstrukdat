#ifndef MESINKATA_H
#define MESINKATA_H

#include "boolean.h"
/**************KUMPULAN ADT******************/
typedef struct {
	char T[100];
	int length;
} KATA;

/******SELEKTOR**************/
#define KATA(K, i) (K).T[i]

//sementara ini dulu ya xD

/*******************************************/

/***********FUNGSI-FUNGSI******************/
void BacaKata(KATA *X); //ini menerima input dari user/player
void TulisKata(KATA X); //ini nulis kata di layar (buat check doang)
boolean IsKataSama(KATA X, KATA Y); //fungsi buat mengecek command dari user.. Nanti ini dijalankan berdasarkan kata yang sesuai

#endif
