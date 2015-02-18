/* 
 * @file htree_node.h
 * 
 * Dieses Modul repräsentiert einen Huffman-Baum-Knoten.
 * Ein solcher Knoten kann vielfach im Huffman-Baum vorkommen und beschreibt 
 * die Gabelungen in der Baumstruktur. Ein Knoten kann dabei zwei weitere 
 * Kind-elemente enthalten die ein Blatt oder wiederum ein Knoten sein können.
 * 
 * @author Tim Buschmann
 *         Artur Leinweber
 *         Alexander Schmitz
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

/**
 * Dieser Datentyp repräsentiert einen Huffman-Baum-Knoten.
 * Variablen diesen Datentyps beinhalten Huffman-Baum-Knoten. 
 */
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

extern void htree_node_set_left(HTREE_NODE* htree_node, 
                                HTREE_ELEMENT* htree_element);

extern void htree_node_set_right(HTREE_NODE* htree_node, 
                                 HTREE_ELEMENT* htree_element);


#endif	/* HTREE_NODE_H */

