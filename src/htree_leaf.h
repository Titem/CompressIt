/* 
 * @file htree_leaf.h
 * 
 * Dieses Modul repräsentiert ein Huffman-Baum-Blatt.
 * Ein solches Blatt enthält das Schriftzeichen, welches an der Position,
 * an der sich das Blatt im Baum befindet, abgelegt ist.
 * 
 * @author Tim Buschmann
 *         Artur Leinweber
 *         Alexander Schmitz
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

