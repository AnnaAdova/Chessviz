#ifndef FIGURE_H

#define FIGURE_H

#include "macro.h"

bool Movement_Figure(PASSED_SET_TYPE_TO_CHECK);
bool Step_Pawns(PASSED_SET_TYPE_TO_CHECK);
bool Step_Rook(PASSED_SET_TYPE_TO_CHECK);
bool Step_Knight(PASSED_SET_TYPE_TO_CHECK);
bool Step_Bishop(PASSED_SET_TYPE_TO_CHECK);
bool Step_King(PASSED_SET_TYPE_TO_CHECK);
bool Step_Queen(PASSED_SET_TYPE_TO_CHECK);
bool Check_Vertical_Obstacle(PASSED_SET_TYPE_TO_CHECK);
bool Check_Horizontal_Obstacle(PASSED_SET_TYPE_TO_CHECK);
bool Check_Diagonal_Obstacle(PASSED_SET_TYPE_TO_CHECK);

#endif