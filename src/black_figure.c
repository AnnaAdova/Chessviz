#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "black_figure.h"
#include "macro.h"

bool Movement_Black_Figure(RECEIVED_SET_VARIABLE_TO_CHECK)
{
    if (board[start_row][start_column] == 'P') {
        if (Step_Black_Pawns(PASSED_SET_VARIABLE_TO_CHECK) == true) {
            return true;
        }
    }
    return false;
}

bool Step_Black_Pawns(RECEIVED_SET_VARIABLE_TO_CHECK)
{
    if (action == '-') {
        if ((finaly_row - start_row) != 1) {
            if (start_row != 1) {
                return false;
            } else {
                if ((finaly_row - start_row) != 2) {
                    return false;
                }
            }
        }
        if (start_column != finaly_column) {
            return false;
        } else {
            if (board[finaly_row][finaly_column] != ' ') {
                return false;
            } else {
                return true;
            }
        }
    } else {
        if (action == 'x') {
            if ((finaly_row - start_row) != 1) {
                return false;
            } else {
                if (((start_column - finaly_column) != 1)
                    && ((finaly_column - start_column) != 1)) {
                    return false;
                } else {
                    if ((board[finaly_row][finaly_column] < 'a')
                        || (board[finaly_row][finaly_column] == ' ')) {
                        return false;
                    } else {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}