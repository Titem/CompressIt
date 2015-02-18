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

/**
 * Diese Funktion enkodiert einen Inhalt, der von dem übergeben 
 * Eingangs-Datenstrom (z.B. einer Datei) geliefert wird mit der Codierung, 
 * welche durch die übergebene Code-Tabelle geliefert wird, in einen
 * kodierten Inhalt und schreibt diesen in den Ausgangs-Datenstrom 
 * (z.B. eine andere Datei).
 *  
 * @param input_stream Zeiger auf Eingangs-Datenstrom
 * @param output_stream Zeiger auf Ausgangs-Datenstrom
 * @param codetab Zeiger auf Code-Tabelle in der sich die Codes befinden, mit
 *                denen die Schriftzeichen des Inhaltes in Bitfolgen 
 *                enkodiert werden
 * @param content_length positive Ganzzahl [0 bis MAX_ULONG], welche die 
 *                       Länge des Inhalts (in Zeichen bzw. Byts) 
 *                       repräsentiert, der enkodiert werden soll
 *                       (muss mit in den Ausgangs-Datenstrom geschrieben 
 *                       werden, damit der inhalt später wieder dekodiert
 *                       werden kann)
 */
extern void encode_content(FILE* input_stream, FILE* output_stream, 
                           CODETAB* codetab, unsigned long content_length);



/**
 * Diese Funktion dekodiert einen zuvor kodierten Inhalt, der von dem 
 * übergebenen Eingangs-Datenstrom (z.B. einer kodierten Datei) geliefert
 * wird mittels eines übergeben Huffman-Baumes zurück zu einem nicht kodierten
 * Inhalt und schreibt diesen in den ausgangs-datenstrom (z.B. eine andere
 * Datei).
 * 
 * @param input_stream Zeiger auf Eingangs-Datenstrom
 * @param output_stream Zeiger auf Ausgangs-Datenstrom
 * @param htree Zeiger auf Huffman-Baum mit dessen Hilfe die Bitfolgen-Codes
 *              des kodierten Inhaltes in Schriftzeichen dekodiert 
 *              werden können 
 */
extern void decode_content(FILE* input_stream, FILE* output_stream,
                           HTREE* htree);


#endif	/* CONTENT_CODER_H */

