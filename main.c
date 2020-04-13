#include "board.h"
#include "board.c"

int main()
{
    char **board=NULL;
    board = Fill_Board(board);
    Print_Board(board);
	return 0;
}