/* 
 * @file properties.h
 * 
 * Dieses Modul repr�sentiert eine Einstellungsliste mit allen Einstellungen,
 * die f�r das Ausf�hren des Programmes notwendig sind, enth�lt. 
 * Die Einstellungen werden aus den Programm-Aufruf-Parametern ermittelt. 
 * 
 * @author Tim Buschmann
 *         Artur Leinweber
 *         Alexander Schmitz
 */

#ifndef PROPERTIES_H
#define	PROPERTIES_H




/* ======================================================================== *
 * Typdefinitionen                                                          *
 * ======================================================================== */

typedef enum
{
    UNDEFINED,
    COMPRESS,
    DECOMPRESS,
    MANPAGE
}MODE;
/*---------------------------------------------------------------------------------*/
/*---------------DEKLERATION EINER PORPERTIES STRUCT-------------------------------*/
/*---------------------------------------------------------------------------------*/
typedef struct S_PROPERTIES PROPERTIES;




/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include <stdio.h>




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

/*---------------------------------------------------------------------------------*/
/*-----ERSTELLT EINE NEUE STRUCT UND LIEFERT EINEN PROPERTIES POINTER ZUR�CK-------*/
/*---------------------------------------------------------------------------------*/
extern PROPERTIES* create_properties(char** argv, int argc);


/*---------------------------------------------------------------------------------*/
/*------GIBT DEN SPEICHER WIEDER FREI BZW. L�SCHT EINEN PROPERTIES POINTER---------*/
/*---------------------------------------------------------------------------------*/
extern void delete_properties(PROPERTIES** p_properties);

/*---------------------------------------------------------------------------------*/
/*------LIEFERT DEN COMPRESS MODUS-------------------------------------------------*/
/*---------------------------------------------------------------------------------*/
extern MODE properties_get_mode(PROPERTIES* p_properties);

/*---------------------------------------------------------------------------------*/
/*------LIEFERT DEN INPUTSTREAM ZUR�CK---------------------------------------------*/
/*---------------------------------------------------------------------------------*/
extern char* properties_get_input_filename(PROPERTIES* p_properties);

/*---------------------------------------------------------------------------------*/
/*------LIEFERT DEN INPUTSTREAM ZUR�CK---------------------------------------------*/
/*---------------------------------------------------------------------------------*/
extern FILE* properties_get_input_stream(PROPERTIES* p_properties);

/*---------------------------------------------------------------------------------*/
/*------LIEFERT DEN OUTPUTSTREAM ZUR�CK--------------------------------------------*/
/*---------------------------------------------------------------------------------*/
extern char* properties_get_output_filename(PROPERTIES* p_properties);

/*---------------------------------------------------------------------------------*/
/*------LIEFERT DEN OUTPUTSTREAM ZUR�CK--------------------------------------------*/
/*---------------------------------------------------------------------------------*/
extern FILE* properties_get_output_stream(PROPERTIES* p_properties);

#endif	/* PROPERTIES_H */

