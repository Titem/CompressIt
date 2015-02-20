/** 
 * @file error_handler.h
 * 
 * Dieses Modul repräsentiert einen Fehler-Handler, der alle Funktionen
 * zur Fehlerhandhabung bereit stellt.
 * 
 * @author Tim Buschmann
 *         Artur Leinweber
 *         Alexander Schmitz 
 */

#ifndef ERROR_HANDLER_H
#define	ERROR_HANDLER_H




/* ======================================================================== *
 * Typdefinitionen                                                          *
 * ======================================================================== */

/**
 * Dieser Datentyp repräsentiert eine Auswahl um welchen Fehler 
 * es sich handelt. 
 */
typedef enum
{
    UNKNOWN_ERROR,
    CANT_ALLOCATE_MEMORY,
    NO_INPUT_FILENAME,
    TO_FEW_ARGUMENTS,
    TO_MANY_ARGUMENTS,
    FILENAMES_ARE_EQUAL,
    CANT_OPEN_INPUT_FILE,
    CANT_OPEN_OUTPUT_FILE,
    INVALID_FILE_CONTENT_INVALID,
    INVALID_FILE_CONTENT_TO_SHORT,
    INVALID_FILE_CONTENT_TO_LONG,
    INVALID_FILE_CODETAB_INVALID,
    INVALID_FILE_CODETAB_TO_SHORT,
    INVALID_FILE_CONTENTLENGTH_UNREADABLE,
    INVALID_FILE_CODETABLENGTH_UNREADABLE,
    CANT_WRITE_CONTENTLENGTH,
    CANT_WRITE_CODETABLENGTH
} ERROR;




/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "parameterlist.h"




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

/**
 * Diese Funktion aktiviert den Error-Handler.
 * Der Error-Handler benötigt um korrekt zu arbeiten die Parameterliste.
 * 
 * @param parameterlist Zeiger auf die Parameterliste
 */
extern void error_handler_activate(PARAMETERLIST* parameterlist);



/**
 * Diese Funktion behandelt einen übergebenen Fehler.
 * 
 * @param error Auswahl, um welchen Fehler es sich handelt
 * @param file Zeiger auf Zeichenkette, deren Inhalt der Name des 
 *             Moduls (Datei) ist, in der der Fehler aufgetreten ist
 * @param line positive Ganzzahl [1 bis MAX_INT], welche die Zeilennummer
 *             der Zeile repräsentiert, inder der Fehler aufgetreten ist
 */
extern void error_handler_handle_error(ERROR error, char* file, int line);


#endif	/* ERROR_HANDLER_H */

