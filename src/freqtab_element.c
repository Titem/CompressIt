
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "freqtab_element.h"

#include <stdlib.h>

#include "debug_common.h"
#include "error_handler.h"




/* ======================================================================== *
 * Strukturdefinitionen                                                     *
 * ======================================================================== */

/**
 * Diese Struktur beschreibt den Aufbau eines Häufigkeits-Tabellen-Elementes.
 */
struct S_FREQTAB_ELEMENT
{
    /**
     * Diese Variable speichert das Schriftzeichen
     * dieses Häufigkeits-Tabellen-Elementes.
     */
    unsigned char character;

    /**
     * Diese Variable speichert die Häufigkeit
     * dieses Häufigkeits-Tabellen-Elementes.
     */
    unsigned long frequency;
};




/* ======================================================================== *
 * Funktionsdefinitionen                                                    *
 * ======================================================================== */

extern FREQTAB_ELEMENT* create_freqtab_element(unsigned char character)
{
    FREQTAB_ELEMENT* new_freqtab_element = malloc(sizeof(FREQTAB_ELEMENT));

    if (new_freqtab_element == NULL)
    {
	error_handler_handle_error(CANT_ALLOCATE_MEMORY, __FILE__, __LINE__);
    }

    new_freqtab_element->character = character;
    new_freqtab_element->frequency = ININIT_CHARCTER;

    return new_freqtab_element;
}


/* @unused@ */
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

