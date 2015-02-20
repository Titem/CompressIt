
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "pqueue.h"

#include <stdlib.h>
#include <stdio.h>

#include "debug_common.h"




/* ======================================================================== *
 * Makros                                                                   *
 * ======================================================================== */

/**
 * Dieses Makro liefert f�r einen �bergebenen Index innerhalb eines 
 * Bin�ren-Heap-Arrays den Index des linken Kindes zur�ck.
 */
#define GET_LEFT_CHILD_INDEX(INDEX) ((((INDEX) * 2) + 1))

/**
 * Dieses Makro liefert f�r einen �bergebenen Index innerhalb eines 
 * Bin�ren-Heap-Arrays den Index des rechten Kindes zur�ck.
 */
#define GET_RIGHT_CHILD_INDEX(INDEX) ((((INDEX) * 2) + 2))




/* ======================================================================== *
 * Strukturdefinitionen                                                     *
 * ======================================================================== */

/** 
 * Diese Struktur beschreibt den Aufbau einer Priorit�ts-Warteschlange.
 */
struct S_PQUEUE
{
    /**
     * Diese Variable speichert die Anzahl der in dieser 
     * Priorit�ts-Warteschalnge wartenden Elemente.
     */
    unsigned short number_of_entries;
    
    /**
     * Diese Variable speichert den Zeiger auf das Bin�r-Heap-Array, 
     * welches die Zeiger auf die einzelnen Priorit�ts-Warteschalngen-Elemente
     * enth�lt. Das sich hinter dieser Variable befindende Array besitzt die
     * Struktur eines Bin�ren-Heaps. 
     */
    PQUEUE_ELEMENT* entry[256];
};




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

/**
 * Diese Funktion stellt durch umschichten des internen Haufens die 
 * Heap-Bedingung des internen Heaps der �bergebenen 
 * Priorit�ts-Warteschlange wieder her.
 * 
 * @param pqueue Zeiger auf die Priorit�ts-Warteschlange, f�r dessen intenen
 *               Heap, die Heap-Bedingung wiederhergestellt werden soll
 * @param index positive Ganzzahl [0 bis 255], die den Index repr�sentiert
 *              ab dem mit dem umschichten des internen Haufens begonnen werden
 *              soll
 */
static void pqueue_heapify(PQUEUE* pqueue, unsigned short index);



/**
 * Diese Funktion baut den internen Heap der �bergebenen 
 * Priorit�ts-Warteschalnge auf.
 * 
 * @param pqueue Zeiger auf die Priorit�ts-Warteschlange, dessen interner Heap
 *               aufgebaut werden soll
 */
static void pqueue_build_heap(PQUEUE* pqueue);



/**
 * Diese Funktion vertauscht die Warte-Position von zwei wartende Elemente 
 * innerhalb der �bergebenen Priorit�ts-Warteschlange.
 * 
 * @param pqueue Zeiger auf die Priorit�ts-Warteschlange, inder zwei 
 *               wartende Elemente ihre Warte-position tauschen sollen.
 * @param index1 positive Ganzzahl [0 bis 255], die den Index des einen zu 
 *               tauschenden Elementes repr�sentiert
 * @param index2 positive Ganzzahl [0 bis 255], die den Index des anderen zu
 *               tauschenden Elementes repr�sentiert
 */
static void pqueue_swap(PQUEUE* pqueue, unsigned short index1, 
                        unsigned short index2);



/**
 * Diese Funktion gibt ein einzelnes Element mit �bergebenen Index 
 * der internen Heap-Struktur der �bergebenen Priorit�ts-Warteschlange 
 * auf dem bildschirm aus.
 * 
 * @param pqueue Zeiger auf die Priorit�ts-Warteschalnge, aus der das Element
 *               mit dem �bergebenen Index auf dem Bildschirm ausgegeben
 *               werden soll 
 * @param index positive Ganzzahl [0 bis 255], welche den Index des Elementes
 *              repr�sentiert, das auf dem Bildschirm ausgegeben werden soll
 */
static void pqueue_print_element(PQUEUE* pqueue, unsigned short index);




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
    /* Htree-Element hinten in den Heap einf�gen */
    pqueue->entry[pqueue->number_of_entries]
            = create_pqueue_element(htree_element, weight);
    pqueue->number_of_entries++;

    /* Heapbedingung wieder herstellen */
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



extern void pqueue_print(PQUEUE* pqueue)
{
    printf("Heap der Priorit�ts-Warteschalnge:\n"
           "==================================\n");
    
    if (pqueue->number_of_entries >  0)
    {
        /*Heap auf dem Terminal ausgeben.*/
        pqueue_print_element(pqueue, 0);
        printf("\nAnzahl der Elemente: %u\n\n", 
               (unsigned int) pqueue->number_of_entries);
    }
    else
    {
        printf("Es gibt keinen HEAP!");
    }
}



static void pqueue_heapify(PQUEUE* pqueue, unsigned short index)
{
    unsigned short min;
    while (true)
    {
        min = index;
        if ((GET_LEFT_CHILD_INDEX(index) < pqueue->number_of_entries) && 
           (pqueue_element_get_weight(
                pqueue->entry[GET_LEFT_CHILD_INDEX(index)]) 
            < pqueue_element_get_weight(pqueue->entry[min])))
        {
            min = GET_LEFT_CHILD_INDEX(index);
        }
        if ((GET_RIGHT_CHILD_INDEX(index) < pqueue->number_of_entries) 
           && 
           (pqueue_element_get_weight(
                pqueue->entry[GET_RIGHT_CHILD_INDEX(index)]) 
           < pqueue_element_get_weight(pqueue->entry[min])))
        {
            min = GET_RIGHT_CHILD_INDEX(index);
        }
        if (min == index)
        {
            break;
        }

        pqueue_swap(pqueue, index, min);
        index = min;
    }
}



static void pqueue_build_heap(PQUEUE* pqueue)
{
    short i;
    if (pqueue->number_of_entries > 0)
    {
        for (i = ((((short)pqueue->number_of_entries) / 2) - 1); i >= 0; i--)
        {
            pqueue_heapify(pqueue, (unsigned short) i);
        }
    }
}



static void pqueue_swap(PQUEUE* pqueue, unsigned short index1, 
                        unsigned short index2)
{
    PQUEUE_ELEMENT* temp = pqueue->entry[index1];
    pqueue->entry[index1] = pqueue->entry[index2];
    pqueue->entry[index2] = temp;
}



static void pqueue_print_element(PQUEUE* pqueue, unsigned short index)
{
    static unsigned short step = 0;
    
    unsigned short left_child_index = GET_LEFT_CHILD_INDEX(index); 
    unsigned short right_child_index = GET_RIGHT_CHILD_INDEX(index);

    unsigned short i;
    
    for (i = 0; i <= step; i++)
    {
        printf("    ");
    }
    
    printf("|-- %lu\n", (pqueue_element_get_weight(pqueue->entry[index])));
    
    if (left_child_index < pqueue->number_of_entries)
    {   
        step++;
        pqueue_print_element(pqueue, left_child_index);
        step--;
    }

    if (right_child_index < pqueue->number_of_entries)
    {
        step++;
        pqueue_print_element(pqueue, right_child_index);
        step--;
    }
    
}
