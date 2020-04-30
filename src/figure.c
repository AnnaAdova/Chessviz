#include "figure.h"
#include "macro.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool Movement_Figure(RECEIVED_SET_VARIABLE_TO_CHECK)
{
    if ((board[start_row][start_column] == 'p')
        || (board[start_row][start_column] == 'P')) {
        if (Step_Pawns(PASSED_SET_VARIABLE_TO_CHECK) == true) {
            return true;
        }
    } else {
        if ((board[start_row][start_column] == 'r')
            || (board[start_row][start_column] == 'R')) {
            if (Step_Rook(PASSED_SET_VARIABLE_TO_CHECK) == true) {
                printf("\tprohel\t");
                return true;
            }
        } else {
            if ((board[start_row][start_column] == 'n')
                || (board[start_row][start_column] == 'N')) {
                if (Step_Knight(PASSED_SET_VARIABLE_TO_CHECK) == true) {
                    return true;
                }
            } else {
                if ((board[start_row][start_column] == 'b')
                    || (board[start_row][start_column] == 'B')) {
                    if (Step_Bishop(PASSED_SET_VARIABLE_TO_CHECK) == true) {
                        return true;
                    }
                } else {
                    if ((board[start_row][start_column] == 'k')
                        || (board[start_row][start_column] == 'K')) {
                        if (Step_King(PASSED_SET_VARIABLE_TO_CHECK) == true) {
                            return true;
                        }
                    } else {
                        if ((board[start_row][start_column] == 'q')
                            || (board[start_row][start_column] == 'Q')) {
                            if (Step_Queen(PASSED_SET_VARIABLE_TO_CHECK)
                                == true) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

//попробовать сделать функцию проверки препятствий отдельную
bool Step_Rook(RECEIVED_SET_VARIABLE_TO_CHECK)
{
    if ((start_column != finaly_column) && (start_row != finaly_row)) {
        printf("ravenstvo");
        return false;
    }
    if (start_column - finaly_column < 0) {
        for (short int i = start_column + 1; i < finaly_column; i++) {
            printf("1)%c", board[start_row][i]);
            if (board[start_row][i] != ' ') {
                printf("gorizontal");
                return false;
            }
        }
    } else {
        if (start_column - finaly_column > 0) {// попробовать что то придумать чтобы уменьшить условие цикла
            for (short int i = finaly_column + 1; i < start_column; i++) {
                printf("2)%c", board[start_row][i]);
                if (board[start_row][i] != ' ') {
                    printf("gorizontal");
                    return false;
                }
            }
        } else {
            if (start_row - finaly_row < 0) {
                for (short int i = start_row + 1; i < finaly_row; i++) {
                    printf("3)%c", board[i][start_column]);
                    if (board[i][start_column] != ' ') {
                        printf("vertical");
                        return false;
                    }
                }
            } else {
                if (start_row - finaly_row > 0) {
                    for (short int i = finaly_row + 1; i < start_row; i++) {
                        printf("4)%d%d%c", i,start_column,board[i][start_column]);
                        if (board[i][start_column] != ' ') {
                            printf("vertical");
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

bool Step_Knight(RECEIVED_SET_VARIABLE_TO_CHECK)
{
    return false;
}
bool Step_Bishop(RECEIVED_SET_VARIABLE_TO_CHECK)
{
    return false;
}
bool Step_King(RECEIVED_SET_VARIABLE_TO_CHECK)
{
    return false;
}
bool Step_Queen(RECEIVED_SET_VARIABLE_TO_CHECK)
{
    return false;
};

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