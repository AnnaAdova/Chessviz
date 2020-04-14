#include "board.h"

char** Fill_Board(char **board)
{
    board= (char**) malloc (8 *sizeof(char*));
    for(short int i=0;i<8;i++)
    {
        board[i]=(char*) malloc (8 *sizeof(char));
    }
    for(short int i=0;i<8;i++)
    {
        for(short int j=0;j<8;j++)
        {
            board[i][j]=' ';
        }
    }
    for (int j = 0; j < 8; j++) {
        board[1][j] = 'P';
    };
    for (int j = 0; j < 8; j++) {
        board[6][j] = 'p';
    };
    board[0][0] = 'R';
    board[0][1] = 'N';
    board[0][2] = 'B';
    board[0][3] = 'Q';
    board[0][4] = 'K';
    board[0][5] = 'B';
    board[0][6] = 'N';
    board[0][7] = 'R';
    board[7][0] = 'r';
    board[7][1] = 'n';
    board[7][2] = 'b';
    board[7][3] = 'q';
    board[7][4] = 'k';
    board[7][5] = 'b';
    board[7][6] = 'n';
    board[7][7] = 'r';
    return board;
}

void Print_Board(char **board)
{
    for (int i = 0; i < 8; i++) {
        printf(" %d ", i + 1);
        for (int j = 0; j < 8; j++) {
            printf("[ %c ]", board[i][j]);
        };
        printf("\n\n");
    };
    printf(" ");
    for (int i = 0; i < 8; i++) {
        printf("    %c", 'a' + i);
    }
    printf("\n");
}