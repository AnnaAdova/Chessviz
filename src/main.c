#include "board.h"
#include "figure.h"
#include "macro.h"
#include "movements.h"
#include "rules.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char** board = NULL;
    bool white = true;
    board = Fill_Board(board);
    int key_exit = 1;
    while (1) {
        Print_Board(board);
        printf("\nend game?\n0-yes\nother-no\n");
        scanf("%d", &key_exit);
        if (key_exit == 0) {
            break;
        }
        board = Movement(board, white);
        if (white == true) {
            white = false;
        } else {
            white = true;
        }
    }
    Free_Board(board);
    return 0;
}