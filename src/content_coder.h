/* 
 * @file content_coder.h
 * 
 * Dieses Modul repräsentiert das kodiersystem, welches den zu 
 * komprimierenden/dekomprimierenden Inhalt enkodiert/dekodiert.
 * 
 * @author Tim Buschmann
 *         Artur Leinweber
 *         Alexander Schmitz
 */

#ifndef CONTENT_CODER_H
#define	CONTENT_CODER_H




/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include <stdio.h>

#include "codetab.h"




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

extern void encode_content(FILE* input_stream, FILE* output_stream, 
                           CODETAB* codetab, unsigned long content_length);

extern void decode_content(FILE* input_stream, FILE* output_stream,
                           HTREE* htree);


#endif	/* CONTENT_CODER_H */

