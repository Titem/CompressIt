/* 
 * File:   codetab.h
 * Author: Tim Buschmann
 *         Artur Leinweber
 *         Alexander Schmitz
 *
 * Created on 6. Februar 2015, 16:15
 */

#ifndef CODETAB_H
#define	CODETAB_H


typedef CODETAB struct S_CODETAB



extern CODETAB* create_codetab(htree HTREE*);

extern CODETAB* read_codetab(FILE* input_stream);

extern void wirte_codetab(FILE* output_stream, CODETAB* codetab);

extern void delete_codetab(CODETAB* codetab);

extern codetab_get_code(CODETAB* codetab, unsigned char character);

extern codetab_get_char(CODETAB* codetab, unsigned short code);



#endif	/* CODETAB_H */

