
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "freqtab.h"

#include <stdlib.h>
#include <string.h>

#include "error.h"




/* ======================================================================== *
 * Strukturdefinitionen                                                     *
 * ======================================================================== */

/** 
 * Diese Struktur beschreibt den Aufbau einer Häufigkeits-Tabelle.
 */
struct S_FREQTAB
{
    /**
     * Diese Variable speichert die Anzahl der Elemente, die in dieser
     * Häufigkeits-Tabelle gespeichert sind.
     */
    unsigned short length;
    
    /**
     * Diese Variable speichert den Index des Elementes, an dem gerade 
     * gearbeitet wird.
     */
    unsigned short working_index;
    
    /** 
     * Diese Variable speichert den Zeiger auf das Array, welches die
     * Zeiger auf die einzelnen Häufigkeits-Tabellen-Elemente enthält.
     * Der Index des Arrays ist gleichzeitig das Schriftzeichen, dem das
     * Häufigkeits-Tabellen-Element zugeordnet ist.
     */
    FREQTAB_ELEMENT* char_map[MAX_CHARACTERS];
    
    /**
     * Diese Variable speichert die Länge des Inhaltes, auf dessen Basis diese
     * Häufigkeits-Tabelle erstellt wurde in Schriftzeichen (in Byte).
     */
    unsigned long content_length;
};




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

/**
 * Diese Funktion aktualisiert die Häufigkeitstabelle indem es für das 
 * übergebene Schriftzeichen in der übergebenen Häufigkeits-Tabelle
 * die Häufigkeit um 1 erhöht.
 *   
 * @param freqtab Zeiger auf die Häufigkeits-Tabelle, die aktualisiert 
 *                werden soll
 * @param character Schriftzeichen, für das die Häufigkeit erhöht werden soll
 */
static void freqtab_update(FREQTAB* freqtab, unsigned char character);



/**
 * Diese Funktion initialisiert den Arbeits-Index der übergebenen 
 * Häufigkeits-Tabelle, indem sie diesen auf den erste gültige Index setzt, 
 * hinter dem sich ein gültiges Häufigkeits-Tabellen-Element verbirgt.
 * 
 * @param freqtab Zeiger auf die Code-Tabelle, dessen Arbeits-Index
 *                initialisiert werden soll
 */
static void freqtab_init_working_index(FREQTAB* freqtab);



/**
 * Diese Funktion setzt den Arbeits-Index der übergebenen Häufigkeits-Tabelle
 * auf den nächstem gültigen Index, indem sie diesen auf den nächsten gültige
 * Index setzt, hinter dem sich ein gültiges Häufigkeits-Tabellen-Element 
 * verbirgt.
 * 
 * @param freqtab Zeiger auf die Häufigkeits-Tabelle, dessen Arbeits-Index 
 *                auf den nächsten gültigen Index erhöht werden soll.
 */
static void freqtab_next_working_index(FREQTAB* freqtab);




/* ======================================================================== *
 * Funktionsdefinitionen                                                    *
 * ======================================================================== */

extern FREQTAB* create_freqtab(FILE* input_stream)
{
    FREQTAB* new_freqtab = malloc(sizeof (FREQTAB));
    int character_from_file;
    
    if (new_freqtab == NULL)
    {
        print_error(cant_malloc_memory);
        exit(EXIT_FAILURE);
    }

    new_freqtab->length = 0;
    new_freqtab->working_index = 0;
    new_freqtab->content_length = 0;
    memset(new_freqtab->char_map, 0, sizeof(FREQTAB_ELEMENT*) * 256);
    
    character_from_file = fgetc(input_stream);
    while (character_from_file != EOF)
    {
        new_freqtab->content_length++;
        freqtab_update(new_freqtab, (unsigned char) character_from_file);
        character_from_file = fgetc(input_stream);
    }
    
    freqtab_init_working_index(new_freqtab);

    return new_freqtab;
}



extern void delete_freqtab(FREQTAB** freqtab)
{
    
    free(*freqtab);
    *freqtab = NULL;
}



extern FREQTAB_ELEMENT* freqtab_get_element(FREQTAB* freqtab)
{
    FREQTAB_ELEMENT* tmp_p = freqtab->char_map[freqtab->working_index];

    freqtab_next_working_index(freqtab);

    return tmp_p;
}



extern bool freqtab_is_empty(FREQTAB* freqtab)
{
    return freqtab->working_index >= 256;
}



extern unsigned long freqtab_get_content_length(FREQTAB* freqtab)
{
    return freqtab->content_length;
}



extern void freqtab_print(FREQTAB* freqtab)
{
    int i = 0;

    printf("Zeichen  ---> Haeufigkeit ---> NUMERIC\n");
    printf("--------------------------------------\n");
    for (i = 0; i < MAX_CHARACTERS; i++)
    {
        if (freqtab->char_map[i] != NULL)
        {
            printf("%s \t ---> %d \t  ---> %d \n", convert_char(freqtab_elememt_get_char(freqtab->char_map[i])), (int) freqtab_element_get_frequency(freqtab->char_map[i]), (int) freqtab_elememt_get_char(freqtab->char_map[i]));
        }
    }
    printf("--------------------------------------\n");
    printf("Zeichen insgesamt:   %lu\n", freqtab->content_length);
    printf("Zeichen verschieden: %i\n", (int) freqtab->length);

}



static void freqtab_init_working_index(FREQTAB* freqtab)
{
    while (freqtab->working_index < 256 && freqtab->char_map[freqtab->working_index] == NULL)
    {
        freqtab->working_index++;
    }
}



static void freqtab_next_working_index(FREQTAB* freqtab)
{
    if (freqtab->working_index < 256)
    {
        freqtab->working_index++;
    }
    
    freqtab_init_working_index(freqtab);
}



static void freqtab_update(FREQTAB* freqtab, unsigned char character)
{
    if (freqtab->char_map[character] == NULL)
    {
        freqtab->length++;
        freqtab->char_map[character] = create_freqtab_element(character);
    }
    else
    {
        freqtab_element_inc_frequency(freqtab->char_map[character]);
    }
}




