
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "error_handler.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "messages_de.h"
#include "debug_common.h"




/* ======================================================================== *
 * globale Variablen                                                    *
 * ======================================================================== */

/**
 * Diese globale Variable speichert für den Error-Handler einen Zeiger auf
 * die Parameterliste, mit der der Error-Handler aktiviert wurde.
 */
static PARAMETERLIST* error_handler_param;




/* ======================================================================== *
 * Funktionsdefinitionen                                                    *
 * ======================================================================== */

extern void error_handler_activate(PARAMETERLIST* parameterlist)
{
    error_handler_param = parameterlist;
}



extern void error_handler_handle_error(ERROR error, char* file, int line)
{
    switch (error)
    {
    case CANT_ALLOCATE_MEMORY:
        fprintf(stderr, MSG_CANT_ALLOCATE_MEMORY);
        break;
    case NO_INPUT_FILENAME:
        fprintf(stderr, MSG_NO_INPUT_FILENAME);
        break;
    case TO_FEW_ARGUMENTS:
        fprintf(stderr, MSG_TO_FEW_ARGUMENTS);
        break;
    case TO_MANY_ARGUMENTS:
        fprintf(stderr, MSG_WRONG_ARGUMENTS);
        break;
    case FILENAMES_ARE_EQUAL:
        fprintf(stderr, MSG_FILENAMES_ARE_EQUAL);
        break;
    case CANT_OPEN_INPUT_FILE:
        fprintf(stderr, MSG_CANT_OPEN_INPUT_FILE("%s", "%d", "%s"),
                parameterlist_get_input_filename(error_handler_param),
                errno, strerror(errno));
        break;
    case CANT_OPEN_OUTPUT_FILE:
        fprintf(stderr, MSG_CANT_OPEN_OUTPUT_FILE("%s", "%d", "%s"),
                parameterlist_get_output_filename(error_handler_param),
                errno, strerror(errno));
        break;
    case INVALID_FILE_CONTENT_INVALID:
        fprintf(stderr, MSG_INVALID_FILE_CONTENT_INVALID("%s", "%s"),
                parameterlist_get_input_filename(error_handler_param),
                parameterlist_get_input_filename(error_handler_param));
        break;
    case INVALID_FILE_CONTENT_TO_SHORT:
        fprintf(stderr, MSG_INVALID_FILE_CONTENT_TO_SHORT("%s", "%s"),
                parameterlist_get_input_filename(error_handler_param),
                parameterlist_get_input_filename(error_handler_param));
        break;
    case INVALID_FILE_CONTENT_TO_LONG:
        fprintf(stderr, MSG_INVALID_FILE_CONTENT_TO_LONG("%s", "%s"),
                parameterlist_get_input_filename(error_handler_param),
                parameterlist_get_input_filename(error_handler_param));
        break;
    case INVALID_FILE_CODETAB_INVALID:
        fprintf(stderr, MSG_INVALID_FILE_CODETAB_INVALID("%s", "%s"),
                parameterlist_get_input_filename(error_handler_param),
                parameterlist_get_input_filename(error_handler_param));
        break;
    case INVALID_FILE_CODETAB_TO_SHORT:
        fprintf(stderr, MSG_INVALID_FILE_CODETAB_TO_SHORT("%s", "%s"),
                parameterlist_get_input_filename(error_handler_param),
                parameterlist_get_input_filename(error_handler_param));
        break;
    case INVALID_FILE_CODETAB_TO_LONG:
        fprintf(stderr, MSG_INVALID_FILE_CODETAB_TO_LONG("%s", "%s"),
                parameterlist_get_input_filename(error_handler_param),
                parameterlist_get_input_filename(error_handler_param));
        break;
    case INVALID_FILE_CONTENTLENGTH_UNREADABLE:
        fprintf(stderr, MSG_INVALID_FILE_CONTENTLENGTH_UNREADABLE("%s", "%s"),
                parameterlist_get_input_filename(error_handler_param),
                parameterlist_get_input_filename(error_handler_param));
        break;
    case INVALID_FILE_CODETABLENGTH_UNREADABLE:
        fprintf(stderr, MSG_INVALID_FILE_CODETABLENGTH_UNREADABLE("%s", "%s"),
                parameterlist_get_input_filename(error_handler_param),
                parameterlist_get_input_filename(error_handler_param));
        break;
    case CANT_WRITE_CONTENTLENGTH:
        fprintf(stderr, MSG_CANT_WRITE_CONTENTLENGTH);
        break;
    case CANT_WRITE_CODETABLENGTH:
        fprintf(stderr, MSG_CANT_WRITE_CODETABLENGTH);
        break;
    case UNKNOWN_ERROR:
        fprintf(stderr, MSG_UNKNOWN_ERROR);
        break;
    default:
        fprintf(stderr, MSG_UNKNOWN_ERROR);
        break;
    }

    fprintf(stderr, "\n\nModul: %s\nZeile: %d\n\n\n", file, line);

    if (parameterlist_get_input_stream(error_handler_param) != NULL)
    {
        fclose(parameterlist_get_input_stream(error_handler_param));
    }
    if (parameterlist_get_output_stream(error_handler_param) != NULL)
    {
        fclose(parameterlist_get_output_stream(error_handler_param));
    }
    
    if (parameterlist_get_output_stream(error_handler_param) != NULL)
    {
        remove(parameterlist_get_output_filename(error_handler_param));
    }

    exit(EXIT_FAILURE);
}
