#include "figure.h"
#include "macro.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool Movement_Figure(RECEIVED_SET_VARIABLE_TO_CHECK)
{
    if (white == true) {
        if (board[start_row][start_column] == 'p') {
            if (Step_Pawns(PASSED_SET_VARIABLE_TO_CHECK) == true) {
                return true;
            }
        }
    } else {
        if (board[start_row][start_column] == 'P') {
            if (Step_Pawns(PASSED_SET_VARIABLE_TO_CHECK) == true) {
                return true;
            }
        }
    }
    return false;
}

bool Step_Pawns(RECEIVED_SET_VARIABLE_TO_CHECK)
{
    if (white == true) {
        if (action == '-') {
            if ((start_row - finaly_row) != 1) {
                if (start_row != 6) {
                    return false;
                } else {
                    if ((start_row - finaly_row) != 2) {
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
                if ((start_row - finaly_row) != 1) {
                    return false;
                } else {
                    if (((start_column - finaly_column) != 1)
                        && ((finaly_column - start_column) != 1)) {
                        return false;
                    } else {
                        if ((board[finaly_row][finaly_column] > 'Z')
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
    } else {
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
    return false;
}