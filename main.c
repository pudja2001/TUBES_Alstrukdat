#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
/*
#include "player.c"
#include "map.c"*/
#include "mesinkata.c"

int main(){
	/*DEKLARASI AWAL*/
	KATA kata;
	KATA w;
	w.T[0] = 'w';
	KATA a;
	a.T[0] = 'a';
	KATA s;
	s.T[0] = 's';
	KATA d;
	d.T[0] = 'd';
	KATA build;
	build.T[0] = 'b';
	build.T[1] = 'u';
	build.T[2] = 'i';
	build.T[3] = 'l';
	build.T[4] = 'd';
	
	BacaKata(&kata);
	TulisKata(kata);
	
	if(IsKataSama(kata, a) ){
		//geser kiri
	}
	
	return 0;
}
