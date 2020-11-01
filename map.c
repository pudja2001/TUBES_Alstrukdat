#include "map.h"

void ShowMap(MAP M){
	system("cls");
	int i, j;
	if(MAP.Map == 1){
		i = 0;
		j = 0;
		while(i < 7){
			j = 0;
			while(j < 7){
				printf("%c", MAP.M[i][j].karakter);
				j = j + 1;
			}
			printf("\n");
			i = i + 1;
		}
	}
	else if(MAP.Map == 2){
		i = 0;
		j = 7;
		while(i < 7){
			j = 7;
			while(j < 14){
				printf("%c", MAP.M[i][j].karakter);
				j = j + 1;
			}
			printf("\n");
			i = i + 1;
		}
	}
	else if(MAP.Map == 3){
		i = 7;
		j = 7;
		while(i < 14){
			j = 7;
			while(j < 14){
				printf("%c", MAP.M[i][j].karakter);
				j = j + 1;
			}
			printf("\n");
			i = i + 1;
		}
	}
	else if(MAP.Map == 4){
		i = 7;
		j = 0;
		while(i < 14){
			j = 0;
			while(j < 7){
				printf("%c", MAP.M[i][j].karakter);
				j = j + 1;
			}
			printf("\n");
			i = i + 1;
		}
	}
}

