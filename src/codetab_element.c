
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "codetab_element.h"

#include <stdlib.h>

#include "debug_common.h"




/* ======================================================================== *
 * Strukturdefinitionen                                                     *
 * ======================================================================== */

/** 
 * Diese Struktur beschreibt den Aufbau eines Code-Tabellen-Elementes.
 */
struct S_CODETAB_ELEMENT
{
    /**
     * Diese Variable speichert das Schriftzeichen 
     * dieses Code-Tabellen-Elementes.
     */
    unsigned char character;
    
    /**
     * Diese Variable speichert den Zeiger auf das Code-Array, welches den
     * Code dieses Code-Tabellen-Elementes enthält.
     */
    bool* code;
    
    /**
     * Diese Variable speichert die Code-Länge also die Länge des Code-Arrays
     * dieses Code-Tabellen-Elementes.
     */
    unsigned char length;
};




/* ======================================================================== *
 * Funktionsdefinitionen                                                    *
 * ======================================================================== */

extern CODETAB_ELEMENT* create_codetab_element(unsigned char character, 
                                               bool* code,
                                               unsigned char code_length)
{
    CODETAB_ELEMENT* new_codetab_element = malloc(sizeof(CODETAB_ELEMENT));
    
    new_codetab_element->character = character;
    new_codetab_element->code = code;
    new_codetab_element->length = code_length;
    
    return new_codetab_element;
}



extern void delete_codetab_element(CODETAB_ELEMENT** codetab_element)
{
    free(*codetab_element);
    *codetab_element = NULL;
}



extern bool codetab_element_is_bit_set(CODETAB_ELEMENT* codetab_element, 
                                       unsigned char position)
{      
    return codetab_element->code[position];
}



extern unsigned char codetab_element_get_char
                     (CODETAB_ELEMENT* codetab_element)
{
    return codetab_element->character;
}



extern bool* codetab_element_get_code(CODETAB_ELEMENT* codetab_element)
{
    return codetab_element->code;
}



extern unsigned char codetab_element_get_code_length
                     (CODETAB_ELEMENT* codetab_element)
{
    return codetab_element->length;
}