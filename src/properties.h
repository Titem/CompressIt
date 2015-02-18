/* 
 * @file properties.h
 * 
 * Dieses Modul repräsentiert eine Einstellungsliste mit allen Einstellungen,
 * die für das Ausführen des Programmes notwendig sind, enthält. 
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

/**
 * Dieser Datentyp repräsentiert eine Auswahl, in welchem Betriebsmodus die 
 * Anwendung ausgeführt wird.
 * Variablen diesen Datentyps können vier Zustände annehmen 
 * (undefiniert, komprimieren, dekomprimieren, Manpage anzeigen). 
 */
typedef enum
{
    UNDEFINED,
    COMPRESS,
    DECOMPRESS,
    MANPAGE
}MODE;


/**
 * Dieser Datentyp repräsentiert eine Eigenschaftsliste.
 * Variablen diesen Datentyps beinhalten Eigenschaftslisten. 
 */
typedef struct S_PROPERTIES PROPERTIES;




/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include <stdio.h>




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

/*---------------------------------------------------------------------------------*/
/*-----ERSTELLT EINE NEUE STRUCT UND LIEFERT EINEN PROPERTIES POINTER ZURÜCK-------*/
/*---------------------------------------------------------------------------------*/
extern PROPERTIES* create_properties(char** argv, int argc);


/*---------------------------------------------------------------------------------*/
/*------GIBT DEN SPEICHER WIEDER FREI BZW. LÖSCHT EINEN PROPERTIES POINTER---------*/
/*---------------------------------------------------------------------------------*/
extern void delete_properties(PROPERTIES** p_properties);

/*---------------------------------------------------------------------------------*/
/*------LIEFERT DEN COMPRESS MODUS-------------------------------------------------*/
/*---------------------------------------------------------------------------------*/
extern MODE properties_get_mode(PROPERTIES* p_properties);

/*---------------------------------------------------------------------------------*/
/*------LIEFERT DEN INPUTSTREAM ZURÜCK---------------------------------------------*/
/*---------------------------------------------------------------------------------*/
extern char* properties_get_input_filename(PROPERTIES* p_properties);

/*---------------------------------------------------------------------------------*/
/*------LIEFERT DEN INPUTSTREAM ZURÜCK---------------------------------------------*/
/*---------------------------------------------------------------------------------*/
extern FILE* properties_get_input_stream(PROPERTIES* p_properties);

/*---------------------------------------------------------------------------------*/
/*------LIEFERT DEN OUTPUTSTREAM ZURÜCK--------------------------------------------*/
/*---------------------------------------------------------------------------------*/
extern char* properties_get_output_filename(PROPERTIES* p_properties);

/*---------------------------------------------------------------------------------*/
/*------LIEFERT DEN OUTPUTSTREAM ZURÜCK--------------------------------------------*/
/*---------------------------------------------------------------------------------*/
extern FILE* properties_get_output_stream(PROPERTIES* p_properties);

#endif	/* PROPERTIES_H */

