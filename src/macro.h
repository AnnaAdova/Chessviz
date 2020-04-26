#ifndef MACRO_H

#define MACRO_H

#include <stdbool.h>

#define PASSED_SET_TYPE_TO_CHECK \
    bool, char**, const char, const int, const int, const int, const int

#define PASSED_SET_VARIABLE_TO_CHECK \
    white, board, action, start_row, start_column, finaly_row, finaly_column

#define RECEIVED_SET_VARIABLE_TO_CHECK                                \
    bool white, char **board, const char action, const int start_row, \
            const int start_column, const int finaly_row,             \
            const int finaly_column

#endif