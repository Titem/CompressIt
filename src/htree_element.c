
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "htree_element.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "htree_node.h"
#include "htree_leaf.h"
#include "debug_common.h"
#include "error_handler.h"




/* ======================================================================== *
 * Strukturdefinitionen                                                     *
 * ======================================================================== */

/** 
 * Diese Struktur beschreibt den Aufbau eines Huffman-Baum-Elementes.
 */
struct S_HTREE_ELEMENT
{
    /**
     * Diese Variable speichert den Typ dieses Huffman-Baum-Elementes bzw.
     * ob ein Huffman-Baum-Blatt oder ein Huffman-Baum-Knoten von diesem
     * Huffman-Baum-Element gekapselt wird.
     */
    HTREE_ELEMENT_TYPE type;
    
    /**
     * Diese Variable speichert den Zeiger auf das oder den von diesem 
     * Huffman-Baum-Element gekapselte Blatt oder Knoten.
     */
    void* element;
    
    /**
     * Diese Variable speichert, ob dieses Huffman-Baum-Element als 
     * entnommen makiert ist.
     */
    bool removed;
};




/* ======================================================================== *
 * Funktionsdefinitionen                                                    *
 * ======================================================================== */

extern HTREE_ELEMENT* create_htree_element(HTREE_ELEMENT_TYPE type, 
                                           void* element)
{
    HTREE_ELEMENT* new_htree_element = malloc(sizeof(HTREE_ELEMENT));
    
    if (new_htree_element == NULL)
    {
        error_handler_handle_error(CANT_ALLOCATE_MEMORY, __FILE__, __LINE__);
    }
    
    new_htree_element->type = type;
    new_htree_element->element = element;
    new_htree_element->removed = false;
    
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
    
    if (new_htree_element == NULL)
    {
        error_handler_handle_error(CANT_ALLOCATE_MEMORY, __FILE__, __LINE__);
    }
    
    new_htree_element->element = 
            (void*) create_htree_node(left_child, right_child);
    new_htree_element->type = NODE;
    new_htree_element->removed = false;
    
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


extern bool htree_element_is_removed(HTREE_ELEMENT* htree_element)
{
    return htree_element->removed;
}


extern void htree_element_remove(HTREE_ELEMENT* htree_element)
{
    htree_element->removed = true;
}


extern void htree_element_print(HTREE_ELEMENT* htree_element)
{
    static int deepness = 0;
    
    int i;
    if (htree_element != NULL && !htree_element->removed)
    {
        for (i = 0; i < deepness; i++)
        {
            printf("    ");
        }
        printf("|--");
        if(htree_element->type == LEAF)
        {
            printf("[%s]\n", 
                   convert_char(htree_leaf_get_char(
                   (HTREE_LEAF*)(htree_element->element))));
        }
        else
        {
            printf("[NODE]\n");
            deepness++;
            htree_element_print(htree_node_get_left(
                (HTREE_NODE*)(htree_element->element)));
            htree_element_print(htree_node_get_right(
                (HTREE_NODE*)(htree_element->element)));
            deepness--;
        }
    }
}

