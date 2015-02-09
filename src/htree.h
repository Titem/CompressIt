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

extern HTREE* create_htree(FREQTAB* freqtab);

extern void delete_htree(HTREE* htree);

extern CODETAB_ELEMENT* htree_get_codetab_element(HTREE* htree, 
                                                  unsigned short code,
                                                  unsigned char code_length);

extern unsigned short htree_get_deepness(HTREE* htree);

extern void htree_print(HTREE* htree);

#endif	/* HTREE_H */

