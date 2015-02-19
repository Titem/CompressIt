/* 
 * @file htree_node.h
 * 
 * Dieses Modul repräsentiert einen Huffman-Baum-Knoten.
 * Ein solcher Knoten kann vielfach im Huffman-Baum vorkommen und beschreibt 
 * die Gabelungen in der Baumstruktur. Ein Knoten kann dabei zwei weitere 
 * Kind-elemente enthalten die ein Blatt oder wiederum ein Knoten sein können.
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
 * Dieser Datentyp repräsentiert einen Huffman-Baum-Knoten.
 * Variablen diesen Datentyps beinhalten Huffman-Baum-Knoten. 
 */
typedef struct S_HTREE_NODE HTREE_NODE;




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

/**
 * Diese Funktion erstellt einen neuen Huffman-Baum-Knoten auf dem Heap
 * und verknüpft ihn mit den zwei übergebenen Kind-Elementen 
 * und gibt einen Zeiger auf diesen neu erstellten Huffman-Baum-Knoten zurück.
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
 * Diese Funktion löscht den übergebenen Huffman-Baum-Knoten vom Heap 
 * und gibt den Speicher wieder frei.
 * 
 * @param htree_node Zeiger auf die Adresse des Huffman-Baum-knotens,
 *                   der gelöscht werden soll
 */
extern void delete_htree_node(HTREE_NODE** htree_node);



/**
 * Diese Funktion liefert einen Zeiger auf das Huffman-Baum-Element zurück,
 * welches als das linke Kind des übergebenen Huffman-Baum-Knotens 
 * eingetragen ist.
 * 
 * @param htree_node Zeiger auf den Huffman-Baum-Knoten, dessen linkes Kind
 *                   zurückgeliefert werden soll
 * @return Zeiger auf das Huffman-Baum-Element, welches das linke Kind des
 *         übergebenen Huffman-Baum-Knotens ist 
 */
extern HTREE_ELEMENT* htree_node_get_left(HTREE_NODE* htree_node);



/**
 * Diese Funktion liefert einen Zeiger auf das Huffman-Baum-Element zurück,
 * welches als das rechte Kind des übergebenen Huffman-Baum-Knotens 
 * eingetragen ist.
 * 
 * @param htree_node Zeiger auf den Huffman-Baum-Knoten, dessen rechtes Kind
 *                   zurückgeliefert werden soll
 * @return Zeiger auf das Huffman-Baum-Element, welches das rechte Kind des
 *         übergebenen Huffman-Baum-Knotens ist 
 */
extern HTREE_ELEMENT* htree_node_get_right(HTREE_NODE* htree_node);



/**
 * Diese Funktion liefert einen Wahrheitswert zurück, der angibt ob der
 * übergebene Huffman-Baum-Knoten ein linkes Kind besitzt.
 * 
 * @param htree_node Zeiger auf den Huffman-Baum-Knoten der abgefragt 
 *                   werden soll
 * @return Wahrheitswert, der angibt, ob der übergebene Huffman-Baum-Knoten
 *         ein linkes Kind besitzt
 *         (true = linkes Kind vorhande;
 *          false = linkes Knind nicht vorhanden)
 */
extern bool htree_node_has_left(HTREE_NODE* htree_node);



/**
 * Diese Funktion liefert einen Wahrheitswert zurück, der angibt ob der
 * übergebene Huffman-Baum-Knoten ein rechtes Kind besitzt.
 * 
 * @param htree_node Zeiger auf den Huffman-Baum-Knoten der abgefragt 
 *                   werden soll
 * @return Wahrheitswert, der angibt, ob der übergebene Huffman-Baum-Knoten
 *         ein rechtes Kind besitzt
 *         (true = rechtes Kind vorhande;
 *          false = rechtes Knind nicht vorhanden)
 */
extern bool htree_node_has_right(HTREE_NODE* htree_node);



/**
 * Diese Funktion trägt ein übergebenes Huffman-Baum-element als linkes Kind
 * des übergebenen Huffman-Baum-Knotens ein.
 * 
 * @param htree_node Zeiger auf den Huffman-Baum-Knoten, in den das übergebene 
 *                   Huffman-Baum-Element als linkes Kind eingetragen wird
 * @param htree_element Zeiger auf das Huffman-Baum-Element, welches als 
 *                      linkes Kind in den übergebenen Huffman-Baum-Knoten 
 *                      eingetragen wird.
 */
extern void htree_node_set_left(HTREE_NODE* htree_node, 
                                HTREE_ELEMENT* htree_element);



/**
 * Diese Funktion trägt ein übergebenes Huffman-Baum-element als rechtes Kind
 * des übergebenen Huffman-Baum-Knotens ein.
 * 
 * @param htree_node Zeiger auf den Huffman-Baum-Knoten, in den das übergebene 
 *                   Huffman-Baum-Element als rechtes Kind eingetragen wird
 * @param htree_element Zeiger auf das Huffman-Baum-Element, welches als 
 *                      rechtes Kind in den übergebenen Huffman-Baum-Knoten 
 *                      eingetragen wird.
 */
extern void htree_node_set_right(HTREE_NODE* htree_node, 
                                 HTREE_ELEMENT* htree_element);


#endif	/* HTREE_NODE_H */

