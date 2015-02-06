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

typedef struct S_PROPERTIES PROPERTIES;
/*		Name der Strucktur  TYP*/


/*---------------------------------------------------------------------------------*/
/*-----ERSTELLT EINE NEUE STRUCT UND LIEFERT EINEN PROPERTIES POINTER ZUR�CK-------*/
/*---------------------------------------------------------------------------------*/
PROPERTIES* create_properties(char* argv[], int argc);


/*---------------------------------------------------------------------------------*/
/*------GIBT DEN SPEICHER WIEDER FREI BZW. L�SCHT EINEN PROPERTIES POINTER---------*/
/*---------------------------------------------------------------------------------*/
void delete_properties(PROPERTIES(*p_properties));


/*---------------------------------------------------------------------------------*/
/*------INITIALISIERT DEN NAMEN DER AUSGABEDATEI WENN KEINE ANGEGEBEN WURDE--------*/
/*---------------------------------------------------------------------------------*/
char* init_output_filename(char* input_file_name);


/*---------------------------------------------------------------------------------*/
/*-----LIEFERT DEN COMPRESS STATUS ZUR�CK------------------------------------------*/
/*---------------------------------------------------------------------------------*/
MODE properties_get_mode(PROPERTIES* p_properties);


/*---------------------------------------------------------------------------------*/
/*-----LIEFER DEN INPUT STREAM ZUR�CK----------------------------------------------*/
/*---------------------------------------------------------------------------------*/
FILE* properties_get_input_stream(PROPERTIES* p_properties);


/*---------------------------------------------------------------------------------*/
/*-----LIEFERT DEN OUTPUT STREAM STREAM ZUR�CK-------------------------------------*/
/*---------------------------------------------------------------------------------*/
FILE* properties_get_output_stream(PROPERTIES* p_properties);

#endif	/* PROPERTIES_H */

