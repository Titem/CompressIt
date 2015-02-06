/* 
 * File:   freqtab.h
 * Author: Tim Buschmann
 *         Artur Leinweber
 *         Alexander Schmitz 
 *
 * Created on 6. Februar 2015, 16:16
 */

#ifndef FREQTAB_H
#define	FREQTAB_H




#include "freqtab_element.h"

#define MAX_CHARACTERS 256


typedef struct S_FREQTAB FREQTAB;

/*---------------------------------------------------------------------------------*/
/*-----ERSTELLT EINE NEUE FREQTAB--------------------------------------------------*/
/*---------------------------------------------------------------------------------*/
extern FREQTAB* create_freqtab(FILE* input_stream);

/*---------------------------------------------------------------------------------*/
/*-----FÜGT EIN NEUES ELEMENT IN DIE FREQTAB HINZU---------------------------------*/
/*---------------------------------------------------------------------------------*/
void freqtab_update(FREQTAB* freq_tab_p, unsigned char character);


/*---------------------------------------------------------------------------------*/
/*-----DEN FREQTAB MIT NULL INITIALISIERN------------------------------------------*/
/*---------------------------------------------------------------------------------*/
void freqtab_init(FREQTAB* freq_tab_p);


/*---------------------------------------------------------------------------------*/
/*-----INITIALISIERT DEN WORKING INDEX DER FREQTAB---------------------------------*/
/*---------------------------------------------------------------------------------*/
void freqtab_init_working_index(FREQTAB* freq_tab_p);


/*---------------------------------------------------------------------------------*/
/*-----GIBT DIE FREQUENCY TABELLE AUF DEM BILDSCHIRM AUS---------------------------*/
/*---------------------------------------------------------------------------------*/
extern void freqtab_print(FREQTAB* freq_tab_p);


#endif	/* FREQTAB_H */
