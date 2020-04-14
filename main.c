#include "chessviz_library.h"

int main()
{
    char** board = NULL;
    bool white = true;
    board = Fill_Board(board);
    int k = 1;
    while (1) {
        printf("\nexit?-0=yes\n");
        scanf("%d", &k);
        if (k == 0) {
            break;
        }
        Print_Board(board);
        if (white == true) {
            board = White_Movement(board, white);
            white = false;
        } else {
            board = Black_Movement(board, white);
            white = true;
        }
    }
    return 0;
}