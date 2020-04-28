#include "board.h"

#include <stdio.h>
#include <stdlib.h>

char** Fill_Board(char** board)
{
    board = (char**)malloc(8 * sizeof(char*));
    for (short int i = 0; i < 8; i++) {
        board[i] = (char*)malloc(8 * sizeof(char));
    }
    for (short int i = 0; i < 8; i++) {
        for (short int j = 0; j < 8; j++) {
            board[i][j] = ' ';
        }
    }
    for (int j = 0; j < 8; j++) {
        board[1][j] = 'P';
    };
    for (int j = 0; j < 8; j++) {
        board[6][j] = 'p';
    };
    for (short int i = 0; i < 8; i = i + 7) {
        board[i][0] = 'R' + (('a' - 'A') * i / 7);
        board[i][1] = 'N' + (('a' - 'A') * i / 7);
        board[i][2] = 'B' + (('a' - 'A') * i / 7);
        board[i][3] = 'Q' + (('a' - 'A') * i / 7);
        board[i][4] = 'K' + (('a' - 'A') * i / 7);
        board[i][5] = 'B' + (('a' - 'A') * i / 7);
        board[i][6] = 'N' + (('a' - 'A') * i / 7);
        board[i][7] = 'R' + (('a' - 'A') * i / 7);
    }
    return board;
}

void Print_Board(char** board)
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