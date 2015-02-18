/* 
 * @file codetab_element.h
 * 
 * Dieses Modul repräsentiert ein Code-Tabellen-Element also einen Eintrag 
 * in der Code-Tabelle. Ein solcher Eintrag enthält den Code mit seiner 
 * Code-Länge und das Zeichen, welches durch den Code repräsentiert wird. 
 * 
 * @author Tim Buschmann
 *         Artur Leinweber
 *         Alexander Schmitz
 */

#ifndef CODETAB_ELEMENT_H
#define	CODETAB_ELEMENT_H


#include "codetab_element.h"

/* ======================================================================== *
 * Typdefinitionen                                                          *
 * ======================================================================== */

/**
 * Dieser Datentyp repräsentiert ein Code-Tabellen-Element.
 * Variablen diesen Datentyps beinhalten Code-Tabellen-Element. 
 */
typedef struct S_CODETAB_ELEMENT CODETAB_ELEMENT;




/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include <stdbool.h>



/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

extern CODETAB_ELEMENT* create_codetab_element(unsigned char character, 
                                               bool* code,
                                               unsigned char code_length);

extern void delete_codetab_element(CODETAB_ELEMENT** codetab_element);

extern bool codetab_element_is_bit_set(CODETAB_ELEMENT* codetab_element, 
                                       unsigned char position);

extern unsigned char codetab_element_get_char
                     (CODETAB_ELEMENT* codetab_element);

extern bool* codetab_element_get_code(CODETAB_ELEMENT* codetab_element);

extern unsigned char codetab_element_get_code_length
                     (CODETAB_ELEMENT* codetab_element);


#endif	/* CODETAB_ELEMENT_H */

