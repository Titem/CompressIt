
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "codetab.h"

#include <stdbool.h>

#include "codetab_element.h"




/* ======================================================================== *
 * Strukturdefinitionen                                                     *
 * ======================================================================== */

struct S_CODETAB 
{
    unsigned char length;
    unsigned char working_index;
    CODETAB_ELEMENT* char_index[256];
    bool is_emty;
};




/* ======================================================================== *
 * Funktionsdefinitionen                                                    *
 * ======================================================================== */

extern CODETAB* create_codetab(HTREE* htree)
{
    return NULL;
}


extern CODETAB* read_codetab(FILE* input_stream)
{
    return NULL;
}


extern void write_codetab(FILE* output_stream, CODETAB* codetab)
{

}


extern void delete_codetab(CODETAB* codetab)
{
    
}


extern bool** codetab_get_code(CODETAB* codetab, 
                               unsigned char character)
{
    return NULL;
}


extern unsigned char codetab_get_code_length(CODETAB* codetab, 
                                                unsigned char character)
{
    return 0;
}


extern CODETAB_ELEMENT* codetab_get_element(CODETAB* codetab)
{
    return NULL;
}


extern bool codetab_is_emty(CODETAB* codetab)
{
    return false;
}


extern void codetab_print(CODETAB* codetab)
{
    
}

