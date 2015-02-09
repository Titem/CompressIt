
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "htree_element.h"

#include <stdbool.h>
#include <stdlib.h>




/* ======================================================================== *
 * Strukturdefinitionen                                                     *
 * ======================================================================== */

struct S_HTREE_LEAF
{
    unsigned char character;
    unsigned long frequency;
};


struct S_HTREE_NODE
{
    HTREE_ELEMENT* left_child;
    HTREE_ELEMENT* right_child;
    unsigned long weight;
};


struct S_HTREE_ELEMENT
{
    union
    {
        HTREE_LEAF leaf;
        HTREE_NODE node;
    } element;
    bool is_leaf;
    unsigned short deepness;
};




/* ======================================================================== *
 * Funktionsdefinitionen                                                    *
 * ======================================================================== */

extern HTREE_ELEMENT* create_htree_node(HTREE_ELEMENT* left_child, 
                                        HTREE_ELEMENT* right_child)
{
    return NULL;
}

extern HTREE_ELEMENT* create_htree_leaf(unsigned long frequency, 
                                        unsigned char character)
{
    return NULL;
}

extern void delete_htree_element(HTREE_ELEMENT* htree_element)
{
    
}

extern HTREE_ELEMENT* merge_htree_elements(HTREE_ELEMENT* left_child, 
                                           HTREE_ELEMENT* right_child)
{
    return NULL;
}

extern bool htree_element_is_leaf(HTREE_ELEMENT* htree_element)
{
    return false;
}

extern unsigned short htree_element_get_deepness(HTREE_ELEMENT* htree_element)
{
    return 0;
}

extern void htree_element_print(HTREE_ELEMENT* htree_element)
{
    
}

extern HTREE_ELEMENT* htree_node_get_left(HTREE_ELEMENT* htree_node)
{
    return NULL;
}

extern HTREE_ELEMENT* htree_node_get_right(HTREE_ELEMENT* htree_node)
{
    return NULL;
}

extern bool htree_node_has_left(HTREE_ELEMENT* htree_node)
{
    return false;
}

extern bool htree_node_has_right(HTREE_ELEMENT* htree_node)
{
    return false;
}

extern unsigned long htree_node_get_weight(HTREE_ELEMENT* htree_weight)
{
    return 0;
}

extern unsigned char htree_leaf_get_char(HTREE_ELEMENT* htree_leaf)
{
    return 0;
}

extern unsigned long htree_leaf_get_frequency(HTREE_ELEMENT* htree_leaf)
{
    return 0;
}
