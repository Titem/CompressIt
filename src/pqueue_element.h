/* 
 * @file pqueue_element.h
 * 
 * Dieses Modul repr�sentiert ein Priorit�ts-Warteschlangen-Element also einen
 * Eintrag in der Priorit�ts-Warteschlange. Ein solcher Eintrag enth�lt das
 * wartende Huffman-Baum-Element sowie das Gewicht dieses Element, durch das
 * sich die Priorit�t also die Position in der Warteschlange ergibt. 
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
 * Dieser Datentyp repr�sentiert ein Priorit�ts-Warteschlangen-Element.
 * Variablen diesen Datentyps beinhalten Priorit�ts-Warteschlangen-Elemente. 
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
 * Diese Funktion erstellt ein neues Priorit�ts-Warteschlangen-Element auf dem 
 * Heap, das ein �bergebenenes Huffman-Baum-Element mit dem dazugeh�rigen
 * �bergebenen Gewicht speichert und gibt einen Zeiger auf dieses
 * neu erstellte Element zur�ck.
 * 
 * @param htree_element Zeiger auf Huffman-Baum-Element, der in dem neu 
 *                      erstellten Priorit�ts-Warteschlangen-Element 
 *                      gespeichert wird  
 * @param weight positive Ganzzahl [0 bis MAX_ULONG], welche das Gewicht 
 *               repr�sentiert, das in dem neu erstellten
 *               Priorit�ts-Wartenschlangen-Element gespeichert wird
 * @return Zeiger auf das neu erstellte Priorit�ts-Warteschlangen-Element
 */
extern PQUEUE_ELEMENT* create_pqueue_element(HTREE_ELEMENT* htree_element, 
                                             unsigned long weight);



/**
 * Diese Funktion l�scht das �bergebene Priorit�ts-Warteschlangen-Element 
 * vom Heap und gibt den Speicher wieder frei.
 * 
 * @param pqueue_element Zeiger auf die Adresse des 
 *                       Priorit�ts-Warteschlangen-Elementes, das gel�scht 
 *                       werden soll
 */
extern void delete_pqueue_element(PQUEUE_ELEMENT** pqueue_element);



/**
 * Diese Funktion liefert das Gewicht (reziproke Priorit�t) des �bergeben
 * Priorit�ts-Warteschlangen-Elementes zur�ck.
 * 
 * @param pqueue Zeiger auf das Priorit�ts-Warteschlangen-Element, dessen
 *               Gewicht zur�ckgeliefert werden soll
 * @return positive Ganzzahl [0 bis MAX_ULONG], welche das Gewicht 
 *         repr�sentiert, das in dem �bergeben 
 *         Priorit�ts-Warteschlangen-Element gespeichert ist
 */
extern unsigned long pqueue_element_get_weight(PQUEUE_ELEMENT* pqueue);



/**
 * Diese Funktion liefert das Huffman-Baum-Element des �bergeben
 * Priorit�ts-Warteschlangen-Elementes zur�ck.
 * 
 * @param pqueue Zeiger auf das Priorit�ts-Warteschlangen-Element, dessen
 *               Huffman-Baum-element zur�ckgeliefert werden soll
 * @return Zeiger auf das Huffman-Baum-Element, welches in dem �bergeben
 *         Priorit�ts-Warteschlangen-Element gespeichert ist
 */
extern HTREE_ELEMENT* pqueue_element_get_htree_element(PQUEUE_ELEMENT* pqueue);


#endif	/* PQUEUE_ELEMENT_H */

