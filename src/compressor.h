/* 
 * File:   compressor.h
 * Author: Tim Buschmann
 *         Artur Leinweber
 *         Alexander Schmitz
 *
 * Created on 6. Februar 2015, 16:26
 */

#ifndef COMPRESSOR_H
#define	COMPRESSOR_H


extern void compress(FILE* input_stream, FILE* output_stream);

extern void decompress(FILE* input_stream, FILE* output_stream);


#endif	/* COMPRESSOR_H */

