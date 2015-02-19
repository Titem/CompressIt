
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "freqtab_element.h"

#include <stdlib.h>

#include "error.h"




/* ======================================================================== *
 * Strukturdefinitionen                                                     *
 * ======================================================================== */

/** 
 * Diese Struktur beschreibt den Aufbau eines Häufigkeits-Tabellen-Elementes.
 */
struct S_FREQTAB_ELEMENT
{
    unsigned long frequency;
    unsigned char character;
};




/* ======================================================================== *
 * Funktionsdefinitionen                                                    *
 * ======================================================================== */

extern FREQTAB_ELEMENT* create_freqtab_element(unsigned char character)
{
    FREQTAB_ELEMENT* new_freqtab_element = malloc(sizeof(FREQTAB_ELEMENT));

    if (new_freqtab_element == NULL)
    {
	print_error(cant_malloc_memory);
        exit(EXIT_FAILURE);
    }
    
    new_freqtab_element->character = character;
    new_freqtab_element->frequency = ININIT_CHARCTER;
    
    return new_freqtab_element;
}



extern void delete_freqtab_element(FREQTAB_ELEMENT** freqtab_element)
{
    free(*freqtab_element);
    *freqtab_element = NULL;
}



extern unsigned char freqtab_elememt_get_char(FREQTAB_ELEMENT* freqtab_element)
{
    return freqtab_element->character;
}



extern unsigned long freqtab_element_get_frequency(FREQTAB_ELEMENT* freqtab_element)
{
    return freqtab_element->frequency;
}



extern void freqtab_element_inc_frequency(FREQTAB_ELEMENT* freqtab_element)
{
    freqtab_element->frequency++;
}

