
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "codetab.h"

#include "codetab_element.h"




/* ======================================================================== *
 * Strukturdefinitionen                                                     *
 * ======================================================================== */

struct S_CODETAB 
{
    unsigned char length;
    CODETAB_ELEMENT* element[256];
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

extern CODETAB_ELEMENT* codetab_get_code(CODETAB* codetab, 
                                         unsigned char character)
{
    return NULL;
}

extern bool codetab_search_char(CODETAB* codetab, bool bit)
{
    return false;
}

extern unsigned char codetab_get_char(CODETAB* codetab)
{
    return 0;
}

extern void codetab_print(CODETAB* codetab)
{
    
}