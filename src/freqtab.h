/* 
 * @file freqtab.h
 * 
 * Dieses Modul repräsentiert eine Häufigkeits-Tabelle.
 * Eine Häufigkeits-Tabelle beinhaltet die Häufigkeiten, mit der jedes 
 * verwendete Schriftzeichen im Inhalt der zu komprimierenden Datei vorkommt. 
 * 
 * @author Tim Buschmann
 *         Artur Leinweber
 *         Alexander Schmitz 
 */

#ifndef FREQTAB_H
#define	FREQTAB_H




/* ======================================================================== *
 * Typdefinitionen                                                          *
 * ======================================================================== */

typedef struct S_FREQTAB FREQTAB;




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
 * Funktionsprototypen                                                      *
 * ======================================================================== */

/*---------------------------------------------------------------------------------*/
/*-----ERSTELLT EINE NEUE FREQTAB--------------------------------------------------*/
/*---------------------------------------------------------------------------------*/
extern FREQTAB* create_freqtab(FILE* input_stream);


extern void delete_freqtab(FREQTAB** freq_tab_p);


extern FREQTAB_ELEMENT* freqtab_get_element(FREQTAB* freq_tab_p);


extern bool freqtab_is_emty(FREQTAB* freq_tab_p);

extern unsigned long freqtab_get_content_length(FREQTAB* freq_tab_p);

/*---------------------------------------------------------------------------------*/
/*-----GIBT DIE FREQUENCY TABELLE AUF DEM BILDSCHIRM AUS---------------------------*/
/*---------------------------------------------------------------------------------*/
extern void freqtab_print(FREQTAB* freq_tab_p);


#endif	/* FREQTAB_H */
