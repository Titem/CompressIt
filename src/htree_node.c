
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

struct S_HTREE_NODE
{
    HTREE_ELEMENT* left_child;
    HTREE_ELEMENT* right_child;
    unsigned long weight;
};




/* ======================================================================== *
 * Funktionsdefinitionen                                                    *
 * ======================================================================== */

extern HTREE_NODE* create_htree_node(HTREE_ELEMENT* left_child, 
                                     HTREE_ELEMENT* right_child)
{
    HTREE_NODE* new_htree_node = malloc(sizeof(HTREE_NODE));
    unsigned long weight = 0;
    
    if (left_child != NULL)
    {
        if (htree_element_is_leaf(left_child))
        {
            weight += 
                htree_leaf_get_frequency
                    ((HTREE_LEAF*)htree_element_get_element(left_child));
            
        }
        else
        {
            weight += 
                htree_node_get_weight
                    ((HTREE_NODE*)htree_element_get_element(left_child));
        }
    }
    if (right_child != NULL)
    {
        if (htree_element_is_leaf(right_child))
        {
            weight += 
                htree_leaf_get_frequency
                    ((HTREE_LEAF*)htree_element_get_element(right_child));
        }
        else
        {
            weight += 
                htree_node_get_weight
                    ((HTREE_NODE*)htree_element_get_element(right_child));
        }
    }
    
    new_htree_node->weight = weight;
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
    return htree_node->left_child != NULL;
}


extern bool htree_node_has_right(HTREE_NODE* htree_node)
{
    return htree_node->right_child != NULL;
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


extern unsigned long htree_node_get_weight(HTREE_NODE* htree_node)
{
    return htree_node->weight;
}

