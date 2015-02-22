/**
 * @file freqtab_element.h
 * 
 * Dieses Modul repr�sentiert ein H�ufigkeits-Tabellen-Element also einen
 * Eintrag in der H�ufigkeits-Tabelle. Ein solcher Eintrag enth�llt die 
 * H�ufigkeit, mit der ein bestimmtes Schriftzeichen im Inhalt der zu 
 * komprimierenden Datei vorkommt, und dieses Zeichen selber.
 * 
 * @author Tim Buschmann <br>
 *         Artur Leinweber <br>
 *         Alexander Schmitz 
 */

#ifndef FREQTAB_ELEMENT_H
#define	FREQTAB_ELEMENT_H




/* ======================================================================== *
 * Typdefinitionen                                                          *
 * ======================================================================== */

/**
 * Dieser Datentyp repr�sentiert ein H�ufigkeits-Tabellen-Element.
 * Variablen diesen Datentyps beinhalten H�ufigkeits-Tabellen-Elemente. 
 */
typedef struct S_FREQTAB_ELEMENT FREQTAB_ELEMENT;




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

/**
 * Diese Funktion erstellt ein neues H�ufigkeits-Tabellen-Element auf dem Heap
 * f�r das �bergebene Schriftzeichen, dessen H�ufigkeit ermittelt werden soll
 * und gibt einen Zeiger auf dieses neu erstellte H�ufigkeits-Tabellen-Element 
 * zur�ck.
 * 
 * @param character Schriftzeichen des neuen H�ufigkeits-Tabellen-Elementes 
 *                  f�r das die H�ufigkeit ermittelt werden soll
 * @return Zeiger auf das neu erstellte H�ufigkeits-Tabellen-Element
 */
extern FREQTAB_ELEMENT* create_freqtab_element(unsigned char character);



/**
 * Diese Funktion l�scht das �bergebene H�ufigkeits-Tabellen-Element vom Heap 
 * und gibt den Speicher wieder frei.
 * 
 * @param freqtab_element Zeiger auf die Adresse des 
 *                        H�ufigkeits-Tabellen-Elementes, das gel�scht 
 *                        werden soll
 */
extern void delete_freqtab_element(FREQTAB_ELEMENT** freqtab_element);



/**
 * Diese Funktion liefert das Schriftzeichen des �bergeben 
 * H�ufigkeits-Tabellen-Elementes zur�ck.
 * 
 * @param freqtab_element Zeiger auf das H�ufigkeits-Tabellen-Element, dessen 
 *                        Schriftzeichen zur�ckgeliefert werden soll.
 * @return Schriftzeichen, des �bergeben H�ufigkeits-Tabellen-Elementes
 */
extern unsigned char freqtab_elememt_get_char(FREQTAB_ELEMENT* freqtab_element);



/**
 * Diese Funktion liefert die H�ufigkeit des �bergeben 
 * H�ufigkeits-Tabellen-Elementes zur�ck.
 * 
 * @param freqtab_element Zeiger auf das H�ufigkeits-Tabellen-Element, dessen 
 *                        H�ufigkeit zur�ckgeliefert werden soll.
 * @return positive Ganzzahl [0 bis MAX_ULONG], welche die H�ufigkeit des
 *         �bergebenen H�ufigkeits-Tabellen-Elementes repr�sentiert
 */
extern unsigned long freqtab_element_get_frequency(
                                        FREQTAB_ELEMENT* freqtab_element);



/**
 * Diese Funktion erh�ht die H�ufigkeit des �bergebenen 
 * H�ufigkeits-Tabellen-Elementes um 1.
 * 
 * @param freqtab_element Zeiger auf das H�ufigkeits-Tabellen-Element, dessen 
 *                        H�ufigkeit erh�ht werden soll.
 */
extern void freqtab_element_inc_frequency(FREQTAB_ELEMENT* freqtab_element);


#endif	/* FREQTAB_ELEMENT_H */
