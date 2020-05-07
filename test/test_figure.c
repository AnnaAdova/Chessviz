#include "board.h"
#include "board.c"
#include "figure.h"
#include "figure.c"
#include "ctest.h"

CTEST(FIGURE, STEP_ROOK_OBSTACLE)
{
    char **board_test = NULL;
    board_test = Fill_Board(board_test);
    ASSERT_FALSE(Step_Rook(true, board_test, '-', 7, 0, 5, 0));
}

CTEST(FIGURE, STEP_ROOK_CORRECT)
{
    char **board_test = NULL;
    board_test = Fill_Board(board_test);
    board_test[6][0] = ' ';
    ASSERT_TRUE(Step_Rook(true, board_test, '-', 7, 0, 5, 0));
    board_test[1][0] = ' ';
}

CTEST(FIGURE, STEP_ROOK_DIOGONAL)
{
    char **board_test = NULL;
    board_test = Fill_Board(board_test);
    board_test[6][1] = ' ';
    ASSERT_FALSE(Step_Rook(true, board_test, '-', 7, 0, 6, 1));
}

CTEST(FIGURE, STEP_KNIGHT_INCORRECT_STEP)
{
    char **board_test = NULL;
    board_test = Fill_Board(board_test);
    board_test[6][1] = ' ';
    ASSERT_FALSE(Step_Knight(true, board_test, '-', 7, 1, 6, 1));
    board_test[6][2] = ' ';
    ASSERT_FALSE(Step_Knight(true, board_test, '-', 7, 1, 6, 2));
    board_test[7][2] = ' ';
    ASSERT_FALSE(Step_Knight(true, board_test, '-', 7, 1, 7, 2));
}

CTEST(FIGURE, STEP_KNIGHT_CORRECT_STEP)
{
    char **board_test = NULL;
    board_test = Fill_Board(board_test);
    ASSERT_TRUE(Step_Knight(true, board_test, '-', 7, 1, 5, 2));
}

CTEST(FIGURE, STEP_BISHOP_CORRECT_STEP)
{
    char **board_test = NULL;
    board_test = Fill_Board(board_test);
    board_test[6][3] = ' ';
    ASSERT_TRUE(Step_Bishop(true, board_test, '-', 7, 2, 5, 4));
}

CTEST(FIGURE, STEP_BISHOP_INCORRECT_STEP)
{
    char **board_test = NULL;
    board_test = Fill_Board(board_test);
    board_test[7][3] = ' ';
    ASSERT_FALSE(Step_Bishop(true, board_test, '-', 7, 2, 5, 2));
    ASSERT_FALSE(Step_Bishop(true, board_test, '-', 7, 2, 7, 3));
}

CTEST(FIGURE, STEP_QUENN_OBSTACLE)
{
    char **board_test = NULL;
    board_test = Fill_Board(board_test);
    ASSERT_FALSE(Step_Queen(true, board_test, '-', 7, 3, 6, 5));
}

CTEST(FIGURE, STEP_QUENN_INCORRECT_STEP)
{
    char **board_test = NULL;
    board_test = Fill_Board(board_test);
    board_test[6][3] = ' ';
    ASSERT_FALSE(Step_Queen(true, board_test, '-', 7, 3, 6, 5));
}

CTEST(FIGURE, STEP_QUENN_CORRECT_STEP)
{
    char **board_test = NULL;
    board_test = Fill_Board(board_test);
    board_test[5][4] = 'q';
    ASSERT_TRUE(Step_Queen(true, board_test, '-', 5, 4, 5, 3));
    ASSERT_TRUE(Step_Queen(true, board_test, '-', 5, 4, 3, 4));
    ASSERT_TRUE(Step_Queen(true, board_test, '-', 5, 4, 6, 3));
}

CTEST(FIGURE, STEP_KING_CORRECT_STEP)
{
    char **board_test = NULL;
    board_test = Fill_Board(board_test);
    board_test[5][4] = 'k';
    ASSERT_TRUE(Step_Queen(true, board_test, '-', 5, 4, 5, 3));
    ASSERT_TRUE(Step_Queen(true, board_test, '-', 5, 4, 3, 4));
    ASSERT_TRUE(Step_Queen(true, board_test, '-', 5, 4, 6, 3));
}

CTEST(FIGURE, STEP_KING_INCORRECT_STEP)
{
    char **board_test = NULL;
    board_test = Fill_Board(board_test);
    board_test[5][4] = 'k';
    ASSERT_FALSE(Step_King(true, board_test, '-', 5, 4, 5, 1));
}

CTEST(FIGURE, STEP_PAWNS_INCORRECT_STEP)
{
    char **board_test = NULL;
    board_test = Fill_Board(board_test);
    board_test[5][4] = 'p';
    ASSERT_FALSE(Step_Pawns(true, board_test, '-', 5, 4, 3, 4));
    ASSERT_FALSE(Step_Pawns(true, board_test, '-', 5, 4, 5, 3));
    ASSERT_FALSE(Step_Pawns(true, board_test, '-', 5, 4, 6, 4));
    ASSERT_FALSE(Step_Pawns(true, board_test, '-', 5, 4, 4, 3));
}

CTEST(FIGURE, STEP_PAWNS_CORRECT_STEP)
{
    char **board_test = NULL;
    board_test = Fill_Board(board_test);
    ASSERT_TRUE(Step_Pawns(true, board_test, '-', 6, 0, 5, 0));
    ASSERT_TRUE(Step_Pawns(true, board_test, '-', 6, 0, 4, 0));
}

CTEST(FIGURE, STEP_PAWNS_CUT)
{
    char **board_test = NULL;
    board_test = Fill_Board(board_test);
    board_test[5][0] = 'P';
    board_test[5][1] = 'P';
    ASSERT_FALSE(Step_Pawns(true, board_test, 'x', 6, 0, 5, 0));
    ASSERT_TRUE(Step_Pawns(true, board_test, 'x', 6, 0, 5, 1));
}