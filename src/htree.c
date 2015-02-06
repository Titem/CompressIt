

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