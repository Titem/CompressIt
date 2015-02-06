
#include "htree_element.h"

#include <stdbool.h>

struct S_HTREE_ELEMENT
{
    union
    {
        HTREE_LEAF leaf;
        HTREE_NODE node;
    } element;
    bool is_leaf;
};


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


extern HTREE_ELEMENT* create_htree_node(HTREE_ELEMENT* left_child, 
                                        HTREE_ELEMENT* right_child)
{
    
}

extern HTREE_ELEMENT* create_htree_leaf(unsigned long frequency, 
                                        unsigned char character)
{
    
}

extern void delete_htree_element(HTREE_ELEMENT* htree_element)
{
    
}

extern HTREE_ELEMENT* merge_htree_elements(HTREE_ELEMENT* left_child, 
                                           HTREE_ELEMENT* right_child)
{
    
}

extern bool htree_element_is_leaf(HTREE_ELEMENT* htree_element)
{
    
}

extern void htree_element_print(HTREE_ELEMENT* htree_element)
{
    
}

extern HTREE_ELEMENT* htree_node_get_left(HTREE_ELEMENT* htree_node)
{
    
}

extern HTREE_ELEMENT* htree_node_get_right(HTREE_ELEMENT* htree_node)
{
    
}

extern bool htree_node_has_left(HTREE_ELEMENT* htree_node)
{
    
}

extern bool htree_node_has_right(HTREE_ELEMENT* htree_node)
{
    
}

extern unsigned long htree_node_get_weight(HTREE_ELEMENT* htree_weight)
{
    
}

extern unsigned char htree_node_get_char(HTREE_ELEMENT* htree_leaf)
{
    
}

extern unsigned long htree_node_get_frequency(HTREE_ELEMENT* htree_leaf)
{
    
}
