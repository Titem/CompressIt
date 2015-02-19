
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "pqueue_element.h"

#include <stdlib.h>




/* ======================================================================== *
 * Strukturdefinitionen                                                     *
 * ======================================================================== */

/** 
 * Diese Struktur beschreibt den Aufbau eines 
 * Priorit�ts-Warteschlangen-Elementes.
 */
struct S_PQUEUE_ELEMENT
{
    /**
     * Diese Variable speichert das Gewicht (reziproke Priorit�t) dieses 
     * Priorit�ts-Warteschalngen-Elementes.
     */
    unsigned long weight;
    
    /**
     * Diese Variable speichert den Zeiger auf das wartende 
     * Huffman-Baum-Element.
     */
    HTREE_ELEMENT* htree_element;
};




/* ======================================================================== *
 * Funktionsdefinitionen                                                    *
 * ======================================================================== */

extern PQUEUE_ELEMENT* create_pqueue_element(HTREE_ELEMENT* htree_element, 
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