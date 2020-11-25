#include "map.h"
#include "player.h"

void kiri(MAP *M, PLAYER *P){
	char temp;
	//gerak dalam satu map
	if((*M).T[(*P).Pos.x][((*P).Pos.y) - 1].karakter == '-'){ //kalo bukan tembok
		temp = (*M).T[(*P).Pos.x][(*P).Pos.y].karakter;
		(*M).T[(*P).Pos.x][(*P).Pos.y].karakter = (*M).T[(*P).Pos.x][((*P).Pos.y) - 1].karakter;
		(*P).Pos.y = (*P).Pos.y - 1;
		(*M).T[(*P).Pos.x][(*P).Pos.y].karakter = temp;
	}
	//pindah map 2 ke 1
	else if( ((*M).Map == 2) && ((*M).T[(*P).Pos.x][((*P).Pos.y) - 1].karakter == '<') ){
		(*M).T[(*P).Pos.x][(*P).Pos.y].karakter = '-';
		(*M).T[3][5].karakter = 'P';
		(*M).Map = 1;
		(*P).Pos.x = 3;
		(*P).Pos.y = 5;
	}
	//pindah map 3 ke 4
	else if( ((*M).Map == 3) && ((*M).T[(*P).Pos.x][((*P).Pos.y) - 1].karakter == '<') ){
		(*M).T[(*P).Pos.x][(*P).Pos.y].karakter = '-';
		(*M).T[10][5].karakter = 'P';
		(*M).Map = 4;
		(*P).Pos.x = 10;
		(*P).Pos.y = 5;
	}
}

void atas(MAP *M, PLAYER *P){
	char temp;
	if((*M).T[((*P).Pos.x)-1][(*P).Pos.y].karakter == '-'){ //kalo bukan tembok
		temp = (*M).T[(*P).Pos.x][(*P).Pos.y].karakter;
		(*M).T[(*P).Pos.x][(*P).Pos.y].karakter = (*M).T[((*P).Pos.x) - 1][(*P).Pos.y].karakter;
		(*P).Pos.x = (*P).Pos.x - 1;
		(*M).T[(*P).Pos.x][(*P).Pos.y].karakter = temp;
	}
	//pindah map 4 ke 1
	else if( ((*M).Map == 4) && ((*M).T[((*P).Pos.x) - 1][(*P).Pos.y].karakter == '^') ){
		(*M).T[(*P).Pos.x][(*P).Pos.y].karakter = '-';
		(*M).T[5][3].karakter = 'P';
		(*M).Map = 1;
		(*P).Pos.x = 5;
		(*P).Pos.y = 3;
	}
	//pindah map 3 ke 2
	else if( ((*M).Map == 3) && ((*M).T[((*P).Pos.x) - 1][(*P).Pos.y].karakter == '^') ){
		(*M).T[(*P).Pos.x][(*P).Pos.y].karakter = '-';
		(*M).T[5][10].karakter = 'P';
		(*M).Map = 2;
		(*P).Pos.x = 5;
		(*P).Pos.y = 10;
	}
}

void kanan(MAP *M, PLAYER *P){
	char temp;
	if((*M).T[(*P).Pos.x][((*P).Pos.y)+1].karakter == '-'){ //kalo bukan tembok
		temp = (*M).T[(*P).Pos.x][(*P).Pos.y].karakter;
		(*M).T[(*P).Pos.x][(*P).Pos.y].karakter = (*M).T[(*P).Pos.x][((*P).Pos.y)+1].karakter;
		(*P).Pos.y = (*P).Pos.y + 1;
		(*M).T[(*P).Pos.x][(*P).Pos.y].karakter = temp;
	}
	//pindah map 1 ke 2
	else if( ((*M).Map == 1) && ((*M).T[(*P).Pos.x][((*P).Pos.y)+1].karakter == '>') ){
		(*M).T[(*P).Pos.x][(*P).Pos.y].karakter = '-';
		(*M).T[3][8].karakter = 'P';
		(*M).Map = 2;
		(*P).Pos.x = 3;
		(*P).Pos.y = 8;
	}
	//pindah map 4 ke 3
	else if( ((*M).Map == 4) && ((*M).T[(*P).Pos.x][((*P).Pos.y)+1].karakter == '>') ){
		(*M).T[(*P).Pos.x][(*P).Pos.y].karakter = '-';
		(*M).T[10][8].karakter = 'P';
		(*M).Map = 3;
		(*P).Pos.x = 10;
		(*P).Pos.y = 8;
	}
}

void bawah(MAP *M, PLAYER *P){
	char temp;
	if((*M).T[((*P).Pos.x)+1][(*P).Pos.y].karakter == '-'){ //kalo bukan tembok
		temp = (*M).T[(*P).Pos.x][(*P).Pos.y].karakter;
		(*M).T[(*P).Pos.x][(*P).Pos.y].karakter = (*M).T[((*P).Pos.x) + 1][(*P).Pos.y].karakter;
		(*P).Pos.x = (*P).Pos.x + 1;
		(*M).T[(*P).Pos.x][(*P).Pos.y].karakter = temp;
	}
	//pindah map 1 ke 4
	else if( ((*M).Map == 1) && ((*M).T[((*P).Pos.x)+1][(*P).Pos.y].karakter == 'v') ){
		(*M).T[(*P).Pos.x][(*P).Pos.y].karakter = '-';
		(*M).T[8][3].karakter = 'P';
		(*M).Map = 4;
		(*P).Pos.x = 8;
		(*P).Pos.y = 3;
	}
	//pindah map 2 ke 3
	else if( ((*M).Map == 2) && ((*M).T[((*P).Pos.x)+1][(*P).Pos.y].karakter == 'v') ){
		(*M).T[(*P).Pos.x][(*P).Pos.y].karakter = '-';
		(*M).T[8][10].karakter = 'P';
		(*M).Map = 3;
		(*P).Pos.x = 8;
		(*P).Pos.y = 10;
	}
}
