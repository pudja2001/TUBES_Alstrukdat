#ifndef MAP_H
#define MAP_H

#include "boolean.h"

/**************KUMPULAN ADT******************/
typedef struct {
	WAHANA M[14][14]; //ini matriksnya yang membentuk MAP
	int Map; // disini Map adalah penanda dia ada dimana (berdasarkan 4 peta partisi)
} MAP;

typedef struct {
	DETAIL_WAHANA D; //ini nanti berisi detail wahana
	LAPORAN_WAHANA L; //berisi laporan penjualan dan lain-lain
	char karakter; //karakter yang ditampilkan di MAP
} WAHANA;

typedef struct {
	char NAMA[100];
} DETAIL_WAHANA;

typedef struct {
	int NAIK_TOTAL;
} LAPORAN_WAHANA;
//sementara ini dulu ya xD

/*******************************************/

/***********FUNGSI-FUNGSI******************/
void ShowMap(MAP M);	//menampilkan map di user interface


#endif
