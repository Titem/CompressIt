/**
 * @file freqtab.h
 * 
 * Dieses Modul repr�sentiert eine H�ufigkeits-Tabelle.
 * Eine H�ufigkeits-Tabelle beinhaltet die H�ufigkeiten, mit der jedes 
 * verwendete Schriftzeichen im Inhalt der zu komprimierenden Datei vorkommt. 
 * 
 * @author Tim Buschmann
 *         Artur Leinweber
 *         Alexander Schmitz 
 */

#ifndef FREQTAB_H
#define	FREQTAB_H




/* ======================================================================== *
 * Typdefinitionen                                                          *
 * ======================================================================== */

/**
 * Dieser Datentyp repr�sentiert eine H�ufigkeits-Tabelle.
 * Variablen diesen Datentyps beinhalten H�ufigkeits-Tabellen. 
 */
typedef struct S_FREQTAB FREQTAB;




/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include <stdbool.h>
#include <stdio.h>

#include "freqtab_element.h"




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

/**
 * Diese Funktion erstellt eine neue H�ufigkeits-Tabelle auf dem Heap und 
 * f�llt diese mit den H�ufigkeiten der verschiedenen Schriftzeichen auf, wie
 * h�ufig diese Schriftzeichen im �bergebenen Eingangs-Datenstrom vorkommen, 
 * und liefert einen Zeiger auf die neu erstellte H�ufigkeits-Tabelle zu�ck.
 * 
 * @param input_stream Zeiger auf Eingangs-Datenstrom
 * @return Zeiger auf die neu erstellte H�ufigkeits-Tabelle
 */
extern FREQTAB* create_freqtab(FILE* input_stream);



/**
 * Diese Funktion l�scht die �bergebene H�ufigkeits-Tabelle vom Heap 
 * und gibt den Speicher wieder frei.
 * 
 * @param freqtab Zeiger auf die Adresse der H�ufigkeits-Tabelle, 
 *                die gel�scht werden soll
 */
extern void delete_freqtab(FREQTAB** freqtab);



/**
 * Diese Funktion entnimmt ein H�ufigkeits-Tabellen-Element aus der �bergebenen 
 * H�ufigkeits-Tabelle und liefert einen Zeiger auf das entnommene Element 
 * zur�ck.
 * 
 * @param freqtab Zeiger auf die H�ufigkeits-Tabelle, 
 *                der ein Element entnommen werden soll
 * @return 
 */
extern FREQTAB_ELEMENT* freqtab_get_element(FREQTAB* freqtab);



/**
 * Diese Funktion liefert einen Wahrheitswert zur�ck, der angibt, ob die 
 * �bergebene H�ufigkeits-Tabelle noch Elemente enth�lt, oder leer ist.
 * 
 * @param freqtab Zeiger auf die H�ufigkeits-Tabelle, die abgefragt werden soll 
 * @return Wahrheitswert, der gangibt ob die H�ufigkeits-Tabelle leer ist
 *         (true = H�ufigkeits-Tabelle enth�lt KEINE Elemente (leer);
 *          false = H�ufigkeits-Tabelle enth�lt noch Elemente)
 */
extern bool freqtab_is_empty(FREQTAB* freqtab);



/**
 * Diese Funktion liefert die Summe aller H�ufigkeiten 
 * aller H�ufigkeitselemente, die in der �bergeben H�ufigkeits-Tabelle 
 * eingetragen sind, zur�ck. Diese Summe der H�ufigkeiten ist gleich der
 * Summe aller eingelesenen Zeichen des Daten-Strom-Inhaltes auf dessen
 * Basis die �bergebene H�ufigkeits-Tabelle erstellt wurde.
 *  
 * @param freqtab Zeiger auf die H�ufigkeits-Tabelle, dessen Inhalts-L�nge
 *                zur�ckgegeben werden soll 
 *                (Summe aller eingespeicherten H�ufigkeiten)
 * @return positive ganzzahl [0 bis MAX_ULONG], welche die Inhalts-L�nge
 *         des Daten-Stromes repr�sentiert auf dessen Basis die �bergebene
 *         H�ufigkeits-Tabelle erstellt wurde
 */
extern unsigned long freqtab_get_content_length(FREQTAB* freqtab);



/**
 * Diese Funktion gibt die �bergebene H�ufigkeits-Tabelle auf dem 
 * Bildschirm aus.
 * 
 * @param freqtab Zeiger auf H�ufigkeits-Tabelle, die auf dem Bildschirm 
 *                ausgegeben werden soll
 */
 /*@unused@*/
extern void freqtab_print(FREQTAB* freqtab);


#endif	/* FREQTAB_H */
