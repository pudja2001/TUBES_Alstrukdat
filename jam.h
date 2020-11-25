#ifndef JAM_H
#define JAM_H

#include "boolean.h"
/**************KUMPULAN ADT******************/
typedef struct {
	int minutes;
	int total; //Ini total waktu maksimal mengelola taman bermain
} JAM;

/***********FUNGSI-FUNGSI******************/
void ShowJam(JAM J);

#endif

