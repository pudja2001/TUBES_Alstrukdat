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
	
	/*************DEKLARASI ONII-CHANNNN**********/
	PLAYER P;
	
	/*************DEKLARASI MAP PETAAAAAA*********/
	char temp; //untuk pindah pindah
	MAP M;
	int i;
	int j;
	i = 0;
	j = 0;
	while(i < 14){
		j = 0;
		while(j < 14){
			if( (i == 0) || (i == 6) || (i == 7) || (i == 13)){
				M.T[i][j].karakter = '*';
			}
			else if( (j == 0) || (j == 6) || (j == 7) || (j == 13) ){
				M.T[i][j].karakter = '*';
			}
			else{
				M.T[i][j].karakter = '-';
			}
			j = j + 1;
		}
		i = i + 1;
	}
	//POSISI PEMAINNYA DAN TEROWONGAN
	M.T[3][3].karakter = 'P';
	P.Pos.x = 3;
	P.Pos.y = 3;
	
	M.T[3][6].karakter = '>';
	M.T[6][3].karakter = 'v';
	M.T[3][7].karakter = '<';
	M.T[6][10].karakter = 'v';
	M.T[7][10].karakter = '^';
	M.T[10][7].karakter = '<';
	M.T[10][6].karakter = '>';
	M.T[7][3].karakter = '^';
	M.Map = 1;
	
	
	/****************DEKLARASI COMMAND************/
	//Note: nanti untuk mengecek command mana yang dijalankan, nanti kita akan menggunakan
	//	    fungsi IsKataSama(X, Y) dimana X dan Y bertipe KATA
	
	//VARIABEL command yang nanti buat nyimpen perintah player
	KATA command;
	
	//Command untuk gerak (wasd)
	KATA w;
	w.T[0] = 'w';
	w.T[1] = '\n';
	w.length = 1;
	KATA a;
	a.T[0] = 'a';
	a.T[1] = '\n';
	a.length = 1;
	KATA s;
	s.T[0] = 's';
	s.T[1] = '\n';
	s.length = 1;
	KATA d;
	d.T[0] = 'd';
	d.T[1] = '\n';
	d.length = 1;
	
	//Command untuk new game
	KATA newgame;
	newgame.T[0] = 'n';
	newgame.T[1] = 'e';
	newgame.T[2] = 'w';
	newgame.T[3] = '\n';
	newgame.length = 3;
	
	//Command untuk quit (q)
	KATA quit;
	quit.T[0] = 'q';
	quit.T[1] = 'u';
	quit.T[2] = 'i';
	quit.T[3] = 't';
	quit.T[4] = '\n';
	quit.length = 4;
	
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
		
		//Apakah mau quit atau maen sama kawaii imouto
		printf("Onii-chan pengen apa cepet: ");
		BacaKata(&command);
	}
	
	//INI KAMU MAU QUIT ATAU MAEN SAMA KAWAII IMOUTO
	if(IsKataSama(command, newgame)){
		system("cls");
		printf("Ikuzooo onii-chan <3\n");
		//PROSES PEMBUATAN PEMAIN DAN INISIASI NAMA + UANG DLL
		CreatePlayer(&P);
		
		//LOOPING GAME YANG SESUNGGUHNYA
		while(IsKataSama(command, quit) == false /*AND WAKTU MASIH ADA*/){//SEMENTARA BELUM BUTUH, MASIH MAU NGECE JALAN JALAN
			system("cls");
			ShowMap(M);
			ShowPlayer(P);
			printf("Damme onii-chan, ini mau ngapain??? >_>\n");
			printf("wasd jalan onii-chan\n");
			printf("Ngapain onii-chan, imuoto bakal ngikut ini: ");
			BacaKata(&command);
			if(IsKataSama(command,a)){
				//gerak dalam satu map
				if(M.T[P.Pos.x][(P.Pos.y) - 1].karakter == '-'){ //kalo bukan tembok
					temp = M.T[P.Pos.x][P.Pos.y].karakter;
					M.T[P.Pos.x][P.Pos.y].karakter = M.T[P.Pos.x][(P.Pos.y) - 1].karakter;
					P.Pos.y = P.Pos.y - 1;
					M.T[P.Pos.x][P.Pos.y].karakter = temp;
				}
				//pindah map 2 ke 1
				else if( (M.Map == 2) && (M.T[P.Pos.x][(P.Pos.y) - 1].karakter == '<') ){
					M.T[P.Pos.x][P.Pos.y].karakter = '-';
					M.T[3][5].karakter = 'P';
					M.Map = 1;
					P.Pos.x = 3;
					P.Pos.y = 5;
				}
				//pindah map 3 ke 4
				else if( (M.Map == 3) && (M.T[P.Pos.x][(P.Pos.y) - 1].karakter == '<') ){
					M.T[P.Pos.x][P.Pos.y].karakter = '-';
					M.T[10][5].karakter = 'P';
					M.Map = 4;
					P.Pos.x = 10;
					P.Pos.y = 5;
				}
			}
			else if(IsKataSama(command,w)){
				if(M.T[(P.Pos.x)-1][P.Pos.y].karakter == '-'){ //kalo bukan tembok
					temp = M.T[P.Pos.x][P.Pos.y].karakter;
					M.T[P.Pos.x][P.Pos.y].karakter = M.T[(P.Pos.x) - 1][P.Pos.y].karakter;
					P.Pos.x = P.Pos.x - 1;
					M.T[P.Pos.x][P.Pos.y].karakter = temp;
				}
				//pindah map 4 ke 1
				else if( (M.Map == 4) && (M.T[(P.Pos.x) - 1][P.Pos.y].karakter == '^') ){
					M.T[P.Pos.x][P.Pos.y].karakter = '-';
					M.T[5][3].karakter = 'P';
					M.Map = 1;
					P.Pos.x = 5;
					P.Pos.y = 3;
				}
				//pindah map 3 ke 2
				else if( (M.Map == 3) && (M.T[(P.Pos.x) - 1][P.Pos.y].karakter == '^') ){
					M.T[P.Pos.x][P.Pos.y].karakter = '-';
					M.T[5][10].karakter = 'P';
					M.Map = 2;
					P.Pos.x = 5;
					P.Pos.y = 10;
				}
			}
			else if(IsKataSama(command,d)){
				if(M.T[P.Pos.x][(P.Pos.y)+1].karakter == '-'){ //kalo bukan tembok
					temp = M.T[P.Pos.x][P.Pos.y].karakter;
					M.T[P.Pos.x][P.Pos.y].karakter = M.T[P.Pos.x][(P.Pos.y)+1].karakter;
					P.Pos.y = P.Pos.y + 1;
					M.T[P.Pos.x][P.Pos.y].karakter = temp;
				}
				//pindah map 1 ke 2
				else if( (M.Map == 1) && (M.T[P.Pos.x][(P.Pos.y)+1].karakter == '>') ){
					M.T[P.Pos.x][P.Pos.y].karakter = '-';
					M.T[3][8].karakter = 'P';
					M.Map = 2;
					P.Pos.x = 3;
					P.Pos.y = 8;
				}
				//pindah map 4 ke 3
				else if( (M.Map == 4) && (M.T[P.Pos.x][(P.Pos.y)+1].karakter == '>') ){
					M.T[P.Pos.x][P.Pos.y].karakter = '-';
					M.T[10][8].karakter = 'P';
					M.Map = 3;
					P.Pos.x = 10;
					P.Pos.y = 8;
				}
			}
			else if(IsKataSama(command,s)){
				if(M.T[(P.Pos.x)+1][P.Pos.y].karakter == '-'){ //kalo bukan tembok
					temp = M.T[P.Pos.x][P.Pos.y].karakter;
					M.T[P.Pos.x][P.Pos.y].karakter = M.T[(P.Pos.x) + 1][P.Pos.y].karakter;
					P.Pos.x = P.Pos.x + 1;
					M.T[P.Pos.x][P.Pos.y].karakter = temp;
				}
				//pindah map 1 ke 4
				else if( (M.Map == 1) && (M.T[(P.Pos.x)+1][P.Pos.y].karakter == 'v') ){
					M.T[P.Pos.x][P.Pos.y].karakter = '-';
					M.T[8][3].karakter = 'P';
					M.Map = 4;
					P.Pos.x = 8;
					P.Pos.y = 3;
				}
				//pindah map 2 ke 3
				else if( (M.Map == 2) && (M.T[(P.Pos.x)+1][P.Pos.y].karakter == 'v') ){
					M.T[P.Pos.x][P.Pos.y].karakter = '-';
					M.T[8][10].karakter = 'P';
					M.Map = 3;
					P.Pos.x = 8;
					P.Pos.y = 10;
				}
			}
		}
		
	}
	else if(IsKataSama(command, quit)){
		printf("\n");
		printf("Onii-chan no BAKAAAA!");
	}
	
	return 0;
}
