#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

#define SIZE 19
#define USR_MOV 1
#define AI_MOV 2
#define BLANK 0

int sw;

typedef short elem

int AITurn(elem *board, int ml, int mc);        //return 0 means game continued.
                                                //1 for AI win. -1 for Usr win.
void UsrTurn(elem *board, int *ml, int *mc);

int IndexOf(int line, int col);

void PrintBoard(elem *board);

int main(int ac, char **av){
	elem *board = 0;
	int mid_l, mid_c;
	printf("This is a Gomoku game. The board is of size :%dX%d.\n", SIZE, SIZE);
	if(ac == 1){
		printf("Choose your color [b,w]:\n");
		scanf("%c",&sw);
	}
	sw = tolower(sw);
	else if(av[1][0] == '-')
		sw = av[1][1];
	else sw = av[1][0];
	while(sw != 'b' && sw != 'w'){
		write(stderr, "Wrong Argument.\n");
		scanf("%c",&sw);
		sw = tolower(sw);
	}
	board = (elem*)calloc(sizeof(elem),SIZE*SIZE);
	if(sw == 'b')
		UsrTurn(board, &mid_l, &mid_c);
	while((sw = AITurn(board,mid_l,mid_c)) == 0){
		PrintBoard(board);
		UsrTurn(board, &mid_l, &mid_c);
	}
	switch(sw){
		case 1:
			printf("You Lose!\n");
			break;
		case 2:
			printf("You Win!\n");
			break;
	}
	free(board);
	return 0;
}

int AITurn(elem *board, int ml, int mc){
	
}

void UsrTurn(elem *board, int *ml, int *mc){
	int c,l;
	int flag = 0;
	printf("Move?[Line,Column]\n");
	while(flag == 0){
		if(l <= 0 || l > SIZE || c <= 0 || c > SIZE)
			write(stderr, "Invalid.\n");
		else if(board[IndexOf(l,c)] != 0)
			write(stderr, "Already used.\n");
		scanf("%d%d",&l,&c);
	}
	board[IndexOf(l,c)] = USR_MOV;
	return;
}

int IndexOf(int line, int col){
	return SIZE * (line - 1) + col - 1;
}

void PrintBoard(elem *board){
	int i,j;
	for(i = 0;i < SIZE;++i){
		for(j = 0;j < SIZE;++j){
			switch(board[i * SIZE + j]){
				case BLANK:
					putchar(' ');
					break;
				case AI_MOV:
					if(sw == 'b')
						putchar('O');
					else 
						putchar('X');
					break;
				case USR_MOV:
					if(sw == 'b')
						putchar('X');
					else
						putchar('O');
					break;
			}
		}
		putchar('\n');
	}
}

