#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "black_figure.h"
#include "macro.h"
#include "movements.h"
#include "rules.h"
#include "white_figure.h"

char** White_Movement(char** board, const bool white)
{
    char temp_input_first, temp_input_second, action;
    int start_row, start_column, finaly_row, finaly_column;
    while (1) {
        printf("\nWhite step:\n");
        scanf("%c %d %c %c %d",
              &temp_input_first,
              &start_row,
              &action,
              &temp_input_second,
              &finaly_row);
        start_column = Convert_Start_Column(temp_input_first);
        finaly_column = Convert_Finaly_Column(temp_input_second);
        start_row--;
        finaly_row--;
        if ((Check_Correctly(white, PASSED_SET_VARIABLE_TO_CHECK)) == true) {
            if ((Movement_White_Figure(PASSED_SET_VARIABLE_TO_CHECK)) == true) {
                board = Change_Board(PASSED_SET_VARIABLE_TO_CHECK);
                break;
            }
        }
    }
    return board;
}

char** Black_Movement(char** board, const bool white)
{
    char temp_input_first, temp_input_second, action;
    int start_row, start_column, finaly_row, finaly_column;
    while (1) {
        printf("\nBlack step:\n");
        scanf("%c %d %c %c %d",
              &temp_input_first,
              &start_row,
              &action,
              &temp_input_second,
              &finaly_row);
        start_column = Convert_Start_Column(temp_input_first);
        finaly_column = Convert_Finaly_Column(temp_input_second);
        start_row--;
        finaly_row--;
        if ((Check_Correctly(white, PASSED_SET_VARIABLE_TO_CHECK)) == true) {
            if ((Movement_Black_Figure(PASSED_SET_VARIABLE_TO_CHECK)) == true) {
                board = Change_Board(PASSED_SET_VARIABLE_TO_CHECK);
                break;
            }
        }
    }
    return board;
}

char** Change_Board(RECEIVED_SET_VARIABLE_TO_CHECK)
{
    board[finaly_row][finaly_column] = board[start_row][start_column];
    board[start_row][start_column] = ' ';
    return board;
}

int Convert_Start_Column(char temp_input_first)
{
    for (short int i = 0; i < 8; i++) {
        if (temp_input_first == 'a' + i) {
            return i;
        }
    }
    return -1;
}

int Convert_Finaly_Column(char temp_input_second)
{
    for (short int i = 0; i < 8; i++) {
        if (temp_input_second == 'a' + i) {
            return i;
        }
    }
    return -1;
}