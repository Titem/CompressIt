
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "codetab.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "codetab_element.h"
#include "codetab.h"



/* ======================================================================== *
 * Strukturdefinitionen                                                     *
 * ======================================================================== */

struct S_CODETAB 
{
    unsigned char length;
    unsigned short working_index;
    CODETAB_ELEMENT* char_index[256];
};

static void codetab_get_next_index(CODETAB* codetab);


/* ======================================================================== *
 * Funktionsdefinitionen                                                    *
 * ======================================================================== */

extern CODETAB* create_codetab(HTREE* htree)
{
    CODETAB* new_codetab = malloc(sizeof(CODETAB));
    CODETAB_ELEMENT* new_codetab_element;
    
    int i;
    
    new_codetab->working_index = 0;
    new_codetab->length = 0;
    
    for(i = 0; i < 256; i++)
    {
        new_codetab->char_index[i] = NULL;
    }
    
    codetab_get_next_index(new_codetab);
    while (!htree_is_emty(htree))
    {
        new_codetab_element = htree_get_codetab_element(htree);
        new_codetab->char_index[codetab_element_get_char(new_codetab_element)] 
                = new_codetab_element;
/*
        htree_print(htree);
*/
		/* codetab_elemente zaehlen */
		new_codetab->length++;
    }
    
    return new_codetab;
}


extern CODETAB* read_codetab(FILE* input_stream)
{

    enum {
        CHAR,
        LENGTH,
        CODE
                
    } STATE;
    
    return NULL;
}


extern void write_codetab(FILE* output_stream, CODETAB* codetab)
{
	enum {
		CHAR,
		LENGTH,
		CODE

	} STATE;
	/*Init*/
	unsigned char code_length = 0;
	unsigned char queue_usage = 0;
	unsigned char char_shift = 8;
	unsigned char length_shift = 8;
	unsigned char code_index = 0;
	unsigned char count = 0;
	unsigned char bitqueue = 0;
	unsigned char character = 0;
	bool bit = false;
	bool* code = NULL;
	STATE = CHAR;


	codetab_get_next_index(codetab);
	fputc(codetab->length, output_stream);
	
	
	while (count < codetab->length)
	{
		if (queue_usage == 8)
		{
			fputc(bitqueue, output_stream);
			queue_usage = 0;
		}

		switch (STATE)
		{
		case CHAR:
			if (char_shift == 8)
			{
				character = codetab_element_get_char(codetab->char_index[codetab->working_index]);
				char_shift = 0;
			}
			/*MSB filtern.*/
			bit = character >= 128;
			
			/*Gelesenes MSB der Bitqueue als LSB hinzufügen*/
			if (bit)
			{
				bitqueue += 1;
			}
			/*Platz für das nächste Bit vorbereiten*/
			bitqueue <<= 1;
			
			/*Füllstand der Bitqueue*/
			queue_usage++;
			
			/*Nächstes Bit für die Bitqueue vorbereiten*/
			character <<= 1;
			
			/*Aktuelle Position in dem Char*/
			char_shift++;

			if (char_shift == 8)
			{
				STATE = LENGTH;
			}

			break;

		case LENGTH:
			if (length_shift == 8)
			{
				code_length = codetab_element_get_code_length(codetab->char_index[codetab->working_index]);
				length_shift = 0;
			}

			/*MSB filtern.*/
			bit = code_length >= 128;

			/*Gelesenes MSB der Bitqueue als LSB hinzufügen*/
			if (bit)
			{
				bitqueue += 1;
			}
			/*Platz für das nächste Bit vorbereiten*/
			bitqueue <<= 1;

			/*Füllstand der Bitqueue*/
			queue_usage++;

			/*Nächstes Bit für die Bitqueue vorbereiten*/
			code_length <<= 1;

			/*Aktuelle Position in dem Char*/
			length_shift++;

			if (length_shift == 8)
			{
				STATE = CODE;
			}


			break;

		case CODE:
			if (code_index = code_length -1)
			{
				code_index = 0;
			}

			/*MSB filtern.*/
			bit = code[code_index];

			/*Gelesenes MSB der Bitqueue als LSB hinzufügen*/
			if (bit)
			{
				bitqueue += 1;
			}
			/*Platz für das nächste Bit vorbereiten*/
			bitqueue <<= 1;

			/*Füllstand der Bitqueue*/
			queue_usage++;

			/*Aktuelle Position in dem Char*/
			code_index++;

			if (code_index == code_length -1 && count != codetab->length)
			{
				STATE = CHAR;
				count++;
				codetab_get_next_index(codetab);
			}
			break;
		}

	}


	/*Padding Bits*/
	while (queue_usage < 8)
	{
		bitqueue <<= 1;
		queue_usage++;
	}

	fputc(bitqueue, output_stream);

}


extern void delete_codetab(CODETAB** codetab)
{
    free(*codetab);
    *codetab = NULL;
}


extern bool* codetab_get_code(CODETAB* codetab, unsigned char character)
{
    return codetab_element_get_code(codetab->char_index[character]);
}


extern unsigned char codetab_get_code_length(CODETAB* codetab, unsigned char character)
{
    return codetab_element_get_code_length(codetab->char_index[character]);
}


extern CODETAB_ELEMENT* codetab_get_element(CODETAB* codetab)
{
    unsigned short old_working_index;
    
    /* aktuellen working_index zwischenspeichern */
    old_working_index = codetab->working_index;
    
    /* working_index auf naechstes codetab_element setzen */
    codetab_get_next_index(codetab);
    
    return codetab->char_index[old_working_index];
}


extern bool codetab_is_empty(CODETAB* codetab)
{
    return codetab->working_index > 255;
}

static void codetab_get_next_index(CODETAB* codetab)
{
    
    /* Naechstes codetab Element auswählen */
    while(codetab->working_index < 256 && codetab->char_index[codetab->working_index + 1] == NULL) 
    {
        codetab->working_index++;
        
    }
    codetab->working_index++;
}


extern void codetab_print(CODETAB* codetab)
{
    unsigned short i = 0;
    unsigned short x = 0;
    int count = 0;
    bool* code = NULL;
    
    for (i = 0; i < 256; i++)
    {
        if (codetab->char_index[i] != NULL)
        {
            count++;
            printf("%c  ", codetab_element_get_char(codetab->char_index[i]));
            
            code = codetab_element_get_code(codetab->char_index[i]);
            for (x = 0; x < codetab_get_code_length(codetab,(unsigned char) i); x++)
            {
                printf("%u", *code);
                code++;
            }
            printf("\n");
        }
    }
    printf("Anzahl Element: %i\n", count);
}



