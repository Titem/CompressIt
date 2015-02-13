
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "pqueue.h"

#include <stdlib.h>
#include <stdio.h>

#define LEFT(position) ((((position) * 2) + 1))
#define RIGHT(position) ((((position) * 2) + 2))


/* ======================================================================== *
 * Strukturdefinitionen                                                     *
 * ======================================================================== */

struct S_PQUEUE
{
    unsigned short number_of_entries;
    PQUEUE_ELEMENT* entry[256]; 
};




static void pqueue_heapify(PQUEUE* pqueue, unsigned short index);

static void pqueue_build_heap(PQUEUE* pqueue);

static void pqueue_swap(PQUEUE* pqueue, unsigned short index1, unsigned short index2);

static void print_out_heap(PQUEUE* pqueue, unsigned short position, 
                                           unsigned short step);

static void print_step(unsigned short step);




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
                                        HTREE_ELEMENT* htree_element,
                                        unsigned long weight)
{
    /*INSERT*/
    /*Element in den Heap einf�gen.*/
    /*Bei Index 0 Anfangen*/

    pqueue->entry[pqueue->number_of_entries] 
            = create_pqueue_element(htree_element, weight);

    /*Anzahl der Heap Elemente hochzaehlen.*/
    pqueue->number_of_entries++;

    /*BUILD*/
    pqueue_build_heap(pqueue);
}

extern PQUEUE_ELEMENT* pqueue_get_min_entry(PQUEUE* pqueue)
{
    unsigned short last_index;
    
    PQUEUE_ELEMENT* min_element = pqueue->entry[0];
    last_index = pqueue->number_of_entries - 1;
    pqueue_swap(pqueue, 0, last_index);
    pqueue->number_of_entries--;
    if (0 != last_index)
    {
        pqueue_heapify(pqueue, 0);
    }
    
    return min_element;
}

extern unsigned short pqueue_get_number_of_entries(PQUEUE* pqueue)
{
    return pqueue->number_of_entries;
}


static void pqueue_heapify(PQUEUE* pqueue, unsigned short index)
{
    unsigned short min;
    do
    {
        min = index;
        if ((LEFT(index) < pqueue->number_of_entries) && (pqueue_element_get_weight(pqueue->entry[LEFT(index)]) < pqueue_element_get_weight(pqueue->entry[min])))
        {
            min = LEFT(index);
        }
        if ((RIGHT(index) < pqueue->number_of_entries) && (pqueue_element_get_weight(pqueue->entry[RIGHT(index)]) < pqueue_element_get_weight(pqueue->entry[min])))
        {
            min = RIGHT(index);
        }
        if (min == index)
        {
            break;
        }

        pqueue_swap(pqueue, index, min);
        index = min;
    } while (true);
}

static void pqueue_build_heap(PQUEUE* pqueue)
{
    unsigned short i;
    if (pqueue->number_of_entries > 0)
    {
        for (i = ((pqueue->number_of_entries / 2) - 1); i >= 0; i--)
        {
            pqueue_heapify(pqueue, i);
        }
    }
}

static void pqueue_swap(PQUEUE* pqueue, unsigned short index1, unsigned short index2)
{
    PQUEUE_ELEMENT* temp = pqueue->entry[index1];
    pqueue->entry[index1] = pqueue->entry[index2];
    pqueue->entry[index2] = temp;
}

/*--------------------------------HEAP-AUF-DEM-TERMINAL-AUSGEBEN--------------------*/
extern void pqueue_print(PQUEUE* pqueue)
{
    if (pqueue->number_of_entries >  0)
    {
        /*Heap auf dem Terminal ausgeben.*/
        printf("Heap: (%u Elemente)\n", (unsigned int) pqueue->number_of_entries);

        /*CODE*/
        printf("|-- %lu\n", (pqueue_element_get_weight(pqueue->entry[ROOT_INDEX])));
        print_out_heap(pqueue,ROOT_INDEX, STEP_INDEX);
    }
    else
    {
        printf("Es gibt keinen HEAP!");
    }
}

static void print_out_heap(PQUEUE* pqueue, unsigned short position, 
                                           unsigned short step)
{
    unsigned short left;
    unsigned short right;
    left = LEFT(position);
    right = RIGHT(position);

    if (left < pqueue->number_of_entries)
    {
        print_step(step);
        printf("|-- %lu\n", (pqueue_element_get_weight(pqueue->entry[left])));
        print_out_heap(pqueue,left, step + STEP_INDEX);
    }

    if (right < pqueue->number_of_entries)
    {
        print_step(step);
        printf("|-- %lu\n", (pqueue_element_get_weight(pqueue->entry[right])));
        print_out_heap(pqueue,right, step + STEP_INDEX);
    }
}

static void print_step(unsigned short step)
{
    unsigned short i;
    for (i = 0; i < step * BLANKS; i++)
    {
        printf(" ");
    }
}