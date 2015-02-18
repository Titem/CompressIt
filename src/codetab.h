/* 
 * @file codetab.h
 * 
 * Dieses Modul repräsentiert eine Code-Tabelle.
 * Eine Code-Tabelle, auch Codebuch genannt, beinhaltet die Codes für die 
 * verwendeten Schriftzeichen. Die Code-Tabelle wird am Anfang der 
 * komprimierten Datei abgelegt um das spätere Dekomprimieren (Dekodieren)
 * zu ermöglichen.
 * 
 * @author Tim Buschmann
 *         Artur Leinweber
 *         Alexander Schmitz
 */

#ifndef CODETAB_H
#define	CODETAB_H




/* ======================================================================== *
 * Typdefinitionen                                                          *
 * ======================================================================== */
typedef struct S_CODETAB CODETAB;




/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include <stdio.h>
#include <stdbool.h>

#include "htree.h"
#include "codetab_element.h"




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

extern CODETAB* create_codetab(HTREE* htree);

extern CODETAB* read_codetab(FILE* input_stream);

extern void write_codetab(FILE* output_stream, CODETAB* codetab);

extern void delete_codetab(CODETAB** codetab);

extern bool* codetab_get_code(CODETAB* codetab, 
                               unsigned char character);

extern unsigned char codetab_get_code_length(CODETAB* codetab, 
                                                unsigned char character);

extern CODETAB_ELEMENT* codetab_get_element(CODETAB* codetab);

extern bool codetab_is_empty(CODETAB* codetab);

extern void codetab_print(CODETAB* codetab);



#endif	/* CODETAB_H */

