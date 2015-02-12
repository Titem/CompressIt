/* 
 * File:   content_coder.h
 * Author: Tim Buschmann
 *         Artur Leinweber
 *         Alexander Schmitz
 *
 * Created on 6. Februar 2015, 16:16
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

