/* 
 * @file htree_element.h
 * 
 * Dieses Modul repräsentiert ein Huffman-Baum-Element also ein Bestandteil
 * eines Huffman-Baumes. Ein solches Element kann entweder ein 
 * Knoten (htree_node) sein oder ein Blatt (htree_leaf).
 * Ein Huffman-Baum-Element stellt in etwa eine abstrakte Generalisierung eines
 * Huffman-Baum-Knotens und einem Huffman-Baum-Blattes da.
 * 
 * @author Tim Buschmann
 *         Artur Leinweber
 *         Alexander Schmitz
 */

#ifndef HTREE_ELEMENT_H
#define	HTREE_ELEMENT_H




/* ======================================================================== *
 * Typdefinitionen                                                          *
 * ======================================================================== */

/**
 * Dieser Datentyp repräsentiert ein Huffman-Baum-Element.
 * Variablen diesen Datentyps beinhalten Huffman-Baum-Elemente. 
 */
typedef struct S_HTREE_ELEMENT HTREE_ELEMENT;


/**
 * Dieser Datentyp repräsentiert eine Auswahl um welchen Typ von 
 * Huffman-Baum-Element es sich handelt.
 * Variablen diesen Datentyps können zwei Zustände annehmen, entweder Knoten oder
 * Blatt. 
 */
typedef enum
{
    NODE,
    LEAF
} HTREE_ELEMENT_TYPE;




/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include <stdbool.h>




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

extern HTREE_ELEMENT* create_htree_element(HTREE_ELEMENT_TYPE type, void* element);

extern void delete_htree_element(HTREE_ELEMENT** htree_element);

extern HTREE_ELEMENT* merge_htree_elements(HTREE_ELEMENT* left_child, 
                                           HTREE_ELEMENT* right_child);

extern void* htree_element_get_element(HTREE_ELEMENT* htree_element);

extern bool htree_element_is_leaf(HTREE_ELEMENT* htree_element);

extern bool htree_element_is_killed(HTREE_ELEMENT* htree_element);

extern void htree_element_kill(HTREE_ELEMENT* htree_element);

extern void htree_element_print(HTREE_ELEMENT* htree_element);


#endif	/* HTREE_ELEMENT_H */

