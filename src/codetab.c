
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

extern void wirte_codetab(FILE* output_stream, CODETAB* codetab)
{
    
}

extern void delete_codetab(CODETAB* codetab)
{
    
}

extern unsigned short codetab_get_code(CODETAB* codetab, 
                                       unsigned char character)
{
    return 0;
}

extern unsigned char codetab_get_char(CODETAB* codetab, unsigned short code)
{
    return 0;
}

extern void codetab_print(CODETAB* codetab)
{
    
}