

#include "pqueue.h"

#include "htree_element.h"


struct S_PQUEUE
{
    unsigned char number_of_entries;
    HTREE_ELEMENT* entry[256]; 
};
