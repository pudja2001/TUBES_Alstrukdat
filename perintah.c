#include "map.h"
#include "player.h"
#include "jam.h"

void kiri(MAP *M, PLAYER *P, JAM *J){
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
	(*J).minutes = ( (*J).minutes + 5)%1440;
	(*J).total = (*J).total + 5;
}

void atas(MAP *M, PLAYER *P, JAM *J){
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
	(*J).minutes = ( (*J).minutes + 5)%1440;
	(*J).total = (*J).total + 5;
}

void kanan(MAP *M, PLAYER *P, JAM *J){
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
	(*J).minutes = ( (*J).minutes + 5)%1440;
	(*J).total = (*J).total + 5;
}

void bawah(MAP *M, PLAYER *P, JAM *J){
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
	(*J).minutes = ( (*J).minutes + 5)%1440;
	(*J).total = (*J).total + 5;
}

void interact(MAP M, PLAYER P, JAM J){
	KATA opsi;
	system("cls");
	ShowMap(M);
	printf("\n");
	ShowJam(J);
	printf("\n");
	ShowPlayer(P);
	printf("\n");
	printf("Interaksi dengan sebelah mana onii-chan?\n");
	printf("wasd juga untuk memilih dan q untuk cancel\n");
	printf("Ayoo cepet pilih: ");
	BacaKata(&opsi);
	
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
	KATA q;
	q.T[0] = 'q';
	q.T[1] = '\n';
	q.length = 1;
	
	while( (IsKataSama(opsi,w)==false) && (IsKataSama(opsi,a)==false) && (IsKataSama(opsi,s)==false) && (IsKataSama(opsi,d)==false) && (IsKataSama(opsi,q)==false) ){
		system("cls");
		ShowMap(M);
		printf("\n");
		ShowJam(J);
		printf("\n");
		ShowPlayer(P);
		printf("\n");
		printf("Interaksi dengan sebelah mana onii-chan?\n");
		printf("wasd juga untuk memilih dan q untuk cancel\n");
		printf("Ayoo cepet pilih: ");
		BacaKata(&opsi);
	}
	if(IsKataSama(opsi,q)){
		//do nothing
	}
	else if(IsKataSama(opsi,w)){
		if(M.T[(P.Pos.x) - 1][P.Pos.y].karakter == '*'){
			printf("Tembok! Jangan ditabrak onii-chan!");
		}
		else if(M.T[(P.Pos.x) - 1][P.Pos.y].karakter == '-'){
			printf("Lahan kosong buat rumah kita onii-chan :3 ");
		}
		else{
			printf("Terowongan yang gelap onii-chan xD");
		}
	}
	else if(IsKataSama(opsi,a)){
		if(M.T[P.Pos.x][(P.Pos.y) - 1].karakter == '*'){
			printf("Tembok! Jangan ditabrak onii-chan!");
		}
		else if(M.T[P.Pos.x][(P.Pos.y) - 1].karakter == '-'){
			printf("Lahan kosong buat rumah kita onii-chan :3 ");
		}
		else{
			printf("Terowongan yang gelap onii-chan xD");
		}
	}
	else if(IsKataSama(opsi,s)){
		if(M.T[(P.Pos.x) + 1][P.Pos.y].karakter == '*'){
			printf("Tembok! Jangan ditabrak onii-chan!");
		}
		else if(M.T[(P.Pos.x) + 1][P.Pos.y].karakter == '-'){
			printf("Lahan kosong buat rumah kita onii-chan :3 ");
		}
		else{
			printf("Terowongan yang gelap onii-chan xD");
		}
	}
	else if(IsKataSama(opsi,d)){
		if(M.T[P.Pos.x][(P.Pos.y) + 1].karakter == '*'){
			printf("Tembok! Jangan ditabrak onii-chan!");
		}
		else if(M.T[P.Pos.x][(P.Pos.y) + 1].karakter == '-'){
			printf("Lahan kosong buat rumah kita onii-chan :3 ");
		}
		else{
			printf("Terowongan yang gelap onii-chan xD");
		}
	}
	printf("\n");
	printf("Tekan enter untuk melanjutkan maen xD");
	BacaKata(&opsi);
}
