/**
 * @file parameterlist.h
 * 
 * Dieses Modul repr�sentiert eine Parameterliste mit allen Parametern,
 * die f�r das Ausf�hren des Programmes notwendig sind. 
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
 * Dieser Datentyp repr�sentiert eine Auswahl, in welchem Betriebs-Modus die 
 * Anwendung ausgef�hrt wird.
 * Variablen diesen Datentyps k�nnen vier Zust�nde annehmen 
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
 * Dieser Datentyp repr�sentiert eine Parameterliste.
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
 * der �bergebenen Aufruf-Parameter und liefert einen Zeiger auf die neu 
 * erstellte Parameterliste zur�ck.
 * 
 * @param argv Zeiger auf ein Zeichenketten-Array, welches die Aufruf-Parameter
 *             enth�lt
 * @param argc positive Ganzzahl [0 bis MAX_INT], welche die Anzahl der
 *             �bergebenen Aufruf-Parameter repr�sentiert
 * @return Zeiger auf die neu erstellte Parameterliste
 */
extern PARAMETERLIST* create_parameterlist(char** argv, int argc);



/**
 * Diese Funktion l�scht eine �bergebene Parameterliste vom Heap und gibt den
 * Speicher wieder frei.
 * 
 * @param parameterlist Zeiger auf die Adresse der Parameterliste, 
 *                      die gel�scht werden soll
 */
extern void delete_parameterlist(PARAMETERLIST** parameterlist);



/**
 * Diese Funktion liefert den Betriebs-Modus der Anwendung, der in der
 * Parameterliste enthalten ist, zur�ck.
 * 
 * @param parameterlist Zeiger auf die Parameterliste, aus der eine Eigenschaft
 *                      zur�ckgeliefert werden soll
 * @return Zustandsauswahl um welchen Betriebs-modus es sich handelt
 *         (komprimieren, dekomprimieren, manpage anzeigen, undefiniert)
 */
extern RUN_MODE parameterlist_get_run_mode(PARAMETERLIST* parameterlist);



/**
 * Diese Funktion liefert einen Zeiger auf den Datei-Namen der Quell-Datei,
 * der in der �bergebenen Parameterliste gespeichert ist, zur�ck.
 * 
 * @param parameterlist Zeiger auf die Parameterliste, aus der eine Eigenschaft
 *                      zur�ckgeliefert werden soll
 * @return Zeiger auf eine Zeichenkette, die den Datei-Namen der Quell-Datei
 *         enth�lt
 */
extern char* parameterlist_get_input_filename(PARAMETERLIST* parameterlist);



/**
 * Diese Funktion liefert einen Zeiger auf den Eingangs-Datenstrom, 
 * der in der �bergebenen Parameterliste gespeichert ist, zur�ck.
 * 
 * @param parameterlist Zeiger auf die Parameterliste, aus der eine Eigenschaft
 *                      zur�ckgeliefert werden soll
 * @return Zeiger auf Eingangs-Datenstrom
 */
extern FILE* parameterlist_get_input_stream(PARAMETERLIST* parameterlist);



/**
 * Diese Funktion liefert einen Zeiger auf den Datei-Namen der Ziel-Datei,
 * der in der �bergebenen Parameterliste gespeichert ist, zur�ck.
 * 
 * @param parameterlist Zeiger auf die Parameterliste, aus der eine Eigenschaft
 *                      zur�ckgeliefert werden soll
 * @return Zeiger auf eine Zeichenkette, die den Datei-Namen der Ziel-Datei
 *         enth�lt
 */
extern char* parameterlist_get_output_filename(PARAMETERLIST* parameterlist);



/**
 * Diese Funktion liefert einen Zeiger auf den Ausgangs-Datenstrom,
 * der in der �bergebenen Parameterliste gespeichert ist, zur�ck.
 * 
 * @param parameterlist Zeiger auf die Parameterliste, aus der eine Eigenschaft
 *                      zur�ckgeliefert werden soll
 * @return Zeiger auf Ausgangs-Datenstrom
 */
extern FILE* parameterlist_get_output_stream(PARAMETERLIST* parameterlist);


#endif	/* PARAMETERLIST_H */

