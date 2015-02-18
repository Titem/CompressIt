/* 
 * @file pqueue_element.h
 * 
 * Dieses Modul repräsentiert ein Prioritäts-Warteschlangen-Element also einen
 * Eintrag in der Prioritäts-Warteschlange. Ein solcher Eintrag enthält das
 * wartende Huffman-Baum-Element sowie das Gewicht dieses Element, durch das
 * sich die Priorität also die Position in der Warteschlange ergibt. 
 * 
 * @author Tim Buschmann
 *         Artur Leinweber
 *         Alexander Schmitz
 */

#ifndef PQUEUE_ELEMENT_H
#define	PQUEUE_ELEMENT_H




/* ======================================================================== *
 * Typdefinitionen                                                          *
 * ======================================================================== */

/**
 * Dieser Datentyp repräsentiert ein Prioritäts-Warteschlangen-Element.
 * Variablen diesen Datentyps beinhalten Prioritäts-Warteschlangen-Elemente. 
 */
typedef struct S_PQUEUE_ELEMENT PQUEUE_ELEMENT;




/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include <stdbool.h>

#include "htree_element.h"




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

/**
 * Diese Funktion erstellt ein neues Prioritäts-Warteschlangen-Element auf dem 
 * Heap, das ein übergebenenes Huffman-Baum-Element mit dem dazugehörigen
 * übergebenen Gewicht speichert und gibt einen Zeiger auf dieses
 * neu erstellte Element zurück.
 * 
 * @param htree_element Zeiger auf Huffman-Baum-Element, der in dem neu 
 *                      erstellten Prioritäts-Warteschlangen-Element 
 *                      gespeichert wird  
 * @param weight positive Ganzzahl [0 bis MAX_ULONG], welche das Gewicht 
 *               repräsentiert, das in dem neu erstellten
 *               Prioritäts-Wartenschlangen-Element gespeichert wird
 * @return Zeiger auf das neu erstellte Prioritäts-Warteschlangen-Element
 */
extern PQUEUE_ELEMENT* create_pqueue_element(HTREE_ELEMENT* htree_element, 
                                             unsigned long weight);



/**
 * Diese Funktion löscht das übergebene Prioritäts-Warteschlangen-Element 
 * vom Heap und gibt den Speicher wieder frei.
 * 
 * @param pqueue_element Zeiger auf die Adresse des 
 *                       Prioritäts-Warteschlangen-Elementes, das gelöscht 
 *                       werden soll
 */
extern void delete_pqueue_element(PQUEUE_ELEMENT** pqueue_element);



/**
 * Diese Funktion liefert das Gewicht (reziproke Priorität) des übergeben
 * Prioritäts-Warteschlangen-Elementes zurück.
 * 
 * @param pqueue Zeiger auf das Prioritäts-Warteschlangen-Element, dessen
 *               Gewicht zurückgeliefert werden soll
 * @return positive Ganzzahl [0 bis MAX_ULONG], welche das Gewicht 
 *         repräsentiert, das in dem übergeben 
 *         Prioritäts-Warteschlangen-Element gespeichert ist
 */
extern unsigned long pqueue_element_get_weight(PQUEUE_ELEMENT* pqueue);



/**
 * Diese Funktion liefert das Huffman-Baum-Element des übergeben
 * Prioritäts-Warteschlangen-Elementes zurück.
 * 
 * @param pqueue Zeiger auf das Prioritäts-Warteschlangen-Element, dessen
 *               Huffman-Baum-element zurückgeliefert werden soll
 * @return Zeiger auf das Huffman-Baum-Element, welches in dem übergeben
 *         Prioritäts-Warteschlangen-Element gespeichert ist
 */
extern HTREE_ELEMENT* pqueue_element_get_htree_element(PQUEUE_ELEMENT* pqueue);


#endif	/* PQUEUE_ELEMENT_H */

