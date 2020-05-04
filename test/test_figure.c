#include "../src/board.h"
#include "../src/figure.h"
#include "../src/macro.h"
#include "../src/movements.h"
#include "../src/rules.h"
#include "../thirdparty/ctest.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

char** board_test = NULL;

// board_test = Fill_Board(board_test);

// board_test = (char**)malloc(8 * sizeof(char*));
// for (short int i = 0; i < 8; i++) {
//     board_test[i] = (char*)malloc(8 * sizeof(char));
// }
// for (short int i = 0; i < 8; i++) {
//     for (short int j = 0; j < 8; j++) {
//         board_test[i][j] = ' ';
//     }
// }
// for (int j = 0; j < 8; j++) {
//     board_test[1][j] = 'P';
// }
// for (int j = 0; j < 8; j++) {
//     board_test[6][j] = 'p';
// }
// for (short int i = 0; i < 8; i = i + 7) {
//     board[i][0] = 'R' + (('a' - 'A') * i / 7);
//     board[i][1] = 'N' + (('a' - 'A') * i / 7);
//     board[i][2] = 'B' + (('a' - 'A') * i / 7);
//     board[i][3] = 'Q' + (('a' - 'A') * i / 7);
//     board[i][4] = 'K' + (('a' - 'A') * i / 7);
//     board[i][5] = 'B' + (('a' - 'A') * i / 7);
//     board[i][6] = 'N' + (('a' - 'A') * i / 7);
//     board[i][7] = 'R' + (('a' - 'A') * i / 7);
// }

CTEST(FIGURE, STEP_ROOK)
{
    ASSERT_FALSE(Step_Rook(true, board_test, '-', 7, 0, 5, 0));
}

CTEST(FIGURE, STEP_ROOK)
{
    ASSERT_FALSE(Step_Rook(true, board_test, '-', 7, 3, 5, 3));
}

CTEST(FIGURE, STEP_ROOK)
{
    board_test[6][0] = ' ';
    ASSERT_TRUE(Step_Rook(true, board_test, '-', 7, 0, 5, 0));
    board_test[6][0] = 'p';
}

CTEST(FIGURE, STEP_ROOK)
{
    board_test[6][1] = ' ';
    ASSERT_FALSE(Step_Rook(true, board_test, '-', 7, 0, 6, 1));
    board_test[6][0] = 'p';
}

// for (short int i = 0; i < 8; i++) {
//     free(board[i]);
// }
//free(board);