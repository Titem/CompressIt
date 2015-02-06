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
/*-----ERSTELLT EINE NEUE STRUCT UND LIEFERT EINEN PROPERTIES POINTER ZUR�CK-------*/
/*---------------------------------------------------------------------------------*/
extern PROPERTIES* create_properties(char* argv[], int argc);


/*---------------------------------------------------------------------------------*/
/*------GIBT DEN SPEICHER WIEDER FREI BZW. L�SCHT EINEN PROPERTIES POINTER---------*/
/*---------------------------------------------------------------------------------*/
extern void delete_properties(PROPERTIES(*p_properties));

/*---------------------------------------------------------------------------------*/
/*------LIEFERT DEN COMPRESS MODUS-------------------------------------------------*/
/*---------------------------------------------------------------------------------*/
extern MODE properties_get_mode(PROPERTIES* p_properties);


/*---------------------------------------------------------------------------------*/
/*------LIEFERT DEN INPUTSTREAM ZUR�CK---------------------------------------------*/
/*---------------------------------------------------------------------------------*/
extern FILE* properties_get_input_stream(PROPERTIES* p_properties);

/*---------------------------------------------------------------------------------*/
/*------LIEFERT DEN OUTPUTSTREAM ZUR�CK--------------------------------------------*/
/*---------------------------------------------------------------------------------*/
extern FILE* properties_get_output_stream(PROPERTIES* p_properties);

#endif	/* PROPERTIES_H */

