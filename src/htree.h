/* 
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

extern HTREE* create_htree_from_freqtab(FREQTAB* freqtab);

extern HTREE* create_htree_from_codetab(CODETAB* codetab);

extern void delete_htree(HTREE** htree);

extern CODETAB_ELEMENT* htree_get_codetab_element(HTREE* htree);

extern bool htree_is_emty(HTREE* htree);

extern bool htree_search_char(HTREE* htree, bool bit);

extern unsigned char htree_get_char(HTREE* htree);

extern void htree_print(HTREE* htree);

#endif	/* HTREE_H */

