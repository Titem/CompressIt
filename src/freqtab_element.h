/**
 * @file freqtab_element.h
 * 
 * Dieses Modul repräsentiert ein Häufigkeits-Tabellen-Element also einen
 * Eintrag in der Häufigkeits-Tabelle. Ein solcher Eintrag enthällt die 
 * Häufigkeit, mit der ein bestimmtes Schriftzeichen im Inhalt der zu 
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
 * Dieser Datentyp repräsentiert ein Häufigkeits-Tabellen-Element.
 * Variablen diesen Datentyps beinhalten Häufigkeits-Tabellen-Elemente. 
 */
typedef struct S_FREQTAB_ELEMENT FREQTAB_ELEMENT;




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

/**
 * Diese Funktion erstellt ein neues Häufigkeits-Tabellen-Element auf dem Heap
 * für das übergebene Schriftzeichen, dessen Häufigkeit ermittelt werden soll
 * und gibt einen Zeiger auf dieses neu erstellte Häufigkeits-Tabellen-Element 
 * zurück.
 * 
 * @param character Schriftzeichen des neuen Häufigkeits-Tabellen-Elementes 
 *                  für das die Häufigkeit ermittelt werden soll
 * @return Zeiger auf das neu erstellte Häufigkeits-Tabellen-Element
 */
extern FREQTAB_ELEMENT* create_freqtab_element(unsigned char character);



/**
 * Diese Funktion löscht das übergebene Häufigkeits-Tabellen-Element vom Heap 
 * und gibt den Speicher wieder frei.
 * 
 * @param freqtab_element Zeiger auf die Adresse des 
 *                        Häufigkeits-Tabellen-Elementes, das gelöscht 
 *                        werden soll
 */
extern void delete_freqtab_element(FREQTAB_ELEMENT** freqtab_element);



/**
 * Diese Funktion liefert das Schriftzeichen des übergeben 
 * Häufigkeits-Tabellen-Elementes zurück.
 * 
 * @param freqtab_element Zeiger auf das Häufigkeits-Tabellen-Element, dessen 
 *                        Schriftzeichen zurückgeliefert werden soll.
 * @return Schriftzeichen, des übergeben Häufigkeits-Tabellen-Elementes
 */
extern unsigned char freqtab_elememt_get_char(FREQTAB_ELEMENT* freqtab_element);



/**
 * Diese Funktion liefert die Häufigkeit des übergeben 
 * Häufigkeits-Tabellen-Elementes zurück.
 * 
 * @param freqtab_element Zeiger auf das Häufigkeits-Tabellen-Element, dessen 
 *                        Häufigkeit zurückgeliefert werden soll.
 * @return positive Ganzzahl [0 bis MAX_ULONG], welche die Häufigkeit des
 *         übergebenen Häufigkeits-Tabellen-Elementes repräsentiert
 */
extern unsigned long freqtab_element_get_frequency(
                                        FREQTAB_ELEMENT* freqtab_element);



/**
 * Diese Funktion erhöht die Häufigkeit des übergebenen 
 * Häufigkeits-Tabellen-Elementes um 1.
 * 
 * @param freqtab_element Zeiger auf das Häufigkeits-Tabellen-Element, dessen 
 *                        Häufigkeit erhöht werden soll.
 */
extern void freqtab_element_inc_frequency(FREQTAB_ELEMENT* freqtab_element);


#endif	/* FREQTAB_ELEMENT_H */
