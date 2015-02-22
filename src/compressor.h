/** 
 * @file compressor.h
 * 
 * Dieses Modul repräsentiert den Komprimierungs-Controller, der nacheinander
 * die einzelnen Schritte bei der Komprimierung sowie Dekomprimierung 
 * ansteuert.
 * 
 * @author Tim Buschmann <br>
 *         Artur Leinweber <br>
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

/**
 * Diese Funktion komprimiert den Inhalt eines übergeben Eingangs-Datenstromes 
 * (z.B. einer Datei) und schreibt die komprimierte Form dieses Inhalts in
 * den übergebenen Ausgangs-Datenstrom (z.B. eine andere Datei).
 * 
 * @param input_stream Zeiger auf Eingangs-Datenstrom
 * @param output_stream Zeiger auf Ausgangs-Datenstrom
 */
extern void compress(FILE* input_stream, FILE* output_stream);



/**
 * Diese Funktion dekomprimiert den Inhalt eines übergeben Eingangs-Datenstromes
 * (z.B. einer komprimierten Datei) und schreibt die dekomprimierte Form dieses
 * Inhalts in den übergebenen Ausgangs-Datenstrom (z.B. eine andere Datei).
 * 
 * @param input_stream Zeiger auf Eingangs-Datenstrom
 * @param output_stream Zeiger auf Ausgangs-Datenstrom
 */
extern void decompress(FILE* input_stream, FILE* output_stream);


#endif	/* COMPRESSOR_H */

