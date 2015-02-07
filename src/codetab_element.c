
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "codetab_element.h"




/* ======================================================================== *
 * Strukturdefinitionen                                                     *
 * ======================================================================== */

struct S_CODETAB_ELEMENT
{
    unsigned char character;
    unsigned short code;
    unsigned char code_length;
};




/* ======================================================================== *
 * Funktionsdefinitionen                                                    *
 * ======================================================================== */

extern CODETAB_ELEMENT* creat_codetab_element(unsigned char character, 
                                              unsigned short code,
                                              unsigned char code_length)
{
    
}

extern void delete_codetab_element(CODETAB_ELEMENT* codetab_element)
{
    
}

extern bool codetab_element_is_bit_set(CODETAB_ELEMENT* codetab_element, 
                                       unsigned char position)
{
    
}

extern unsigned char codetab_element_get_char
                     (CODETAB_ELEMENT* codetab_element)
{
    
}

extern unsigned char codetab_element_get_code
                     (CODETAB_ELEMENT* codetab_element)
{
    
}

extern unsigned char codetab_element_get_code_length
                     (CODETAB_ELEMENT* codetab_element)
{
    
}