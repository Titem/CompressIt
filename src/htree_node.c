
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "htree_node.h"

#include <stdbool.h>
#include <stdlib.h>




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
    return NULL;
}


extern void delete_htree_node(HTREE_NODE* htree_node)
{
    
}


extern HTREE_ELEMENT* htree_node_get_left(HTREE_NODE* htree_node)
{
    return NULL;
}


extern HTREE_ELEMENT* htree_node_get_right(HTREE_NODE* htree_node)
{
    return NULL;
}


extern bool htree_node_has_left(HTREE_NODE* htree_node)
{
    return false;
}


extern bool htree_node_has_right(HTREE_NODE* htree_node)
{
    return false;
}


extern unsigned long htree_node_get_weight(HTREE_NODE* htree_node)
{
    return 0;
}

