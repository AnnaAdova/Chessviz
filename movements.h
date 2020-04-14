#ifndef MOVEMENTS_H

#define MOVEMENTS_H

#include "black_figure.h"
#include "rules.h"
#include "white_figure.h"

char** White_Movement(char**, const bool);
char** Black_Movement(char**, const bool);
int Convert_Start_Column(char);
int Convert_Finaly_Column(char);
char** Change_Board(PASSED_SET_TYPE_TO_CHECK);

#endif