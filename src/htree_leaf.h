/* 
 * File:   htree_element.h
 * Author: Tim Buschmann
 *         Artur Leinweber
 *         Alexander Schmitz
 *
 * Created on 6. Februar 2015, 16:15
 */

#ifndef HTREE_LEAF_H
#define	HTREE_LEAF_H




/* ======================================================================== *
 * Typdefinitionen                                                          *
 * ======================================================================== */

typedef struct S_HTREE_LEAF HTREE_LEAF;




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

extern HTREE_LEAF* create_htree_leaf(unsigned char character);

extern void delete_htree_leaf(HTREE_LEAF** htree_leaf);

extern unsigned char htree_leaf_get_char(HTREE_LEAF* htree_leaf);


#endif	/* HTREE_LEAF_H */

