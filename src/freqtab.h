/**
 * @file freqtab.h
 * 
 * Dieses Modul repräsentiert eine Häufigkeits-Tabelle.
 * Eine Häufigkeits-Tabelle beinhaltet die Häufigkeiten, mit der jedes 
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
 * Dieser Datentyp repräsentiert eine Häufigkeits-Tabelle.
 * Variablen diesen Datentyps beinhalten Häufigkeits-Tabellen. 
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
 * Diese Funktion erstellt eine neue Häufigkeits-Tabelle auf dem Heap und 
 * füllt diese mit den Häufigkeiten der verschiedenen Schriftzeichen auf, wie
 * häufig diese Schriftzeichen im übergebenen Eingangs-Datenstrom vorkommen, 
 * und liefert einen Zeiger auf die neu erstellte Häufigkeits-Tabelle zuück.
 * 
 * @param input_stream Zeiger auf Eingangs-Datenstrom
 * @return Zeiger auf die neu erstellte Häufigkeits-Tabelle
 */
extern FREQTAB* create_freqtab(FILE* input_stream);



/**
 * Diese Funktion löscht die übergebene Häufigkeits-Tabelle vom Heap 
 * und gibt den Speicher wieder frei.
 * 
 * @param freqtab Zeiger auf die Adresse der Häufigkeits-Tabelle, 
 *                die gelöscht werden soll
 */
extern void delete_freqtab(FREQTAB** freqtab);



/**
 * Diese Funktion entnimmt ein Häufigkeits-Tabellen-Element aus der übergebenen 
 * Häufigkeits-Tabelle und liefert einen Zeiger auf das entnommene Element 
 * zurück.
 * 
 * @param freqtab Zeiger auf die Häufigkeits-Tabelle, 
 *                der ein Element entnommen werden soll
 * @return 
 */
extern FREQTAB_ELEMENT* freqtab_get_element(FREQTAB* freqtab);



/**
 * Diese Funktion liefert einen Wahrheitswert zurück, der angibt, ob die 
 * übergebene Häufigkeits-Tabelle noch Elemente enthält, oder leer ist.
 * 
 * @param freqtab Zeiger auf die Häufigkeits-Tabelle, die abgefragt werden soll 
 * @return Wahrheitswert, der gangibt ob die Häufigkeits-Tabelle leer ist
 *         (true = Häufigkeits-Tabelle enthält KEINE Elemente (leer);
 *          false = Häufigkeits-Tabelle enthält noch Elemente)
 */
extern bool freqtab_is_empty(FREQTAB* freqtab);



/**
 * Diese Funktion liefert die Summe aller Häufigkeiten 
 * aller Häufigkeitselemente, die in der übergeben Häufigkeits-Tabelle 
 * eingetragen sind, zurück. Diese Summe der Häufigkeiten ist gleich der
 * Summe aller eingelesenen Zeichen des Daten-Strom-Inhaltes auf dessen
 * Basis die übergebene Häufigkeits-Tabelle erstellt wurde.
 *  
 * @param freqtab Zeiger auf die Häufigkeits-Tabelle, dessen Inhalts-Länge
 *                zurückgegeben werden soll 
 *                (Summe aller eingespeicherten Häufigkeiten)
 * @return positive ganzzahl [0 bis MAX_ULONG], welche die Inhalts-Länge
 *         des Daten-Stromes repräsentiert auf dessen Basis die übergebene
 *         Häufigkeits-Tabelle erstellt wurde
 */
extern unsigned long freqtab_get_content_length(FREQTAB* freqtab);



/**
 * Diese Funktion gibt die übergebene Häufigkeits-Tabelle auf dem 
 * Bildschirm aus.
 * 
 * @param freqtab Zeiger auf Häufigkeits-Tabelle, die auf dem Bildschirm 
 *                ausgegeben werden soll
 */
 /*@unused@*/
extern void freqtab_print(FREQTAB* freqtab);


#endif	/* FREQTAB_H */
