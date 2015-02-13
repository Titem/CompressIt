
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "codetab.h"

#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "codetab_element.h"
#include "codetab.h"



/* ======================================================================== *
 * Strukturdefinitionen                                                     *
 * ======================================================================== */

struct S_CODETAB 
{
    unsigned char length;
    unsigned short working_index;
    CODETAB_ELEMENT* char_index[256];
};

static void codetab_get_next_index(CODETAB* codetab);


/* ======================================================================== *
 * Funktionsdefinitionen                                                    *
 * ======================================================================== */

extern CODETAB* create_codetab(HTREE* htree)
{
    CODETAB* new_codetab = malloc(sizeof(CODETAB));
    CODETAB_ELEMENT* new_codetab_element;
    new_codetab->working_index = 0;
    codetab_get_next_index(new_codetab);
    while (!htree_is_emty(htree))
    {
        new_codetab_element = htree_get_codetab_element(htree);
        new_codetab->char_index[codetab_element_get_char(new_codetab_element)] 
                = new_codetab_element;
        htree_print(htree);
    }
    
    return new_codetab;
}


extern CODETAB* read_codetab(FILE* input_stream)
{

    enum {
        CHAR,
        LENGTH,
        CODE
                
    } STATE;
    
    return NULL;
}


extern void write_codetab(FILE* output_stream, CODETAB* codetab)
{
    
}


extern void delete_codetab(CODETAB** codetab)
{
    free(*codetab);
    *codetab = NULL;
}


extern bool** codetab_get_code(CODETAB* codetab, unsigned char character)
{
    return codetab_element_get_code(codetab->char_index[character]);
}


extern unsigned char codetab_get_code_length(CODETAB* codetab,                                                unsigned char character)
{
    return codetab_element_get_code_length(codetab->char_index[character]);
}


extern CODETAB_ELEMENT* codetab_get_element(CODETAB* codetab)
{
    unsigned short old_working_index;
    
    /* aktuellen working_index zwischenspeichern */
    old_working_index = codetab->working_index;
    
    /* working_index auf naechstes codetab_element setzen */
    codetab_get_next_index(codetab);
    
    return codetab->char_index[old_working_index];
}


extern bool codetab_is_empty(CODETAB* codetab)
{
    return codetab->working_index > 255;
}

static void codetab_get_next_index(CODETAB* codetab)
{
    unsigned short i;
    
    i = codetab->working_index;
    
    /* Naechstes codetab Element auswählen */
    while(codetab->working_index < 256 && codetab->char_index[i] == NULL) 
    {
        codetab->working_index++;
    }
}


extern void codetab_print(CODETAB* codetab)
{
    int i = 0;
    while (!codetab_is_empty(codetab))
    {
        printf("%u\n", i);
        codetab_get_next_index(codetab);
        i++;
        
    }
}


