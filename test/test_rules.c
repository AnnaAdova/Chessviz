#include "board.h"
#include "rules.h"
#include "ctest.h"

CTEST(RULES, RANGE_INCORRECT_ACTION)
{
    ASSERT_FALSE(Check_Range(true, NULL, '.', 7, 0, 5, 0));
}

CTEST(RULES, RANGE_INCORRECT_START_COLUMN)
{
    ASSERT_FALSE(Check_Range(true, NULL, '-', 7, -1, 5, 0));
    ASSERT_FALSE(Check_Range(true, NULL, '-', 7, 9, 5, 0));
}

CTEST(RULES, RANGE_INCORRECT_START_ROW)
{
    ASSERT_FALSE(Check_Range(true, NULL, '-', -1, 0, 5, 0));
    ASSERT_FALSE(Check_Range(true, NULL, '-', 9, 0, 5, 0));
}

CTEST(RULES, RANGE_INCORRECT_FINALY_COLUMN)
{
    ASSERT_FALSE(Check_Range(true, NULL, '-', 7, 0, 5, -1));
    ASSERT_FALSE(Check_Range(true, NULL, '-', 7, 0, 5, 9));
}

CTEST(RULES, RANGE_INCORRECT_FINALY_ROW)
{
    ASSERT_FALSE(Check_Range(true, NULL, '-', 7, 0, -1, 0));
    ASSERT_FALSE(Check_Range(true, NULL, '-', 7, 0, 9, 0));
}

CTEST(RULES, RANGE_ALL_CORRECT)
{
    ASSERT_TRUE(Check_Range(true, NULL, '-', 7, 0, 5, 0));
    ASSERT_TRUE(Check_Range(true, NULL, 'x', 7, 0, 5, 0));
}

CTEST(RULES, START_FIGURE_INCORRECT)
{
    char **board_test = NULL;
    board_test = Fill_Board(board_test);
    ASSERT_FALSE(Check_Start_Figure(true, board_test, '-', 5, 0, 4, 0));
    ASSERT_FALSE(Check_Start_Figure(true, board_test, '-', 1, 0, 2, 0));
    ASSERT_FALSE(Check_Start_Figure(false, board_test, '-', 7, 0, 6, 0));
}

CTEST(RULES, START_FIGURE_CORRECT)
{
    char **board_test = NULL;
    board_test = Fill_Board(board_test);
    ASSERT_TRUE(Check_Start_Figure(true, board_test, '-', 6, 0, 5, 0));
    ASSERT_TRUE(Check_Start_Figure(false, board_test, '-', 1, 0, 2, 0));
}

CTEST(RULES, FINALY_FIGURE_INCORRECT)
{
    char **board_test = NULL;
    board_test = Fill_Board(board_test);
    ASSERT_FALSE(Check_Finaly_Figure(true, board_test, '-', 7, 0, 6, 0));
    ASSERT_FALSE(Check_Finaly_Figure(true, board_test, 'x', 7, 0, 6, 0));
    ASSERT_FALSE(Check_Finaly_Figure(true, board_test, 'x', 6, 0, 5, 0));
    ASSERT_FALSE(Check_Finaly_Figure(false, board_test, '-', 0, 0, 1, 0));
    ASSERT_FALSE(Check_Finaly_Figure(false, board_test, 'x', 0, 0, 1, 0));
    ASSERT_FALSE(Check_Finaly_Figure(false, board_test, 'x', 1, 0, 2, 0));
}

CTEST(RULES, FINALY_FIGURE_CORRECT)
{
    char **board_test = NULL;
    board_test = Fill_Board(board_test);
    ASSERT_TRUE(Check_Finaly_Figure(true, board_test, '-', 6, 0, 5, 0));
    board_test[5][1] = 'P';
    ASSERT_TRUE(Check_Finaly_Figure(true, board_test, 'x', 6, 0, 5, 1));
    ASSERT_TRUE(Check_Finaly_Figure(false, board_test, '-', 1, 0, 2, 0));
    board_test[2][1] = 'p';
    ASSERT_TRUE(Check_Finaly_Figure(false, board_test, 'x', 1, 0, 2, 1));
}

