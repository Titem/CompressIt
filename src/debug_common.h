/* 
 * @file debug_common.h
 * 
 * Dieses Modul enthält alle Fehlermeldungs-Texte und soinstige Funktionen
 * zur Fehlerhandhabung.
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



/*---------------------------------------------------------------------------------*/
/*-----------------------------------ENUM FÜR FEHLER-------------------------------*/
/*---------------------------------------------------------------------------------*/
enum error_message
{
	dont_found_input_document,
	dont_found_compress_mode,
	too_many_arguments,
	cant_malloc_memory,
	in_and_output_document_are_the_same,
	help,
	AND
};




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

/*---------------------------------------------------------------------------------*/
/*---------------------PRÜFT EINEN STREAM AUF FEHLER-------------------------------*/
/*---------------------------------------------------------------------------------*/
extern void test_nullpointer_exception(FILE *file_p, char* file_name);

/*---------------------------------------------------------------------------------*/
/*---------------------GIBT DENN FEHLER AUF DEM BILDSCHIRM AUS---------------------*/
/*---------------------------------------------------------------------------------*/
extern void print_error(int error_message);


extern char* convert_char(unsigned char character);


#endif	/* DEBUG_COMMON_H */