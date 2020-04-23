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
    int k = 1;
    while (1) {
        Print_Board(board);
        printf("\nexit?-0=yes\n");
        scanf("%d", &k);
        if (k == 0) {
            break;
        }
        Movement(board, white);
        if (white == true) {
            white = false;
        } else {
            white = true;
        }
    }
    return 0;
}