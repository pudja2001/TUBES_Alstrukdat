#include <stdio.h>
#include <stdlib.h>

#include "player.c"

int main(){
	PLAYER P;
	
	CreatePlayer(&P);
	system("cls");
	printf("Kimi no namae wa: ");
	ShowPlayer(P);
	
	return 0;
}
