/**
 * @file htree_leaf.h
 * 
 * Dieses Modul repr�sentiert ein Huffman-Baum-Blatt.
 * Ein solches Blatt enth�lt das Schriftzeichen, welches an der Position,
 * an der sich das Blatt im Baum befindet, abgelegt ist.
 * 
 * @author Tim Buschmann <br>
 *         Artur Leinweber <br>
 *         Alexander Schmitz
 */

#ifndef HTREE_LEAF_H
#define	HTREE_LEAF_H




/* ======================================================================== *
 * Typdefinitionen                                                          *
 * ======================================================================== */

/**
 * Dieser Datentyp repr�sentiert ein Huffman-Baum-Blatt.
 * Variablen diesen Datentyps beinhalten Huffman-Baum-Bl�tter. 
 */
typedef struct S_HTREE_LEAF HTREE_LEAF;




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

/**
 * Diese Funktion erstellt ein neues Huffman-Baum-Blatt mit dem
 * �bergebenen Schriftzeichen auf dem Heap und gibt einen Zeiger auf dieses
 * neu erstellte Huffman-Baum-Blatt zur�ck.
 * 
 * @param character Schriftzeichen, das in dem neu erstellten 
 *                  Huffman-Baum-Blatt gespeichert ist
 * @return Zeiger auf das neu erstellte Huffman-Baum-Blatt
 */
extern HTREE_LEAF* create_htree_leaf(unsigned char character);



/**
 * Diese Funktion l�scht ein �bergebenes Huffman-Baum-Blatt vom Heap 
 * und gibt den Speicher wieder frei.
 * 
 * @param htree_leaf Zeiger auf die Adresse des Huffman-Baum-Blattes, 
 *                   das gel�scht werden soll
 */
extern void delete_htree_leaf(HTREE_LEAF** htree_leaf);



/**
 * Diese Funktion liefert das Schriftzeichen des �berbenen 
 * Huffman-Baum-Blattes zur�ck.
 * 
 * @param htree_leaf Zeiger auf das Huffman-Baum-Blatt, dessen Schriftzeichen
 *                   zur�ckgeliefert werden soll
 * @return Schriftzeichen des �bergeben Huffman-Baum-Blattes
 */
extern unsigned char htree_leaf_get_char(HTREE_LEAF* htree_leaf);


#endif	/* HTREE_LEAF_H */

