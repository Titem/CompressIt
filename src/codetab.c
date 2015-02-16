
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
    unsigned short length;
    unsigned short working_index;
    CODETAB_ELEMENT* char_index[256];
};

static void codetab_get_next_index(CODETAB* codetab);




/* ======================================================================== *
 * Funktionsdefinitionen                                                    *
 * ======================================================================== */

extern CODETAB* create_codetab(HTREE* htree)
{
    CODETAB* new_codetab = malloc(sizeof (CODETAB));
    CODETAB_ELEMENT* new_codetab_element;
    /*int count = 0;*/

    new_codetab->working_index = 0;
    new_codetab->length = 0;
    memset(new_codetab->char_index, 0, sizeof(CODETAB_ELEMENT*) * 256);

    while (!htree_is_emty(htree))
    {

        new_codetab_element = htree_get_codetab_element(htree);
        /*DEBUG*/
        /*count++;*/
        /*printf("Count: %i \t|   {%c}\n",count,codetab_element_get_char(new_codetab_element));*/


        new_codetab->char_index[codetab_element_get_char(new_codetab_element)]
                = new_codetab_element;
        /*DEBUG*/
        /*htree_print(htree);*/

        /* codetab_elemente zaehlen */
        new_codetab->length++;
    }


    /* Working Index auf erstes Element setzen */
    while(new_codetab->working_index < 256 && new_codetab->char_index[new_codetab->working_index] == NULL)
    {
        new_codetab->working_index++;
    }

    return new_codetab;
}

extern CODETAB* read_codetab(FILE* input_stream)
{
    CODETAB_ELEMENT* new_codetab_element;
    CODETAB* new_codetab;

    enum
    {
        CHAR,
        LENGTH,
        CODE
    } state = CHAR;

    /* Werte Init */
    unsigned char character = 0;
    unsigned char code_length = 0;
    bool* code = NULL;

    /* Werte-Shift / Werte-Position */
    unsigned char char_shift = 0;
    unsigned char length_shift = 0;
    unsigned char code_index = 0;

    /* Bitqueue Init */
    int byte = 0;
    unsigned char bitqueue = 0;
    unsigned char queue_usage = 0;
    bool bit = false;

    /* Zählervariable Init */
    unsigned short count = 0;


    new_codetab = malloc(sizeof(CODETAB));

    if (fread(&(new_codetab->length), sizeof(unsigned short), 1, input_stream) != 1)
    {
        printf("Hier stimmt was nicht!\n"
               "Modul: codetab.c\tFunktion: read_codetab\n\n");
        exit(EXIT_FAILURE);
    }

    new_codetab->working_index = 0;
    memset(new_codetab->char_index, 0, sizeof(CODETAB_ELEMENT*) * 256);

    while (count < new_codetab->length)
    {
        if (queue_usage == 0)
        {
            byte = fgetc(input_stream);
            if (byte == EOF)
            {
                printf("Datei ungültig! #0\n"
                       "Die Code-Tabelle endet zu früh!\n"
                       "Modul: codetab.c\tFunktion: read_codetab\n\n");
                printf("Position Output-Stream: %lu\n\n", (unsigned long) ftell(input_stream));
                exit(EXIT_FAILURE);
            }
            bitqueue = (unsigned char) byte;
            queue_usage = 8;
        }

        switch (state)
        {
        case CHAR:
            /*MSB filtern.*/
            bit = bitqueue >= 128;


            /*MSB aus Bitqueue entnehmen*/
            bitqueue <<= 1;
            /*Gelesenes MSB der Bitqueue als LSB hinzufügen*/



            /*Füllstand der Bitqueue verringern */
            queue_usage--;

            /*Nächstes Bit für die Bitqueue vorbereiten*/
            character <<= 1;
            if (bit)
            {
                character += 1;
            }

            /*Aktuelle Position in dem Char*/
            char_shift++;

            if (char_shift == 8)
            {
                state = LENGTH;
                char_shift = 0;
            }
            break;



        case LENGTH:
            /*MSB filtern.*/
            bit = bitqueue >= 128;

            bitqueue <<= 1;
            /*Gelesenes MSB der Bitqueue als LSB hinzufügen*/

            /*Platz für das nächste Bit vorbereiten*/


            /*Füllstand der Bitqueue*/
            queue_usage--;

            /*Nächstes Bit für die Bitqueue vorbereiten*/
            code_length <<= 1;
            if (bit)
            {
                code_length += 1;
            }



            /*Aktuelle Position in dem Char*/
            length_shift++;

            if (length_shift == 8)
            {
                state = CODE;
                length_shift = 0;

                code = malloc(sizeof(bool) * code_length);
            }
            break;



        case CODE:
            /*MSB filtern.*/
            bit = bitqueue >= 128;

            bitqueue <<= 1;
            /*Gelesenes MSB der Bitqueue als LSB hinzufügen*/

            /*Platz für das nächste Bit vorbereiten*/


            /*Füllstand der Bitqueue*/
            queue_usage--;

            code[code_index] = bit;

            /*Aktuelle Position im Code*/
            code_index++;

            if (code_index == code_length)
            {
                state = CHAR;
                code_index = 0;

                new_codetab_element = create_codetab_element(character, code, code_length);

                new_codetab->char_index[character] = new_codetab_element;

                count++;
            }
            break;
        }

    }

    /* Working Index auf erstes Element setzen */
    while(new_codetab->working_index < 256 && new_codetab->char_index[new_codetab->working_index] == NULL)
    {
        new_codetab->working_index++;
    }

    /*codetab_get_next_index(new_codetab);*/

    return new_codetab;
}



extern void write_codetab(FILE* output_stream, CODETAB* codetab)
{

    enum
    {
        CHAR,
        LENGTH,
        CODE
    } state = CHAR;

    /*Init*/
    unsigned char code_length = 0;
    unsigned char queue_usage = 0;
    unsigned char char_shift = 7;
    unsigned char length_shift = 7;
    unsigned char code_index = 0;
    unsigned short count = 0;
    unsigned char bitqueue = 0;
    unsigned char character = 0;
    bool bit = false;
    bool* code = NULL;

    if (fwrite(&(codetab->length), sizeof(unsigned short), 1, output_stream) != 1)
    {
        printf("Hier stimmt was nicht!\n"
               "Modul: codetab.c\tFunktion: write_codetab\n\n");
        exit(EXIT_FAILURE);
    }

    /* fprintf(output_stream, codetab->length);  */
    fflush(output_stream);

    /* Init */
    character = codetab_element_get_char(codetab->char_index[codetab->working_index]);
    char_shift = 0;

    while (count < codetab->length)
    {
        if (queue_usage == 8)
        {
            fputc(bitqueue, output_stream);
            fflush(output_stream);
            queue_usage = 0;
        }

        switch (state)
        {
        case CHAR:
            /*MSB filtern.*/
            bit = character >= 128;

            bitqueue <<= 1;
            /*Gelesenes MSB der Bitqueue als LSB hinzufügen*/
            if (bit)
            {
                bitqueue += 1;
            }
            /*Platz für das nächste Bit vorbereiten*/


            /*Füllstand der Bitqueue*/
            queue_usage++;

            /*Nächstes Bit für die Bitqueue vorbereiten*/
            character <<= 1;

            /*Aktuelle Position in dem Char*/
            char_shift++;

            if (char_shift == 8)
            {
                state = LENGTH;
                code_length = codetab_element_get_code_length(codetab->char_index[codetab->working_index]);
                length_shift = 0;
            }
            break;



        case LENGTH:
            /*MSB filtern.*/
            bit = code_length >= 128;

            bitqueue <<= 1;
            /*Gelesenes MSB der Bitqueue als LSB hinzufügen*/
            if (bit)
            {
                bitqueue += 1;
            }
            /*Platz für das nächste Bit vorbereiten*/


            /*Füllstand der Bitqueue*/
            queue_usage++;

            /*Nächstes Bit für die Bitqueue vorbereiten*/
            code_length <<= 1;

            /*Aktuelle Position in dem Char*/
            length_shift++;

            if (length_shift == 8)
            {
                state = CODE;
                code = codetab_element_get_code(codetab->char_index[codetab->working_index]);
                code_length = codetab_element_get_code_length(codetab->char_index[codetab->working_index]);
                code_index = 0;
            }
            break;



        case CODE:
            /*MSB filtern.*/
            bit = code[code_index];

            bitqueue <<= 1;
            /*Gelesenes MSB der Bitqueue als LSB hinzufügen*/
            if (bit)
            {
                bitqueue += 1;
            }
            /*Platz für das nächste Bit vorbereiten*/


            /*Füllstand der Bitqueue*/
            queue_usage++;

            /*Aktuelle Position in dem Char*/
            code_index++;


            if (code_index == code_length)
            {
                if (count < codetab->length - 1)
                {
                    codetab_get_next_index(codetab);
                    character = codetab_element_get_char(codetab->char_index[codetab->working_index]);

                }
                state = CHAR;
                char_shift = 0;
                count++;
            }
            break;
        }

    }


    /*Padding Bits*/
    while (queue_usage > 0 && queue_usage < 8)
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
    while (codetab->working_index < 256 && codetab->char_index[codetab->working_index + 1] == NULL)
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
    unsigned long padding_bits = 0;

    for (i = 0; i < 256; i++)
    {
        if (codetab->char_index[i] != NULL)
        {
            count++;
            printf("%c \t %i \t %i \t", codetab_element_get_char(codetab->char_index[i]), (int) codetab_element_get_char(codetab->char_index[i]), codetab_element_get_code_length(codetab->char_index[i]));

            code = codetab_element_get_code(codetab->char_index[i]);
            padding_bits += codetab_element_get_code_length(codetab->char_index[i]) + 16;
            for (x = 0; x < codetab_get_code_length(codetab, (unsigned char) i); x++)
            {
                printf("%u", *code);
                code++;
            }
            printf("\n");
        }
    }

    padding_bits = 8 - ((padding_bits + 8) % 8);

    printf("Anzahl Element: count %i und codetab->length %i\n", count, (int) codetab->length);
    printf("Anzahl der Padding Bits: %lu \n", padding_bits);
}



