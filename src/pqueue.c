
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "pqueue.h"




/* ======================================================================== *
 * Strukturdefinitionen                                                     *
 * ======================================================================== */

struct S_PQUEUE
{
    unsigned char number_of_entries;
    HTREE_ELEMENT* entry[256]; 
};




/* ======================================================================== *
 * Funktionsdefinitionen                                                    *
 * ======================================================================== */

extern PQUEUE* create_pqueue(void)
{
    
}

extern void delete_pqueue(PQUEUE* pqueue)
{
    
}

extern void pqueue_insert_htree_element(PQUEUE* pqueue, 
                                        HTREE_ELEMENT* htree_element)
{
    
}

extern HTREE_ELEMENT* pqueue_get_min_entry(PQUEUE* pqueue)
{
    
}

extern unsigned char pqueue_get_number_of_entries(PQUEUE* pqueue)
{
    
}