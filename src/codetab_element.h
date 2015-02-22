/** 
 * @file codetab_element.h
 * 
 * Dieses Modul repr�sentiert ein Code-Tabellen-Element also einen Eintrag 
 * in der Code-Tabelle. Ein solcher Eintrag enth�lt den Code mit seiner 
 * Code-L�nge und das Zeichen, welches durch den Code repr�sentiert wird. 
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
 * Dieser Datentyp repr�sentiert ein Code-Tabellen-Element.
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
 * auf Basis der �bergebenen Attribute und gibt einen Zeiger auf dieses
 * neu erstellte Code-Tabellen-Element zur�ck.
 * 
 * @param character Schriftzeichen, das in diesem Code-Tabellen-Element 
 *                  gespeichert werden soll
 * @param code Zeiger auf Array, welches den Code enth�lt, der in diesem 
 *             Code-Tabellen-Element gespeichert werden soll
 * @param code_length Code-L�nge (Breite des zuvor �bergeben Code-Array), 
 *                    die in diesem Code-Tabellen-Element gespeichert 
 *                    werden soll
 * @return Zeiger auf das neu erstellte Code-Tabellen-Element
 */
extern CODETAB_ELEMENT* create_codetab_element(unsigned char character, 
                                               bool* code,
                                               unsigned char code_length);



/**
 * Diese Funktion l�scht das �bergebene Code-Tabellen-Element vom Heap 
 * und gibt den Speicher wieder frei.
 * 
 * @param codetab_element Zeiger auf die Adresse des Code-Tabellen-Elementes,
 *                        das gel�scht werden soll
 */
extern void delete_codetab_element(CODETAB_ELEMENT** codetab_element);



/**
 * Diese Funktion pr�ft ob das Bit an der �bergeben Position des Codes des
 * �bergeben Schriftzeichens gesetzt ist und liefert einen Wahrheitswert 
 * zur�ck, der angibt ob dies der Fall ist.
 * 
 * @param codetab_element
 * @param position
 * @return Wahrheitswert der angibt, ob das ausgew�hlte Bit gesetzt ist
 *         (true = Bit ist gesetzt bzw. ist 1;
 *          false = Bit ist nicht gesetzt bzw. ist 0)
 */
extern bool codetab_element_is_bit_set(CODETAB_ELEMENT* codetab_element, 
                                       unsigned char position);



/**
 * Diese Funktion liefert das Schriftzeichen des �bergeben 
 * Code-Tabellen-Elementes zur�ck.
 * 
 * @param codetab_element Zeiger auf Code-Tabellen-Element, dessen 
 *                        Schriftzeichen zur�ckgeliefert werden soll.
 * @return Schriftzeichen, des �bergeben Code-Tabellen-Elementes
 */
extern unsigned char codetab_element_get_char
                     (CODETAB_ELEMENT* codetab_element);



/**
 * Diese Funktion liefert den Code des �bergebenen 
 * Code-Tabellen-Elementes zur�ck.
 * 
 * @param codetab_element Zeiger auf Code-Tabellen-Element, dessen 
 *                        Code zur�ckgeliefert werden soll.
 * @return Zeiger auf das Code-Array dieses Code-Tabellen-Elementes 
 */
extern bool* codetab_element_get_code(CODETAB_ELEMENT* codetab_element);



/**
 * Diese Funktion liefert die Code-L�nge des �bergebenen 
 * Code-Tabellen-Elementes zur�ck.
 * 
 * @param codetab_element Zeiger auf Code-Tabellen-Element, dessen 
 *                        Code-L�nge zur�ckgeliefert werden soll.
 * @return positive Ganzzahl [0 bis 255], welche die Code-L�nge repr�sentiert
 *         (l�nge des Code-Arrays dieses Code-Tabellen-Elementes)
 */
extern unsigned char codetab_element_get_code_length
                     (CODETAB_ELEMENT* codetab_element);


#endif	/* CODETAB_ELEMENT_H */

