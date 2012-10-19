#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

#define SIZE 19
#define USR_MOV 1
#define AI_MOV 2

int AITurn(short *board);              //return 0 means game continued.
                                       //1 for AI win. -1 for Usr win.
void UsrTurn(short *board);

int main(int ac, char **av){
	short board[SIZE*SIZE];
	int sw;
	printf("This is a Gomoku game. The board is %dX%d.\n", SIZE, SIZE);
	if(ac == 1){
		printf("Choose your color [b,w]:\n");
		scanf("%c",&sw);
	}
	else if(av[1][0] == '-')
		sw = av[1][1];
	else sw = av[1][0];
	while(sw != 'b' && sw != 'B'
			&& sw != 'w' && sw != 'W'){
		printf("Wrong Argument.\n");
		scanf("%c",&sw);
	}
	memset(board, 0, sizeof(board));
	if(sw == 'b' || sw == 'B')
		UsrTurn(board);
	while((sw = AITurn(board)) == 0)
		UsrTurn(board);
	switch(sw){
		case 1:
			printf("You Lose!\n");
			break;
		case 2:
			printf("You Win!\n");
			break;
	}
	return 0;
}

int AITurn(short *board){
	
}

void UsrTurn(short *board){
	int c,l;
	int flag = 0;
	printf("Move?[Line,Column]\n");
	while(flag == 0){
		if(l <= 0 || l > SIZE || c <= 0 || c > SIZE)
			printf("Invalid.\n");
		else if(board[SIZE*(l - 1) + c] != 0)
			printf("Already used.\n");
		scanf("%d%d",&l,&c);
	}
	board[SIZE*(l - 1) + c] = USR_MOV;
	return;
}
