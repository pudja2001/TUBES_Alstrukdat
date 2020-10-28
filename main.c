#include <stdio.h>
#include <stdlib.h>
#include <windows.h>





// KUMPULAN ADT YANG DI DEFINISIKAN DI MAIN
typedef struct {
	int x; /* absis   */
	int y; /* ordinat */
} Posisi;

typedef struct{
	char T[14][14];
} Matriks;
# define Elmt(M,x,y) (M).T[x][y] //Selektor Matriks


// PROTOTIPE PROSEDUR
void ShowMap(int m, Matriks M);

// MAIN PROGRAM
int main(){
	
	/*DEKLARASI AWAL PETA*/
	Matriks Map; //kita buat peta.. M adalah T[14][14]
	char gerak; //nanti ini diisi wasd dan q untuk mematikan program
	int i, j, map;
	char temp;
	Posisi p;
	
	
	i = 0;
	j = 0;
	while(i < 14){
		j = 0;
		while(j < 14){
			if( (i == 0) || (i == 6) || (i == 7) || (i == 13)){
				Elmt(Map,i,j) = '*';
			}
			else if( (j == 0) || (j == 6) || (j == 7) || (j == 13) ){
				Elmt(Map,i,j) = '*';
			}
			else{
				Elmt(Map, i, j) = '-';
			}
			j = j + 1;
		}
		i = i + 1;
	}
	
	/*POSISI AWAL PEMAIN DAN TEROWONGAN*/
	Map.T[3][3] = 'P';
	p.x = 3;
	p.y = 3;
	
	Map.T[3][6] = '>';
	Map.T[6][3] = 'v';
	Map.T[3][7] = '<';
	Map.T[6][10] = 'v';
	Map.T[7][10] = '^';
	Map.T[10][7] = '<';
	Map.T[10][6] = '>';
	Map.T[7][3] = '^';
	
	
	
	
	/*PRINT PETA TOTAL*/
	system("cls");
	i = 0;
	j = 0;
	while(i < 14){
		j = 0;
		while(j < 14){
			printf("%c", Elmt(Map,i,j));
			j = j + 1;
		}
		printf("\n");
		i = i + 1;
	}
	
	/*CEK PETA PER BAGIAN (ngakalin graff pake partisi peta xD)*/
	map = 1;
	ShowMap(map, Map);
	printf("\n");
	
	/*PROGRAM UTAMA GAME*/
	printf("Masukkan perintah (gerak wasd, quit q): ");
	scanf("%c", &gerak);
	while( gerak != 'q'){
		if(gerak == 'a'){
			//gerak dalam satu map
			if(Map.T[p.x][(p.y) - 1] == '-'){ //kalo bukan tembok
				temp = Map.T[p.x][p.y];
				Map.T[p.x][p.y] = Map.T[p.x][(p.y) - 1];
				p.y = p.y - 1;
				Map.T[p.x][p.y] = temp;
			}
			//pindah map 2 ke 1
			else if( (map == 2) && (Map.T[p.x][(p.y) - 1] == '<') ){
				Map.T[p.x][p.y] = '-';
				Map.T[3][5] = 'P';
				map = 1;
				p.x = 3;
				p.y = 5;
			}
			//pindah map 3 ke 4
			else if( (map == 3) && (Map.T[p.x][(p.y) - 1] == '<') ){
				Map.T[p.x][p.y] = '-';
				Map.T[10][5] = 'P';
				map = 4;
				p.x = 10;
				p.y = 5;
			}
		}
		else if(gerak == 'w'){
			if(Map.T[(p.x)-1][p.y] == '-'){ //kalo bukan tembok
				temp = Map.T[p.x][p.y];
				Map.T[p.x][p.y] = Map.T[(p.x) - 1][p.y];
				p.x = p.x - 1;
				Map.T[p.x][p.y] = temp;
			}
			//pindah map 4 ke 1
			else if( (map == 4) && (Map.T[(p.x) - 1][p.y] == '^') ){
				Map.T[p.x][p.y] = '-';
				Map.T[5][3] = 'P';
				map = 1;
				p.x = 5;
				p.y = 3;
			}
			//pindah map 3 ke 2
			else if( (map == 3) && (Map.T[(p.x) - 1][p.y] == '^') ){
				Map.T[p.x][p.y] = '-';
				Map.T[5][10] = 'P';
				map = 2;
				p.x = 5;
				p.y = 10;
			}
		}
		else if(gerak == 'd'){
			if(Map.T[p.x][(p.y)+1] == '-'){ //kalo bukan tembok
				temp = Map.T[p.x][p.y];
				Map.T[p.x][p.y] = Map.T[p.x][(p.y)+1];
				p.y = p.y + 1;
				Map.T[p.x][p.y] = temp;
			}
			//pindah map 1 ke 2
			else if( (map == 1) && (Map.T[p.x][(p.y)+1] == '>') ){
				Map.T[p.x][p.y] = '-';
				Map.T[3][8] = 'P';
				map = 2;
				p.x = 3;
				p.y = 8;
			}
			//pindah map 4 ke 3
			else if( (map == 4) && (Map.T[p.x][(p.y)+1] == '>') ){
				Map.T[p.x][p.y] = '-';
				Map.T[10][8] = 'P';
				map = 3;
				p.x = 10;
				p.y = 8;
			}
		}
		else if(gerak == 's'){
			if(Map.T[(p.x)+1][p.y] == '-'){ //kalo bukan tembok
				temp = Map.T[p.x][p.y];
				Map.T[p.x][p.y] = Map.T[(p.x) + 1][p.y];
				p.x = p.x + 1;
				Map.T[p.x][p.y] = temp;
			}
			//pindah map 1 ke 4
			else if( (map == 1) && (Map.T[(p.x)+1][p.y] == 'v') ){
				Map.T[p.x][p.y] = '-';
				Map.T[8][3] = 'P';
				map = 4;
				p.x = 8;
				p.y = 3;
			}
			//pindah map 2 ke 3
			else if( (map == 2) && (Map.T[(p.x)+1][p.y] == 'v') ){
				Map.T[p.x][p.y] = '-';
				Map.T[8][10] = 'P';
				map = 3;
				p.x = 8;
				p.y = 10;
			}
		}
		else{ // kalo bukan semua command ga ngapain-ngapain.. Nanti ini diisi sama command lain pake ADT Mesin Karakter & Mesin Kata
		}
		
		
		system("cls");
		ShowMap(map, Map);
		printf("\n");
		printf("Masukkan perintah (gerak wasd, quit q): ");
		scanf("%c", &gerak);
	}
	printf("Arigatou, oniii-chan");
	return 0;
}



//IMPLEMENTASI FUNGSI DAN PROSEDUR


void ShowMap(int m, Matriks M){
	system("cls");
	int i, j;
	if(m == 1){
		i = 0;
		j = 0;
		while(i < 7){
			j = 0;
			while(j < 7){
				printf("%c", Elmt(M,i,j));
				j = j + 1;
			}
			printf("\n");
			i = i + 1;
		}
	}
	else if(m == 2){
		i = 0;
		j = 7;
		while(i < 7){
			j = 7;
			while(j < 14){
				printf("%c", Elmt(M,i,j));
				j = j + 1;
			}
			printf("\n");
			i = i + 1;
		}
	}
	else if(m == 3){
		i = 7;
		j = 7;
		while(i < 14){
			j = 7;
			while(j < 14){
				printf("%c", Elmt(M,i,j));
				j = j + 1;
			}
			printf("\n");
			i = i + 1;
		}
	}
	else if(m == 4){
		i = 7;
		j = 0;
		while(i < 14){
			j = 0;
			while(j < 7){
				printf("%c", Elmt(M,i,j));
				j = j + 1;
			}
			printf("\n");
			i = i + 1;
		}
	}
}
