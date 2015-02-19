/* 
 * @file htree_node.h
 * 
 * Dieses Modul repr�sentiert einen Huffman-Baum-Knoten.
 * Ein solcher Knoten kann vielfach im Huffman-Baum vorkommen und beschreibt 
 * die Gabelungen in der Baumstruktur. Ein Knoten kann dabei zwei weitere 
 * Kind-elemente enthalten die ein Blatt oder wiederum ein Knoten sein k�nnen.
 * 
 * @author Tim Buschmann
 *         Artur Leinweber
 *         Alexander Schmitz
 */

#ifndef HTREE_NODE_H
#define	HTREE_NODE_H




/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include <stdbool.h>

#include "htree_element.h"




/* ======================================================================== *
 * Typdefinitionen                                                          *
 * ======================================================================== */

/**
 * Dieser Datentyp repr�sentiert einen Huffman-Baum-Knoten.
 * Variablen diesen Datentyps beinhalten Huffman-Baum-Knoten. 
 */
typedef struct S_HTREE_NODE HTREE_NODE;




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

/**
 * Diese Funktion erstellt einen neuen Huffman-Baum-Knoten auf dem Heap
 * und verkn�pft ihn mit den zwei �bergebenen Kind-Elementen 
 * und gibt einen Zeiger auf diesen neu erstellten Huffman-Baum-Knoten zur�ck.
 * 
 * @param left_child Zeiger auf das Huffman-Baum-Element, welches als linkes
 *                   Kind des neu erstellten Knotens eingetragen werden soll
 * @param right_child Zeiger auf das Huffman-Baum-Element, welches als rechtes
 *                    Kind des neu erstellten Knotens eingetragen werden soll
 * @return Zeiger auf den neu erstellten Huffman-Baum-Knoten
 */
extern HTREE_NODE* create_htree_node(HTREE_ELEMENT* left_child, 
                                     HTREE_ELEMENT* right_child);



/**
 * Diese Funktion l�scht den �bergebenen Huffman-Baum-Knoten vom Heap 
 * und gibt den Speicher wieder frei.
 * 
 * @param htree_node Zeiger auf die Adresse des Huffman-Baum-knotens,
 *                   der gel�scht werden soll
 */
extern void delete_htree_node(HTREE_NODE** htree_node);



/**
 * Diese Funktion liefert einen Zeiger auf das Huffman-Baum-Element zur�ck,
 * welches als das linke Kind des �bergebenen Huffman-Baum-Knotens 
 * eingetragen ist.
 * 
 * @param htree_node Zeiger auf den Huffman-Baum-Knoten, dessen linkes Kind
 *                   zur�ckgeliefert werden soll
 * @return Zeiger auf das Huffman-Baum-Element, welches das linke Kind des
 *         �bergebenen Huffman-Baum-Knotens ist 
 */
extern HTREE_ELEMENT* htree_node_get_left(HTREE_NODE* htree_node);



/**
 * Diese Funktion liefert einen Zeiger auf das Huffman-Baum-Element zur�ck,
 * welches als das rechte Kind des �bergebenen Huffman-Baum-Knotens 
 * eingetragen ist.
 * 
 * @param htree_node Zeiger auf den Huffman-Baum-Knoten, dessen rechtes Kind
 *                   zur�ckgeliefert werden soll
 * @return Zeiger auf das Huffman-Baum-Element, welches das rechte Kind des
 *         �bergebenen Huffman-Baum-Knotens ist 
 */
extern HTREE_ELEMENT* htree_node_get_right(HTREE_NODE* htree_node);



/**
 * Diese Funktion liefert einen Wahrheitswert zur�ck, der angibt ob der
 * �bergebene Huffman-Baum-Knoten ein linkes Kind besitzt.
 * 
 * @param htree_node Zeiger auf den Huffman-Baum-Knoten der abgefragt 
 *                   werden soll
 * @return Wahrheitswert, der angibt, ob der �bergebene Huffman-Baum-Knoten
 *         ein linkes Kind besitzt
 *         (true = linkes Kind vorhande;
 *          false = linkes Knind nicht vorhanden)
 */
extern bool htree_node_has_left(HTREE_NODE* htree_node);



/**
 * Diese Funktion liefert einen Wahrheitswert zur�ck, der angibt ob der
 * �bergebene Huffman-Baum-Knoten ein rechtes Kind besitzt.
 * 
 * @param htree_node Zeiger auf den Huffman-Baum-Knoten der abgefragt 
 *                   werden soll
 * @return Wahrheitswert, der angibt, ob der �bergebene Huffman-Baum-Knoten
 *         ein rechtes Kind besitzt
 *         (true = rechtes Kind vorhande;
 *          false = rechtes Knind nicht vorhanden)
 */
extern bool htree_node_has_right(HTREE_NODE* htree_node);



/**
 * Diese Funktion tr�gt ein �bergebenes Huffman-Baum-element als linkes Kind
 * des �bergebenen Huffman-Baum-Knotens ein.
 * 
 * @param htree_node Zeiger auf den Huffman-Baum-Knoten, in den das �bergebene 
 *                   Huffman-Baum-Element als linkes Kind eingetragen wird
 * @param htree_element Zeiger auf das Huffman-Baum-Element, welches als 
 *                      linkes Kind in den �bergebenen Huffman-Baum-Knoten 
 *                      eingetragen wird.
 */
extern void htree_node_set_left(HTREE_NODE* htree_node, 
                                HTREE_ELEMENT* htree_element);



/**
 * Diese Funktion tr�gt ein �bergebenes Huffman-Baum-element als rechtes Kind
 * des �bergebenen Huffman-Baum-Knotens ein.
 * 
 * @param htree_node Zeiger auf den Huffman-Baum-Knoten, in den das �bergebene 
 *                   Huffman-Baum-Element als rechtes Kind eingetragen wird
 * @param htree_element Zeiger auf das Huffman-Baum-Element, welches als 
 *                      rechtes Kind in den �bergebenen Huffman-Baum-Knoten 
 *                      eingetragen wird.
 */
extern void htree_node_set_right(HTREE_NODE* htree_node, 
                                 HTREE_ELEMENT* htree_element);


#endif	/* HTREE_NODE_H */

