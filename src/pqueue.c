

#include "pqueue.h"




struct S_PQUEUE
{
    unsigned char number_of_entries;
    HTREE_ELEMENT* entry[256]; 
};
