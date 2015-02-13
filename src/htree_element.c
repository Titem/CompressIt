
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "htree_element.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "htree_node.h"
#include "htree_leaf.h"




/* ======================================================================== *
 * Strukturdefinitionen                                                     *
 * ======================================================================== */

struct S_HTREE_ELEMENT
{
    HTREE_TYPE type;
    void* element;
    bool killed;
};




/* ======================================================================== *
 * Funktionsdefinitionen                                                    *
 * ======================================================================== */

extern HTREE_ELEMENT* create_htree_element(HTREE_TYPE type, void* element)
{
    HTREE_ELEMENT* new_htree_element = malloc(sizeof(HTREE_ELEMENT));
    
    new_htree_element->type = type;
    new_htree_element->element = element;
    new_htree_element->killed = false;
    
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
    HTREE_ELEMENT* new_htree_element = malloc(sizeof(HTREE_ELEMENT));
    
    new_htree_element->element = 
            (void*) create_htree_node(left_child, right_child);
    new_htree_element->type = NODE;
    new_htree_element->killed = false;
    
    return new_htree_element;
}


extern void* htree_element_get_element(HTREE_ELEMENT* htree_element)
{
    return htree_element->element;
}


extern bool htree_element_is_leaf(HTREE_ELEMENT* htree_element)
{
    return htree_element->type == LEAF;
}


extern bool htree_element_is_killed(HTREE_ELEMENT* htree_element)
{
    return htree_element->killed;
}


extern void htree_element_kill(HTREE_ELEMENT* htree_element)
{
    htree_element->killed = true;
}


extern void htree_element_print(HTREE_ELEMENT* htree_element)
{
    static int deepness = 0;
    
    int i;
    if (htree_element != NULL && !htree_element->killed)
    {
        for (i = 0; i < deepness; i++)
        {
            printf("    ");
        }
        printf("|--");
        if(htree_element->type == LEAF)
        {
            printf("[%c]\n", htree_leaf_get_char((HTREE_LEAF*)(htree_element->element)));
        }
        else
        {
            printf("[NODE]\n");
            deepness++;
            htree_element_print(htree_node_get_left((HTREE_NODE*)(htree_element->element)));
            htree_element_print(htree_node_get_right((HTREE_NODE*)(htree_element->element)));
            deepness--;
        }
    }
}

