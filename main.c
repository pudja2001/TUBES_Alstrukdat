//include header bawaan
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//include file header buatan sendiri
#include "player.c"
#include "map.c"
#include "mesinkata.c"
#include "perintah.c"
#include "jam.c"

int main(){
	
	/****************DEKLARASI AWAL****************/
	
	/*************DEKLARASI ONII-CHANNNN**********/
	PLAYER P;
	
	/*************DEKLARASI JAM*******************/
	JAM J;
	J.minutes = 0;
	
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
	//POSISI PEMAIN DAN LAINNYA
	//Pemain
	M.T[3][3].karakter = 'P';
	P.Pos.x = 3;
	P.Pos.y = 3;
	//Terowongan
	M.T[3][6].karakter = '>';
	M.T[6][3].karakter = 'v';
	M.T[3][7].karakter = '<';
	M.T[6][10].karakter = 'v';
	M.T[7][10].karakter = '^';
	M.T[10][7].karakter = '<';
	M.T[10][6].karakter = '>';
	M.T[7][3].karakter = '^';
	//Office dll
	M.T[4][4].karakter = 'O';
	M.T[3][1].karakter = 'G';
	M.T[1][1].karakter = 'A';
	
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
	
	//Command untuk interaksi
	KATA interaksi;
	interaksi.T[0] = 'i';
	interaksi.T[1] = 'n';
	interaksi.T[2] = 't';
	interaksi.T[3] = 'e';
	interaksi.T[4] = 'r';
	interaksi.T[5] = 'a';
	interaksi.T[6] = 'k';
	interaksi.T[7] = 's';
	interaksi.T[8] = 'i';
	interaksi.T[9] = '\n';
	interaksi.length = 9;
	
	//PREPARATION PHASE
	//Command untuk buy
	KATA buy;
	buy.T[0] = 'b';
	buy.T[1] = 'u';
	buy.T[2] = 'y';
	buy.T[3] = '\n';
	buy.length = 3;
	//Command untuk main
	KATA skip;
	skip.T[0] = 's';
	skip.T[1] = 'k';
	skip.T[2] = 'i';
	skip.T[3] = 'p';
	skip.T[4] = '\n';
	skip.length = 4;
	//Command untuk build
	KATA build;
	build.T[0] = 'b';
	build.T[1] = 'u';
	build.T[2] = 'i';
	build.T[3] = 'l';
	build.T[4] = 'd';
	build.T[5] = '\n';
	build.length = 5;
	
	/********BAGIAN UTAMA GAME NON DEKLARASI************/
	system("cls");
	printf("Selamat datang Onii-chan!\n");
	printf("Onii-chan, kita buat area bermain yuk!\n");
	printf("Kawaii imouto ini pengen  maen sama onii-chan <3 \n");
	printf("\n");
	printf("new -> mulai merancang taman bermain imouto\n");
	printf("quit-> quit dan gapeduli karena sukanya sama onee-san\n");
	printf("\n");
	
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
		printf("\n");
		printf("MASUKIN COMMAND YANG BENER ONII-CHAN BAKAAA!\n");
		printf("\n");
		
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
		
			//USER INTERFACE
			
			//PREPARATION PHASE
			
			if(J.minutes < 480){
				system("cls");
				ShowMap(M);
				printf("\n");
				ShowJam(J);
				printf("Preparation Phase\n");
				printf("\n");
				ShowPlayer(P);
				printf("\n");
				printf("Yametteee onii-chan, ini mau ngapain??? >_>\n");
				printf("wasd -> gendong aku onii-chan. Jalan malem-malem begini ga ngehabisis waktu koq\n");
				printf("interaksi -> untuk berinteraksi dengan lingkungan sekitar, biar ga sama aku terus onii-chan :3\n");
				
				printf("buy -> membeli kayu, batu, atau besi xD\n");
				printf("build -> Membangun wahana baru onii-chan xD\n");
				printf("skip -> langsung aja ke Main Phase onii-chan\n");
				
				printf("quit -> sudah karena ada papa-mama!\n");
				printf("\n");
				printf("Ngapain onii-chan, imuoto bakal ngikut ini: ");
				BacaKata(&command);
				printf("\n");
				
				if(IsKataSama(command,a)){
					kiri(&M,&P,&J);
					J.minutes = J.minutes - 5;
					J.total = J.total - 5;
				}
				else if(IsKataSama(command,w)){
					atas(&M, &P,&J);
					J.minutes = J.minutes - 5;
					J.total = J.total - 5;
				}
				else if(IsKataSama(command,d)){
					kanan(&M, &P,&J);
					J.minutes = J.minutes - 5;
					J.total = J.total - 5;
				}
				else if(IsKataSama(command,s)){
					bawah(&M, &P,&J);
					J.minutes = J.minutes - 5;
					J.total = J.total - 5;
				}
				else if(IsKataSama(command,interaksi)){
					interact(M,P,J);
				}
				else if(IsKataSama(command,buy)){
					beli(&P,&J);
				}
				else if(IsKataSama(command,skip)){
					loncat(&J);
				}
				else if(IsKataSama(command,build)){
					bangun(&M,&P,&J);
				}
			}
			
			//MAIN PHASE
			else{ //buka jam 8 pagi
				system("cls");
				ShowMap(M);
				printf("\n");
				ShowJam(J);
				printf("Main Phase\n");
				printf("\n");
				ShowPlayer(P);
				printf("\n");
				printf("Yametteee onii-chan, ini mau ngapain??? >_>\n");
				printf("wasd -> gendong aku onii-chan (Jangan nabrak tembok, buang-buang waktu baka!). Jalan butuh 5 menit onii-chan!\n");
				printf("interaksi -> untuk berinteraksi dengan lingkungan sekitar, biar ga sama aku terus onii-chan :3\n");
				printf("quit -> sudah karena ada papa-mama!\n");
				printf("\n");
				printf("Ngapain onii-chan, imuoto bakal ngikut ini: ");
				BacaKata(&command);
				printf("\n");
				
				if(IsKataSama(command,a)){
					kiri(&M,&P,&J);
				}
				else if(IsKataSama(command,w)){
					atas(&M, &P,&J);
				}
				else if(IsKataSama(command,d)){
					kanan(&M, &P,&J);
				}
				else if(IsKataSama(command,s)){
					bawah(&M, &P,&J);
				}
				else if(IsKataSama(command,interaksi)){
					interact(M,P,J);
				}
			}
		}	
		printf("Oniii-chan, kurang lama ;-;\n");
		
	}
	else if(IsKataSama(command, quit)){
		printf("\n");
		printf("Onii-chan BAKAAAA!");
	}
	
	return 0;
}
