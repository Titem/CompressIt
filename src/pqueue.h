/**
 * @file pqueue.h
 * 
 * Dieses Modul repr�sentiert eine Priorit�ts-Warteschlange f�r 
 * Huffman-Baum-Elemente. In dieser Warteschlange warten beim erstellen 
 * eines Huffman-Baumes die einzelnen Huffman-Baum-Elemente auf ihr 
 * Zusammengef�gtwerden (Merge). 
 * Die Warteschalnge kann wartende Huffman-Baum-Elemente aufnehmen. Intern 
 * werden die wartenden Huffman-Baum-Elemente in die Reihenfolge gebracht,
 * sodass das Element mit dem niedrigsten Gewicht der Wartescxhlange zuerst 
 * entnommen werden kann um es dem Merge-Prozess zuzuf�hren.  
 * 
 * @author Tim Buschmann <br>
 *         Artur Leinweber <br>
 *         Alexander Schmitz
 */

#ifndef PQUEUE_H
#define	PQUEUE_H




/* ======================================================================== *
 * Typdefinitionen                                                          *
 * ======================================================================== */

/**
 * Dieser Datentyp repr�sentiert eine Priorit�ts-Warteschlang.
 * Variablen diesen Datentyps beinhalten Priorit�ts-Warteschlangen. 
 */
typedef struct S_PQUEUE PQUEUE;




/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "htree_element.h"

#include "pqueue_element.h"




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

/**
 * Diese Funktion erstellt eine neue, leere Priorit�ts-Warteschlange 
 * auf dem Heap und liefert einen Zeiger auf die neu erstellte 
 * Priorit�ts-Warteschlange zur�ck.
 * 
 * @return Zeiger auf die neu erstellte Priorit�ts-Warteschlange
 */
extern PQUEUE* create_pqueue(void);



/**
 * Diese Funktion l�scht eine �bergebene Priorit�ts-Warteschlange vom Heap 
 * und gibt den Speicher wieder frei.
 * 
 * @param pqueue Zeiger auf die Adresse der Priorit�ts-Warteschlange, 
 *               die gel�scht werden soll
 */
extern void delete_pqueue(PQUEUE** pqueue);



/**
 * Diese Funktion f�gt ein �bergebenes Huffman-Baum-Element mit einem �bergeben
 * Gewicht (reziproke Priorit�t) in die �bergebene Priorit�ts-Warteschalnge
 * ein. Das Gewicht bestimmt �ber die Position, die das wartende 
 * Huffman-Baum-Element in der Warteschalnge einnimmt und somit wie lange dieses
 * Element warten muss.
 * 
 * @param pqueue Zeiger auf die Priorit�ts-Warteschlange, in die das
 *               Huffman-Baum-Element eingef�gt werden soll
 * @param htree_element Zeiger auf das Huffman-Baum-Element, welches in die
 *                      �bergebene Priorit�ts-Warteschlange eingef�gt 
 *                      werden soll
 * @param weight Gewicht (reziproke Priorit�t) mit der das Huffman-Baum-Element
 *               in die Priorit�ts-Warteschlange eingef�gt werden soll
 *               (ist ausschlaggebend f�r die Position des Elementes in der
 *                Warteschalnge bzw. wie lange das element warten muss)
 */
extern void pqueue_insert_htree_element(PQUEUE* pqueue, 
                                        HTREE_ELEMENT* htree_element,
                                        unsigned long weight);



/**
 * Diese Funktion entnimmt das vorderste wartende Element der �bergebenen 
 * Priorit�ts-Warteschlange und liefert einen Zeiger auf dieses entnommene
 * Element zur�ck. Dises entnommende Element ist das Element mit dem 
 * kleinsten Gewicht und somit der gr��ten Priorit�t.
 * 
 * @param pqueue Zeiger auf die Priorit�ts-Warteschlange, der das h�chst
 *               priorisierte Element mit dem kleinsten Gewicht entnommen
 *               werden soll
 * @return Zeiger auf das entnommene Priorit�ts-Warteschlangen-Element
 */
extern PQUEUE_ELEMENT* pqueue_get_min_entry(PQUEUE* pqueue);



/**
 * Diese Funktion liefert die Anzahl der wartenden Elemente zur�ck, die in der 
 * �bergebenen Priorit�ts-Warteschlange eingetragen sind.
 * 
 * @param pqueue Zeiger auf die Priorit�ts-Warteschlange, dessen Anzahl
 *               wartender Elemente (Anzahl an Eintr�gen) zur�ckgeliefert
 *               werden soll
 * @return positive Ganzzahl [0 bis 256], welche die Anzahl der wartenden 
 *         Elemente der �bergeben Priorit�ts-Warteschlange repr�sentiert
 */
extern unsigned short pqueue_get_number_of_entries(PQUEUE* pqueue);



/**
 * Diese Funktion gibt die �bergebene Priorit�ts-Warteschlange auf dem 
 * Bildschirm aus.
 * 
 * @param pqueue Zeiger auf die Priorit�ts-Warteschlange, die auf dem 
 *               Bildschirm ausgegeben werden soll
 */
 /*@unused@*/
extern void pqueue_print(PQUEUE* pqueue);


#endif	/* PQUEUE_H */

