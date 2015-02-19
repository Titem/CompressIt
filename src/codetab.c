
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "common.h"
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

/** 
 * Diese Struktur beschreibt den Aufbau einer Code-Tabelle.
 */
struct S_CODETAB
{
    /**
     * Diese Variable speichert die Anzahl der Elemente, die in dieser
     * Code-Tabelle gespeichert sind.
     */
    unsigned short length;
    
    /**
     * Diese Variable speichert den Index des Elementes, an dem gerade 
     * gearbeitet wird.
     */
    unsigned short working_index;
    
    /**
     * Diese Variable speichert den Zeiger auf das Array, welches die
     * Zeiger auf die einzelnen Code-Tabellen-Elemente enthält.
     * Der Index des Arrays ist gleichzeitig das Schriftzeichen, dem das
     * Code-Tabellen-Element zugeordnet ist.
     */
    CODETAB_ELEMENT* char_map[256];
};




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

/**
 * Diese Funktion initialisiert den Arbeits-Index der 
 * übergebenen Code-Tabelle, indem sie diesen auf den erste gültige
 * Index setzt, hinter dem sich ein gültiges Code-Tabellen-Element verbirgt.
 * 
 * @param codetab Zeiger auf die Code-Tabelle, dessen Arbeits-Index
 *                initialisiert werden soll
 */
static void codetab_init_working_index(CODETAB* codetab);



/**
 * Diese Funktion setzt den Arbeits-Index der übergebenen Code-Tabelle
 * auf den nächstem gültigen Index, indem sie diesen auf den nächsten gültige
 * Index setzt, hinter dem sich ein gültiges Code-Tabellen-Element verbirgt.
 *  
 * @param codetab Zeiger auf die Code-Tabelle, dessen Arbeits-Index 
 *                auf den nächsten gültigen Index erhöht werden soll.
 */
static void codetab_next_working_index(CODETAB* codetab);




/* ======================================================================== *
 * Funktionsdefinitionen                                                    *
 * ======================================================================== */

extern CODETAB* create_codetab(HTREE* htree)
{
    CODETAB* new_codetab = malloc(sizeof (CODETAB));
    CODETAB_ELEMENT* new_codetab_element;

    /* Initialisieren */
    new_codetab->working_index = 0;
    new_codetab->length = 0;
    memset(new_codetab->char_map, 0, sizeof(CODETAB_ELEMENT*) * 256);

    /* Codetab-Elemente abholen und einfügen */
    while (!htree_is_empty(htree))
    {
        new_codetab_element = htree_get_codetab_element(htree);
        new_codetab->char_map[codetab_element_get_char(new_codetab_element)]
                = new_codetab_element;
        new_codetab->length++;
    }

    /* Working-Index auf erstes gültiges Element setzen */
    codetab_init_working_index(new_codetab);

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

    /* Werte-Shift-Position Init */
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
    memset(new_codetab->char_map, 0, sizeof(CODETAB_ELEMENT*) * 256);

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
            /* MSB der Bitqueue entnehmen */
            bit = bitqueue >= 128;
            bitqueue <<= 1;
            queue_usage--;
            
            /* Gelesenes MSB der Bitqueue als LSB dem character hinzufügen */
            character <<= 1;
            if (bit)
            {
                character += 1;
            }
            char_shift++;

            if (char_shift == 8)
            {
                state = LENGTH;
                char_shift = 0;
            }
            break;



        case LENGTH:
            /* MSB der Bitqueue entnehmen */
            bit = bitqueue >= 128;
            bitqueue <<= 1;
            queue_usage--;

            /*Gelesenes MSB der Bitqueue als LSB der code_length hinzufügen*/
            code_length <<= 1;
            if (bit)
            {
                code_length += 1;
            }
            length_shift++;

            if (length_shift == 8)
            {
                state = CODE;
                length_shift = 0;

                code = malloc(sizeof(bool) * code_length);
            }
            break;



        case CODE:
            /* MSB der Bitqueue entnehmen */
            bit = bitqueue >= 128;
            bitqueue <<= 1;
            queue_usage--;
            
            /*Gelesenes MSB der Bitqueue dem Code hinzufügen*/
            code[code_index] = bit;
            code_index++;

            if (code_index == code_length)
            {
                state = CHAR;
                code_index = 0;

                new_codetab_element = create_codetab_element(character, code, code_length);
                new_codetab->char_map[character] = new_codetab_element;

                count++;
            }
            break;
        }
    }

    /* Working Index auf erstes gültiges Element setzen */
    codetab_init_working_index(new_codetab);

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

    /* Werte Init */
    unsigned char character = codetab_element_get_char(codetab->char_map[codetab->working_index]);
    unsigned char code_length = 0;
    bool* code = NULL;
    
    /* Werte-Shift-Position Init */
    unsigned char char_shift = 0;
    unsigned char length_shift = 0;
    unsigned char code_index = 0;
    
    /* Bitqueue Init */
    unsigned char bitqueue = 0;
    unsigned char queue_usage = 0;
    bool bit = false;
    
    /* Zählervariable Init */
    unsigned short count = 0;

    if (fwrite(&(codetab->length), sizeof(unsigned short), 1, output_stream) != 1)
    {
        printf("Hier stimmt was nicht!\n"
               "Modul: codetab.c\tFunktion: write_codetab\n\n");
        exit(EXIT_FAILURE);
    }

    while (count < codetab->length)
    {
        if (queue_usage == 8)
        {
            fputc(bitqueue, output_stream);
            queue_usage = 0;
        }

        switch (state)
        {
        case CHAR:
            /* MSB dem Character entnehmen */
            bit = character >= 128;
            character <<= 1;
            char_shift++;
            
            /* Entnommenes MSB des Characters als LSB der Bitqueue hinzufügen*/
            bitqueue <<= 1;
            if (bit)
            {
                bitqueue += 1;
            }
            queue_usage++;

            if (char_shift == 8)
            {
                state = LENGTH;
                code_length = codetab_element_get_code_length(codetab->char_map[codetab->working_index]);
                length_shift = 0;
            }
            break;



        case LENGTH:
            /* MSB der code_length entnehmen */
            bit = code_length >= 128;
            code_length <<= 1;
            length_shift++;
            
            /* Entnommenes MSB der code_length als LSB der Bitqueue hinzufügen*/
            bitqueue <<= 1;
            if (bit)
            {
                bitqueue += 1;
            }
            queue_usage++;

            if (length_shift == 8)
            {
                state = CODE;
                code = codetab_element_get_code(codetab->char_map[codetab->working_index]);
                code_length = codetab_element_get_code_length(codetab->char_map[codetab->working_index]);
                code_index = 0;
            }
            break;



        case CODE:
            /* Bit dem code entnehmen */
            bit = code[code_index];
            code_index++;
            
            /* Entnommenes Bit des Codes als LSB der Bitqueue hinzufügen*/
            bitqueue <<= 1;
            if (bit)
            {
                bitqueue += 1;
            }
            queue_usage++;

            if (code_index == code_length)
            {
                if (count < codetab->length - 1)
                {   state = CHAR;
                    codetab_next_working_index(codetab);
                    character = codetab_element_get_char(codetab->char_map[codetab->working_index]);
                    char_shift = 0;
                }
                count++;
            }
            break;
        }
    }

    /* Padding Bits hinzufügen */
    while (queue_usage > 0 && queue_usage < 8)
    {
        bitqueue <<= 1;
        queue_usage++;
    }
    fputc(bitqueue, output_stream);

}



extern void delete_codetab(CODETAB** codetab)
{
    unsigned short i;
    
    for (i = 0; i < 256; i++)
    {
        if ((*codetab)->char_map[i] != NULL)
        {
            delete_codetab_element(&((*codetab)->char_map[i]));
        }
    }
    
    free(*codetab);
    *codetab = NULL;
}



extern bool* codetab_get_code(CODETAB* codetab, unsigned char character)
{
    return codetab_element_get_code(codetab->char_map[character]);
}



extern unsigned char codetab_get_code_length(CODETAB* codetab, unsigned char character)
{
    return codetab_element_get_code_length(codetab->char_map[character]);
}



extern CODETAB_ELEMENT* codetab_get_element(CODETAB* codetab)
{
    /* aktuellen working_index zwischenspeichern */
    unsigned short old_working_index = codetab->working_index;

    /* working_index auf naechstes codetab_element setzen */
    codetab_next_working_index(codetab);

    return codetab->char_map[old_working_index];
}



extern bool codetab_is_empty(CODETAB* codetab)
{
    return codetab->working_index > 255;
}



extern void codetab_print(CODETAB* codetab)
{
    unsigned short i = 0;
    unsigned short x = 0;
    bool* code = NULL;

    printf("char\tchar\tcode_length\tcode\n"
           "=================================================\n");
    for (i = 0; i < 256; i++)
    {
        if (codetab->char_map[i] != NULL)
        {
            printf("%c\t%i\t%i\t", 
                   codetab_element_get_char(codetab->char_map[i]), 
                   (int) codetab_element_get_char(codetab->char_map[i]), 
                   codetab_element_get_code_length(codetab->char_map[i]));

            code = codetab_element_get_code(codetab->char_map[i]);
            for (x = 0; x < codetab_get_code_length(codetab, (unsigned char) i); x++)
            {
                printf("%u", *code);
                code++;
            }
            printf("\n");
        }
    }
    printf("=================================================\n");
    printf("Anzahl Element: %i\n", (int) codetab->length);
}



static void codetab_init_working_index(CODETAB* codetab)
{
    while (codetab->working_index < 256 && codetab->char_map[codetab->working_index] == NULL)
    {
        codetab->working_index++;
    }
}



static void codetab_next_working_index(CODETAB* codetab)
{
    if (codetab->working_index < 256)
    {
        codetab->working_index++;
    }
    
    /* Naechstes codetab Element auswählen */
    codetab_init_working_index(codetab);
}







