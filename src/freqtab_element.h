/* 
 * @file freqtab_element.h
 * 
 * Dieses Modul repr�sentiert ein H�ufigkeits-Tabellen-Element also einen
 * Eintrag in der H�ufigkeits-Tabelle. Ein solcher Eintrag enth�llt die 
 * H�ufigkeit, mit der ein bestimmtes Schriftzeichen im Inhalt der zu 
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
 * Dieser Datentyp repr�sentiert ein H�ufigkeits-Tabellen-Element.
 * Variablen diesen Datentyps beinhalten H�ufigkeits-Tabellen-Elemente. 
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
/*-----L�SCHT EIN FREQUENCY TABLE ELEMENT BZW GIBT DEN SPEICHER WIEDER FREI--------*/
/*---------------------------------------------------------------------------------*/
extern void delete_freqtab_element(FREQTAB_ELEMENT** freq);


/*---------------------------------------------------------------------------------*/
/*-----LIEFERT DAS ZEICHEN EINER FREQUENCY TABLE ELEMENT---------------------------*/
/*---------------------------------------------------------------------------------*/
extern unsigned char freqtab_elememt_get_char(FREQTAB_ELEMENT* freq);


/*---------------------------------------------------------------------------------*/
/*-----LIEFERT DIE H�UFIGKEIT EINER FREQUENCY TABLE ELEMENT------------------------*/
/*---------------------------------------------------------------------------------*/
extern unsigned long freqtab_element_get_frequency(FREQTAB_ELEMENT* freq);


/*---------------------------------------------------------------------------------*/
/*------ERH�HT DIE H�UFIGKEIT EINER FREQUENCY TABLE ELEMENT------------------------*/
/*---------------------------------------------------------------------------------*/
extern void freqtab_element_inc_frequency(FREQTAB_ELEMENT* freq);



#endif	/* FREQTAB_ELEMENT_H */