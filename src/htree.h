/**
 * @file htree.h
 * 
 * Dieses Modul repräseintiert einen Huffman-Baum. 
 * Ein Huffman-Baum enthält die Zeichen, die im Inhalt einer zu 
 * komprimierenden Datei vorkommen. Diese Zeichen sind dabei als Blätter im
 * Huffman-Baum so angeordnet, dass der Weg von der Wurzel zu den Blättern 
 * die Kodierung des jeweiligen Zeichens repräsentiert.  
 * 
 * @author Tim Buschmann
 *         Artur Leinweber
 *         Alexander Schmitz
 */

#ifndef HTREE_H
#define	HTREE_H




/* ======================================================================== *
 * Typdefinitionen                                                          *
 * ======================================================================== */

/**
 * Dieser Datentyp repräsentiert einen Huffman-Baum.
 * Variablen diesen Datentyps beinhalten Huffman-Bäume. 
 */
typedef struct S_HTREE HTREE;




/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include <stdbool.h>

#include "freqtab.h"
#include "codetab.h"
#include "codetab_element.h"




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

/**
 * Diese Funktion erstelle einen Huffman-Baum auf dem Heap aus einer 
 * übergebenen Häufigkeits-Tabelle und liefert einen Zeiger auf diesen neu
 * erstellte Huffman-Baum zurück.
 * 
 * @param freqtab Zeiger auf Häufigkeits-Tabelle aus der der Huffman-Baum
 *                erstellt wird
 * @return Zeiger auf den neu erstellten Huffman-Baum
 */
extern HTREE* create_htree_from_freqtab(FREQTAB* freqtab);



/**
 * Diese Funktion erstellt einen Huffman-Baum auf dem Heap aus einer
 * übergebenen Code-Tabelle und liefert einen Zeiger auf diesen neu
 * erstellten Huffman-Baum zurück.
 * 
 * @param codetab Zeiger auf Code-Tabelle aus der der Huffman-Baum 
 *                erstellt wird
 * @return Zeiger auf den neu erstellten Huffman-Baum
 */
extern HTREE* create_htree_from_codetab(CODETAB* codetab);



/**
 * Diese Funktion löscht einen übergebenen Huffman-Baum vom Heap und gibt den
 * Speicher wieder frei.
 * 
 * @param htree Zeiger auf die Adresse des Huffman-Baumes, der gelöscht werden
 *              soll
 */
extern void delete_htree(HTREE** htree);



/**
 * Diese Funktion entnimmt dem Hufmann-baum ein Blatt und erzeugt aus diesem
 * ein Code-Tabellen-Element und liefert einen Zeiger auf das neu erstellte 
 * Code-Tabellen-element zurück. 
 * Das Schriftzeichen des neu erstellten Code-Tabellen-Elementes ist das
 * Schriftzeichen des Blattes, der Code des Code-Tabellen-Elementes ergibt
 * aus der Position des entnommenen Blattes innerhalb des Baumes.
 * 
 * @param htree Zeiger auf den Huffman-Baum dem ein Blatt entnommen wird, 
 *              welches in Form eines Code-Tabellen-Elementes zurückgeliefert
 *              wird 
 * @return Zeiger auf neu erstelltes Code-Tabellen-Element
 */
extern CODETAB_ELEMENT* htree_get_codetab_element(HTREE* htree);



/**
 * Diese Funktion liefert einen Wahrheitswert zurück, der angibt, ob der 
 * übergebene Huffman-Baum noch Blätter besitzt oder leer ist.
 *  
 * @param htree Zeiger auf den Huffman-Baum, der abgefragt werden soll 
 * @return Wahrheitswert, der gangibt ob der Huffman-Baum leer ist bzw.
 *         keine Blätter mehr enthält
 *         (true = Huffman-Baum enthält KEINE Blätter (leer);
 *          false = Huffman-Baum enthält noch Blätter)
 */
extern bool htree_is_empty(HTREE* htree);



/**
 * Diese Funktion sucht durch mehrmaliges Aufrufen bit für bit das passende
 * Schriftzeichen für einen Code in dem übergebenen Huffman-Baum 
 * und liefert true zurück, wenn ein Schriftzeichen gefunden wurde. 
 * 
 * @param htree Zeiger auf den Huffman-Baum, indem nach dem Schriftzeichen 
 *              gesucht werden soll 
 * @param bit Bit des Codes des gesuchten Schriftzeichens
 * @return Wahrheitswert, der angibt, ob bereits ein Schriftzeichen gefunden
 *         wurde
 *         (true = es wurde ein Schriftzeichen gefunden;
 *          false = es wurde bis jetzt noch kein Schriftzeichen gefunden,
 *                  die Funktion muss mit weiteren Bits aufgerufen werden)
 */
extern bool htree_search_char(HTREE* htree, bool bit);



/**
 * Diese Funktion liefert das gesuchte Schriftzeichen, dass durch mehrmaliges
 * Aufrufen der Funktion htree_search_char ermittelt aus dem
 * übergebenen Baum wurde zurück.
 * 
 * @param htree Zeiger auf den Huffman-Baum, aus dem das Schriftzeichen 
 *              zurückgeliefert werden soll
 * @return gesuchtes Schriftzeichen
 */
extern unsigned char htree_get_char(HTREE* htree);



/**
 * Diese Funktion gibt den übergebene Huffman-Baum auf dem Bildschirm aus.
 * 
 * @param htree Zeiger auf den Huffman-Baum, der auf dem Bildschirm ausgegeben 
 *              werden soll
 */
extern void htree_print(HTREE* htree);


#endif	/* HTREE_H */

