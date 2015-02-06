/* 
 * File:   properties.h
 * Author: Tim Buschmann
 *         Artur Leinweber
 *         Alexander Schmitz
 *
 * Created on 6. Februar 2015, 16:26
 */

#ifndef PROPERTIES_H
#define	PROPERTIES_H



#include <stdio.h>

typedef enum
{
	COMPRESS,
	DECOMPRESS,
	MANPAGE
}MODE;
/*---------------------------------------------------------------------------------*/
/*---------------DEKLERATION EINER PORPERTIES STRUCT-------------------------------*/
/*---------------------------------------------------------------------------------*/
typedef struct S_PROPERTIES PROPERTIES;





/*---------------------------------------------------------------------------------*/
/*-----ERSTELLT EINE NEUE STRUCT UND LIEFERT EINEN PROPERTIES POINTER ZURÜCK-------*/
/*---------------------------------------------------------------------------------*/
PROPERTIES* create_properties(char* argv[], int argc);


/*---------------------------------------------------------------------------------*/
/*------GIBT DEN SPEICHER WIEDER FREI BZW. LÖSCHT EINEN PROPERTIES POINTER---------*/
/*---------------------------------------------------------------------------------*/

void delete_properties(PROPERTIES(*p_properties));


/*---------------------------------------------------------------------------------*/
/*------INITIALISIERT DEN NAMEN DER AUSGABEDATEI WENN KEINE ANGEGEBEN WURDE--------*/
/*---------------------------------------------------------------------------------*/
char* init_output_filename(char* input_file_name);

#endif	/* PROPERTIES_H */

