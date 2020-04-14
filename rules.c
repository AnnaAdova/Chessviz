#include "rules.h"

bool Check_Correctly(const bool white, RECEIVED_SET_VARIABLE_TO_CHECK)
{
    if (Check_Range(PASSED_SET_VARIABLE_TO_CHECK) == false) {
        return false;
    } else {
        if (Check_Start_Figure(white, PASSED_SET_VARIABLE_TO_CHECK) == false) {
            return false;
        } else {
            if (Check_Finaly_Figure(white, PASSED_SET_VARIABLE_TO_CHECK)
                == false) {
                return false;
            } else {
                return true;
            }
        }
    }
    return false;
}

bool Check_Start_Figure(const bool white, RECEIVED_SET_VARIABLE_TO_CHECK)
{
    if (white == true) {
        if (board[start_row][start_column] < 'a') {
            return false;
        } else {
            return true;
        }

    } else {
        if ((board[start_row][start_column] > 'Z')
            || (board[start_row][start_column]) == ' ') {
            return false;
        } else {
            return true;
        }
    }
    return false;
}

bool Check_Finaly_Figure(const bool white, RECEIVED_SET_VARIABLE_TO_CHECK)
{
    if (white == true) {
        if (action == '-') {
            if (board[finaly_row][finaly_column] != ' ') {
                return false;
            } else {
                return true;
            }
        } else {
            if (action == 'x') {
                if ((board[finaly_row][finaly_column] > 'Z')
                    || (board[finaly_row][finaly_column] == ' ')) {
                    return false;
                } else {
                    return true;
                }
            }
        }
    } else {
        if (action == '-') {
            if (board[finaly_row][finaly_column] != ' ') {
                return false;
            } else {
                return true;
            }
        } else {
            if (action == 'x') {
                if ((board[finaly_row][finaly_column] < 'a')
                    || (board[finaly_row][finaly_column] == ' ')) {
                    return false;
                } else {
                    return true;
                }
            }
        }
    }

    return false;
}

bool Check_Range(RECEIVED_SET_VARIABLE_TO_CHECK)
{
    if ((action != '-') && (action != 'x')) {
        return false;
    } else {
        if ((start_row < 0) || (start_row > 7) || (start_column < 0)
            || (start_column > 7) || (finaly_row < 0) || (finaly_row > 7)
            || (finaly_column < 0) || (finaly_column > 7)) {
            return false;
        } else {
            return true;
        }
    }
    return false;
}