/* 
 * File:   pqueue.h
 * Author: Tim Buschmann
 *         Artur Leinweber
 *         Alexander Schmitz
 *
 * Created on 6. Februar 2015, 16:14
 */

#ifndef PQUEUE_H
#define	PQUEUE_H




/* ======================================================================== *
 * Typdefinitionen                                                          *
 * ======================================================================== */

typedef struct S_PQUEUE PQUEUE;




/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "htree_element.h"




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

extern PQUEUE* create_pqueue(void);

extern void delete_pqueue(PQUEUE* pqueue);

extern void pqueue_insert_htree_element(PQUEUE* pqueue, 
                                        HTREE_ELEMENT* htree_element);

extern HTREE_ELEMENT* pqueue_get_min_entry(PQUEUE* pqueue);

extern unsigned char pqueue_get_number_of_entries(PQUEUE* pqueue);


#endif	/* PQUEUE_H */

