
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "htree_node.h"

#include <stdbool.h>
#include <stdlib.h>

#include "htree_leaf.h"




/* ======================================================================== *
 * Strukturdefinitionen                                                     *
 * ======================================================================== */

/** 
 * Diese Struktur beschreibt den Aufbau eines Huffman-Baum-Knotens.
 */
struct S_HTREE_NODE
{
    /**
     * Diese Variable speichert den Zeiger auf das Huffman-Baum-Element,
     * welches das linke Kind dieses Huffman-Baum-Elementes ist.
     */
    HTREE_ELEMENT* left_child;
    
    /**
     * Diese Variable speichert den Zeiger auf das Huffman-Baum-Element,
     * welches das rechte Kind dieses Huffman-Baum-Elementes ist.
     */
    HTREE_ELEMENT* right_child;
};




/* ======================================================================== *
 * Funktionsdefinitionen                                                    *
 * ======================================================================== */

extern HTREE_NODE* create_htree_node(HTREE_ELEMENT* left_child, 
                                     HTREE_ELEMENT* right_child)
{
    HTREE_NODE* new_htree_node = malloc(sizeof(HTREE_NODE));
    
    new_htree_node->left_child = left_child;
    new_htree_node->right_child = right_child;
    
    return new_htree_node;
}


extern void delete_htree_node(HTREE_NODE** htree_node)
{
    delete_htree_element(&((*htree_node)->left_child));
    delete_htree_element(&((*htree_node)->right_child));
    free(*htree_node);
    *htree_node = NULL;
}


extern HTREE_ELEMENT* htree_node_get_left(HTREE_NODE* htree_node)
{
    return htree_node->left_child;
}


extern HTREE_ELEMENT* htree_node_get_right(HTREE_NODE* htree_node)
{
    return htree_node->right_child;
}


extern bool htree_node_has_left(HTREE_NODE* htree_node)
{
    return htree_node->left_child != NULL
           && !htree_element_is_removed(htree_node->left_child);
}


extern bool htree_node_has_right(HTREE_NODE* htree_node)
{
    return htree_node->right_child != NULL
           && !htree_element_is_removed(htree_node->right_child);
}


extern void htree_node_set_left(HTREE_NODE* htree_node, 
                                HTREE_ELEMENT* htree_element)
{
    htree_node->left_child = htree_element;
}


extern void htree_node_set_right(HTREE_NODE* htree_node, 
                                 HTREE_ELEMENT* htree_element)
{
    htree_node->right_child = htree_element;
}

