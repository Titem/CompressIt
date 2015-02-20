
#include "error_handler.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "debug_common.h"



PARAMETERLIST* error_handler_param;

extern void error_handler_activate(PARAMETERLIST* parameterlist)
{
    error_handler_param = parameterlist; 
}

extern void error_handler_handle_error(ERROR error, char* file, int line)
{
    
    
    fprintf(stderr, "Modul:        %s\n"
                    "Zeile:        %d\n"
                    "Fehlernummer: %d\n"
                    "Beschreibung: %s\n\n",
            file, line, errno, strerror(errno));
    
    if (parameterlist_get_output_stream(error_handler_param) != NULL)
    {
        remove(parameterlist_get_output_filename(error_handler_param));
    }
    
    exit(EXIT_FAILURE);
}