#ifndef MAP_H
#define MAP_H

#include "boolean.h"

/**************KUMPULAN ADT******************/
typedef struct {
	char NAMA[100];
	int length;
} DETAIL_WAHANA;

typedef struct {
	int NAIK_TOTAL;
} LAPORAN_WAHANA;

typedef struct {
	DETAIL_WAHANA D; //ini nanti berisi detail wahana
	LAPORAN_WAHANA L; //berisi laporan penjualan dan lain-lain
	char karakter; //karakter yang ditampilkan di MAP
	/*CATATAN KARAKTER
	* : tembok
	- : kosong
	> < ^ v : terowongan
	
	O : office
	G : Gudang (tempat apa ya?)
	A : antrian pengganggu kesenangan kita berdua onii-chan
	
	Wahana
	B : Bioskop khusus anime xD
	M : Maid cafe
	C : foto spot + Cosplay
	S : wibu Shop
	L : Love arcade (tempat game)
	T : Taman mainan biasa (sejenis roler coeaster apalah itu pokoknya)
	
	P : player
	*/ 
} WAHANA;

typedef struct {
	WAHANA T[14][14]; //ini matriksnya yang membentuk MAP
	int Map; // disini Map adalah penanda dia ada dimana (berdasarkan 4 peta partisi)
} MAP;


//sementara ini dulu ya xD

/*******************************************/

/***********FUNGSI-FUNGSI******************/
void ShowMap(MAP M);	//menampilkan map di user interface


#endif
