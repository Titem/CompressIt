/* 
 * File:   freqtab_element.h
 * Author: Tim Buschmann
 *         Artur Leinweber
 *         Alexander Schmitz 
 *
 * Created on 6. Februar 2015, 16:16
 */

#ifndef FREQTAB_ELEMENT_H
#define	FREQTAB_ELEMENT_H




/* ======================================================================== *
 * Makros                                                                   *
 * ======================================================================== */

#define ININIT_CHARCTER 1




/* ======================================================================== *
 * Typdefinitionen                                                          *
 * ======================================================================== */

/*---------------------------------------------------------------------------------*/
/*-----STRUCT DEFINITION F�R FREQUENCY TABLE ELEMENT-------------------------------*/
/*---------------------------------------------------------------------------------*/
typedef struct S_FREQTAB_ELEMENT FREQTAB_ELEMENT;




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
extern void delete_freqtab_element(FREQTAB_ELEMENT* freq);


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