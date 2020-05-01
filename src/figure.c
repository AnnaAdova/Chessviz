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

bool Check_Horizontal_Obstacle(RECEIVED_SET_VARIABLE_TO_CHECK)
{
    if (start_column - finaly_column < 0) {
        for (short int i = start_column + 1; i < finaly_column; i++) {
            if (board[start_row][i] != ' ') {
                return true;
            }
        }
    } else {
        if (start_column - finaly_column > 0) {
            for (short int i = finaly_column + 1; i < start_column; i++) {
                if (board[start_row][i] != ' ') {
                    return true;
                }
            }
        }
    }
    return false;
}
bool Check_Vertical_Obstacle(RECEIVED_SET_VARIABLE_TO_CHECK)
{
    if (start_row - finaly_row < 0) {
        for (short int i = start_row + 1; i < finaly_row; i++) {
            if (board[i][start_column] != ' ') {
                return true;
            }
        }
    } else {
        if (start_row - finaly_row > 0) {
            for (short int i = finaly_row + 1; i < start_row; i++) {
                if (board[i][start_column] != ' ') {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Check_Diagonal_Obstacle(RECEIVED_SET_VARIABLE_TO_CHECK)
{
    if (start_column - finaly_column > 0) { // c--
        if (start_row - finaly_row > 0) {
            for (short int i = finaly_row + 1, j = finaly_column + 1;
                 i < start_row;
                 i++, j++) // r-- c--
            {
                if (board[i][j] != ' ') {
                    printf("1)");
                    return true;
                }
            }
        } else {
            for (short int i = start_row + 1, j = start_column + 1;
                 i < finaly_row;
                 i++, j--) // r++ c--
            {
                if (board[i][j] != ' ') {
                    printf("2)");
                    return true;
                }
            }
        }
    } else {                              // c++
        if (start_row - finaly_row > 0) { // r-- c++
            for (short int i = finaly_row + 1, j = start_column + 1;
                 i < start_row;
                 i++, j++) {
                if (board[i][j] != ' ') {
                    printf("3)");
                    return true;
                }
            }
        } else { // r++ c--
            for (short int i = start_row + 1, j = start_column + 1; i < finaly_row;
                 i++, j--) {
                if (board[i][j] != ' ') {
                    printf("4)");
                    return true;
                }
            }
        }
    }
    return false;
}

bool Step_Rook(RECEIVED_SET_VARIABLE_TO_CHECK)
{
    if ((start_column != finaly_column) && (start_row != finaly_row)) {
        return false;
    }
    if (Check_Vertical_Obstacle(PASSED_SET_VARIABLE_TO_CHECK) == true) {
        return false;
    }
    if (Check_Horizontal_Obstacle(PASSED_SET_VARIABLE_TO_CHECK) == true) {
        return false;
    }
    return true;
}

bool Step_Knight(RECEIVED_SET_VARIABLE_TO_CHECK)
{
    return false;
}

bool Step_Bishop(RECEIVED_SET_VARIABLE_TO_CHECK)
{
    // if (((finaly_column - start_column) != 1) //
    //     && (finaly_row - start_row) != 1) {
    //     return false;
    // }
    if (Check_Diagonal_Obstacle(PASSED_SET_VARIABLE_TO_CHECK) == false) {
        return true;
    }
    return false;
}

bool Step_King(RECEIVED_SET_VARIABLE_TO_CHECK)
{
    if ((((finaly_column - start_column) != 1)
         && (start_column - finaly_column) != 1)
        && (((finaly_row - start_row) != 1) && (start_row - finaly_row) != 1)) {
        return false;
    }
    return true;
}
bool Step_Queen(RECEIVED_SET_VARIABLE_TO_CHECK)
{
    if (Check_Diagonal_Obstacle(PASSED_SET_VARIABLE_TO_CHECK) == true) {
        return false;
    }
    if (Check_Vertical_Obstacle(PASSED_SET_VARIABLE_TO_CHECK) == true) {
        return false;
    }
    if (Check_Horizontal_Obstacle(PASSED_SET_VARIABLE_TO_CHECK) == true) {
        return false;
    }
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
                    } else {
                        if (Check_Vertical_Obstacle(
                                    PASSED_SET_VARIABLE_TO_CHECK)
                            == true) {
                            return false;
                        }
                    }
                }
            }
            if (start_column != finaly_column) {
                return false;
            } else {
                return true;
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
                        return true;
                    }
                }
            }
        }
    } else {
        if (action == '-') {
            if ((finaly_row - start_row) != 1) {
                if (start_row != 1) {
                    return false;
                } else {
                    if ((finaly_row - start_row) != 2) {
                        return false;
                    } else {
                        if (Check_Vertical_Obstacle(
                                    PASSED_SET_VARIABLE_TO_CHECK)
                            == true) {
                            return false;
                        }
                    }
                }
            }
            if (start_column != finaly_column) {
                return false;
            } else {
                return true;
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
                        return true;
                    }
                }
            }
        }
    }
    return false;
}