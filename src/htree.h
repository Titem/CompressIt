/* 
 * File:   htree.h
 * Author: Tim Buschmann
 *         Artur Leinweber
 *         Alexander Schmitz
 *
 * Created on 6. Februar 2015, 16:13
 */

#ifndef HTREE_H
#define	HTREE_H


typedef S_HTREE HTREE;


extern HTREE* create_htree(FREQTAB* freqtab);

extern void delete_htree(HTREE* htree);

extern CODETABLE_ELEMENT* htree_get_codetab_element(HTREE* htree);

extern bool htree_is_emty(HTREE* htree);

#endif	/* HTREE_H */

