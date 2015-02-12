/* 
 * File:   codetab.h
 * Author: Tim Buschmann
 *         Artur Leinweber
 *         Alexander Schmitz
 *
 * Created on 6. Februar 2015, 16:15
 */

#ifndef CODETAB_H
#define	CODETAB_H




/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include <stdio.h>
#include <stdbool.h>

#include "htree.h"




/* ======================================================================== *
 * Typdefinitionen                                                          *
 * ======================================================================== */
typedef struct S_CODETAB CODETAB;




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

extern CODETAB* create_codetab(HTREE* htree, unsigned long content_length);

extern CODETAB* read_codetab(FILE* input_stream);

extern void write_codetab(FILE* output_stream, CODETAB* codetab);

extern void delete_codetab(CODETAB* codetab);

extern bool** codetab_get_code(CODETAB* codetab, 
                               unsigned char character);

extern unsigned char codetab_get_code_length(CODETAB* codetab, 
                                                unsigned char character);

extern CODETAB_ELEMENT* codetab_get_element(CODETAB* codetab);

extern bool codetab_is_emty(CODETAB* codetab);

extern void codetab_print(CODETAB* codetab);



#endif	/* CODETAB_H */

