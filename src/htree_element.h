/** 
 * @file htree_element.h
 * 
 * Dieses Modul repr�sentiert ein Huffman-Baum-Element also ein Bestandteil
 * eines Huffman-Baumes. Ein solches Element kann entweder ein 
 * Knoten (htree_node) sein oder ein Blatt (htree_leaf).
 * Ein Huffman-Baum-Element stellt in etwa eine abstrakte Generalisierung eines
 * Huffman-Baum-Knotens und einem Huffman-Baum-Blattes da.
 * 
 * @author Tim Buschmann
 *         Artur Leinweber
 *         Alexander Schmitz
 */

#ifndef HTREE_ELEMENT_H
#define	HTREE_ELEMENT_H




/* ======================================================================== *
 * Typdefinitionen                                                          *
 * ======================================================================== */

/**
 * Dieser Datentyp repr�sentiert ein Huffman-Baum-Element.
 * Variablen diesen Datentyps beinhalten Huffman-Baum-Elemente. 
 */
typedef struct S_HTREE_ELEMENT HTREE_ELEMENT;


/**
 * Dieser Datentyp repr�sentiert eine Auswahl um welchen Typ von 
 * Huffman-Baum-Element es sich handelt.
 * Variablen diesen Datentyps k�nnen zwei Zust�nde annehmen, 
 * entweder Knoten oder Blatt. 
 */
typedef enum
{
    NODE,
    LEAF
} HTREE_ELEMENT_TYPE;




/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include <stdbool.h>




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

/**
 * Diese Funktion erstellt ein neues Huffman-Baum-Element auf dem Heap
 * auf Basis eines �bergebenen Huffman-Baum-Blattes oder Huffman-Baum-Knotens 
 * und der Angabe, um welchen Typ (Blatt, Knoten) von Huffman-Baum-Element
 * es sich handelt, und gibt einen Zeiger auf das neu erstellte 
 * Huffman-Baum-Element zur�ck.
 * 
 * @param type Typ-Angabe, um welchen Typ von Huffman-Baum-Element es sich 
 *             handelt (Blatt oder Knoten)
 * @param element Zeiger auf das Huffman-Baum-Blatt oder den 
 *                Huffman-Baum-Knoten der durch dieses neu erstellte 
 *                Huffman-baum-element abstrakt gekapselt werden soll
 * @return Zeiger auf das neu erstellte Huffman-Baum-Element
 */
extern HTREE_ELEMENT* create_htree_element(HTREE_ELEMENT_TYPE type, 
                                           void* element);



/**
 * Diese Funktion l�scht ein �bergebenes Huffman-Baum-Element vom Heap 
 * und gibt den Speicher wieder frei.
 * 
 * @param htree_element Zeiger auf die Adresse des Huffman-Baum-Elementes, 
 *                      das gel�scht werden soll
 */
extern void delete_htree_element(HTREE_ELEMENT** htree_element);



/**
 * Diese Funktion f�gt zwei Huffman-Baum-Elemente zusammen zu einem neu 
 * erstellten Huffamn-Baum-Element. Die beiden Huffman-baum-Elemente, die
 * zusammengef�gt werden soll, werden dabei als Kinder dem 
 * neuen Huffman-Baum-Element hinzugef�gt.
 * 
 * @param left_child Zeiger auf das Huffman-Baum-Element, welches nach dem
 *                   zusammenf�gen das linke Kind des neuen
 *                   Huffman-Baum-Elementes ist
 * @param right_child Zeiger auf das Huffman-Baum-Element, welches nach dem
 *                    zusammenf�gen das rechtes Kind des neuen
 *                    Huffman-Baum-Elementes ist
 * @return Zeiger auf das neu erstellte Huffman-Baum-Element, das die 
 *         Zusammenf�gung der zwei �bergebenen Huffman-Baum-Elemente 
 *         repr�sentiert 
 */
extern HTREE_ELEMENT* merge_htree_elements(HTREE_ELEMENT* left_child, 
                                           HTREE_ELEMENT* right_child);



/**
 * Diese Funktion liefert einen Zeiger auf das Huffman-Baum-Blatt oder den
 * Huffman-Baum-Knoten zur�ck, der vom �bergebenen Huffman-Baum-Element
 * gekapselt wird.
 * 
 * @param htree_element Zeiger auf das Huffman-Baum-Element, dessen gekapseltes
 *                      Huffman-Baum-Blatt oder Huffman-Baum-Knoten 
 *                      zur�ckgeliefert werden soll 
 * @return Zeiger auf das Huffman-Baum-Blatt oder den Huffman-Baum-Knoten,
 *         der vom �bergebenen Huffman-Baum-Element gekapselt wird
 */
extern void* htree_element_get_element(HTREE_ELEMENT* htree_element);



/**
 * Diese Funition liefert einen Wahrheitswert zur�ck, der angibt, ob das
 * �bergebene Huffman-Baum-Element ein Blatt ist bzw. ein 
 * Huffman-Baum-Blatt kapselt.
 *  
 * @param htree_element Zeiger auf das Huffman-Baum-Element, welches abgefragt
 *                      werden soll
 * @return Wahrheitswert, der angibt, ob das �bergebene Huffman-Baum-Element
 *         ein Huffman-Baum-Blatt enth�lt
 *         (true = es ist ein Blatt;
 *          false = es ist ein Knoten)
 */
extern bool htree_element_is_leaf(HTREE_ELEMENT* htree_element);



/**
 * Diese Funktion liefert einen Wahrheitswert zur�ck, der angibt, ob das 
 * �bergebene Huffman-Baum-Element als entnommen makiert ist.
 * 
 * @param htree_element Zeiger auf das Huffman-Baum-Element, welches abgefragt
 *                      werden soll
 * @return Wahrheitswert, der angibt, ob das �bergebene Huffman-Baum-Element
 *         als entnommen makiert ist
 *         (true = entnommen;
 *          false = nicht entnommen)
 */
extern bool htree_element_is_removed(HTREE_ELEMENT* htree_element);



/**
 * Diese Funktion makiert das �bergebene Huffman-Baum-Element als entnommen.
 * Haben alle Huffman-Baum-Elemente den Status entnommen, gilt der Huffman-Baum
 * als leer.
 * 
 * @param htree_element Zeiger auf das Huffman-Baum-Element, das als entnommen
 *                      makiert werden soll
 */
extern void htree_element_remove(HTREE_ELEMENT* htree_element);



/**
 * Diese Funktion gibt das �bergebene Huffman-Baum-Element auf dem 
 * Bildschirm aus.
 * 
 * @param htree_element Zeiger auf das Huffman-Baum-Element, das auf 
 *                      dem Bildschirm ausgegeben werden soll
 */
extern void htree_element_print(HTREE_ELEMENT* htree_element);


#endif	/* HTREE_ELEMENT_H */

