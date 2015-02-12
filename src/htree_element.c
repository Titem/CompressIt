
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "htree_element.h"

#include <stdbool.h>
#include <stdlib.h>




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


extern void htree_element_print(HTREE_ELEMENT* htree_element)
{
    
}

