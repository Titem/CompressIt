
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "pqueue.h"

#include <stdlib.h>




/* ======================================================================== *
 * Strukturdefinitionen                                                     *
 * ======================================================================== */

struct S_PQUEUE
{
    unsigned short number_of_entries;
    HTREE_ELEMENT* entry[256]; 
};


static void pqueue_heapify(PQUEUE* pqueue, unsigned char index);

static void pqueue_build_heap(PQUEUE* pqueue);


/* ======================================================================== *
 * Funktionsdefinitionen                                                    *
 * ======================================================================== */

extern PQUEUE* create_pqueue(void)
{
    PQUEUE* new_pqueue = malloc(sizeof(PQUEUE));
    
    new_pqueue->number_of_entries = 0;
    
    return new_pqueue;
}

extern void delete_pqueue(PQUEUE** pqueue)
{
    free(*pqueue);
    *pqueue = NULL;
}

extern void pqueue_insert_htree_element(PQUEUE* pqueue, 
                                        HTREE_ELEMENT* htree_element)
{
    
}

extern HTREE_ELEMENT* pqueue_get_min_entry(PQUEUE* pqueue)
{
    return NULL;
}

extern unsigned char pqueue_get_number_of_entries(PQUEUE* pqueue)
{
    return pqueue->number_of_entries;
}


static void pqueue_heapify(PQUEUE* pqueue, unsigned char index)
{
    do 
    {
        
    }
}

static void pqueue_build_heap(PQUEUE* pqueue)
{
    unsigned char i;
    if (pqueue->number_of_entries > 0)
    {
        for (i = ((pqueue->number_of_entries / 2) - 1); i >= 0; i--)
        {
            pqueue_heapify(pqueue, i);
        }
    }
}

static void swap(PQUEUE* pqueue, unsigned char index1, unsigned char index2)
{
    HTREE_ELEMENT* temp = pqueue->entry[index1];
    pqueue->entry[index1] = pqueue->entry[index2];
    pqueue->entry[index2] = temp;
}