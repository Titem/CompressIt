/* 
 * @file pqueue.h
 * 
 * Dieses Modul repräsentiert eine Prioritäts-Warteschlange für 
 * Huffman-Baum-Elemente. In dieser Warteschlange warten beim erstellen 
 * eines Huffman-Baumes die einzelnen Huffman-Baum-Elemente auf ihr 
 * Zusammengefügtwerden (Merge). 
 * Die Warteschalnge kann wartende Huffman-Baum-Elemente aufnehmen. Intern 
 * werden die wartenden Huffman-Baum-Elemente in die Reihenfolge gebracht,
 * sodass das Element mit dem niedrigsten Gewicht der Wartescxhlange zuerst 
 * entnommen werden kann um es dem Merge-Prozess zuzuführen.  
 * 
 * @author Tim Buschmann
 *         Artur Leinweber
 *         Alexander Schmitz
 */

#ifndef PQUEUE_H
#define	PQUEUE_H




/* ======================================================================== *
 * Typdefinitionen                                                          *
 * ======================================================================== */

typedef struct S_PQUEUE PQUEUE;




/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "htree_element.h"

#include "pqueue_element.h"



/*Index der Wurzel bzw. des Minimums oder Maximums eines Heaps.*/
#define ROOT_INDEX 0
/*-----------------------------------------------------------------------------------------------------------------------------------*/
/*Beschreibt die Stufenschrittweite zwischen den einzelnen Elementen im Heap.*/
#define STEP_INDEX 1
/*-----------------------------------------------------------------------------------------------------------------------------------*/
/*Anzahl der Leerzeichen, die den Abstand zwischen den Elementen im Heap bestimmen.*/
#define BLANKS 4

/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */



extern PQUEUE* create_pqueue(void);

extern void delete_pqueue(PQUEUE** pqueue);

extern void pqueue_insert_htree_element(PQUEUE* pqueue, 
                                        HTREE_ELEMENT* htree_element,
                                        unsigned long weight);

/* char *min_element ist das Zeichen bzw. das Char Array in dem die Zeichenkette bzw. das Minimum zurï¿½ckgegeben wird.
Liefert TRUE wenn das Minimum entfernt wurde und FALSE wenn kein Element mehr existiert
evtl. den Speicherplatz verkleinern.*/
extern PQUEUE_ELEMENT* pqueue_get_min_entry(PQUEUE* pqueue);

extern unsigned short pqueue_get_number_of_entries(PQUEUE* pqueue);

extern void pqueue_print(PQUEUE* pqueue);


#endif	/* PQUEUE_H */

