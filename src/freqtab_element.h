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




/*---------------------------------------------------------------------------------*/
/*-----STRUCT DEFINITION FÜR FREQUENCY TABLE ELEMENT-------------------------------*/
/*---------------------------------------------------------------------------------*/
typedef struct S_FREQTAB_ELEMENT FREQTAB_ELEMENT;

#define ININIT_CHARCTER 1




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

/*---------------------------------------------------------------------------------*/
/*-----ERSTELLT EINE NEUES FREQUENCY TABLE ELEMENT---------------------------------*/
/*---------------------------------------------------------------------------------*/
FREQTAB_ELEMENT* create_freqtab_element(char character);


/*---------------------------------------------------------------------------------*/
/*-----LÖSCHT EIN FREQUENCY TABLE ELEMENT BZW GIBT DEN SPEICHER WIEDER FREI--------*/
/*---------------------------------------------------------------------------------*/
void delete_freqtab_element(FREQTAB_ELEMENT* freq);


/*---------------------------------------------------------------------------------*/
/*-----LIEFERT DAS ZEICHEN EINER FREQUENCY TABLE ELEMENT---------------------------*/
/*---------------------------------------------------------------------------------*/
unsigned char freqtab_elememt_get_char(FREQTAB_ELEMENT* freq);


/*---------------------------------------------------------------------------------*/
/*-----LIEFERT DIE HÄUFIGKEIT EINER FREQUENCY TABLE ELEMENT------------------------*/
/*---------------------------------------------------------------------------------*/
long freqtab_element_get_frequency(FREQTAB_ELEMENT* freq);


/*---------------------------------------------------------------------------------*/
/*------ERHÖHT DIE HÄUFIGKEIT EINER FREQUENCY TABLE ELEMENT------------------------*/
/*---------------------------------------------------------------------------------*/
extern void freqtab_element_inc_frequency(FREQTAB_ELEMENT* freq);



#endif	/* FREQTAB_ELEMENT_H */