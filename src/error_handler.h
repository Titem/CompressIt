/* 
 * File:   error_handler.h
 * Author: Alexander Schmitz
 *
 * Created on 20. Februar 2015, 12:30
 */

#ifndef ERROR_HANDLER_H
#define	ERROR_HANDLER_H

#include "parameterlist.h"

typedef enum
{
    CANT_ALLOCATE_MEMORY,
    NO_INPUT_FILENAME,
    TO_FEW_ARGUMENTS,
    TO_MANY_ARGUMENTS,
    FILENAMES_ARE_EQUAL,
    CANT_OPEN_INPUT_FILE,
    CANT_OPEN_OUTPUT_FILE
} ERROR;

extern void error_handler_activate(PARAMETERLIST* parameterlist);

extern void error_handler_handle_error(ERROR error, char* file, int line);

#endif	/* ERROR_HANDLER_H */

