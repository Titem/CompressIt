/* 
 * File:   htree_element.h
 * Author: Tim Buschmann
 *         Artur Leinweber
 *         Alexander Schmitz
 *
 * Created on 6. Februar 2015, 16:15
 */

#ifndef HTREE_ELEMENT_H
#define	HTREE_ELEMENT_H




/* ======================================================================== *
 * Typdefinitionen                                                          *
 * ======================================================================== */

typedef struct S_HTREE_ELEMENT HTREE_ELEMENT;

typedef enum
{
    NODE,
    LEAF
} HTREE_TYPE;




/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include <stdbool.h>




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

extern HTREE_ELEMENT* create_htree_element(HTREE_TYPE type, void* element);

extern void delete_htree_element(HTREE_ELEMENT* htree_element);

extern HTREE_ELEMENT* merge_htree_elements(HTREE_ELEMENT* left_child, 
                                           HTREE_ELEMENT* right_child);

extern bool htree_element_is_leaf(HTREE_ELEMENT* htree_element);

extern void htree_element_print(HTREE_ELEMENT* htree_element);


#endif	/* HTREE_ELEMENT_H */

