/* 
 * @file htree.h
 * 
 * Dieses Modul repr�seintiert einen Huffman-Baum. 
 * Ein Huffman-Baum enth�lt die Zeichen, die im Inhalt einer zu 
 * komprimierenden Datei vorkommen. Diese Zeichen sind dabei als Bl�tter im
 * Huffman-Baum so angeordnet, dass der Weg von der Wurzel zu den Bl�ttern 
 * die Kodierung des jeweiligen Zeichens repr�sentiert.  
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
 * Dieser Datentyp repr�sentiert einen Huffman-Baum.
 * Variablen diesen Datentyps beinhalten Huffman-B�ume. 
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

extern HTREE* create_htree_from_freqtab(FREQTAB* freqtab);

extern HTREE* create_htree_from_codetab(CODETAB* codetab);

extern void delete_htree(HTREE** htree);

extern CODETAB_ELEMENT* htree_get_codetab_element(HTREE* htree);

extern bool htree_is_emty(HTREE* htree);

extern bool htree_search_char(HTREE* htree, bool bit);

extern unsigned char htree_get_char(HTREE* htree);

extern void htree_print(HTREE* htree);

#endif	/* HTREE_H */

