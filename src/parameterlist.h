/**
 * @file parameterlist.h
 * 
 * Dieses Modul repräsentiert eine Parameterliste mit allen Parametern,
 * die für das Ausführen des Programmes notwendig sind. 
 * Die Parameter der Parameterliste werden aus den 
 * Programm-Aufruf-Parametern ermittelt. 
 * 
 * @author Tim Buschmann <br>
 *         Artur Leinweber <br>
 *         Alexander Schmitz
 */

#ifndef PARAMETERLIST_H
#define	PARAMETERLIST_H




/* ======================================================================== *
 * Typdefinitionen                                                          *
 * ======================================================================== */

/**
 * Dieser Datentyp repräsentiert eine Auswahl, in welchem Betriebs-Modus die 
 * Anwendung ausgeführt wird.
 * Variablen diesen Datentyps können vier Zustände annehmen 
 * (undefiniert, komprimieren, dekomprimieren, Manpage anzeigen). 
 */
typedef enum
{
    /**
     * Es ist noch nicht entschieden, was die Anwendung tun soll.
     */
    UNDEFINED,
            
    /**
     * Die Anwendung soll eine Datei komprimieren.
     */
    COMPRESS,
            
    /**
     * Die Anwendung soll eine Datei dekomprimieren.
     */
    DECOMPRESS,
            
    /**
     * Die Anwendung soll die Hilfe-Seite (Manpage) anzeigen.
     */
    MANPAGE
}RUN_MODE;


/**
 * Dieser Datentyp repräsentiert eine Parameterliste.
 * Variablen diesen Datentyps beinhalten Parameterlisten. 
 */
typedef struct S_PARAMETERLIST PARAMETERLIST;




/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include <stdio.h>




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

/**
 * Diese Funktion erstellt eine neue Parameterliste auf dem Heap auf Basis
 * der übergebenen Aufruf-Parameter und liefert einen Zeiger auf die neu 
 * erstellte Parameterliste zurück.
 * 
 * @param argv Zeiger auf ein Zeichenketten-Array, welches die Aufruf-Parameter
 *             enthält
 * @param argc positive Ganzzahl [0 bis MAX_INT], welche die Anzahl der
 *             übergebenen Aufruf-Parameter repräsentiert
 * @return Zeiger auf die neu erstellte Parameterliste
 */
extern PARAMETERLIST* create_parameterlist(char** argv, int argc);



/**
 * Diese Funktion löscht eine übergebene Parameterliste vom Heap und gibt den
 * Speicher wieder frei.
 * 
 * @param parameterlist Zeiger auf die Adresse der Parameterliste, 
 *                      die gelöscht werden soll
 */
extern void delete_parameterlist(PARAMETERLIST** parameterlist);



/**
 * Diese Funktion liefert den Betriebs-Modus der Anwendung, der in der
 * Parameterliste enthalten ist, zurück.
 * 
 * @param parameterlist Zeiger auf die Parameterliste, aus der eine Eigenschaft
 *                      zurückgeliefert werden soll
 * @return Zustandsauswahl um welchen Betriebs-modus es sich handelt
 *         (komprimieren, dekomprimieren, manpage anzeigen, undefiniert)
 */
extern RUN_MODE parameterlist_get_run_mode(PARAMETERLIST* parameterlist);



/**
 * Diese Funktion liefert einen Zeiger auf den Datei-Namen der Quell-Datei,
 * der in der übergebenen Parameterliste gespeichert ist, zurück.
 * 
 * @param parameterlist Zeiger auf die Parameterliste, aus der eine Eigenschaft
 *                      zurückgeliefert werden soll
 * @return Zeiger auf eine Zeichenkette, die den Datei-Namen der Quell-Datei
 *         enthält
 */
extern char* parameterlist_get_input_filename(PARAMETERLIST* parameterlist);



/**
 * Diese Funktion liefert einen Zeiger auf den Eingangs-Datenstrom, 
 * der in der übergebenen Parameterliste gespeichert ist, zurück.
 * 
 * @param parameterlist Zeiger auf die Parameterliste, aus der eine Eigenschaft
 *                      zurückgeliefert werden soll
 * @return Zeiger auf Eingangs-Datenstrom
 */
extern FILE* parameterlist_get_input_stream(PARAMETERLIST* parameterlist);



/**
 * Diese Funktion liefert einen Zeiger auf den Datei-Namen der Ziel-Datei,
 * der in der übergebenen Parameterliste gespeichert ist, zurück.
 * 
 * @param parameterlist Zeiger auf die Parameterliste, aus der eine Eigenschaft
 *                      zurückgeliefert werden soll
 * @return Zeiger auf eine Zeichenkette, die den Datei-Namen der Ziel-Datei
 *         enthält
 */
extern char* parameterlist_get_output_filename(PARAMETERLIST* parameterlist);



/**
 * Diese Funktion liefert einen Zeiger auf den Ausgangs-Datenstrom,
 * der in der übergebenen Parameterliste gespeichert ist, zurück.
 * 
 * @param parameterlist Zeiger auf die Parameterliste, aus der eine Eigenschaft
 *                      zurückgeliefert werden soll
 * @return Zeiger auf Ausgangs-Datenstrom
 */
extern FILE* parameterlist_get_output_stream(PARAMETERLIST* parameterlist);


#endif	/* PARAMETERLIST_H */

