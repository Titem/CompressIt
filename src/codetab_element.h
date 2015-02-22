/** 
 * @file codetab_element.h
 * 
 * Dieses Modul repräsentiert ein Code-Tabellen-Element also einen Eintrag 
 * in der Code-Tabelle. Ein solcher Eintrag enthält den Code mit seiner 
 * Code-Länge und das Zeichen, welches durch den Code repräsentiert wird. 
 * 
 * @author Tim Buschmann <br>
 *         Artur Leinweber <br>
 *         Alexander Schmitz
 */

#ifndef CODETAB_ELEMENT_H
#define	CODETAB_ELEMENT_H




/* ======================================================================== *
 * Typdefinitionen                                                          *
 * ======================================================================== */

/**
 * Dieser Datentyp repräsentiert ein Code-Tabellen-Element.
 * Variablen diesen Datentyps beinhalten Code-Tabellen-Element. 
 */
typedef struct S_CODETAB_ELEMENT CODETAB_ELEMENT;




/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "codetab_element.h"

#include <stdbool.h>




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

/**
 * Diese Funktion erstellt ein neues Code-Tabellen-Element auf dem Heap
 * auf Basis der übergebenen Attribute und gibt einen Zeiger auf dieses
 * neu erstellte Code-Tabellen-Element zurück.
 * 
 * @param character Schriftzeichen, das in diesem Code-Tabellen-Element 
 *                  gespeichert werden soll
 * @param code Zeiger auf Array, welches den Code enthält, der in diesem 
 *             Code-Tabellen-Element gespeichert werden soll
 * @param code_length Code-Länge (Breite des zuvor übergeben Code-Array), 
 *                    die in diesem Code-Tabellen-Element gespeichert 
 *                    werden soll
 * @return Zeiger auf das neu erstellte Code-Tabellen-Element
 */
extern CODETAB_ELEMENT* create_codetab_element(unsigned char character, 
                                               bool* code,
                                               unsigned char code_length);



/**
 * Diese Funktion löscht das übergebene Code-Tabellen-Element vom Heap 
 * und gibt den Speicher wieder frei.
 * 
 * @param codetab_element Zeiger auf die Adresse des Code-Tabellen-Elementes,
 *                        das gelöscht werden soll
 */
extern void delete_codetab_element(CODETAB_ELEMENT** codetab_element);



/**
 * Diese Funktion prüft ob das Bit an der übergeben Position des Codes des
 * übergeben Schriftzeichens gesetzt ist und liefert einen Wahrheitswert 
 * zurück, der angibt ob dies der Fall ist.
 * 
 * @param codetab_element
 * @param position
 * @return Wahrheitswert der angibt, ob das ausgewählte Bit gesetzt ist
 *         (true = Bit ist gesetzt bzw. ist 1;
 *          false = Bit ist nicht gesetzt bzw. ist 0)
 */
extern bool codetab_element_is_bit_set(CODETAB_ELEMENT* codetab_element, 
                                       unsigned char position);



/**
 * Diese Funktion liefert das Schriftzeichen des übergeben 
 * Code-Tabellen-Elementes zurück.
 * 
 * @param codetab_element Zeiger auf Code-Tabellen-Element, dessen 
 *                        Schriftzeichen zurückgeliefert werden soll.
 * @return Schriftzeichen, des übergeben Code-Tabellen-Elementes
 */
extern unsigned char codetab_element_get_char
                     (CODETAB_ELEMENT* codetab_element);



/**
 * Diese Funktion liefert den Code des übergebenen 
 * Code-Tabellen-Elementes zurück.
 * 
 * @param codetab_element Zeiger auf Code-Tabellen-Element, dessen 
 *                        Code zurückgeliefert werden soll.
 * @return Zeiger auf das Code-Array dieses Code-Tabellen-Elementes 
 */
extern bool* codetab_element_get_code(CODETAB_ELEMENT* codetab_element);



/**
 * Diese Funktion liefert die Code-Länge des übergebenen 
 * Code-Tabellen-Elementes zurück.
 * 
 * @param codetab_element Zeiger auf Code-Tabellen-Element, dessen 
 *                        Code-Länge zurückgeliefert werden soll.
 * @return positive Ganzzahl [0 bis 255], welche die Code-Länge repräsentiert
 *         (länge des Code-Arrays dieses Code-Tabellen-Elementes)
 */
extern unsigned char codetab_element_get_code_length
                     (CODETAB_ELEMENT* codetab_element);


#endif	/* CODETAB_ELEMENT_H */

