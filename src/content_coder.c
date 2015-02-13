
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "content_coder.h"

#include <stdio.h>




/* ======================================================================== *
 * Funktionsdefinitionen                                                    *
 * ======================================================================== */

extern void encode_content(FILE* input_stream, FILE* output_stream, 
                           CODETAB* codetab, unsigned long content_length)
{
    /*Codelaenge des Codes*/
    unsigned long code_length = 0;
    /*Aktuelle <position in der Bitqueue*/
    unsigned char shift_count = 0;
    int character;
    bool** code = {false};
    unsigned char bitqueue;
    
    /* content_length in output_stream schreiben */
    fwrite(&content_length, sizeof(unsigned long), 1, output_stream);
    
    while (true)
    {
        if (code_length == 0)
        {
            /* Zeichen aus Imputstream lesen */
            character = fgetc(input_stream);
            
            if (character == EOF)
            {
                break;
            }
            
            /* code für gelesenes Zeichen anfordern */
            code = codetab_get_code(codetab, character);
            
            /* code_length für gelesenes Zeichen anfordern */
            code_length = codetab_get_code_length(codetab, character);
        }
        
        if (shift_count == 7)
        {
            /* Byte aus Bitqueue wegschreiben */
            fputc(bitqueue, output_stream);
            
            /* shift_count zurücksetzen */
            shift_count = 0;
        }
        
        /* MSB des Codes in die Bitqueue einfügen (an LSB Stelle) */
        if (code[code_length - 1])
        {
            bitqueue = bitqueue & 1;
        }
        
        /* Bitqueue nach links schieben */
        bitqueue <<= 1;
        
        /* shift_count erhöhen */
        shift_count++;
        
        /* code_length erniedrigen */
        code_length--;
    }
    
    /* Padding-Bits einfügen */
    while (shift_count < 7)
    {
        /* Bitqueue nach links schieben */
        bitqueue <<= 1;
        
        /* shift_count erhöhen */
        shift_count++;
    }
    
    /* Byte aus Bitqueue wegschreiben */
    fputc(bitqueue, output_stream);
    
    /*MD5 Prüfsumme*/
}

extern void decode_content(FILE* input_stream, FILE* output_stream,
                           HTREE* htree)
{
    unsigned char shift_count = 0;
    bool is_char_found = false;
    unsigned long content_length;
    unsigned char character;
    unsigned char bitqueue;
    int byte;
    bool bit;
    
    /* content_length aus input_stream lesen */
    fread(&content_length, sizeof(unsigned long), 1, input_stream);
    
    while (true)
    {
        if (is_char_found)
        {
            /* gesuchtes Zeichen von htree anfordern */
            character = htree_get_char(htree);
            
            /**/
            fputc(character, output_stream);
            content_length--;
        }
        if (shift_count == 7)
        {
            byte = fgetc(input_stream);
            if (byte == EOF)
            {
                break;
            }
            bitqueue = (unsigned char) byte;
            shift_count = 0;
        }
        bit = bitqueue >= 128;
        is_char_found = htree_search_char(htree, bit);
        bitqueue <<= 1;
        shift_count++;
    }
}

