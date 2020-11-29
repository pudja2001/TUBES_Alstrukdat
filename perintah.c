#include "map.h"
#include "player.h"
#include "jam.h"
#include <windows.h>
#include <time.h>


//FUNGSI YANG BERLAKU DI SEMUA PHASE
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
		else if(M.T[(P.Pos.x) - 1][P.Pos.y].karakter == 'O'){
			printf("Office");
		}
		else if(M.T[(P.Pos.x) - 1][P.Pos.y].karakter == 'G'){
			printf("Gudang");
		}
		else if(M.T[(P.Pos.x) - 1][P.Pos.y].karakter == 'A'){
			printf("Antrian");
		}
		else if(M.T[(P.Pos.x) - 1][P.Pos.y].karakter == 'B'){
			printf("Bioskop Same Day As Japan");
		}
		else if(M.T[(P.Pos.x) - 1][P.Pos.y].karakter == 'M'){
			printf("Maid Cafe");
		}
		else if(M.T[(P.Pos.x) - 1][P.Pos.y].karakter == 'C'){
			printf("Cosplay Spot");
		}
		else if(M.T[(P.Pos.x) - 1][P.Pos.y].karakter == 'S'){
			printf("Weebs Store");
		}
		else if(M.T[(P.Pos.x) - 1][P.Pos.y].karakter == 'L'){
			printf("Love Arcade");
		}
		else if(M.T[(P.Pos.x) - 1][P.Pos.y].karakter == 'H'){
			printf("Host Club");
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
		else if(M.T[(P.Pos.x) ][(P.Pos.y) - 1].karakter == 'O'){
			printf("Office");
		}
		else if(M.T[(P.Pos.x)][(P.Pos.y) - 1].karakter == 'G'){
			printf("Gudang");
		}
		else if(M.T[(P.Pos.x)][(P.Pos.y)-1].karakter == 'A'){
			printf("Antrian");
		}
		else if(M.T[(P.Pos.x)][(P.Pos.y)-1].karakter == 'B'){
			printf("Bioskop Same Day As Japan");
		}
		else if(M.T[(P.Pos.x) ][(P.Pos.y)-1].karakter == 'M'){
			printf("Maid Cafe");
		}
		else if(M.T[(P.Pos.x)][(P.Pos.y)-1].karakter == 'C'){
			printf("Cosplay Spot");
		}
		else if(M.T[(P.Pos.x) ][(P.Pos.y)-1].karakter == 'S'){
			printf("Weebs Store");
		}
		else if(M.T[(P.Pos.x) ][(P.Pos.y)-1].karakter == 'L'){
			printf("Love Arcade");
		}
		else if(M.T[(P.Pos.x) ][(P.Pos.y)-1].karakter == 'H'){
			printf("Host Club");
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
		else if(M.T[(P.Pos.x) + 1][P.Pos.y].karakter == 'O'){
			printf("Office");
		}
		else if(M.T[(P.Pos.x) + 1][P.Pos.y].karakter == 'G'){
			printf("Gudang");
		}
		else if(M.T[(P.Pos.x) + 1][P.Pos.y].karakter == 'A'){
			printf("Antrian");
		}
		else if(M.T[(P.Pos.x) + 1][P.Pos.y].karakter == 'B'){
			printf("Bioskop Same Day As Japan");
		}
		else if(M.T[(P.Pos.x) + 1][P.Pos.y].karakter == 'M'){
			printf("Maid Cafe");
		}
		else if(M.T[(P.Pos.x) + 1][P.Pos.y].karakter == 'C'){
			printf("Cosplay Spot");
		}
		else if(M.T[(P.Pos.x) + 1][P.Pos.y].karakter == 'S'){
			printf("Weebs Store");
		}
		else if(M.T[(P.Pos.x) + 1][P.Pos.y].karakter == 'L'){
			printf("Love Arcade");
		}
		else if(M.T[(P.Pos.x) + 1][P.Pos.y].karakter == 'H'){
			printf("Host Club");
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
		else if(M.T[(P.Pos.x) ][(P.Pos.y) + 1].karakter == 'O'){
			printf("Office");
		}
		else if(M.T[(P.Pos.x)][(P.Pos.y) + 1].karakter == 'G'){
			printf("Gudang");
		}
		else if(M.T[(P.Pos.x)][(P.Pos.y) + 1].karakter == 'A'){
			printf("Antrian");
		}
		else if(M.T[(P.Pos.x)][(P.Pos.y)+1].karakter == 'B'){
			printf("Bioskop Same Day As Japan");
		}
		else if(M.T[(P.Pos.x) ][(P.Pos.y)+1].karakter == 'M'){
			printf("Maid Cafe");
		}
		else if(M.T[(P.Pos.x)][(P.Pos.y)+1].karakter == 'C'){
			printf("Cosplay Spot");
		}
		else if(M.T[(P.Pos.x) ][(P.Pos.y)+1].karakter == 'S'){
			printf("Weebs Store");
		}
		else if(M.T[(P.Pos.x) ][(P.Pos.y)+1].karakter == 'L'){
			printf("Love Arcade");
		}
		else if(M.T[(P.Pos.x) ][(P.Pos.y)+1].karakter == 'H'){
			printf("Host Club");
		}
		else{
			printf("Terowongan yang gelap onii-chan xD");
		}
	}
	printf("\n");
	printf("Tekan enter untuk melanjutkan maen xD");
	BacaKata(&opsi);
}

//FUNGSI YANG BERLAKU DI PREPARATION PHASE ONLY
void beli(PLAYER *P, JAM *J){
	char opsi;
	KATA huhuhu;
	int jumlah;
	if( (*J).minutes < 450){
		system("cls");
		printf("Uang: %d\n", (*P).Det.uang);
		printf("1 -> Beli kayu. 1 kayu = 1 uang\n");
		printf("2 -> Beli batu. 1 batu = 5 uang\n");
		printf("3 -> Beli besi. 1 besi = 10 uang\n");
		printf("Masukkan yang mau dibeli (1/2/3): ");
		scanf("%c", &opsi);
		while( (opsi != '1') && (opsi != '2') && (opsi != '3') ){
			system("cls");
			printf("Uang: %d\n", (*P).Det.uang);
			printf("1 -> Beli kayu. 1 kayu = 1 uang\n");
			printf("2 -> Beli batu. 1 batu = 5 uang\n");
			printf("3 -> Beli besi. 1 besi = 10 uang\n");
			printf("MASUKKAN YANG BENER ONII-CHAN\n");
			printf("Masukkan yang mau dibeli (1/2/3): ");
			scanf("%c",&opsi);
		}
		if( opsi == '1'){
			system("cls");
			printf("Uang: %d\n", (*P).Det.uang);
			printf("Berapa kayu yang mau dibeli (0 - %d): \n", (int)((*P).Det.uang));
			printf("Kayu: %d\n", (*P).Det.kayu);
			scanf("%d", &jumlah);
			while( (jumlah < 0) || (jumlah > (int)((*P).Det.uang)) ){
				system("cls");
				printf("Masukkan jumlah yang valid\n");
				printf("Uang: %d\n", (*P).Det.uang);
				printf("Berapa kayu yang mau dibeli (0 - %d): \n", (int)((*P).Det.uang));
				scanf("%d", &jumlah);
			}
			(*P).Det.uang = (*P).Det.uang - jumlah;
			(*P).Det.kayu = (*P).Det.kayu + jumlah;
		}
		if( opsi == '2'){
			system("cls");
			printf("Uang: %d\n", (*P).Det.uang);
			printf("Batu: %d\n", (*P).Det.batu);
			printf("Berapa batu yang mau dibeli (0 - %d): \n", (int)((*P).Det.uang/5));
			scanf("%d", &jumlah);
			while( (jumlah < 0) || (jumlah > (int)((*P).Det.uang/5)) ){
				system("cls");
				printf("Masukkan jumlah yang valid\n");
				printf("Uang: %d\n", (*P).Det.uang);
				printf("Berapa batu yang mau dibeli (0 - %d): \n", (int)((*P).Det.uang/5));
				scanf("%d", &jumlah);
			}
			(*P).Det.uang = (*P).Det.uang - (jumlah*5);
			(*P).Det.batu = (*P).Det.batu + jumlah;
		}
		if( opsi == '3'){
			system("cls");
			printf("Uang: %d\n", (*P).Det.uang);
			printf("Besi: %d\n", (*P).Det.besi);
			printf("Berapa besi yang mau dibeli (0 - %d): \n", (int)((*P).Det.uang/10));
			scanf("%d", &jumlah);
			while( (jumlah < 0) || (jumlah > (int)((*P).Det.uang/10)) ){
				system("cls");
				printf("Masukkan jumlah yang valid\n");
				printf("Uang: %d\n", (*P).Det.uang);
				printf("Berapa kayu yang mau dibeli (0 - %d): \n", (int)((*P).Det.uang/10));
				scanf("%d", &jumlah);
			}
			(*P).Det.uang = (*P).Det.uang - (jumlah*10);
			(*P).Det.besi = (*P).Det.besi + jumlah;
		}
		(*J).minutes = (*J).minutes + 30;
		(*J).total = (*J).total + 30;
	}
	else if (  ((*J).minutes >= 450) && ((*J).minutes < 480) ){
		printf("Waktu tidak cukup onii-chan, keburu buka :p\n");
		printf("\n");
		printf("Tekan enter untuk melanjutkan maen xD");
		BacaKata(&huhuhu);
	}
	else{
		printf("Bukan fasenya :p\n");
		printf("\n");
		printf("Tekan enter untuk melanjutkan maen xD");
		BacaKata(&huhuhu);
	}
	
	
}

void loncat(JAM *J){
	(*J).total = (*J).total + (480 - (*J).minutes);
	(*J).minutes = 480;
}

void bangun(MAP *M, PLAYER *P, JAM *J){
	char opsi;
	char bangunan;
	KATA huhuhu;
	
	int i, j;
	i = (*P).Pos.x;
	j = (*P).Pos.y;
	
	//CEK WAKTU
	if ( (*J).minutes < 180 ){
		//CEK APAKAH ADA TEMPAT UNTUK MEMBANGUN
		if ( ((*M).T[i+1][j].karakter == '-') || ((*M).T[i-1][j].karakter == '-') || ((*M).T[i][j+1].karakter == '-') || ((*M).T[i][j-1].karakter == '-')){
			//ADA TEMPAT UNTUK MEMBANGUN
			system("cls");
			printf("Mode membangun\n");
			//MEMILIH BANGUNAN
			printf("Memilih wahana yang ingin dibangung\n");
			printf("Harta Onii-chan\n");
			printf("Kayu: %d | Batu: %d | Besi: %d\n",(*P).Det.kayu,(*P).Det.batu,(*P).Det.besi);
			//PILIHAN WAHANA
			printf("\n");
			printf("B -> Bioskop Same Day As Japan\n");
			printf("Kayu: 2000 | Batu: 400 | Besi: 100\n");
			printf("Durasi: 90 | Harga: 50 | Kapasitas: 1\n");
			
			printf("\n");
			printf("M -> Maid Cafe\n");
			printf("Kayu: 500 | Batu: 100 | Besi: 150\n");
			printf("Durasi: 60 | Harga: 25 | Kapasitas: 1\n");
			
			printf("\n");
			printf("C -> Cosplay Spot\n");
			printf("Kayu: 150 | Batu: 100 | Besi: 35\n");
			printf("Durasi: 60 | Harga: 10 | Kapasitas: 1\n");
			
			printf("\n");
			printf("S-> Weebs Store\n");
			printf("Kayu: 50 | Batu: 80 | Besi: 5\n");
			printf("Durasi: 120 | Harga: 5 | Kapasitas: 1\n");
			
			printf("\n");
			printf("L -> Love Arcade\n");
			printf("Kayu: 200 | Batu: 10 | Besi: 55\n");
			printf("Durasi: 30 | Harga: 8 | Kapasitas: 1\n");
			
			printf("\n");
			printf("H -> Host Club\n");
			printf("Kayu: 100 | Batu: 100 | Besi: 20\n");
			printf("Durasi: 30 | Harga: 8 | Kapasitas: 1\n");
			printf("\n");
			
			printf("Pilih wahana (B,M,C,S,L,H), Q untuk cancel: ");
			scanf("%c", &bangunan);
			while ( (bangunan != 'B') && (bangunan != 'M') && (bangunan != 'C') && (bangunan != 'S') && (bangunan != 'L') && (bangunan != 'H') && (bangunan != 'Q')){
				system("cls");
				printf("Mode membangun\n");
				//MEMILIH BANGUNAN
				printf("Memilih wahana yang ingin dibangung\n");
				printf("Harta Onii-chan\n");
				printf("Kayu: %d | Batu: %d | Besi: %d\n",(*P).Det.kayu,(*P).Det.batu,(*P).Det.besi);
				//PILIHAN WAHANA
				printf("\n");
				printf("B -> Bioskop Same Day As Japan\n");
				printf("Kayu: 2000 | Batu: 400 | Besi: 100\n");
				printf("Durasi: 90 | Harga: 50 | Kapasitas: 1\n");
				
				printf("\n");
				printf("M -> Maid Cafe\n");
				printf("Kayu: 500 | Batu: 100 | Besi: 150\n");
				printf("Durasi: 60 | Harga: 25 | Kapasitas: 1\n");
				
				printf("\n");
				printf("C -> Cosplay Spot\n");
				printf("Kayu: 150 | Batu: 100 | Besi: 35\n");
				printf("Durasi: 60 | Harga: 10 | Kapasitas: 1\n");
				
				printf("\n");
				printf("S-> Weebs Store\n");
				printf("Kayu: 50 | Batu: 80 | Besi: 5\n");
				printf("Durasi: 120 | Harga: 5 | Kapasitas: 1\n");
				
				printf("\n");
				printf("L -> Love Arcade\n");
				printf("Kayu: 200 | Batu: 10 | Besi: 55\n");
				printf("Durasi: 30 | Harga: 8 | Kapasitas: 1\n");
			
				printf("\n");
				printf("H -> Host Club\n");
				printf("Kayu: 100 | Batu: 100 | Besi: 20\n");
				printf("Durasi: 30 | Harga: 8 | Kapasitas: 1\n");
				printf("\n");
				
				printf("Masukkan dengan bener onii-chan >_<\n");
				printf("Pilih wahana (B,M,C,S,L,H) dan Q untuk batal membangun: ");
				scanf("%c", &bangunan);
			}
			
			//cek apakah materialnya mampu
			if (bangunan == 'B'){
				if ( ( (*P).Det.kayu >= 2000) && ( (*P).Det.batu >= 400) && ( (*P).Det.besi >= 100) ){
					//Mampu membangun
					system("cls");
					ShowMap(*M);
					printf("Hati-hati, salah tempat mengakibatkan pembangunan gagal onii-chan\n");
					printf("Membangun di sisi mana (w,a,s,d) dan q untuk batal: ");
					scanf("%c", &opsi);
					while (  (opsi != 'w') && (opsi != 'a') && (opsi != 's') && (opsi != 'd') && (opsi != 'q')){
						system("cls");
						ShowMap(*M);
						printf("Pilih posisi yang tepat onii-chan :3\n");
						printf("Membangun di sisi mana (w,a,s,d) dan q untuk batal: ");
						scanf("%c", &opsi);
					}
					
					if ( opsi == 'w' && (*M).T[(*P).Pos.x - 1][(*P).Pos.y].karakter == '-'){
						//DIBANGUN
						(*M).T[(*P).Pos.x - 1][(*P).Pos.y].karakter = 'B';
						(*M).T[(*P).Pos.x - 1][(*P).Pos.y].D.level = 1;
						(*M).T[(*P).Pos.x - 1][(*P).Pos.y].D.durasi = 90;
						(*M).T[(*P).Pos.x - 1][(*P).Pos.y].D.harga = (*M).T[(*P).Pos.x - 1][(*P).Pos.y].D.level * 50;
						(*M).T[(*P).Pos.x - 1][(*P).Pos.y].D.kapasitas = (*M).T[(*P).Pos.x - 1][(*P).Pos.y].D.level;
						//material berkuarng
						(*P).Det.kayu = (*P).Det.kayu - 2000;
						(*P).Det.batu = (*P).Det.batu - 400;
						(*P).Det.besi = (*P).Det.besi - 100;
						(*J).minutes = (*J).minutes + 300;
						(*J).total = (*J).total + 300;
					}
					if ( opsi == 'a' && (*M).T[(*P).Pos.x][(*P).Pos.y - 1].karakter == '-'){
						//DIBANGUN
						(*M).T[(*P).Pos.x][(*P).Pos.y - 1].karakter = 'B';
						(*M).T[(*P).Pos.x][(*P).Pos.y - 1].D.level = 1;
						(*M).T[(*P).Pos.x][(*P).Pos.y - 1].D.durasi = 90;
						(*M).T[(*P).Pos.x][(*P).Pos.y - 1].D.harga = (*M).T[(*P).Pos.x][(*P).Pos.y - 1].D.level * 50;
						(*M).T[(*P).Pos.x][(*P).Pos.y - 1].D.kapasitas = (*M).T[(*P).Pos.x][(*P).Pos.y - 1].D.level;
						//material berkuarng
						(*P).Det.kayu = (*P).Det.kayu - 2000;
						(*P).Det.batu = (*P).Det.batu - 400;
						(*P).Det.besi = (*P).Det.besi - 100;
						(*J).minutes = (*J).minutes + 300;
						(*J).total = (*J).total + 300;
					}
					if ( opsi == 's' && (*M).T[(*P).Pos.x + 1][(*P).Pos.y].karakter == '-'){
						//DIBANGUN
						(*M).T[(*P).Pos.x + 1][(*P).Pos.y].karakter = 'B';
						(*M).T[(*P).Pos.x + 1][(*P).Pos.y].D.level = 1;
						(*M).T[(*P).Pos.x + 1][(*P).Pos.y].D.durasi = 90;
						(*M).T[(*P).Pos.x + 1][(*P).Pos.y].D.harga = (*M).T[(*P).Pos.x + 1][(*P).Pos.y].D.level * 50;
						(*M).T[(*P).Pos.x + 1][(*P).Pos.y].D.kapasitas = (*M).T[(*P).Pos.x + 1][(*P).Pos.y].D.level;
						//material berkuarng
						(*P).Det.kayu = (*P).Det.kayu - 2000;
						(*P).Det.batu = (*P).Det.batu - 400;
						(*P).Det.besi = (*P).Det.besi - 100;
						(*J).minutes = (*J).minutes + 300;
						(*J).total = (*J).total + 300;
					}
					if ( opsi == 'd' && (*M).T[(*P).Pos.x][(*P).Pos.y + 1].karakter == '-'){
						//DIBANGUN
						(*M).T[(*P).Pos.x][(*P).Pos.y + 1].karakter = 'B';
						(*M).T[(*P).Pos.x][(*P).Pos.y + 1].D.level = 1;
						(*M).T[(*P).Pos.x][(*P).Pos.y + 1].D.durasi = 90;
						(*M).T[(*P).Pos.x][(*P).Pos.y + 1].D.harga = (*M).T[(*P).Pos.x][(*P).Pos.y + 1].D.level * 50;
						(*M).T[(*P).Pos.x][(*P).Pos.y + 1].D.kapasitas = (*M).T[(*P).Pos.x][(*P).Pos.y + 1].D.level;
						//material berkuarng
						(*P).Det.kayu = (*P).Det.kayu - 2000;
						(*P).Det.batu = (*P).Det.batu - 400;
						(*P).Det.besi = (*P).Det.besi - 100;
						(*J).minutes = (*J).minutes + 300;
						(*J).total = (*J).total + 300;
					}
				}
				else{
					scanf("%c", &bangunan);
					printf("\n");
					printf("Kurang bahan onii-chan :( \n");
					printf("Tekan enter untuk melanjutkan maen xD");
				}
			}
			else if(bangunan == 'M'){
				if ( ( (*P).Det.kayu >= 500) && ( (*P).Det.batu >= 100 ) && ( (*P).Det.besi >= 150) ){
					//Mampu membangun
					system("cls");
					ShowMap(*M);
					printf("Hati-hati, salah tempat mengakibatkan pembangunan gagal onii-chan\n");
					printf("Membangun di sisi mana (w,a,s,d) dan q untuk batal: ");
					scanf("%c", &opsi);
					while (  (opsi != 'w') && (opsi != 'a') && (opsi != 's') && (opsi != 'd') && (opsi != 'q')){
						system("cls");
						ShowMap(*M);
						printf("Pilih posisi yang tepat onii-chan :3\n");
						printf("Membangun di sisi mana (w,a,s,d) dan q untuk batal: ");
						scanf("%c", &opsi);
					}
					
					if ( opsi == 'w' && (*M).T[(*P).Pos.x - 1][(*P).Pos.y].karakter == '-'){
						//DIBANGUN
						(*M).T[(*P).Pos.x - 1][(*P).Pos.y].karakter = 'M';
						(*M).T[(*P).Pos.x - 1][(*P).Pos.y].D.level = 1;
						(*M).T[(*P).Pos.x - 1][(*P).Pos.y].D.durasi = 60;
						(*M).T[(*P).Pos.x - 1][(*P).Pos.y].D.harga = (*M).T[(*P).Pos.x - 1][(*P).Pos.y].D.level * 25;
						(*M).T[(*P).Pos.x - 1][(*P).Pos.y].D.kapasitas = (*M).T[(*P).Pos.x - 1][(*P).Pos.y].D.level;
						//material berkuarng
						(*P).Det.kayu = (*P).Det.kayu - 500;
						(*P).Det.batu = (*P).Det.batu - 100;
						(*P).Det.besi = (*P).Det.besi - 150;
						(*J).minutes = (*J).minutes + 300;
						(*J).total = (*J).total + 300;
					}
					if ( opsi == 'a' && (*M).T[(*P).Pos.x][(*P).Pos.y - 1].karakter == '-'){
						//DIBANGUN
						(*M).T[(*P).Pos.x][(*P).Pos.y - 1].karakter = 'M';
						(*M).T[(*P).Pos.x][(*P).Pos.y - 1].D.level = 1;
						(*M).T[(*P).Pos.x][(*P).Pos.y - 1].D.durasi = 60;
						(*M).T[(*P).Pos.x][(*P).Pos.y - 1].D.harga = (*M).T[(*P).Pos.x][(*P).Pos.y - 1].D.level * 25;
						(*M).T[(*P).Pos.x][(*P).Pos.y - 1].D.kapasitas = (*M).T[(*P).Pos.x][(*P).Pos.y - 1].D.level;
						//material berkuarng
						(*P).Det.kayu = (*P).Det.kayu - 500;
						(*P).Det.batu = (*P).Det.batu - 100;
						(*P).Det.besi = (*P).Det.besi - 150;
						(*J).minutes = (*J).minutes + 300;
						(*J).total = (*J).total + 300;
					}
					if ( opsi == 's' && (*M).T[(*P).Pos.x + 1][(*P).Pos.y].karakter == '-'){
						//DIBANGUN
						(*M).T[(*P).Pos.x + 1][(*P).Pos.y].karakter = 'M';
						(*M).T[(*P).Pos.x + 1][(*P).Pos.y].D.level = 1;
						(*M).T[(*P).Pos.x + 1][(*P).Pos.y].D.durasi = 60;
						(*M).T[(*P).Pos.x + 1][(*P).Pos.y].D.harga = (*M).T[(*P).Pos.x + 1][(*P).Pos.y].D.level * 25;
						(*M).T[(*P).Pos.x + 1][(*P).Pos.y].D.kapasitas = (*M).T[(*P).Pos.x + 1][(*P).Pos.y].D.level;
						//material berkuarng
						(*P).Det.kayu = (*P).Det.kayu - 500;
						(*P).Det.batu = (*P).Det.batu - 100;
						(*P).Det.besi = (*P).Det.besi - 150;
						(*J).minutes = (*J).minutes + 300;
						(*J).total = (*J).total + 300;
					}
					if ( opsi == 'd' && (*M).T[(*P).Pos.x][(*P).Pos.y + 1].karakter == '-'){
						//DIBANGUN
						(*M).T[(*P).Pos.x][(*P).Pos.y + 1].karakter = 'M';
						(*M).T[(*P).Pos.x][(*P).Pos.y + 1].D.level = 1;
						(*M).T[(*P).Pos.x][(*P).Pos.y + 1].D.durasi = 60;
						(*M).T[(*P).Pos.x][(*P).Pos.y + 1].D.harga = (*M).T[(*P).Pos.x][(*P).Pos.y + 1].D.level * 25;
						(*M).T[(*P).Pos.x][(*P).Pos.y + 1].D.kapasitas = (*M).T[(*P).Pos.x][(*P).Pos.y + 1].D.level;
						//material berkuarng
						(*P).Det.kayu = (*P).Det.kayu - 500;
						(*P).Det.batu = (*P).Det.batu - 100;
						(*P).Det.besi = (*P).Det.besi - 150;
						(*J).minutes = (*J).minutes + 300;
						(*J).total = (*J).total + 300;
					}
				}
				else{
					scanf("%c", &bangunan);
					printf("\n");
					printf("Kurang bahan onii-chan :( \n");
					printf("Tekan enter untuk melanjutkan maen xD");
				}
				
			}
			else if(bangunan == 'C'){
				if ( ( (*P).Det.kayu >= 150) && ( (*P).Det.batu >= 100) && ( (*P).Det.besi >= 35) ){
					//Mampu membangun
					system("cls");
					ShowMap(*M);
					printf("Hati-hati, salah tempat mengakibatkan pembangunan gagal onii-chan\n");
					printf("Membangun di sisi mana (w,a,s,d) dan q untuk batal: ");
					scanf("%c", &opsi);
					while (  (opsi != 'w') && (opsi != 'a') && (opsi != 's') && (opsi != 'd') && (opsi != 'q')){
						system("cls");
						ShowMap(*M);
						printf("Pilih posisi yang tepat onii-chan :3\n");
						printf("Membangun di sisi mana (w,a,s,d) dan q untuk batal: ");
						scanf("%c", &opsi);
					}
					
					if ( opsi == 'w' && (*M).T[(*P).Pos.x - 1][(*P).Pos.y].karakter == '-'){
						//DIBANGUN
						(*M).T[(*P).Pos.x - 1][(*P).Pos.y].karakter = 'C';
						(*M).T[(*P).Pos.x - 1][(*P).Pos.y].D.level = 1;
						(*M).T[(*P).Pos.x - 1][(*P).Pos.y].D.durasi = 60;
						(*M).T[(*P).Pos.x - 1][(*P).Pos.y].D.harga = (*M).T[(*P).Pos.x - 1][(*P).Pos.y].D.level * 10;
						(*M).T[(*P).Pos.x - 1][(*P).Pos.y].D.kapasitas = (*M).T[(*P).Pos.x - 1][(*P).Pos.y].D.level;
						//material berkuarng
						(*P).Det.kayu = (*P).Det.kayu - 150;
						(*P).Det.batu = (*P).Det.batu - 100;
						(*P).Det.besi = (*P).Det.besi - 35;
						(*J).minutes = (*J).minutes + 300;
						(*J).total = (*J).total + 300;
					}
					if ( opsi == 'a' && (*M).T[(*P).Pos.x][(*P).Pos.y - 1].karakter == '-'){
						//DIBANGUN
						(*M).T[(*P).Pos.x][(*P).Pos.y - 1].karakter = 'C';
						(*M).T[(*P).Pos.x][(*P).Pos.y - 1].D.level = 1;
						(*M).T[(*P).Pos.x][(*P).Pos.y - 1].D.durasi = 60;
						(*M).T[(*P).Pos.x][(*P).Pos.y - 1].D.harga = (*M).T[(*P).Pos.x][(*P).Pos.y - 1].D.level * 10;
						(*M).T[(*P).Pos.x][(*P).Pos.y - 1].D.kapasitas = (*M).T[(*P).Pos.x][(*P).Pos.y - 1].D.level;
						//material berkuarng
						(*P).Det.kayu = (*P).Det.kayu - 150;
						(*P).Det.batu = (*P).Det.batu - 100;
						(*P).Det.besi = (*P).Det.besi - 35;
						(*J).minutes = (*J).minutes + 300;
						(*J).total = (*J).total + 300;
					}
					if ( opsi == 's' && (*M).T[(*P).Pos.x + 1][(*P).Pos.y].karakter == '-'){
						//DIBANGUN
						(*M).T[(*P).Pos.x + 1][(*P).Pos.y].karakter = 'C';
						(*M).T[(*P).Pos.x + 1][(*P).Pos.y].D.level = 1;
						(*M).T[(*P).Pos.x + 1][(*P).Pos.y].D.durasi = 60;
						(*M).T[(*P).Pos.x + 1][(*P).Pos.y].D.harga = (*M).T[(*P).Pos.x + 1][(*P).Pos.y].D.level * 10;
						(*M).T[(*P).Pos.x + 1][(*P).Pos.y].D.kapasitas = (*M).T[(*P).Pos.x + 1][(*P).Pos.y].D.level;
						//material berkuarng
						(*P).Det.kayu = (*P).Det.kayu - 150;
						(*P).Det.batu = (*P).Det.batu - 100;
						(*P).Det.besi = (*P).Det.besi - 35;
						(*J).minutes = (*J).minutes + 300;
						(*J).total = (*J).total + 300;
					}
					if ( opsi == 'd' && (*M).T[(*P).Pos.x][(*P).Pos.y + 1].karakter == '-'){
						//DIBANGUN
						(*M).T[(*P).Pos.x][(*P).Pos.y + 1].karakter = 'C';
						(*M).T[(*P).Pos.x][(*P).Pos.y + 1].D.level = 1;
						(*M).T[(*P).Pos.x][(*P).Pos.y + 1].D.durasi = 60;
						(*M).T[(*P).Pos.x][(*P).Pos.y + 1].D.harga = (*M).T[(*P).Pos.x][(*P).Pos.y + 1].D.level * 10;
						(*M).T[(*P).Pos.x][(*P).Pos.y + 1].D.kapasitas = (*M).T[(*P).Pos.x][(*P).Pos.y + 1].D.level;
						//material berkuarng
						(*P).Det.kayu = (*P).Det.kayu - 150;
						(*P).Det.batu = (*P).Det.batu - 100;
						(*P).Det.besi = (*P).Det.besi - 35;
						(*J).minutes = (*J).minutes + 300;
						(*J).total = (*J).total + 300;
					}
				}
				else{
					scanf("%c", &bangunan);
					printf("\n");
					printf("Kurang bahan onii-chan :( \n");
					printf("Tekan enter untuk melanjutkan maen xD");
				}
			}
			else if(bangunan == 'S'){
				if ( ( (*P).Det.kayu >= 50 ) && ( (*P).Det.batu >= 80 ) && ( (*P).Det.besi >= 5) ){
					//Mampu membangun
					system("cls");
					ShowMap(*M);
					printf("Hati-hati, salah tempat mengakibatkan pembangunan gagal onii-chan\n");
					printf("Membangun di sisi mana (w,a,s,d) dan q untuk batal: ");
					scanf("%c", &opsi);
					while (  (opsi != 'w') && (opsi != 'a') && (opsi != 's') && (opsi != 'd') && (opsi != 'q')){
						system("cls");
						ShowMap(*M);
						printf("Pilih posisi yang tepat onii-chan :3\n");
						printf("Membangun di sisi mana (w,a,s,d) dan q untuk batal: ");
						scanf("%c", &opsi);
					}
					
					if ( opsi == 'w' && (*M).T[(*P).Pos.x - 1][(*P).Pos.y].karakter == '-'){
						//DIBANGUN
						(*M).T[(*P).Pos.x - 1][(*P).Pos.y].karakter = 'S';
						(*M).T[(*P).Pos.x - 1][(*P).Pos.y].D.level = 1;
						(*M).T[(*P).Pos.x - 1][(*P).Pos.y].D.durasi = 120;
						(*M).T[(*P).Pos.x - 1][(*P).Pos.y].D.harga = (*M).T[(*P).Pos.x - 1][(*P).Pos.y].D.level * 5;
						(*M).T[(*P).Pos.x - 1][(*P).Pos.y].D.kapasitas = (*M).T[(*P).Pos.x - 1][(*P).Pos.y].D.level;
						//material berkuarng
						(*P).Det.kayu = (*P).Det.kayu - 50;
						(*P).Det.batu = (*P).Det.batu - 80;
						(*P).Det.besi = (*P).Det.besi - 5;
						(*J).minutes = (*J).minutes + 300;
						(*J).total = (*J).total + 300;
					}
					if ( opsi == 'a' && (*M).T[(*P).Pos.x][(*P).Pos.y - 1].karakter == '-'){
						//DIBANGUN
						(*M).T[(*P).Pos.x][(*P).Pos.y - 1].karakter = 'S';
						(*M).T[(*P).Pos.x][(*P).Pos.y - 1].D.level = 1;
						(*M).T[(*P).Pos.x][(*P).Pos.y - 1].D.durasi = 120;
						(*M).T[(*P).Pos.x][(*P).Pos.y - 1].D.harga = (*M).T[(*P).Pos.x][(*P).Pos.y - 1].D.level * 5;
						(*M).T[(*P).Pos.x][(*P).Pos.y - 1].D.kapasitas = (*M).T[(*P).Pos.x][(*P).Pos.y - 1].D.level;
						//material berkuarng
						(*P).Det.kayu = (*P).Det.kayu - 50;
						(*P).Det.batu = (*P).Det.batu - 80;
						(*P).Det.besi = (*P).Det.besi - 5;
						(*J).minutes = (*J).minutes + 300;
						(*J).total = (*J).total + 300;
					}
					if ( opsi == 's' && (*M).T[(*P).Pos.x + 1][(*P).Pos.y].karakter == '-'){
						//DIBANGUN
						(*M).T[(*P).Pos.x + 1][(*P).Pos.y].karakter = 'S';
						(*M).T[(*P).Pos.x + 1][(*P).Pos.y].D.level = 1;
						(*M).T[(*P).Pos.x + 1][(*P).Pos.y].D.durasi = 120;
						(*M).T[(*P).Pos.x + 1][(*P).Pos.y].D.harga = (*M).T[(*P).Pos.x + 1][(*P).Pos.y].D.level * 5;
						(*M).T[(*P).Pos.x + 1][(*P).Pos.y].D.kapasitas = (*M).T[(*P).Pos.x + 1][(*P).Pos.y].D.level;
						//material berkuarng
						(*P).Det.kayu = (*P).Det.kayu - 50;
						(*P).Det.batu = (*P).Det.batu - 80;
						(*P).Det.besi = (*P).Det.besi - 5;
						(*J).minutes = (*J).minutes + 300;
						(*J).total = (*J).total + 300;
					}
					if ( opsi == 'd' && (*M).T[(*P).Pos.x][(*P).Pos.y + 1].karakter == '-'){
						//DIBANGUN
						(*M).T[(*P).Pos.x][(*P).Pos.y + 1].karakter = 'S';
						(*M).T[(*P).Pos.x][(*P).Pos.y + 1].D.level = 1;
						(*M).T[(*P).Pos.x][(*P).Pos.y + 1].D.durasi = 120;
						(*M).T[(*P).Pos.x][(*P).Pos.y + 1].D.harga = (*M).T[(*P).Pos.x][(*P).Pos.y + 1].D.level * 5;
						(*M).T[(*P).Pos.x][(*P).Pos.y + 1].D.kapasitas = (*M).T[(*P).Pos.x][(*P).Pos.y + 1].D.level;
						//material berkuarng
						(*P).Det.kayu = (*P).Det.kayu - 50;
						(*P).Det.batu = (*P).Det.batu - 80;
						(*P).Det.besi = (*P).Det.besi - 5;
						(*J).minutes = (*J).minutes + 300;
						(*J).total = (*J).total + 300;
					}
				}
				else{
					scanf("%c", &bangunan);
					printf("\n");
					printf("Kurang bahan onii-chan :( \n");
					printf("Tekan enter untuk melanjutkan maen xD");
				}
			}
			else if(bangunan == 'L'){
				if ( ( (*P).Det.kayu >= 200) && ( (*P).Det.batu >= 10 ) && ( (*P).Det.besi >= 55) ){
					//Mampu membangun
					system("cls");
					ShowMap(*M);
					printf("Hati-hati, salah tempat mengakibatkan pembangunan gagal onii-chan\n");
					printf("Membangun di sisi mana (w,a,s,d) dan q untuk batal: ");
					scanf("%c", &opsi);
					while (  (opsi != 'w') && (opsi != 'a') && (opsi != 's') && (opsi != 'd') && (opsi != 'q')){
						system("cls");
						ShowMap(*M);
						printf("Pilih posisi yang tepat onii-chan :3\n");
						printf("Membangun di sisi mana (w,a,s,d) dan q untuk batal: ");
						scanf("%c", &opsi);
					}
					
					if ( opsi == 'w' && (*M).T[(*P).Pos.x - 1][(*P).Pos.y].karakter == '-'){
						//DIBANGUN
						(*M).T[(*P).Pos.x - 1][(*P).Pos.y].karakter = 'L';
						(*M).T[(*P).Pos.x - 1][(*P).Pos.y].D.level = 1;
						(*M).T[(*P).Pos.x - 1][(*P).Pos.y].D.durasi = 30;
						(*M).T[(*P).Pos.x - 1][(*P).Pos.y].D.harga = (*M).T[(*P).Pos.x - 1][(*P).Pos.y].D.level * 8;
						(*M).T[(*P).Pos.x - 1][(*P).Pos.y].D.kapasitas = (*M).T[(*P).Pos.x - 1][(*P).Pos.y].D.level;
						//material berkuarng
						(*P).Det.kayu = (*P).Det.kayu - 200;
						(*P).Det.batu = (*P).Det.batu - 10;
						(*P).Det.besi = (*P).Det.besi - 55;
						(*J).minutes = (*J).minutes + 300;
						(*J).total = (*J).total + 300;
					}
					if ( opsi == 'a' && (*M).T[(*P).Pos.x][(*P).Pos.y - 1].karakter == '-'){
						//DIBANGUN
						(*M).T[(*P).Pos.x][(*P).Pos.y - 1].karakter = 'L';
						(*M).T[(*P).Pos.x][(*P).Pos.y - 1].D.level = 1;
						(*M).T[(*P).Pos.x][(*P).Pos.y - 1].D.durasi = 30;
						(*M).T[(*P).Pos.x][(*P).Pos.y - 1].D.harga = (*M).T[(*P).Pos.x][(*P).Pos.y - 1].D.level * 8;
						(*M).T[(*P).Pos.x][(*P).Pos.y - 1].D.kapasitas = (*M).T[(*P).Pos.x][(*P).Pos.y - 1].D.level;
						//material berkuarng
						(*P).Det.kayu = (*P).Det.kayu - 200;
						(*P).Det.batu = (*P).Det.batu - 10;
						(*P).Det.besi = (*P).Det.besi - 55;
						(*J).minutes = (*J).minutes + 300;
						(*J).total = (*J).total + 300;
					}
					if ( opsi == 's' && (*M).T[(*P).Pos.x + 1][(*P).Pos.y].karakter == '-'){
						//DIBANGUN
						(*M).T[(*P).Pos.x + 1][(*P).Pos.y].karakter = 'L';
						(*M).T[(*P).Pos.x + 1][(*P).Pos.y].D.level = 1;
						(*M).T[(*P).Pos.x + 1][(*P).Pos.y].D.durasi = 30;
						(*M).T[(*P).Pos.x + 1][(*P).Pos.y].D.harga = (*M).T[(*P).Pos.x + 1][(*P).Pos.y].D.level * 8;
						(*M).T[(*P).Pos.x + 1][(*P).Pos.y].D.kapasitas = (*M).T[(*P).Pos.x + 1][(*P).Pos.y].D.level;
						//material berkuarng
						(*P).Det.kayu = (*P).Det.kayu - 200;
						(*P).Det.batu = (*P).Det.batu - 10;
						(*P).Det.besi = (*P).Det.besi - 55;
						(*J).minutes = (*J).minutes + 300;
						(*J).total = (*J).total + 300;
					}
					if ( opsi == 'd' && (*M).T[(*P).Pos.x][(*P).Pos.y + 1].karakter == '-'){
						//DIBANGUN
						(*M).T[(*P).Pos.x][(*P).Pos.y + 1].karakter = 'L';
						(*M).T[(*P).Pos.x][(*P).Pos.y + 1].D.level = 1;
						(*M).T[(*P).Pos.x][(*P).Pos.y + 1].D.durasi = 30;
						(*M).T[(*P).Pos.x][(*P).Pos.y + 1].D.harga = (*M).T[(*P).Pos.x][(*P).Pos.y + 1].D.level * 8;
						(*M).T[(*P).Pos.x][(*P).Pos.y + 1].D.kapasitas = (*M).T[(*P).Pos.x][(*P).Pos.y + 1].D.level;
						//material berkuarng
						(*P).Det.kayu = (*P).Det.kayu - 200;
						(*P).Det.batu = (*P).Det.batu - 10;
						(*P).Det.besi = (*P).Det.besi - 55;
						(*J).minutes = (*J).minutes + 300;
						(*J).total = (*J).total + 300;
					}
				}
				else{
					scanf("%c", &bangunan);
					printf("\n");
					printf("Kurang bahan onii-chan :( \n");
					printf("Tekan enter untuk melanjutkan maen xD");
				}
			}
			else if(bangunan == 'H'){
				if ( ( (*P).Det.kayu >= 100) && ( (*P).Det.batu >= 100 ) && ( (*P).Det.besi >= 20) ){
					//Mampu membangun
					system("cls");
					ShowMap(*M);
					printf("Hati-hati, salah tempat mengakibatkan pembangunan gagal onii-chan\n");
					printf("Membangun di sisi mana (w,a,s,d) dan q untuk batal: ");
					scanf("%c", &opsi);
					while (  (opsi != 'w') && (opsi != 'a') && (opsi != 's') && (opsi != 'd') && (opsi != 'q')){
						system("cls");
						ShowMap(*M);
						printf("Pilih posisi yang tepat onii-chan :3\n");
						printf("Membangun di sisi mana (w,a,s,d) dan q untuk batal: ");
						scanf("%c", &opsi);
					}
					
					if ( opsi == 'w' && (*M).T[(*P).Pos.x - 1][(*P).Pos.y].karakter == '-'){
						//DIBANGUN
						(*M).T[(*P).Pos.x - 1][(*P).Pos.y].karakter = 'H';
						(*M).T[(*P).Pos.x - 1][(*P).Pos.y].D.level = 1;
						(*M).T[(*P).Pos.x - 1][(*P).Pos.y].D.durasi = 30;
						(*M).T[(*P).Pos.x - 1][(*P).Pos.y].D.harga = (*M).T[(*P).Pos.x - 1][(*P).Pos.y].D.level * 8;
						(*M).T[(*P).Pos.x - 1][(*P).Pos.y].D.kapasitas = (*M).T[(*P).Pos.x - 1][(*P).Pos.y].D.level;
						//material berkuarng
						(*P).Det.kayu = (*P).Det.kayu - 100;
						(*P).Det.batu = (*P).Det.batu - 100;
						(*P).Det.besi = (*P).Det.besi - 20;
						(*J).minutes = (*J).minutes + 300;
						(*J).total = (*J).total + 300;
					}
					if ( opsi == 'a' && (*M).T[(*P).Pos.x][(*P).Pos.y - 1].karakter == '-'){
						//DIBANGUN
						(*M).T[(*P).Pos.x][(*P).Pos.y - 1].karakter = 'H';
						(*M).T[(*P).Pos.x][(*P).Pos.y - 1].D.level = 1;
						(*M).T[(*P).Pos.x][(*P).Pos.y - 1].D.durasi = 30;
						(*M).T[(*P).Pos.x][(*P).Pos.y - 1].D.harga = (*M).T[(*P).Pos.x][(*P).Pos.y - 1].D.level * 8;
						(*M).T[(*P).Pos.x][(*P).Pos.y - 1].D.kapasitas = (*M).T[(*P).Pos.x][(*P).Pos.y - 1].D.level;
						//material berkuarng
						(*P).Det.kayu = (*P).Det.kayu - 100;
						(*P).Det.batu = (*P).Det.batu - 100;
						(*P).Det.besi = (*P).Det.besi - 20;
						(*J).minutes = (*J).minutes + 300;
						(*J).total = (*J).total + 300;
					}
					if ( opsi == 's' && (*M).T[(*P).Pos.x + 1][(*P).Pos.y].karakter == '-'){
						//DIBANGUN
						(*M).T[(*P).Pos.x + 1][(*P).Pos.y].karakter = 'H';
						(*M).T[(*P).Pos.x + 1][(*P).Pos.y].D.level = 1;
						(*M).T[(*P).Pos.x + 1][(*P).Pos.y].D.durasi = 30;
						(*M).T[(*P).Pos.x + 1][(*P).Pos.y].D.harga = (*M).T[(*P).Pos.x + 1][(*P).Pos.y].D.level * 8;
						(*M).T[(*P).Pos.x + 1][(*P).Pos.y].D.kapasitas = (*M).T[(*P).Pos.x + 1][(*P).Pos.y].D.level;
						//material berkuarng
						(*P).Det.kayu = (*P).Det.kayu - 100;
						(*P).Det.batu = (*P).Det.batu - 100;
						(*P).Det.besi = (*P).Det.besi - 20;
						(*J).minutes = (*J).minutes + 300;
						(*J).total = (*J).total + 300;
					}
					if ( opsi == 'd' && (*M).T[(*P).Pos.x][(*P).Pos.y + 1].karakter == '-'){
						//DIBANGUN
						(*M).T[(*P).Pos.x][(*P).Pos.y + 1].karakter = 'H';
						(*M).T[(*P).Pos.x][(*P).Pos.y + 1].D.level = 1;
						(*M).T[(*P).Pos.x][(*P).Pos.y + 1].D.durasi = 30;
						(*M).T[(*P).Pos.x][(*P).Pos.y + 1].D.harga = (*M).T[(*P).Pos.x][(*P).Pos.y + 1].D.level * 8;
						(*M).T[(*P).Pos.x][(*P).Pos.y + 1].D.kapasitas = (*M).T[(*P).Pos.x][(*P).Pos.y + 1].D.level;
						//material berkuarng
						(*P).Det.kayu = (*P).Det.kayu - 100;
						(*P).Det.batu = (*P).Det.batu - 100;
						(*P).Det.besi = (*P).Det.besi - 20;
						(*J).minutes = (*J).minutes + 300;
						(*J).total = (*J).total + 300;
					}
				}
				else{
					scanf("%c", &bangunan);
					printf("\n");
					printf("Kurang bahan onii-chan :( \n");
					printf("Tekan enter untuk melanjutkan maen xD");
				}
			}
			else{
				scanf("%c", &bangunan);
				printf("\n");
				printf("Tidak jadi membangun onii-chan :(((( \n");
				printf("Tekan enter untuk melanjutkan maen xD");
			}
		}
		else{
			scanf("%c", &bangunan);
			printf("\n");
			printf("Tidak ada tempat untuk membangun :( \n");
			printf("Tekan enter untuk melanjutkan maen xD");
		}
	}
	else if ( ((*J).minutes >= 180) && ((*J).minutes < 480)){
		scanf("%c", &bangunan);
		printf("\n");
		printf("Waktu tidak cukup onii-chan, keburu buka :p\n");
		printf("Tekan enter untuk melanjutkan maen xD");
	}
	else{
		scanf("%c", &bangunan);
		printf("\n");
		printf("Bukan fasenya :p\n");
		printf("Tekan enter untuk melanjutkan maen xD");
	}
}

void up(MAP *M, PLAYER *P, JAM *J){
	char opsi;
	KATA huhuhu;
	
	int i, j;
	i = (*P).Pos.x;
	j = (*P).Pos.y;
	
	//CEK WAKTU
	if ( (*J).minutes < 180 ){
		//ADA WAKTU UNTUK UPGRADE
		system("cls");
		
		ShowMap(*M);
		printf("\n");
		
		printf("Mode upgrade\n");
		//MEMILIH BANGUNAN
		printf("\n");
		printf("Memilih wahana yang ingin diupgrade\n");
		printf("Pastikan ada wahana di sekitarmu!\n");
		printf("\n");
		printf("Harta Onii-chan\n");
		printf("Kayu: %d | Batu: %d | Besi: %d\n",(*P).Det.kayu,(*P).Det.batu,(*P).Det.besi);
		//PILIHAN WAHANA
		printf("\n");
		printf("B -> Bioskop Same Day As Japan\n");
		printf("Kayu: 1000 | Batu: 200 | Besi: 50\n");
		printf("Durasi: 90 | Harga: 50 | Kapasitas: +1\n");
			
		printf("\n");
		printf("M -> Maid Cafe\n");
		printf("Kayu: 250 | Batu: 50 | Besi: 75\n");
		printf("Durasi: 60 | Harga: 25 | Kapasitas: +1\n");
			
		printf("\n");
		printf("C -> Cosplay Spot\n");
		printf("Kayu: 75 | Batu: 50 | Besi: 35\n");
		printf("Durasi: 60 | Harga: 10 | Kapasitas: +1\n");
		
		printf("\n");
		printf("S-> Weebs Store\n");
		printf("Kayu: 25 | Batu: 40 | Besi: 5\n");
		printf("Durasi: 120 | Harga: 5 | Kapasitas: +1\n");
		
		printf("\n");
		printf("L -> Love Arcade\n");
		printf("Kayu: 100 | Batu: 5 | Besi: 55\n");
		printf("Durasi: 30 | Harga: 8 | Kapasitas: +1\n");
			
		printf("\n");
		printf("H -> Host Club\n");
		printf("Kayu: 50 | Batu: 50 | Besi: 10\n");
		printf("Durasi: 30 | Harga: 8 | Kapasitas: +1\n");
		printf("\n");
		
		printf("Pilih tempat yang mau diupgrade (wasd) dan pastikan itu bertipe wahana atau upgrade gagal! q untuk batal: ");
		scanf("%c", &opsi);
		
		while (  (opsi != 'w') && (opsi != 'a') && (opsi != 's') && (opsi != 'd') && (opsi != 'q')){
			system("cls");
			
			ShowMap(*M);
			printf("\n");
			
			printf("Mode upgrade\n");
			//MEMILIH BANGUNAN
			printf("\n");
			printf("Memilih wahana yang ingin diupgrade\n");
			printf("Pastikan ada wahana di sekitarmu!\n");
			printf("\n");
			printf("Harta Onii-chan\n");
			printf("Kayu: %d | Batu: %d | Besi: %d\n",(*P).Det.kayu,(*P).Det.batu,(*P).Det.besi);
			//PILIHAN WAHANA
			printf("\n");
			printf("B -> Bioskop Same Day As Japan\n");
			printf("Kayu: 1000 | Batu: 200 | Besi: 50\n");
			printf("Durasi: 90 | Harga: 50 | Kapasitas: +1\n");
				
			printf("\n");
			printf("M -> Maid Cafe\n");
			printf("Kayu: 250 | Batu: 50 | Besi: 75\n");
			printf("Durasi: 60 | Harga: 25 | Kapasitas: +1\n");
				
			printf("\n");
			printf("C -> Cosplay Spot\n");
			printf("Kayu: 75 | Batu: 50 | Besi: 35\n");
			printf("Durasi: 60 | Harga: 10 | Kapasitas: +1\n");
		
			printf("\n");
			printf("S-> Weebs Store\n");
			printf("Kayu: 25 | Batu: 40 | Besi: 5\n");
			printf("Durasi: 120 | Harga: 5 | Kapasitas: +1\n");
		
			printf("\n");
			printf("L -> Love Arcade\n");
			printf("Kayu: 100 | Batu: 5 | Besi: 55\n");
			printf("Durasi: 30 | Harga: 8 | Kapasitas: +1\n");
			
			printf("\n");
			printf("H -> Host Club\n");
			printf("Kayu: 50 | Batu: 50 | Besi: 10\n");
			printf("Durasi: 30 | Harga: 8 | Kapasitas: +1\n");
			printf("\n");
			
			printf("Pilih tempat yang mau diupgrade (wasd) dan pastikan itu bertipe wahana atau upgrade gagal! q untuk batal: ");
			scanf("%c", &opsi);
		}
		
		//kalo pilih atas
		if (opsi == 'w'){
			//kalo bioskop
			if( (*M).T[i-1][j].karakter == 'B'){
				//kalo mampu membangun
				if( (*P).Det.kayu >= 1000 && (*P).Det.batu >= 200 && (*P).Det.besi >= 50){
					(*M).T[i - 1][j].D.level = (*M).T[i - 1][j].D.level + 1;
					(*M).T[i - 1][j].D.harga = (*M).T[i - 1][j].D.level * 50;
					(*M).T[i - 1][j].D.kapasitas = (*M).T[i - 1][j].D.level;
					
					(*P).Det.kayu = (*P).Det.kayu - 1000;
					(*P).Det.batu = (*P).Det.batu - 200;
					(*P).Det.besi = (*P).Det.besi - 50;
					
					(*J).minutes = (*J).minutes + 300;
					(*J).total = (*J).total + 300;
				}
				else{
					scanf("%c", &opsi);
					printf("\n");
					printf("Tidak material upgrade onii-chan, keburu buka :p\n");
					printf("Tekan enter untuk melanjutkan maen xD");
				}
			}
			else if ( (*M).T[i-1][j].karakter == 'M'){
				//kalo mampu membangun
				if( (*P).Det.kayu >= 250 && (*P).Det.batu >= 50 && (*P).Det.besi >= 75){
					(*M).T[i - 1][j].D.level = (*M).T[i - 1][j].D.level + 1;
					(*M).T[i - 1][j].D.harga = (*M).T[i - 1][j].D.level * 25;
					(*M).T[i - 1][j].D.kapasitas = (*M).T[i - 1][j].D.level;
					
					(*P).Det.kayu = (*P).Det.kayu - 250;
					(*P).Det.batu = (*P).Det.batu - 50;
					(*P).Det.besi = (*P).Det.besi - 75;
					
					(*J).minutes = (*J).minutes + 300;
					(*J).total = (*J).total + 300;
				}
				else{
					scanf("%c", &opsi);
					printf("\n");
					printf("Tidak material upgrade onii-chan, keburu buka :p\n");
					printf("Tekan enter untuk melanjutkan maen xD");
				}
			}
			else if ( (*M).T[i-1][j].karakter == 'C'){
				//kalo mampu membangun
				if( (*P).Det.kayu >= 75 && (*P).Det.batu >= 50 && (*P).Det.besi >= 35){
					(*M).T[i - 1][j].D.level = (*M).T[i - 1][j].D.level + 1;
					(*M).T[i - 1][j].D.harga = (*M).T[i - 1][j].D.level * 10;
					(*M).T[i - 1][j].D.kapasitas = (*M).T[i - 1][j].D.level;
					
					(*P).Det.kayu = (*P).Det.kayu - 75;
					(*P).Det.batu = (*P).Det.batu - 50;
					(*P).Det.besi = (*P).Det.besi - 35;
					
					(*J).minutes = (*J).minutes + 300;
					(*J).total = (*J).total + 300;
				}
				else{
					scanf("%c", &opsi);
					printf("\n");
					printf("Tidak material upgrade onii-chan, keburu buka :p\n");
					printf("Tekan enter untuk melanjutkan maen xD");
				}
			}
			else if ( (*M).T[i-1][j].karakter == 'S'){
				//kalo mampu membangun
				if( (*P).Det.kayu >= 25 && (*P).Det.batu >= 40 && (*P).Det.besi >= 5){
					(*M).T[i - 1][j].D.level = (*M).T[i - 1][j].D.level + 1;
					(*M).T[i - 1][j].D.harga = (*M).T[i - 1][j].D.level * 5;
					(*M).T[i - 1][j].D.kapasitas = (*M).T[i - 1][j].D.level;
					
					(*P).Det.kayu = (*P).Det.kayu - 25;
					(*P).Det.batu = (*P).Det.batu - 40;
					(*P).Det.besi = (*P).Det.besi - 5;
					
					(*J).minutes = (*J).minutes + 300;
					(*J).total = (*J).total + 300;
				}
				else{
					scanf("%c", &opsi);
					printf("\n");
					printf("Tidak material upgrade onii-chan, keburu buka :p\n");
					printf("Tekan enter untuk melanjutkan maen xD");
				}
			}
			else if ( (*M).T[i-1][j].karakter == 'L'){
				//kalo mampu membangun
				if( (*P).Det.kayu >= 100 && (*P).Det.batu >= 5 && (*P).Det.besi >= 55){
					(*M).T[i - 1][j].D.level = (*M).T[i - 1][j].D.level + 1;
					(*M).T[i - 1][j].D.harga = (*M).T[i - 1][j].D.level * 8;
					(*M).T[i - 1][j].D.kapasitas = (*M).T[i - 1][j].D.level;
					
					(*P).Det.kayu = (*P).Det.kayu - 100;
					(*P).Det.batu = (*P).Det.batu - 5;
					(*P).Det.besi = (*P).Det.besi - 55;
					
					(*J).minutes = (*J).minutes + 300;
					(*J).total = (*J).total + 300;
				}
				else{
					scanf("%c", &opsi);
					printf("\n");
					printf("Tidak material upgrade onii-chan, keburu buka :p\n");
					printf("Tekan enter untuk melanjutkan maen xD");
				}
			}
			else if ( (*M).T[i-1][j].karakter == 'H'){
				//kalo mampu membangun
				if( (*P).Det.kayu >= 50 && (*P).Det.batu >= 50 && (*P).Det.besi >= 10){
					(*M).T[i - 1][j].D.level = (*M).T[i - 1][j].D.level + 1;
					(*M).T[i - 1][j].D.harga = (*M).T[i - 1][j].D.level * 8;
					(*M).T[i - 1][j].D.kapasitas = (*M).T[i - 1][j].D.level;
					
					(*P).Det.kayu = (*P).Det.kayu - 50;
					(*P).Det.batu = (*P).Det.batu - 50;
					(*P).Det.besi = (*P).Det.besi - 10;
					
					(*J).minutes = (*J).minutes + 300;
					(*J).total = (*J).total + 300;
				}
				else{
					scanf("%c", &opsi);
					printf("\n");
					printf("Tidak material upgrade onii-chan, keburu buka :p\n");
					printf("Tekan enter untuk melanjutkan maen xD");
				}
			}
			else{
				//do nothing
			}
		}
		else if (opsi == 'a'){
			//kalo bioskop
			if( (*M).T[i][j - 1].karakter == 'B'){
				//kalo mampu membangun
				if( (*P).Det.kayu >= 1000 && (*P).Det.batu >= 200 && (*P).Det.besi >= 50){
					(*M).T[i][j - 1].D.level = (*M).T[i][j - 1].D.level + 1;
					(*M).T[i][j - 1].D.harga = (*M).T[i][j - 1].D.level * 50;
					(*M).T[i][j - 1].D.kapasitas = (*M).T[i][j - 1].D.level;
					
					(*P).Det.kayu = (*P).Det.kayu - 1000;
					(*P).Det.batu = (*P).Det.batu - 200;
					(*P).Det.besi = (*P).Det.besi - 50;
					
					(*J).minutes = (*J).minutes + 300;
					(*J).total = (*J).total + 300;
				}
				else{
					scanf("%c", &opsi);
					printf("\n");
					printf("Tidak material upgrade onii-chan, keburu buka :p\n");
					printf("Tekan enter untuk melanjutkan maen xD");
				}
			}
			else if ( (*M).T[i][j - 1].karakter == 'M'){
				//kalo mampu membangun
				if( (*P).Det.kayu >= 250 && (*P).Det.batu >= 50 && (*P).Det.besi >= 75){
					(*M).T[i][j - 1].D.level = (*M).T[i - 1][j].D.level + 1;
					(*M).T[i][j - 1].D.harga = (*M).T[i][j - 1].D.level * 25;
					(*M).T[i][j - 1].D.kapasitas = (*M).T[i][j - 1].D.level;
					
					(*P).Det.kayu = (*P).Det.kayu - 250;
					(*P).Det.batu = (*P).Det.batu - 50;
					(*P).Det.besi = (*P).Det.besi - 75;
					
					(*J).minutes = (*J).minutes + 300;
					(*J).total = (*J).total + 300;
				}
				else{
					scanf("%c", &opsi);
					printf("\n");
					printf("Tidak material upgrade onii-chan, keburu buka :p\n");
					printf("Tekan enter untuk melanjutkan maen xD");
				}
			}
			else if ( (*M).T[i][j - 1].karakter == 'C'){
				//kalo mampu membangun
				if( (*P).Det.kayu >= 75 && (*P).Det.batu >= 50 && (*P).Det.besi >= 35){
					(*M).T[i][j - 1].D.level = (*M).T[i][j - 1].D.level + 1;
					(*M).T[i][j - 1].D.harga = (*M).T[i][j - 1].D.level * 10;
					(*M).T[i][j - 1].D.kapasitas = (*M).T[i][j - 1].D.level;
					
					(*P).Det.kayu = (*P).Det.kayu - 75;
					(*P).Det.batu = (*P).Det.batu - 50;
					(*P).Det.besi = (*P).Det.besi - 35;
					
					(*J).minutes = (*J).minutes + 300;
					(*J).total = (*J).total + 300;
				}
				else{
					scanf("%c", &opsi);
					printf("\n");
					printf("Tidak material upgrade onii-chan, keburu buka :p\n");
					printf("Tekan enter untuk melanjutkan maen xD");
				}
			}
			else if ( (*M).T[i][j - 1].karakter == 'S'){
				//kalo mampu membangun
				if( (*P).Det.kayu >= 25 && (*P).Det.batu >= 40 && (*P).Det.besi >= 5){
					(*M).T[i][j - 1].D.level = (*M).T[i][j - 1].D.level + 1;
					(*M).T[i][j - 1].D.harga = (*M).T[i][j - 1].D.level * 5;
					(*M).T[i][j - 1].D.kapasitas = (*M).T[i][j - 1].D.level;
					
					(*P).Det.kayu = (*P).Det.kayu - 25;
					(*P).Det.batu = (*P).Det.batu - 40;
					(*P).Det.besi = (*P).Det.besi - 5;
					
					(*J).minutes = (*J).minutes + 300;
					(*J).total = (*J).total + 300;
				}
				else{
					scanf("%c", &opsi);
					printf("\n");
					printf("Tidak material upgrade onii-chan, keburu buka :p\n");
					printf("Tekan enter untuk melanjutkan maen xD");
				}
			}
			else if ( (*M).T[i][j - 1].karakter == 'L'){
				//kalo mampu membangun
				if( (*P).Det.kayu >= 100 && (*P).Det.batu >= 5 && (*P).Det.besi >= 55){
					(*M).T[i][j - 1].D.level = (*M).T[i][j - 1].D.level + 1;
					(*M).T[i][j - 1].D.harga = (*M).T[i][j - 1].D.level * 8;
					(*M).T[i][j - 1].D.kapasitas = (*M).T[i][j - 1].D.level;
					
					(*P).Det.kayu = (*P).Det.kayu - 100;
					(*P).Det.batu = (*P).Det.batu - 5;
					(*P).Det.besi = (*P).Det.besi - 55;
					
					(*J).minutes = (*J).minutes + 300;
					(*J).total = (*J).total + 300;
				}
				else{
					scanf("%c", &opsi);
					printf("\n");
					printf("Tidak material upgrade onii-chan, keburu buka :p\n");
					printf("Tekan enter untuk melanjutkan maen xD");
				}
			}
			else if ( (*M).T[i][j - 1].karakter == 'H'){
				//kalo mampu membangun
				if( (*P).Det.kayu >= 50 && (*P).Det.batu >= 50 && (*P).Det.besi >= 10){
					(*M).T[i][j - 1].D.level = (*M).T[i][j - 1].D.level + 1;
					(*M).T[i][j - 1].D.harga = (*M).T[i][j - 1].D.level * 8;
					(*M).T[i][j - 1].D.kapasitas = (*M).T[i][j - 1].D.level;
					
					(*P).Det.kayu = (*P).Det.kayu - 50;
					(*P).Det.batu = (*P).Det.batu - 50;
					(*P).Det.besi = (*P).Det.besi - 10;
					
					(*J).minutes = (*J).minutes + 300;
					(*J).total = (*J).total + 300;
				}
				else{
					scanf("%c", &opsi);
					printf("\n");
					printf("Tidak material upgrade onii-chan, keburu buka :p\n");
					printf("Tekan enter untuk melanjutkan maen xD");
				}
			}
			else{
				//do nothing
			}
		}
		if (opsi == 's'){
			//kalo bioskop
			if( (*M).T[i+1][j].karakter == 'B'){
				//kalo mampu membangun
				if( (*P).Det.kayu >= 1000 && (*P).Det.batu >= 200 && (*P).Det.besi >= 50){
					(*M).T[i + 1][j].D.level = (*M).T[i + 1][j].D.level + 1;
					(*M).T[i + 1][j].D.harga = (*M).T[i + 1][j].D.level * 50;
					(*M).T[i + 1][j].D.kapasitas = (*M).T[i + 1][j].D.level;
					
					(*P).Det.kayu = (*P).Det.kayu - 1000;
					(*P).Det.batu = (*P).Det.batu - 200;
					(*P).Det.besi = (*P).Det.besi - 50;
					
					(*J).minutes = (*J).minutes + 300;
					(*J).total = (*J).total + 300;
				}
				else{
					scanf("%c", &opsi);
					printf("\n");
					printf("Tidak material upgrade onii-chan, keburu buka :p\n");
					printf("Tekan enter untuk melanjutkan maen xD");
				}
			}
			else if ( (*M).T[i+1][j].karakter == 'M'){
				//kalo mampu membangun
				if( (*P).Det.kayu >= 250 && (*P).Det.batu >= 50 && (*P).Det.besi >= 75){
					(*M).T[i + 1][j].D.level = (*M).T[i + 1][j].D.level + 1;
					(*M).T[i + 1][j].D.harga = (*M).T[i + 1][j].D.level * 25;
					(*M).T[i + 1][j].D.kapasitas = (*M).T[i + 1][j].D.level;
					
					(*P).Det.kayu = (*P).Det.kayu - 250;
					(*P).Det.batu = (*P).Det.batu - 50;
					(*P).Det.besi = (*P).Det.besi - 75;
					
					(*J).minutes = (*J).minutes + 300;
					(*J).total = (*J).total + 300;
				}
				else{
					scanf("%c", &opsi);
					printf("\n");
					printf("Tidak material upgrade onii-chan, keburu buka :p\n");
					printf("Tekan enter untuk melanjutkan maen xD");
				}
			}
			else if ( (*M).T[i+1][j].karakter == 'C'){
				//kalo mampu membangun
				if( (*P).Det.kayu >= 75 && (*P).Det.batu >= 50 && (*P).Det.besi >= 35){
					(*M).T[i + 1][j].D.level = (*M).T[i + 1][j].D.level + 1;
					(*M).T[i + 1][j].D.harga = (*M).T[i + 1][j].D.level * 10;
					(*M).T[i + 1][j].D.kapasitas = (*M).T[i + 1][j].D.level;
					
					(*P).Det.kayu = (*P).Det.kayu - 75;
					(*P).Det.batu = (*P).Det.batu - 50;
					(*P).Det.besi = (*P).Det.besi - 35;
					
					(*J).minutes = (*J).minutes + 300;
					(*J).total = (*J).total + 300;
				}
				else{
					scanf("%c", &opsi);
					printf("\n");
					printf("Tidak material upgrade onii-chan, keburu buka :p\n");
					printf("Tekan enter untuk melanjutkan maen xD");
				}
			}
			else if ( (*M).T[i+1][j].karakter == 'S'){
				//kalo mampu membangun
				if( (*P).Det.kayu >= 25 && (*P).Det.batu >= 40 && (*P).Det.besi >= 5){
					(*M).T[i + 1][j].D.level = (*M).T[i + 1][j].D.level + 1;
					(*M).T[i + 1][j].D.harga = (*M).T[i + 1][j].D.level * 5;
					(*M).T[i + 1][j].D.kapasitas = (*M).T[i + 1][j].D.level;
					
					(*P).Det.kayu = (*P).Det.kayu - 25;
					(*P).Det.batu = (*P).Det.batu - 40;
					(*P).Det.besi = (*P).Det.besi - 5;
					
					(*J).minutes = (*J).minutes + 300;
					(*J).total = (*J).total + 300;
				}
				else{
					scanf("%c", &opsi);
					printf("\n");
					printf("Tidak material upgrade onii-chan, keburu buka :p\n");
					printf("Tekan enter untuk melanjutkan maen xD");
				}
			}
			else if ( (*M).T[i+1][j].karakter == 'L'){
				//kalo mampu membangun
				if( (*P).Det.kayu >= 100 && (*P).Det.batu >= 5 && (*P).Det.besi >= 55){
					(*M).T[i + 1][j].D.level = (*M).T[i + 1][j].D.level + 1;
					(*M).T[i + 1][j].D.harga = (*M).T[i + 1][j].D.level * 8;
					(*M).T[i + 1][j].D.kapasitas = (*M).T[i + 1][j].D.level;
					
					(*P).Det.kayu = (*P).Det.kayu - 100;
					(*P).Det.batu = (*P).Det.batu - 5;
					(*P).Det.besi = (*P).Det.besi - 55;
					
					(*J).minutes = (*J).minutes + 300;
					(*J).total = (*J).total + 300;
				}
				else{
					scanf("%c", &opsi);
					printf("\n");
					printf("Tidak material upgrade onii-chan, keburu buka :p\n");
					printf("Tekan enter untuk melanjutkan maen xD");
				}
			}
			else if ( (*M).T[i+1][j].karakter == 'H'){
				//kalo mampu membangun
				if( (*P).Det.kayu >= 50 && (*P).Det.batu >= 50 && (*P).Det.besi >= 10){
					(*M).T[i + 1][j].D.level = (*M).T[i + 1][j].D.level + 1;
					(*M).T[i + 1][j].D.harga = (*M).T[i + 1][j].D.level * 8;
					(*M).T[i + 1][j].D.kapasitas = (*M).T[i + 1][j].D.level;
					
					(*P).Det.kayu = (*P).Det.kayu - 50;
					(*P).Det.batu = (*P).Det.batu - 50;
					(*P).Det.besi = (*P).Det.besi - 10;
					
					(*J).minutes = (*J).minutes + 300;
					(*J).total = (*J).total + 300;
				}
				else{
					scanf("%c", &opsi);
					printf("\n");
					printf("Tidak material upgrade onii-chan, keburu buka :p\n");
					printf("Tekan enter untuk melanjutkan maen xD");
				}
			}
			else{
				//do nothing
			}
		}
		else if (opsi == 'd'){
			//kalo bioskop
			if( (*M).T[i][j + 1].karakter == 'B'){
				//kalo mampu membangun
				if( (*P).Det.kayu >= 1000 && (*P).Det.batu >= 200 && (*P).Det.besi >= 50){
					(*M).T[i][j + 1].D.level = (*M).T[i][j + 1].D.level + 1;
					(*M).T[i][j + 1].D.harga = (*M).T[i][j + 1].D.level * 50;
					(*M).T[i][j + 1].D.kapasitas = (*M).T[i][j + 1].D.level;
					
					(*P).Det.kayu = (*P).Det.kayu - 1000;
					(*P).Det.batu = (*P).Det.batu - 200;
					(*P).Det.besi = (*P).Det.besi - 50;
					
					(*J).minutes = (*J).minutes + 300;
					(*J).total = (*J).total + 300;
				}
				else{
					scanf("%c", &opsi);
					printf("\n");
					printf("Tidak material upgrade onii-chan, keburu buka :p\n");
					printf("Tekan enter untuk melanjutkan maen xD");
				}
			}
			else if ( (*M).T[i][j + 1].karakter == 'M'){
				//kalo mampu membangun
				if( (*P).Det.kayu >= 250 && (*P).Det.batu >= 50 && (*P).Det.besi >= 75){
					(*M).T[i][j + 1].D.level = (*M).T[i + 1][j].D.level + 1;
					(*M).T[i][j + 1].D.harga = (*M).T[i][j + 1].D.level * 25;
					(*M).T[i][j + 1].D.kapasitas = (*M).T[i][j + 1].D.level;
					
					(*P).Det.kayu = (*P).Det.kayu - 250;
					(*P).Det.batu = (*P).Det.batu - 50;
					(*P).Det.besi = (*P).Det.besi - 75;
					
					(*J).minutes = (*J).minutes + 300;
					(*J).total = (*J).total + 300;
				}
				else{
					scanf("%c", &opsi);
					printf("\n");
					printf("Tidak material upgrade onii-chan, keburu buka :p\n");
					printf("Tekan enter untuk melanjutkan maen xD");
				}
			}
			else if ( (*M).T[i][j + 1].karakter == 'C'){
				//kalo mampu membangun
				if( (*P).Det.kayu >= 75 && (*P).Det.batu >= 50 && (*P).Det.besi >= 35){
					(*M).T[i][j + 1].D.level = (*M).T[i][j + 1].D.level + 1;
					(*M).T[i][j + 1].D.harga = (*M).T[i][j + 1].D.level * 10;
					(*M).T[i][j + 1].D.kapasitas = (*M).T[i][j + 1].D.level;
					
					(*P).Det.kayu = (*P).Det.kayu - 75;
					(*P).Det.batu = (*P).Det.batu - 50;
					(*P).Det.besi = (*P).Det.besi - 35;
					
					(*J).minutes = (*J).minutes + 300;
					(*J).total = (*J).total + 300;
				}
				else{
					scanf("%c", &opsi);
					printf("\n");
					printf("Tidak material upgrade onii-chan, keburu buka :p\n");
					printf("Tekan enter untuk melanjutkan maen xD");
				}
			}
			else if ( (*M).T[i][j + 1].karakter == 'S'){
				//kalo mampu membangun
				if( (*P).Det.kayu >= 25 && (*P).Det.batu >= 40 && (*P).Det.besi >= 5){
					(*M).T[i][j + 1].D.level = (*M).T[i][j + 1].D.level + 1;
					(*M).T[i][j + 1].D.harga = (*M).T[i][j + 1].D.level * 5;
					(*M).T[i][j + 1].D.kapasitas = (*M).T[i][j + 1].D.level;
					
					(*P).Det.kayu = (*P).Det.kayu - 25;
					(*P).Det.batu = (*P).Det.batu - 40;
					(*P).Det.besi = (*P).Det.besi - 5;
					
					(*J).minutes = (*J).minutes + 300;
					(*J).total = (*J).total + 300;
				}
				else{
					scanf("%c", &opsi);
					printf("\n");
					printf("Tidak material upgrade onii-chan, keburu buka :p\n");
					printf("Tekan enter untuk melanjutkan maen xD");
				}
			}
			else if ( (*M).T[i][j + 1].karakter == 'L'){
				//kalo mampu membangun
				if( (*P).Det.kayu >= 100 && (*P).Det.batu >= 5 && (*P).Det.besi >= 55){
					(*M).T[i][j + 1].D.level = (*M).T[i][j + 1].D.level + 1;
					(*M).T[i][j + 1].D.harga = (*M).T[i][j + 1].D.level * 8;
					(*M).T[i][j + 1].D.kapasitas = (*M).T[i][j + 1].D.level;
					
					(*P).Det.kayu = (*P).Det.kayu - 100;
					(*P).Det.batu = (*P).Det.batu - 5;
					(*P).Det.besi = (*P).Det.besi - 55;
					
					(*J).minutes = (*J).minutes + 300;
					(*J).total = (*J).total + 300;
				}
				else{
					scanf("%c", &opsi);
					printf("\n");
					printf("Tidak material upgrade onii-chan, keburu buka :p\n");
					printf("Tekan enter untuk melanjutkan maen xD");
				}
			}
			else if ( (*M).T[i][j + 1].karakter == 'H'){
				//kalo mampu membangun
				if( (*P).Det.kayu >= 50 && (*P).Det.batu >= 50 && (*P).Det.besi >= 10){
					(*M).T[i][j + 1].D.level = (*M).T[i][j + 1].D.level + 1;
					(*M).T[i][j + 1].D.harga = (*M).T[i][j + 1].D.level * 8;
					(*M).T[i][j + 1].D.kapasitas = (*M).T[i][j + 1].D.level;
					
					(*P).Det.kayu = (*P).Det.kayu - 50;
					(*P).Det.batu = (*P).Det.batu - 50;
					(*P).Det.besi = (*P).Det.besi - 10;
					
					(*J).minutes = (*J).minutes + 300;
					(*J).total = (*J).total + 300;
				}
				else{
					scanf("%c", &opsi);
					printf("\n");
					printf("Tidak material upgrade onii-chan, keburu buka :p\n");
					printf("Tekan enter untuk melanjutkan maen xD");
				}
			}
			else{
				//do nothing
			}
		}
		else{
			//do nothing
		}
	}
	
	else if ( (*J).minutes >= 180 && (*J).minutes < 480){
		scanf("%c", &opsi);
		printf("\n");
		printf("Tidak adaa waktu upgrade onii-chan, keburu buka :p\n");
		printf("Tekan enter untuk melanjutkan maen xD");
	}
	else{
		scanf("%c", &opsi);
		printf("\n");
		printf("Bukan fasenya :p\n");
		printf("Tekan enter untuk melanjutkan maen xD");
	}
}


//FUNGSI YANG BERLAKU DI MAIN PHASE ONLY
void skiptime( JAM *J){
	char opsi;
	system("cls");
	ShowJam(*J);
	printf("\n");
	printf("\n");
	printf("0 -> batal\n");
	printf("1 -> skip 15 menit\n");
	printf("2 -> skip 30 menit\n");
	printf("3 -> skip 1 jam\n");
	printf("4 -> skip 2 jam\n");
	printf("\n");
	printf("Pilihan onii-chan: ");
	scanf("%c", &opsi);
	while ( (opsi != '0') && (opsi != '1') && (opsi != '2') && (opsi != '3') && (opsi != '4') ){
		system("cls");
		ShowJam(*J);
		printf("\n");
		printf("\n");
		printf("0 -> batal\n");
		printf("1 -> skip 15 menit\n");
		printf("2 -> skip 30 menit\n");
		printf("3 -> skip 1 jam\n");
		printf("4 -> skip 2 jam\n");
		printf("\n");
		printf("Pilihan onii-chan: (Ieeee, masukin yang bener pilihannya onii-chan)");
		scanf("%c", &opsi);
	}
	if ( opsi == '1'){
		(*J).minutes = (*J).minutes + 15;
		(*J).total = (*J).total + 15;
	}
	else if ( opsi == '2'){
		(*J).minutes = (*J).minutes + 30;
		(*J).total = (*J).total + 30;
	}
	else if ( opsi == '3'){
		(*J).minutes = (*J).minutes + 60;
		(*J).total = (*J).total + 60;
	}
	else if ( opsi == '4'){
		(*J).minutes = (*J).minutes + 120;
		(*J).total = (*J).total + 120;
	}
	else{
		//do nothing
	}
	
}


void judi(PLAYER *P, JAM *J){
	char opsi;
	
	int tangan;
	int tangan_lawan;
	int x;
	
	int kayu;
	int batu;
	int besi;
	
	int bet;
	
	srand(time(NULL));
	
	system("cls");
	printf("KAKEGURUI INTERFACE\n");
	printf("\n");
	printf("Uangmu: %d",(*P).Det.uang);
	printf("\n");
	printf("0 -> KABUR!\n");
	printf("1 -> Bermain 'batu gunting kertas' biasa (minimum bet: 10; maximum bet: 25)\n");
	printf("2 -> Bermain 'batu gunting kertas' melawan Yumeko Jabami (minimum bet: 100; maximum bet: 200)\n");
	printf("3 -> Gacha 50 uang hadiah uang\n");
	printf("4 -> Gacha 200 uang hadiah material\n");
	printf("\n");
	printf("Berani yang mana: ");
	scanf("%c", &opsi);
	while ( (opsi != '0') && (opsi != '1') && (opsi != '2') && (opsi != '3') && (opsi != '4') ){
		system("cls");
		printf("KAKEGURUI INTERFACE\n");
		printf("\n");
		printf("Uangmu: %d",(*P).Det.uang);
		printf("\n");
		printf("0 -> KABUR!\n");
		printf("1 -> Bermain 'batu gunting kertas' biasa (minimum bet: 10; maximum bet: 25)\n");
		printf("2 -> Bermain 'batu gunting kertas' melawan Yumeko Jabami (minimum bet: 100; maximum bet: 200)\n");
		printf("3 -> Gacha 50 uang hadiah uang\n");
		printf("\n");
		printf("Berani yang mana: ");
		scanf("%c", &opsi);
	}
	
	//Lawan orang normal
	if (opsi == '1'){
		//punya cukup duit kita maen
		if( (*P).Det.uang >= 10){
			system("cls");
			printf("KAKEGURUI INTERFACE\n");
			printf("Batu gunting kertas biasa\n");
			printf("\n");
			printf("Uangmu: %d",(*P).Det.uang);
			printf("\n");
			printf("Masukkan taruhanmu (10-25): ");
			scanf("%d", &bet);
			while(bet < 10 || bet > 25){
				system("cls");
				printf("KAKEGURUI INTERFACE\n");
				printf("Batu gunting kertas biasa\n");
				printf("\n");
				printf("Uangmu: %d",(*P).Det.uang);
				printf("\n");
				printf("Masukkan taruhanmu (10-25): ");
				scanf("%d", &bet);
			}
			printf("\n");
			printf("Masukkan tanganmu!\n");
			printf(" 0 -> 1 | 1 -> 2 | 2 -> 0\n");
			printf("Masukkan 0, 1, atau 2! Salah memasukkan, uang mengalir ke lawan!\n");
			printf("Tanganmu: ");
			scanf("%d", &tangan);
			tangan = tangan%3; //antisipasi
			tangan_lawan = rand()%3;
			printf("Tangan lawan: %d\n", tangan_lawan);
			printf("\n");
			if( tangan == 0){
				if(tangan_lawan == 0){
					(*J).minutes = (*J).minutes + 30;
					(*J).total = (*J).total + 30;
					scanf("%c", &opsi);
					printf("Seri?!\n");
					printf("Tekan enter untuk pulang!\n");
				}
				else if(tangan_lawan == 1){
					(*P).Det.uang = (*P).Det.uang + bet;
					(*J).minutes = (*J).minutes + 30;
					(*J).total = (*J).total + 30;
					scanf("%c", &opsi);
					printf("Menang woiii!\n");
					printf("Tekan enter untuk pulang!\n");
				}
				else{
					(*P).Det.uang = (*P).Det.uang - bet;
					(*J).minutes = (*J).minutes + 30;
					(*J).total = (*J).total + 30;
					scanf("%c", &opsi);
					printf("MASIH BERANI LAGI GAK?\n");
					printf("Tekan enter untuk pulang!\n");
				}
			}
			else if(tangan == 1){
				if(tangan_lawan == 1){
					(*J).minutes = (*J).minutes + 30;
					(*J).total = (*J).total + 30;
					scanf("%c", &opsi);
					printf("Seri?!\n");
					printf("Tekan enter untuk pulang!\n");
				}
				else if(tangan_lawan == 2){
					(*P).Det.uang = (*P).Det.uang + bet;
					(*J).minutes = (*J).minutes + 30;
					(*J).total = (*J).total + 30;
					scanf("%c", &opsi);
					printf("Menang woiii!\n");
					printf("Tekan enter untuk pulang!\n");
				}
				else{
					(*P).Det.uang = (*P).Det.uang - bet;
					(*J).minutes = (*J).minutes + 30;
					(*J).total = (*J).total + 30;
					scanf("%c", &opsi);
					printf("MASIH BERANI LAGI GAK?\n");
					printf("Tekan enter untuk pulang!\n");
				}
			}
			else{
				if(tangan_lawan == 2){
					(*J).minutes = (*J).minutes + 30;
					(*J).total = (*J).total + 30;
					scanf("%c", &opsi);
					printf("Seri?!\n");
					printf("Tekan enter untuk pulang!\n");
				}
				else if(tangan_lawan == 0){
					(*P).Det.uang = (*P).Det.uang + bet;
					(*J).minutes = (*J).minutes + 30;
					(*J).total = (*J).total + 30;
					scanf("%c", &opsi);
					printf("Menang woiii!\n");
					printf("Tekan enter untuk pulang!\n");
				}
				else{
					(*P).Det.uang = (*P).Det.uang - bet;
					(*J).minutes = (*J).minutes + 30;
					(*J).total = (*J).total + 30;
					scanf("%c", &opsi);
					printf("MASIH BERANI LAGI GAK?\n");
					printf("Tekan enter untuk pulang!\n");
				}
			}
		}
		//kurang duit
		else{
			scanf("%c", &opsi);
			printf("Miskin ga usah sok maen ke kasino!\n");
			printf("Tekan enter untuk pulang!\n");
		}
	}
	//Lawan YUMEKO JABAMI
	if (opsi == '2'){
		//punya cukup duit kita maen
		if( (*P).Det.uang >= 100){
			system("cls");
			printf("KAKEGURUI INTERFACE\n");
			printf("Batu gunting kertas melawan YUMEKO JABAMI\n");
			printf("\n");
			printf("Uangmu: %d",(*P).Det.uang);
			printf("\n");
			printf("Jadi, kali ini kita bertaruh berapa (100-200): ");
			scanf("%d", &bet);
			while(bet < 100 || bet > 200){
				system("cls");
				printf("KAKEGURUI INTERFACE\n");
				printf("Batu gunting kertas biasa\n");
				printf("\n");
				printf("Uangmu: %d",(*P).Det.uang);
				printf("\n");
				printf("Jadi, kali ini kita bertaruh berapa (100-200): ");
				scanf("%d", &bet);
			}
			printf("\n");
			printf("Masukkan tangan andalanmu!\n");
			printf(" 0 -> 1 | 1 -> 2 | 2 -> 0\n");
			printf("Masukkan 0, 1, atau 2! Salah memasukkan, peluang dipanggil POCHI jadi besar~\n");
			printf("Tanganmu: ");
			scanf("%d", &tangan);
			tangan = tangan%3; //antisipasi
			if( tangan == 0){
				
				x = rand()%100;
				//Yumeko menang saat tangan_lawan = 2
				if( x < 90){
					tangan_lawan = 2;
				}
				else if( x >= 90 && x < 95){
					tangan_lawan = 0;
				}
				else if( x >= 95 && x <100){
					tangan_lawan = 1;
				}
				printf("Tangan YUMEKO: %d", tangan_lawan);
				printf("\n");
				
				
				
				if(tangan_lawan == 0){
					(*J).minutes = (*J).minutes + 30;
					(*J).total = (*J).total + 30;
					scanf("%c", &opsi);
					printf("Ara, seri?!\n");
					printf("Tekan enter untuk poker face!\n");
				}
				else if(tangan_lawan == 1){
					(*P).Det.uang = (*P).Det.uang + bet;
					(*J).minutes = (*J).minutes + 30;
					(*J).total = (*J).total + 30;
					scanf("%c", &opsi);
					printf("Omedetto!\n");
					printf("Tekan enter untuk ara-ara!\n");
				}
				else{
					(*P).Det.uang = (*P).Det.uang - bet;
					(*J).minutes = (*J).minutes + 30;
					(*J).total = (*J).total + 30;
					scanf("%c", &opsi);
					printf("Sanggupkah kamu membayar kekalahanmu, onii-san?\n");
					printf("Tekan enter untuk menangis dan lari!\n");
				}
			}
			else if(tangan == 1){
				
				
				x = rand()%100;
				//Yumeko menang saat tangan_lawan = 0
				if( x < 90){
					tangan_lawan = 0;
				}
				else if( x >= 90 && x < 95){
					tangan_lawan = 1;
				}
				else if( x >= 95 && x <100){
					tangan_lawan = 2;
				}
				printf("Tangan YUMEKO: %d", tangan_lawan);
				printf("\n");
				
				
				if(tangan_lawan == 1){
					(*J).minutes = (*J).minutes + 30;
					(*J).total = (*J).total + 30;
					scanf("%c", &opsi);
					printf("Ara, seri?!\n");
					printf("Tekan enter untuk poker face!\n");
				}
				else if(tangan_lawan == 2){
					(*P).Det.uang = (*P).Det.uang + bet;
					(*J).minutes = (*J).minutes + 30;
					(*J).total = (*J).total + 30;
					scanf("%c", &opsi);
					printf("Omedetto!\n");
					printf("Tekan enter untuk ara-ara!\n");
				}
				else{
					(*P).Det.uang = (*P).Det.uang - bet;
					(*J).minutes = (*J).minutes + 30;
					(*J).total = (*J).total + 30;
					scanf("%c", &opsi);
					printf("Sanggupkah kamu membayar kekalahanmu, onii-san?\n");
					printf("Tekan enter untuk menangis dan lari!\n");
				}
			}
			else{
				
				x = rand()%100;
				//Yumeko menang saat tangan_lawan = 1
				if( x < 90){
					tangan_lawan = 1;
				}
				else if( x >= 90 && x < 95){
					tangan_lawan = 2;
				}
				else if( x >= 95 && x <100){
					tangan_lawan = 0;
				}
				printf("Tangan YUMEKO: %d", tangan_lawan);
				printf("\n");
				
				
				if(tangan_lawan == 2){
					(*J).minutes = (*J).minutes + 30;
					(*J).total = (*J).total + 30;
					scanf("%c", &opsi);
					printf("Ara, seri?!\n");
					printf("Tekan enter untuk poker face!\n");
				}
				else if(tangan_lawan == 0){
					(*P).Det.uang = (*P).Det.uang + bet;
					(*J).minutes = (*J).minutes + 30;
					(*J).total = (*J).total + 30;
					scanf("%c", &opsi);
					printf("Omedetto!\n");
					printf("Tekan enter untuk ara-ara!\n");
				}
				else{
					(*P).Det.uang = (*P).Det.uang - bet;
					(*J).minutes = (*J).minutes + 30;
					(*J).total = (*J).total + 30;
					scanf("%c", &opsi);
					printf("Sanggupkah kamu membayar kekalahanmu, onii-san?\n");
					printf("Tekan enter untuk menangis dan lari!\n");
				}
			}
		}
		//kurang duit
		else{
			scanf("%c", &opsi);
			printf("Ara, ternyata uangmu ngga cukup buat melawanku ya?\n");
			printf("Tekan enter untuk KABUR!\n");
		}
	}
	if (opsi == '3'){
		//jika uang cukup langsung GACHA
		if( (*P).Det.uang >= 50){
			
			(*P).Det.uang = (*P).Det.uang - 50;
			
			x = rand()%100;
			
			if( x < 40){
				(*P).Det.uang = (*P).Det.uang + 10;
				scanf("%c", &opsi);
				printf("Uangmu berkurang 40\n");
				printf("Tekan enter untuk pulang!\n");
			}
			else if(x >= 40 && x < 80){
				(*P).Det.uang = (*P).Det.uang + 25;
				scanf("%c", &opsi);
				printf("Uangmu berkurang 25\n");
				printf("Tekan enter untuk pulang!\n");
			}
			else if(x >= 80 && x < 94){
				(*P).Det.uang = (*P).Det.uang + 50;
				scanf("%c", &opsi);
				printf("Uangmu TETAP\n");
				printf("Tekan enter untuk pulang!\n");
			}
			else if( x >= 94 && x < 97){
				(*P).Det.uang = (*P).Det.uang + 75;
				scanf("%c", &opsi);
				printf("Uangmu BERTAMBAH 25, SELAMAT\n");
				printf("Tekan enter untuk pulang!\n");
			}
			else if( x >= 97 && x <99){
				(*P).Det.uang = (*P).Det.uang + 100;
				scanf("%c", &opsi);
				printf("Uangmu BERTAMBAH 50, SELAMAT\n");
				printf("Tekan enter untuk pulang!\n");
			}
			else if( x == 99){
				(*P).Det.uang = (*P).Det.uang + 200;
				scanf("%c", &opsi);
				printf("JACKPOT UANGMU BERTAMBAH 150\n");
				printf("Tekan enter untuk pulang!\n");
			}
			(*J).minutes = (*J).minutes + 30;
			(*J).total = (*J).total + 30;
		}
		else{
			scanf("%c", &opsi);
			printf("Uangmu tidak cukupi untuk GACHA ini\n");
			printf("Tekan enter untuk pulang!\n");
		}
	}
	if (opsi == '4'){
		if( (*P).Det.uang >= 200){
			
			(*P).Det.uang = (*P).Det.uang - 200;
			
			kayu = rand()%100 + 1;
			batu = rand()%20 + 1;
			besi = rand()%10 + 1;
			
			(*P).Det.kayu = (*P).Det.kayu + kayu;
			(*P).Det.batu = (*P).Det.batu + batu;
			(*P).Det.besi = (*P).Det.besi + besi;
			
			(*J).minutes = (*J).minutes + 30;
			(*J).total = (*J).total + 30;
			
			scanf("%c", &opsi);
			printf("Kayumu bertambah: %d\n", kayu);
			printf("Batumu bertambah: %d\n", batu);
			printf("Besimu bertambah: %d\n", besi);
			printf("Tekan enter untuk pulang!\n");
		}
		else{
			scanf("%c", &opsi);
			printf("Uangmu tidak cukup untuk GACHA ini\n");
			printf("Tekan enter untuk pulang!\n");
		}
	}
	
}
