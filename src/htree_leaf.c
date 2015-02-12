
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
    return NULL;
}


extern void delete_htree_leaf(HTREE_LEAF* htree_leaf)
{
    
}


extern unsigned char htree_leaf_get_char(HTREE_LEAF* htree_leaf)
{
    return 0;
}


extern unsigned long htree_leaf_get_frequency(HTREE_LEAF* htree_leaf)
{
    return 0;
}

