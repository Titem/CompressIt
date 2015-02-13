
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "pqueue_element.h"

#include <stdlib.h>




/* ======================================================================== *
 * Strukturdefinitionen                                                     *
 * ======================================================================== */

struct S_PQUEUE_ELEMENT
{
    unsigned long weight;
    HTREE_ELEMENT* htree_element;
};




/* ======================================================================== *
 * Funktionsdefinitionen                                                    *
 * ======================================================================== */

extern PQUEUE_ELEMENT* create_pqueue_element(HTREE_ELEMENT htree_element, 
                                             unsigned long weight)
{
    PQUEUE_ELEMENT* new_pqueue_element = malloc(sizeof(PQUEUE_ELEMENT));
    
    new_pqueue_element->htree_element = htree_element;
    new_pqueue_element->weight = weight;
    
    return new_pqueue_element;
}


extern void delete_pqueue_element(PQUEUE_ELEMENT** pqueue_element)
{
    free(*pqueue_element);
    *pqueue_element = NULL;
}


extern unsigned long pqueue_element_get_weight(PQUEUE_ELEMENT* pqueue_element)
{
    return pqueue_element->weight;
}


extern HTREE_ELEMENT* pqueue_element_get_htree_element(PQUEUE_ELEMENT* pqueue_element)
{
    return pqueue_element->htree_element;
}