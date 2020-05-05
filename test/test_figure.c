#include "../src/board.h"
#include "../src/board.c"
#include "../src/figure.h"
#include "../src/figure.c"
#include "../thirdparty/ctest.h"

CTEST(FIGURE, STEP_ROOK_OBSTACLE)
{
    char **board_test = NULL;
    board_test = Fill_Board(board_test);
    ASSERT_FALSE(Step_Rook(true, board_test, '-', 7, 0, 5, 0));
}

CTEST(FIGURE, STEP_ROOK_NOT_ROOK)
{
    char **board_test = NULL;
    board_test = Fill_Board(board_test);
    ASSERT_FALSE(Step_Rook(true, board_test, '-', 7, 3, 5, 3));
}

CTEST(FIGURE, STEP_ROOK_NORMAL_STEP)
{
    char **board_test = NULL;
    board_test = Fill_Board(board_test);
    board_test[6][0] = ' ';
    ASSERT_TRUE(Step_Rook(true, board_test, '-', 7, 0, 5, 0));
}

CTEST(FIGURE, STEP_ROOK_DIOGONAL)
{
    char **board_test = NULL;
    board_test = Fill_Board(board_test);
    board_test[6][1] = ' ';
    ASSERT_FALSE(Step_Rook(true, board_test, '-', 7, 0, 6, 1));
}

CTEST(FIGURE, STEP_ROOK_CUT)
{
    char **board_test = NULL;
    board_test = Fill_Board(board_test);
    board_test[7][1] = 'P';
    ASSERT_TRUE(Step_Rook(true, board_test, '-', 7, 0, 7, 1));
}