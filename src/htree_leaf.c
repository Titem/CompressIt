
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "htree_leaf.h"

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




/* ======================================================================== *
 * Funktionsdefinitionen                                                    *
 * ======================================================================== */

extern HTREE_LEAF* create_htree_leaf(unsigned char character,
                                     unsigned long frequency)
{
    HTREE_LEAF* new_htree_leaf = malloc(sizeof(HTREE_LEAF));
    new_htree_leaf->character = character;
    new_htree_leaf->frequency = frequency;
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


extern unsigned long htree_leaf_get_frequency(HTREE_LEAF* htree_leaf)
{
    return htree_leaf->frequency;
}
