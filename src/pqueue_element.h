/* 
 * @file pqueue_element.h
 * 
 * Dieses Modul repräsentiert ein Prioritäts-Warteschlangen-Element also einen
 * Eintrag in der Prioritäts-Warteschlange. Ein solcher Eintrag enthält das
 * wartende Huffman-Baum-Element sowie das Gewicht dieses Element, durch das
 * sich die Priorität also die Position in der Warteschlange ergibt. 
 * 
 * @author Tim Buschmann
 *         Artur Leinweber
 *         Alexander Schmitz
 */

#ifndef PQUEUE_ELEMENT_H
#define	PQUEUE_ELEMENT_H




/* ======================================================================== *
 * Typdefinitionen                                                          *
 * ======================================================================== */

/**
 * Dieser Datentyp repräsentiert ein Prioritäts-Warteschlangen-Element.
 * Variablen diesen Datentyps beinhalten Prioritäts-Warteschlangen-Elemente. 
 */
typedef struct S_PQUEUE_ELEMENT PQUEUE_ELEMENT;




/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include <stdbool.h>

#include "htree_element.h"




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

extern PQUEUE_ELEMENT* create_pqueue_element(HTREE_ELEMENT* htree_element, 
                                             unsigned long weight);

extern void delete_pqueue_element(PQUEUE_ELEMENT** pqueue_element);

extern unsigned long pqueue_element_get_weight(PQUEUE_ELEMENT* pqueue);

extern HTREE_ELEMENT* pqueue_element_get_htree_element(PQUEUE_ELEMENT* pqueue);


#endif	/* PQUEUE_ELEMENT_H */

