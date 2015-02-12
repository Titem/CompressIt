
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "htree_element.h"

#include <stdbool.h>
#include <stdlib.h>

#include "htree_node.h"
#include "htree_leaf.h"




/* ======================================================================== *
 * Strukturdefinitionen                                                     *
 * ======================================================================== */

struct S_HTREE_ELEMENT
{
    HTREE_TYPE type;
    void* element;
};




/* ======================================================================== *
 * Funktionsdefinitionen                                                    *
 * ======================================================================== */

extern HTREE_ELEMENT* create_htree_element(HTREE_TYPE type, void* element)
{
    HTREE_ELEMENT* new_htree_element = malloc(sizeof(HTREE_ELEMENT));
    
    new_htree_element->type = type;
    new_htree_element->element = element;
    
    return new_htree_element;
}


extern void delete_htree_element(HTREE_ELEMENT** htree_element)
{
    if ((*htree_element)->type == NODE)
    {
        delete_htree_node((HTREE_NODE**)(&((*htree_element)->element)));
    }
    else
    {
        delete_htree_leaf((HTREE_LEAF**)(&((*htree_element)->element)));
    }
    
    free(*htree_element);
    *htree_element = NULL;
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


extern void htree_element_print(HTREE_ELEMENT* htree_element)
{
    
}

