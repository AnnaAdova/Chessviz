#include "white_figure.h"

bool Movement_White_Figure(RECEIVED_SET_VARIABLE_TO_CHECK )
{
    if(board[start_row][start_column] == 'p')
    {
        if(Step_White_Pawns(PASSED_SET_VARIABLE_TO_CHECK) == true)
        {
            return true;
        }
    }
    return false;
}

bool Step_White_Pawns(RECEIVED_SET_VARIABLE_TO_CHECK )
{
    if(action == '-')
    {
        if( (start_row-finaly_row) != 1 )
        {
            if(start_row != 6)
            {
                return false;
            }
            else
            {
                if( (start_row-finaly_row)!=2 )
                {
                    return false;
                }
            }    
        }
        if(start_column != finaly_column)
        {
            return false;
        }
        else
        {
            if(board[finaly_row][finaly_column] != ' ')
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }
    else
    {
        if(action == 'x')
        {
            if((start_row-finaly_row)!=1)
            {
                return false;
            }
            else
            {
                if( ((start_column-finaly_column)!=1) && ((finaly_column-start_column)!=1) )
                {
                    return false;
                }
                else
                {
                    if( (board[finaly_row][finaly_column] > 'Z') || (board[finaly_row][finaly_column] == ' ') )
                    {
                        return false;
                    }
                    else
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}