/* 
 * @file compressor.h
 * 
 * Dieses Modul repräsentiert den Komprimierungs-Controller, der nacheinander
 * die einzelnen Schritte bei der Komprimierung sowie Dekomprimierung 
 * ansteuert.
 * 
 * author: Tim Buschmann
 *         Artur Leinweber
 *         Alexander Schmitz
 */

#ifndef COMPRESSOR_H
#define	COMPRESSOR_H




/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include <stdio.h>




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

extern void compress(FILE* input_stream, FILE* output_stream);

extern void decompress(FILE* input_stream, FILE* output_stream);


#endif	/* COMPRESSOR_H */

