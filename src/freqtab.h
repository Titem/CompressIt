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




/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include <stdbool.h>
#include <stdio.h>

#include "freqtab_element.h"




/* ======================================================================== *
 * Makros                                                                   *
 * ======================================================================== */

#define MAX_CHARACTERS 256




/* ======================================================================== *
 * Typdefinitionen                                                          *
 * ======================================================================== */

typedef struct S_FREQTAB FREQTAB;




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

/*---------------------------------------------------------------------------------*/
/*-----ERSTELLT EINE NEUE FREQTAB--------------------------------------------------*/
/*---------------------------------------------------------------------------------*/
extern FREQTAB* create_freqtab(FILE* input_stream);


extern void delete_freqtab(FREQTAB* freq_tab_p);


extern FREQTAB_ELEMENT* freqtab_get_element(FREQTAB* freq_tab_p);


extern bool freqtab_is_emty(FREQTAB* freq_tab_p);


/*---------------------------------------------------------------------------------*/
/*-----GIBT DIE FREQUENCY TABELLE AUF DEM BILDSCHIRM AUS---------------------------*/
/*---------------------------------------------------------------------------------*/
extern void freqtab_print(FREQTAB* freq_tab_p);


#endif	/* FREQTAB_H */
