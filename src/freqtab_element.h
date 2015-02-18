/* 
 * @file freqtab_element.h
 * 
 * Dieses Modul repräsentiert ein Häufigkeits-Tabellen-Element also einen
 * Eintrag in der Häufigkeits-Tabelle. Ein solcher Eintrag enthällt die 
 * Häufigkeit, mit der ein bestimmtes Schriftzeichen im Inhalt der zu 
 * komprimierenden Datei vorkommt, und dieses Zeichen selber.
 * 
 * @author Tim Buschmann
 *         Artur Leinweber
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
 * Makros                                                                   *
 * ======================================================================== */

#define ININIT_CHARCTER 1




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

/*---------------------------------------------------------------------------------*/
/*-----ERSTELLT EINE NEUES FREQUENCY TABLE ELEMENT---------------------------------*/
/*---------------------------------------------------------------------------------*/
extern FREQTAB_ELEMENT* create_freqtab_element(unsigned char character);


/*---------------------------------------------------------------------------------*/
/*-----LÖSCHT EIN FREQUENCY TABLE ELEMENT BZW GIBT DEN SPEICHER WIEDER FREI--------*/
/*---------------------------------------------------------------------------------*/
extern void delete_freqtab_element(FREQTAB_ELEMENT** freq);


/*---------------------------------------------------------------------------------*/
/*-----LIEFERT DAS ZEICHEN EINER FREQUENCY TABLE ELEMENT---------------------------*/
/*---------------------------------------------------------------------------------*/
extern unsigned char freqtab_elememt_get_char(FREQTAB_ELEMENT* freq);


/*---------------------------------------------------------------------------------*/
/*-----LIEFERT DIE HÄUFIGKEIT EINER FREQUENCY TABLE ELEMENT------------------------*/
/*---------------------------------------------------------------------------------*/
extern unsigned long freqtab_element_get_frequency(FREQTAB_ELEMENT* freq);


/*---------------------------------------------------------------------------------*/
/*------ERHÖHT DIE HÄUFIGKEIT EINER FREQUENCY TABLE ELEMENT------------------------*/
/*---------------------------------------------------------------------------------*/
extern void freqtab_element_inc_frequency(FREQTAB_ELEMENT* freq);



#endif	/* FREQTAB_ELEMENT_H */