

#include "htree.h"


#include "codetab_element.h"
#include "htree_element.h"
#include "pqueue.h"
#include "freqtab.h"

struct S_HTREE
{
    CODETAB_ELEMENT* prep_codetab_element;
    HTREE_ELEMENT* root_node;
};

extern HTREE* create_htree(FREQTAB* freqtab)
{
    
}

extern void delete_htree(HTREE* htree)
{
    
}

extern CODETABLE_ELEMENT* htree_get_codetab_element(HTREE* htree)
{
    
}

extern bool htree_is_emty(HTREE* htree)
{
    
}