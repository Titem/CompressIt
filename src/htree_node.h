/* 
 * File:   htree_element.h
 * Author: Tim Buschmann
 *         Artur Leinweber
 *         Alexander Schmitz
 *
 * Created on 6. Februar 2015, 16:15
 */

#ifndef HTREE_NODE_H
#define	HTREE_NODE_H




/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include <stdbool.h>

#include "htree_element.h"




/* ======================================================================== *
 * Typdefinitionen                                                          *
 * ======================================================================== */

typedef struct S_HTREE_NODE HTREE_NODE;




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

extern HTREE_NODE* create_htree_node(HTREE_ELEMENT* left_child, 
                                     HTREE_ELEMENT* right_child);

extern void delete_htree_node(HTREE_NODE** htree_node);

extern HTREE_ELEMENT* htree_node_get_left(HTREE_NODE* htree_node);

extern HTREE_ELEMENT* htree_node_get_right(HTREE_NODE* htree_node);

extern bool htree_node_has_left(HTREE_NODE* htree_node);

extern bool htree_node_has_right(HTREE_NODE* htree_node);

extern unsigned long htree_node_get_weight(HTREE_NODE* htree_node);


#endif	/* HTREE_NODE_H */

