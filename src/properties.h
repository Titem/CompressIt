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
extern PROPERTIES* create_properties(char** argv, int argc);



/**
 * Diese Funktion löscht eine übergebene Parameterliste vom Heap und gibt den
 * Speicher wieder frei.
 * 
 * @param p_properties Zeiger auf die Adresse der Parameterliste, 
 *                     die gelöscht werden soll
 */
extern void delete_properties(PROPERTIES** p_properties);



/**
 * Diese Funktion liefert den Betriebs-Modus der Anwendung, der in der
 * Parameterliste enthalten ist, zurück.
 * 
 * @param p_properties Zeiger auf die Parameterliste, aus der eine Eigenschaft
 *                     zurückgeliefert werden soll
 * @return Zustandsauswahl um welchen Betriebs-modus es sich handelt
 *         (komprimieren, dekomprimieren, manpage anzeigen, undefiniert)
 */
extern MODE properties_get_mode(PROPERTIES* p_properties);



/**
 * Diese Funktion liefert einen Zeiger auf den Datei-Namen der Quell-Datei,
 * der in der übergebenen Parameterliste gespeichert ist, zurück.
 * 
 * @param p_properties Zeiger auf die Parameterliste, aus der eine Eigenschaft
 *                     zurückgeliefert werden soll
 * @return Zeiger auf eine Zeichenkette, die den Datei-Namen der Quell-Datei
 *         enthält
 */
extern char* properties_get_input_filename(PROPERTIES* p_properties);



/**
 * Diese Funktion liefert einen Zeiger auf den Eingangs-Datenstrom, 
 * der in der übergebenen Parameterliste gespeichert ist, zurück.
 * 
 * @param p_properties Zeiger auf die Parameterliste, aus der eine Eigenschaft
 *                     zurückgeliefert werden soll
 * @return Zeiger auf Eingangs-Datenstrom
 */
extern FILE* properties_get_input_stream(PROPERTIES* p_properties);



/**
 * Diese Funktion liefert einen Zeiger auf den Datei-Namen der Ziel-Datei,
 * der in der übergebenen Parameterliste gespeichert ist, zurück.
 * 
 * @param p_properties Zeiger auf die Parameterliste, aus der eine Eigenschaft
 *                     zurückgeliefert werden soll
 * @return Zeiger auf eine Zeichenkette, die den Datei-Namen der Ziel-Datei
 *         enthält
 */
extern char* properties_get_output_filename(PROPERTIES* p_properties);



/**
 * Diese Funktion liefert einen Zeiger auf den Ausgangs-Datenstrom,
 * der in der übergebenen Parameterliste gespeichert ist, zurück.
 * 
 * @param p_properties Zeiger auf die Parameterliste, aus der eine Eigenschaft
 *                     zurückgeliefert werden soll
 * @return Zeiger auf Ausgangs-Datenstrom
 */
extern FILE* properties_get_output_stream(PROPERTIES* p_properties);


#endif	/* PROPERTIES_H */

