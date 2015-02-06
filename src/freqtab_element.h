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




#include <stdlib.h>
//#include <stdio.h>
//#include <errno.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>

/*---------------------------------------------------------------------------------*/
/*-----STRUCT DEFINITION F�R FREQUENCY TABLE ELEMENT-------------------------------*/
/*---------------------------------------------------------------------------------*/
typedef struct{

	long frequency;
	char character;

}freqtab_element;

#define ININIT_CHARCTER 1


/*---------------------------------------------------------------------------------*/
/*-----ERSTELLT EINE NEUES FREQUENCY TABLE ELEMENT---------------------------------*/
/*---------------------------------------------------------------------------------*/
freqtab_element* create_freqtab_element(char character);


/*---------------------------------------------------------------------------------*/
/*-----L�SCHT EIN FREQUENCY TABLE ELEMENT BZW GIBT DEN SPEICHER WIEDER FREI--------*/
/*---------------------------------------------------------------------------------*/
void delete_freqtab_element(freqtab_element* freq);


/*---------------------------------------------------------------------------------*/
/*-----LIEFERT DAS ZEICHEN EINER FREQUENCY TABLE ELEMENT---------------------------*/
/*---------------------------------------------------------------------------------*/
char freqtab_elememt_get_char(freqtab_element* freq);


/*---------------------------------------------------------------------------------*/
/*-----LIEFERT DIE H�UFIGKEIT EINER FREQUENCY TABLE ELEMENT------------------------*/
/*---------------------------------------------------------------------------------*/
long freqtab_element_get_frequency(freqtab_element* freq);


/*---------------------------------------------------------------------------------*/
/*------ERH�HT DIE H�UFIGKEIT EINER FREQUENCY TABLE ELEMENT------------------------*/
/*---------------------------------------------------------------------------------*/
extern void freqtab_element_inc_frequency(freqtab_element* freq);



#endif	/* FREQTAB_ELEMENT_H */