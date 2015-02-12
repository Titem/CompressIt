
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "pqueue.h"

#include <stdlib.h>

#define LEFT(position) ((((position) * 2) + 1));
#define RIGHT(position) ((((position) * 2) + 2));


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
    /*INSERT*/
    /*Element in den Heap einf�gen.*/
    /*Bei Index 0 Anfangen*/

    //heap_vektor[heap_elements] = element;

    /*Anzahl der Heap Elemente hochzaehlen.*/
    heap_elements++;

    /*Pr�fung ob mehr Speicher reserviert werden muss.*/
    test_for_enlarging_memory();

    /*Bei Index 1 anfangen. Entspricht dem ROOT Index.*/
    /*heap_vektor[heap_elements] = element;*/

    /*BUILD*/
    build_heap();
}

extern HTREE_ELEMENT* pqueue_get_min_entry(PQUEUE* pqueue)
{
  /*  bool heap_extrahiert;
    int last_index;
    if (heap_elements == 0)
    {
        heap_extrahiert = false;
    }
    else
    {
        *min_element = heap_vektor[ROOT_INDEX];
        last_index = heap_elements - 1;
        swap(ROOT_INDEX, last_index);
        heap_elements--;
        if (ROOT_INDEX != last_index)
        {
            heapify(ROOT_INDEX);
        }
        heap_extrahiert = true;
    }*/
    return NULL;
}

extern unsigned char pqueue_get_number_of_entries(PQUEUE* pqueue)
{
    return pqueue->number_of_entries;
}


static void pqueue_heapify(PQUEUE* pqueue, unsigned char index)
{
 /*   do
    {
        int min = i;
        if ((LEFT(i) < heap_elements) && (heap_vektor[LEFT(i)] < heap_vektor[min]))
        {
            min = LEFT(i);
        }
        if ((RIGHT(i) < heap_elements) && (heap_vektor[RIGHT(i)] < heap_vektor[min]))
        {
            min = RIGHT(i);
        }
        if (min == i)
        {
            break;
        }

        swap(i, min);
        i = min;
    } while (true);*/
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