/** 
 * @file debug_common.h
 * 
 * Dieses Modul stellt allen anderen Modulen Funktionen bereit, die zum
 * Debuggen der Anwendung ben�tigt werden.
 * 
 * @author Tim Buschmann
 *         Artur Leinweber
 *         Alexander Schmitz 
 */

#ifndef DEBUG_COMMON_H
#define	DEBUG_COMMON_H




/* #define DEBUG_HUFFMAN */




/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include <stdio.h>




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

/**
 * Diese Funktion konvertiert ein Schriftzeichen in eine menschenlesbare
 * Zeichenkette und gibt einen Zeiger auf diese Zeichenkette zur�ck.
 * Nicht menschenlesbare Steuerzeichen werden dabei in menschenlesbare 
 * K�rzel aus zwei Buchstaben �bersetzt.
 * 
 * @param character zu konvertierendes Schriftzeichen
 * @return Zeiger auf eine neu erstellte Zeichenkette, die ein menschenlesbares
 *         Equivalent zum �bergebenen Schriftzeichen enth�lt
 */
extern char* convert_char(unsigned char character);


#endif	/* DEBUG_COMMON_H */
