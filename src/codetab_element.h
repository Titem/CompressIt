/* 
 * File:   codetab_element.h
 * Author: Tim Buschmann
 *         Artur Leinweber
 *         Alexander Schmitz
 *
 * Created on 6. Februar 2015, 16:16
 */

#ifndef CODETAB_ELEMENT_H
#define	CODETAB_ELEMENT_H


typedef struct S_CODETAB_ELEMENT CODETAB_ELEMENT


extern CODETAB_ELEMENT* creat_codetab_element(unsigned char character, 
                                              unsigned short code,
                                              unsigned char code_length);

extern void delete_codetab_element(CODETAB_ELEMENT* codetab_element);

extern bool codetab_element_is_bit_set(CODETAB_ELEMENT* codetab_element, 
                                       unsigned char position);

extern unsigned char codetab_element_get_char
                     (CODETAB_ELEMENT* codetab_element);

extern unsigned char codetab_element_get_code
                     (CODETAB_ELEMENT* codetab_element);

extern unsigned char codetab_element_get_code_length
                     (CODETAB_ELEMENT* codetab_element);


#endif	/* CODETAB_ELEMENT_H */

