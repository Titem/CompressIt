/**
 * @file htree_leaf.h
 * 
 * Dieses Modul repräsentiert ein Huffman-Baum-Blatt.
 * Ein solches Blatt enthält das Schriftzeichen, welches an der Position,
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
 * Dieser Datentyp repräsentiert ein Huffman-Baum-Blatt.
 * Variablen diesen Datentyps beinhalten Huffman-Baum-Blätter. 
 */
typedef struct S_HTREE_LEAF HTREE_LEAF;




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

/**
 * Diese Funktion erstellt ein neues Huffman-Baum-Blatt mit dem
 * übergebenen Schriftzeichen auf dem Heap und gibt einen Zeiger auf dieses
 * neu erstellte Huffman-Baum-Blatt zurück.
 * 
 * @param character Schriftzeichen, das in dem neu erstellten 
 *                  Huffman-Baum-Blatt gespeichert ist
 * @return Zeiger auf das neu erstellte Huffman-Baum-Blatt
 */
extern HTREE_LEAF* create_htree_leaf(unsigned char character);



/**
 * Diese Funktion löscht ein übergebenes Huffman-Baum-Blatt vom Heap 
 * und gibt den Speicher wieder frei.
 * 
 * @param htree_leaf Zeiger auf die Adresse des Huffman-Baum-Blattes, 
 *                   das gelöscht werden soll
 */
extern void delete_htree_leaf(HTREE_LEAF** htree_leaf);



/**
 * Diese Funktion liefert das Schriftzeichen des überbenen 
 * Huffman-Baum-Blattes zurück.
 * 
 * @param htree_leaf Zeiger auf das Huffman-Baum-Blatt, dessen Schriftzeichen
 *                   zurückgeliefert werden soll
 * @return Schriftzeichen des übergeben Huffman-Baum-Blattes
 */
extern unsigned char htree_leaf_get_char(HTREE_LEAF* htree_leaf);


#endif	/* HTREE_LEAF_H */

