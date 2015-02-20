/**
 * @file codetab.h
 *
 * Dieses Modul repr�sentiert eine Code-Tabelle.
 * Eine Code-Tabelle, auch Codebuch genannt, beinhaltet die Codes f�r die
 * verwendeten Schriftzeichen. Die Code-Tabelle wird am Anfang der
 * komprimierten Datei abgelegt um das sp�tere Dekomprimieren (Dekodieren)
 * zu erm�glichen.
 *
 * @author Tim Buschmann
 *         Artur Leinweber
 *         Alexander Schmitz
 */

#ifndef CODETAB_H
#define	CODETAB_H




/* ======================================================================== *
 * Typdefinitionen                                                          *
 * ======================================================================== */

/**
 * Dieser Datentyp repr�sentiert eine Code-Tabelle.
 * Variablen diesen Datentyps beinhalten Code-Tabellen.
 */
typedef struct S_CODETAB CODETAB;




/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include <stdio.h>
#include <stdbool.h>

#include "htree.h"
#include "codetab_element.h"




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

/**
 * Diese Funktion erstellt eine neue Code-Tabelle auf dem Heap auf Basis
 * eines �bergebenen Huffman-Baumes und liefert einen Zeiger auf die neu
 * erstellte Code-Tabelle zur�ck.
 *
 * @param htree Zeiger auf Huffman-Baum auf dessen Basis die Code-Tabelle
 *              erstellt wird
 * @return Zeiger auf neu erstellte Code-Tabelle
 */
extern CODETAB* create_codetab(HTREE* htree);



/**
 * Diese Funktion liest eine gespeicherte Code-Tabelle aus eine �bergebenen
 * Eingangs-Datenstrom (z.b. aus einer Datei), legt diese im Heap an und
 * liefert einen Zeiger auf die neu angelegte Code-Tabelle zur�ck.
 * Der �bergebene Eingangs-Datenstrom muss an der Stelle stehen, an der die
 * in der Datei gespeicherte Code-Tabelle beginnt.
 *
 * @param input_stream Zeiger auf Datenstrom-Struktur, die die gespeicherte
 *                     Code-Tabelle liefert
 * @return Zeiger auf ausgelesene Code-Tabelle
 */
extern CODETAB* read_codetab(FILE* input_stream);



/**
 * Diese Funktion schreibt eine �bergebene Code-Tabelle in einen �bergeben
 * Ausgangs-Datenstrom (z.B. in eine Datei).
 *
 * @param output_stream Zeiger auf Datenstrom-Strukturm in die Code-Tabelle
 *                      geschrieben werden soll
 * @param codetab Zeiger auf Code-Tabelle die weggeschrieben werden soll
 */
extern void write_codetab(FILE* output_stream, CODETAB* codetab);



/**
 * Diese Funktion l�scht eine �bergebene Code-Tabelle vom Heap und gibt den
 * Speicher wieder frei.
 *
 * @param codetab Zeiger auf die Adresse der Code-Tabelle, die gel�scht werden
 *                soll
 */
extern void delete_codetab(CODETAB** codetab);



/**
 * Diese Funktion liefert den Code f�r das �bergebene Zeichen.
 *
 * @param codetab Zeiger auf die Code-Tabelle die abgefragt werden soll
 * @param character Zeichen f�r das der passende Code geliefert werden soll
 * @return Zeiger auf Code-Array, welches den Code f�r das �bergebene
 *         Zeichen enth�lt
 */
extern bool* codetab_get_code(CODETAB* codetab,
                               unsigned char character);



/**
 * Diese Funktion liefert die Code-L�nge f�r das �bergebene Zeichen.
 *
 * @param codetab Zeiger auf die Code-Tabelle die abgefragt werden soll
 * @param character Zeichen f�r das die passende Code-L�nge geliefert
 *                  werden soll
 * @return positive Ganzzahl [0 bis 255]
 *         welche die Code-L�nge f�r das �bergebene Zeichen repr�sentiert
 */
extern unsigned char codetab_get_code_length(CODETAB* codetab,
                                             unsigned char character);



/**
 * Diese Funktion entnimmt ein Code-Tabellen-Element aus der �bergebenen
 * Code-Tabelle und liefert einen Zeiger auf das entnommene Element zur�ck.
 *
 * @param codetab Zeiger auf die Code-Tabelle,
 *                der ein Element entnommen werden soll
 * @return Zeiger auf entnommenes Code-Tabellen-Element
 */
extern CODETAB_ELEMENT* codetab_get_element(CODETAB* codetab);



/**
 * Diese Funktion liefert einen Wahrheitswert zur�ck, der angibt, ob die
 * �bergebene Code-Tabelle noch Elemente enth�lt, oder leer ist.
 *
 * @param codetab Zeiger auf die Code-Tabelle, die abgefragt werden soll
 * @return Wahrheitswert, der gangibt ob die Code-Tabelle leer ist
 *         (true = Code-Tabelle enth�lt KEINE Elemente (leer);
 *          false = Code-Tabelle enth�lt noch Elemente)
 */
extern bool codetab_is_empty(CODETAB* codetab);



/**
 * Diese Funktion gibt die �bergebene Code-Tabelle auf dem Bildschirm aus.
 *
 * @param codetab Zeiger auf Code-Tabelle, die auf dem Bildschirm ausgegeben
 *                werden soll
 */
 /*@unused@*/
extern void codetab_print(CODETAB* codetab);


#endif	/* CODETAB_H */

