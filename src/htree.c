
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "htree.h"

#include <stdlib.h>

#include "freqtab.h"
#include "codetab.h"
#include "codetab_element.h"
#include "htree_element.h"
#include "pqueue.h"




/* ======================================================================== *
 * Strukturdefinitionen                                                     *
 * ======================================================================== */

struct S_HTREE
{
    CODETAB_ELEMENT* prep_codetab_element;
    HTREE_ELEMENT* tree_pointer;
    HTREE_ELEMENT* root_node;
};




/* ======================================================================== *
 * Funktionsdefinitionen                                                    *
 * ======================================================================== */

extern HTREE* create_htree_from_freqtab(FREQTAB* freqtab)
{
    return NULL;
}

extern HTREE* create_htree_from_codetab(CODETAB* codetab)
{
    return NULL;
}

extern void delete_htree(HTREE* htree)
{
    
}

extern CODETAB_ELEMENT* htree_get_codetab_element(HTREE* htree)
{
    return NULL;
}

extern bool htree_is_emty(HTREE* htree)
{
    return false;
}

extern bool htree_search_char(HTREE* htree, bool bit)
{
    return false;
}

extern unsigned char htree_get_char(HTREE* htree)
{
    return 0;
}

extern void htree_print(HTREE* htree)
{
    
}

extern void htree_prep_codetab_element(void)
{
    
}