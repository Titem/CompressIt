/** 
 * @file error_handler.h
 * 
 * Dieses Modul repräsentiert einen Fehler-Handler, der alle Funktionen
 * zur Fehlerhandhabung bereit stellt.
 * 
 * @author Tim Buschmann <br>
 *         Artur Leinweber <br>
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
    /** 
     * Ein unbekannter Fehler ist aufgetreten.
     */
    UNKNOWN_ERROR,
            
    /** 
     * Es konnte kein Speicher allociert werden.
     */
    CANT_ALLOCATE_MEMORY,
            
    /** 
     * Es wurde kein Dateiname für die Quell-Datei gefunden.
     */
    NO_INPUT_FILENAME,
            
    /** 
     * Es wurden der Anwendung zu wenige Argumente übergeben.
     */
    TO_FEW_ARGUMENTS,
    
    /** 
     * Es wurden der Anwendung zu viele Argumente übergeben.
     */
    TO_MANY_ARGUMENTS,
            
    /** 
     * Der Dateiname der Quell-Datei ist gleich dem Dateinamen der Ziel-Datei.
     */
    FILENAMES_ARE_EQUAL,
            
    /** 
     * Die Quell-Datei konnte nicht geöffnet werden.
     */
    CANT_OPEN_INPUT_FILE,
            
    /** 
     * Die Ziel-Datei konnte nicht angelegt werden.
     */
    CANT_OPEN_OUTPUT_FILE,
            
    /** 
     * Die Quell-Datei ist ungültig. Der Inhalt enthält eine 
     * ungültige Codierung.
     */
    INVALID_FILE_CONTENT_INVALID,
            
    /** 
     * Die Quell-Datei ist ungültig. Der Inhalt ist zu kurz.
     */
    INVALID_FILE_CONTENT_TO_SHORT,
            
    /** 
     * Die Quell-Datei ist ungültig. Der Inhalt ist zu lang.
     */
    INVALID_FILE_CONTENT_TO_LONG,
            
    /** 
     * Die Quell-Datei ist ungültig. Die Code-Tabelle enthält einen 
     * ungültigen Eintrag.
     */
    INVALID_FILE_CODETAB_INVALID,
            
    /** 
     * Die Quell-Datei ist ungültig. Die Code-Tabelle ist zu kurz.
     */
    INVALID_FILE_CODETAB_TO_SHORT,
            
    /** 
     * Die Quell-Datei ist ungültig. Die Inhalts-Länge ist beschädigt.
     */
    INVALID_FILE_CONTENTLENGTH_UNREADABLE,
            
    /** 
     * Die Quell-Datei ist ungültig. Die Code-Tabellen-Länge ist beschädigt.
     */
    INVALID_FILE_CODETABLENGTH_UNREADABLE,
            
    /** 
     * Die Inhalts-Länge konnte nicht gespeichert werden.
     */
    CANT_WRITE_CONTENTLENGTH,
            
    /** 
     * Die Code-Tabellen-Länge konnte nicht gespeichert werden.
     */
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

