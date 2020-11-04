//include header bawaan
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//include file header buatan sendiri
#include "player.c"
#include "map.c"
#include "mesinkata.c"

int main(){
	
	/****************DEKLARASI AWAL****************/
	
	/*************DEKLARASI OINI-CHANNNN**********/
	PLAYER P;
	
	/****************DEKLARASI COMMAND************/
	//Note: nanti untuk mengecek command mana yang dijalankan, nanti kita akan menggunakan
	//	    fungsi IsKataSama(X, Y) dimana X dan Y bertipe KATA
	
	//VARIABEL command yang nanti buat nyimpen perintah player
	KATA command;
	
	//Command untuk gerak (wasd)
	KATA w;
	w.T[0] = 'w';
	w.T[1] = '\n';
	KATA a;
	a.T[0] = 'a';
	a.T[1] = '\n';
	KATA s;
	s.T[0] = 's';
	s.T[1] = '\n';
	KATA d;
	d.T[0] = 'd';
	d.T[1] = '\n';
	
	//Command untuk new game
	KATA newgame;
	newgame.T[0] = 'n';
	newgame.T[1] = 'e';
	newgame.T[2] = 'w';
	newgame.T[3] = '\n';
	
	//Command untuk quit (q)
	KATA quit;
	quit.T[0] = 'q';
	quit.T[1] = 'u';
	quit.T[2] = 'i';
	quit.T[3] = 't';
	quit.T[4] = '\n';
	
	
	/********BAGIAN UTAMA GAME NON DEKLARASI************/
	system("cls");
	printf("Selamat datang Onii-chan!\n");
	printf("Onii-chan, kita buat area bermain yuk!\n");
	printf("Kawaii imouto ini pengen  maen sama onii-chan <3 \n");
	printf("\n");
	printf("new -> mulai merancang taman bermain imouto\n");
	printf("quit-> quit dan gapeduli karena sukanya sama onee-san\n");
	
	//Apakah mau quit atau maen sama kawaii imouto
	printf("Onii-chan pengen apa: ");
	BacaKata(&command);
	
	//MULAIIII LOOPING GAME
	while( (IsKataSama(command, newgame) == false) && (IsKataSama(command, quit) == false)){
		system("cls");
		printf("Selamat datang Onii-chan!\n");
		printf("Onii-chan, kita buat area bermain yuk!\n");
		printf("Kawaii imouto ini pengen  maen sama onii-chan <3 \n");
		printf("\n");
		printf("new -> mulai merancang taman bermain imouto\n");
		printf("quit-> quit dan gapeduli karena sukanya sama onee-san\n");
		printf("MASUKIN COMMAND YANG BENER ONII-CHAN NO AHO!\n");
		
		//checker
		TulisKata(command);
		printf("\n");
		
		//Apakah mau quit atau maen sama kawaii imouto
		printf("Onii-chan pengen apa cepet: ");
		BacaKata(&command);
	}
	
	//INI KAMU MAU QUIT ATAU MAEN SAMA KAWAII IMOUTO
	if(IsKataSama(command, newgame)){
		system("cls");
		printf("Ikuzooo onii-chan <3\n");
		//PROSES PEMBUATAN PEMAIN
		CreatePlayer(&P);
		
	}
	else if(IsKataSama(command, quit)){
		printf("\n");
		printf("Onii-chan no BAKAAAA!");
	}
	
	return 0;
}
