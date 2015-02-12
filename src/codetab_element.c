
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "codetab_element.h"

#include <stdlib.h>




/* ======================================================================== *
 * Strukturdefinitionen                                                     *
 * ======================================================================== */

struct S_CODETAB_ELEMENT
{
    unsigned char character;
    bool** code;
    unsigned char length;
};




/* ======================================================================== *
 * Funktionsdefinitionen                                                    *
 * ======================================================================== */

extern CODETAB_ELEMENT* create_codetab_element(unsigned char character, 
                                               bool** code,
                                               unsigned char code_length)
{
    return NULL;
}

extern void delete_codetab_element(CODETAB_ELEMENT* codetab_element)
{
    
}

extern bool codetab_element_is_bit_set(CODETAB_ELEMENT* codetab_element, 
                                       unsigned char position)
{
    return false;
}

extern unsigned char codetab_element_get_char
                     (CODETAB_ELEMENT* codetab_element)
{
    return 0;
}

extern bool** codetab_element_get_code(CODETAB_ELEMENT* codetab_element)
{
    return NULL;
}

extern unsigned char codetab_element_get_code_length
                     (CODETAB_ELEMENT* codetab_element)
{
    return 0;
}