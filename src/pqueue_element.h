/* 
 * File:   htree_element.h
 * Author: Tim Buschmann
 *         Artur Leinweber
 *         Alexander Schmitz
 *
 * Created on 6. Februar 2015, 16:15
 */

#ifndef PQUEUE_ELEMENT_H
#define	PQUEUE_ELEMENT_H




/* ======================================================================== *
 * Typdefinitionen                                                          *
 * ======================================================================== */

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

