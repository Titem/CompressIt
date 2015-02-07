/* 
 * File:   error.h
 * Author: Tim Buschmann
 *         Artur Leinweber
 *         Alexander Schmitz 
 *
 * Created on 6. Februar 2015, 16:16
 */

#ifndef ERROR_H
#define	ERROR_H




/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include <stdio.h>



/*---------------------------------------------------------------------------------*/
/*-----------------------------------ENUM F�R FEHLER-------------------------------*/
/*---------------------------------------------------------------------------------*/
enum error_message
{
	dont_found_input_document,
	dont_found_compress_mode,
	too_many_arguments,
	cant_malloc_memory,
	in_and_output_document_are_the_same,
	help,
	AND,
};




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

/*---------------------------------------------------------------------------------*/
/*---------------------PR�FT EINEN STREAM AUF FEHLER-------------------------------*/
/*---------------------------------------------------------------------------------*/
extern void test_nullpointer_exception(FILE *file_p, char* file_name);

/*---------------------------------------------------------------------------------*/
/*---------------------GIBT DENN FEHLER AUF DEM BILDSCHIRM AUS---------------------*/
/*---------------------------------------------------------------------------------*/
extern void print_error(int error_message);


extern char* convert_char(char character);


#endif	/* ERROR_H */