/* 
 * File:   htree.h
 * Author: Tim Buschmann
 *         Artur Leinweber
 *         Alexander Schmitz
 *
 * Created on 6. Februar 2015, 16:13
 */

#ifndef HTREE_H
#define	HTREE_H




/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include <stdbool.h>

#include "freqtab.h"
#include "codetab_element.h"




/* ======================================================================== *
 * Typdefinitionen                                                          *
 * ======================================================================== */

typedef struct S_HTREE HTREE;




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

extern HTREE* create_htree_from_freqtab(FREQTAB* freqtab);

extern HTREE* create_htree_from_codetab(CODETAB* codetab);

extern void delete_htree(HTREE* htree);

extern CODETAB_ELEMENT* htree_get_codetab_element(HTREE* htree);

extern bool htree_is_emty(HTREE* htree);

extern bool htree_search_char(HTREE* htree, bool bit);

extern unsigned char htree_get_char(HTREE* htree);

extern void htree_print(HTREE* htree);

#endif	/* HTREE_H */

