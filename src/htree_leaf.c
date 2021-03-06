
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "htree_leaf.h"

#include <stdbool.h>
#include <stdlib.h>

#include "debug_common.h"
#include "error_handler.h"




/* ======================================================================== *
 * Strukturdefinitionen                                                     *
 * ======================================================================== */

/** 
 * Diese Struktur beschreibt den Aufbau eines Huffman-Baum-Blattes.
 */
struct S_HTREE_LEAF
{
    /**
     * Diese Variable speichert das schrifzeichen dieses Huffman-Baum-Blattes.
     */
    unsigned char character;
};




/* ======================================================================== *
 * Funktionsdefinitionen                                                    *
 * ======================================================================== */

extern HTREE_LEAF* create_htree_leaf(unsigned char character)
{
    HTREE_LEAF* new_htree_leaf = malloc(sizeof(HTREE_LEAF));
    
    if (new_htree_leaf == NULL)
    {
        error_handler_handle_error(CANT_ALLOCATE_MEMORY, __FILE__, __LINE__);
    }
    
    new_htree_leaf->character = character;
    
    return new_htree_leaf;
}


extern void delete_htree_leaf(HTREE_LEAF** htree_leaf)
{
    free(*htree_leaf);
    *htree_leaf = NULL;
}


extern unsigned char htree_leaf_get_char(HTREE_LEAF* htree_leaf)
{
    return htree_leaf->character;
}

