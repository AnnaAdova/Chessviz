#ifndef RULES_H

#define RULES_H

#define PASSED_SET_TYPE_TO_CHECK \
    char**, const char, const int, const int, const int, const int

#define PASSED_SET_VARIABLE_TO_CHECK \
    board, action, start_row, start_column, finaly_row, finaly_column

#define RECEIVED_SET_VARIABLE_TO_CHECK                    \
    char **board, const char action, const int start_row, \
            const int start_column, const int finaly_row, \
            const int finaly_column

bool Check_Correctly(const bool, PASSED_SET_TYPE_TO_CHECK);
bool Check_Range(PASSED_SET_TYPE_TO_CHECK);
bool Check_Start_Figure(const bool, PASSED_SET_TYPE_TO_CHECK);
bool Check_Finaly_Figure(const bool, PASSED_SET_TYPE_TO_CHECK);

#endif