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

/**
 * Dieser Datentyp repräsentiert eine Prioritäts-Warteschlang.
 * Variablen diesen Datentyps beinhalten Prioritäts-Warteschlangen. 
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
 * Diese Funktion erstellt eine neue, leere Prioritäts-Warteschlange 
 * auf dem Heap und liefert einen Zeiger auf die neu erstellte 
 * Prioritäts-Warteschlange zurück.
 * 
 * @return Zeiger auf die neu erstellte Prioritäts-Warteschlange
 */
extern PQUEUE* create_pqueue(void);



/**
 * Diese Funktion löscht eine übergebene Prioritäts-Warteschlange vom Heap 
 * und gibt den Speicher wieder frei.
 * 
 * @param pqueue Zeiger auf die Adresse der Prioritäts-Warteschlange, 
 *               die gelöscht werden soll
 */
extern void delete_pqueue(PQUEUE** pqueue);



/**
 * Diese Funktion fügt ein übergebenes Huffman-Baum-Element mit einem übergeben
 * Gewicht (reziproke Priorität) in die übergebene Prioritäts-Warteschalnge
 * ein. Das Gewicht bestimmt über die Position, die das wartende 
 * Huffman-Baum-Element in der Warteschalnge einnimmt und somit wie lange dieses
 * Element warten muss.
 * 
 * @param pqueue Zeiger auf die Prioritäts-Warteschlange, in die das
 *               Huffman-Baum-Element eingefügt werden soll
 * @param htree_element Zeiger auf das Huffman-Baum-Element, welches in die
 *                      übergebene Prioritäts-Warteschlange eingefügt 
 *                      werden soll
 * @param weight Gewicht (reziproke Priorität) mit der das Huffman-Baum-Element
 *               in die Prioritäts-Warteschlange eingefügt werden soll
 *               (ist ausschlaggebend für die Position des Elementes in der
 *                Warteschalnge bzw. wie lange das element warten muss)
 */
extern void pqueue_insert_htree_element(PQUEUE* pqueue, 
                                        HTREE_ELEMENT* htree_element,
                                        unsigned long weight);

/* char *min_element ist das Zeichen bzw. das Char Array in dem die Zeichenkette bzw. das Minimum zurï¿½ckgegeben wird.
Liefert TRUE wenn das Minimum entfernt wurde und FALSE wenn kein Element mehr existiert
evtl. den Speicherplatz verkleinern.*/

/**
 * 
 * @param pqueue
 * @return 
 */
extern PQUEUE_ELEMENT* pqueue_get_min_entry(PQUEUE* pqueue);



/**
 * Diese Funktion liefert die Anzahl der wartenden Elemente zurück, die in der 
 * übergebenen Prioritäts-Warteschlange eingetragen sind.
 * 
 * @param pqueue Zeiger auf die Prioritäts-Warteschlange, dessen Anzahl
 *               wartender Elemente (Anzahl an Einträgen) zurückgeliefert
 *               werden soll
 * @return positive Ganzzahl [0 bis 256], welche die Anzahl der wartenden 
 *         Elemente der übergeben Prioritäts-Warteschlange repräsentiert
 */
extern unsigned short pqueue_get_number_of_entries(PQUEUE* pqueue);



/**
 * Diese Funktion gibt die übergebene Prioritäts-Warteschlange auf dem 
 * Bildschirm aus.
 * 
 * @param pqueue Zeiger auf die Prioritäts-Warteschlange, die auf dem 
 *               Bildschirm ausgegeben werden soll
 */
extern void pqueue_print(PQUEUE* pqueue);


#endif	/* PQUEUE_H */

