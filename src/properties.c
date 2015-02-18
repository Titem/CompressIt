
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "properties.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "error.h"




/* ======================================================================== *
 * Strukturdefinitionen                                                     *
 * ======================================================================== */

struct S_PROPERTIES
{
    MODE mode;
    char* input_filename;
    FILE* input_file;
    char* output_filename;
    FILE* output_file;
};




/* ======================================================================== *
 * Konstanten                                                               *
 * ======================================================================== */

/* Beschreibt die Argumente für das Kodieren, Decodieren und den Hilfeaufruf. */
const char* COMPPRESS_FLAG = "-c";
const char* DECOMPRESS_FLAG = "-d";
const char* HELP_FLAG = "-h";

/* Beschreibt den MIME-Typ, der der Ausgabedatei angehangen wird. */
const char* COMPRESS_MIME_TYPE = ".hc";
const char* DECOMPRESS_MIME_TYPE = ".hd";

/* Beschreibt den Lese- bzw- Schreibevorgang. */
const char* READ_BINARY = "rb";
const char* WRITE_BINARY = "wb";




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

/** 
 * Diese Funktion erstellt einen Dateinamen als String auf dem Heap,
 * welcher aus dem Dateinamen und dem angehangenen Mime-Typ besteht und
 * liefert einen Zeiger auf diesen neu erstellten String zurück.
 */
static char* get_new_filename(char* filename, const char* mime_type);




/* ======================================================================== *
 * Funktionsdefinitionen                                                    *
 * ======================================================================== */

extern PROPERTIES* create_properties(char** argv, int argc)
{
    bool found_input_document = false;
    bool found_output_document = false;
    bool need_help = false;

    char *output_filename = NULL;
    char *input_filename = NULL;

    FILE *file_read = NULL;
    FILE *file_write = NULL;

    PROPERTIES *p_properties = malloc(sizeof (PROPERTIES));

    if (p_properties == NULL)
    {
        print_error(cant_malloc_memory);
        exit(EXIT_FAILURE);
    }
    
    p_properties->mode = UNDEFINED;
    p_properties->input_filename = NULL;
    p_properties->input_file = NULL;
    p_properties->output_filename = NULL;
    p_properties->output_file = NULL;
    

    

#ifdef DEBUG_HUFFMAN
    printf("Analyse der Parameter!\n");
#endif

        if ((argc == 1) || (argc == 2) || (argc > 4))
        {
            print_error(too_many_arguments);
            exit(EXIT_FAILURE);
        }

    
    while (argc > 1)
    {
        argc--;
        argv++;

        if (!found_input_document && strcmp(*argv, COMPPRESS_FLAG) == 0)
        {
            p_properties->mode = COMPRESS;
            argc--;
            argv++;

            if (*argv == NULL)
            {
                print_error(dont_found_input_document);
                exit(EXIT_FAILURE);
            }
                
            input_filename = *argv;
            found_input_document = true;
            
            #ifdef DEBUG_HUFFMAN
                printf("FOUND INPUT DOCUMENT AND STATUS -c !\n");
            #endif

        }

        if (!found_input_document && strcmp(*argv, DECOMPRESS_FLAG) == 0)
        {
            p_properties->mode = DECOMPRESS;
            argc--;
            argv++;

            if (*argv == NULL)
            {
                print_error(dont_found_input_document);
                exit(EXIT_FAILURE);
            }
                    
            input_filename = *argv;
            found_input_document = true;
            
            #ifdef DEBUG_HUFFMAN
                printf("FOUND INPUT DOCUMENT AND STATUS -d !\n");
            #endif 
        }
        
        if (strcmp(*argv, HELP_FLAG) == 0)
        {
            p_properties->mode = MANPAGE;
            need_help = true;
        }
        /*else if (argc >= 1 && !found_input_document)
        {
            print_error(too_many_arguments);
            print_error(AND);
            print_error(dont_found_input_document);
            exit(EXIT_FAILURE);
        }*/

        if (!found_output_document)
        {
            #ifdef DEBUG_HUFFMAN
                printf("DONT FOUND OUTPUT DOKUMENT!\n");
            #endif

            argc--;
            argv++;
            if (*argv != NULL)
            {
                #ifdef DEBUG_HUFFMAN
                    printf("FOUND OUTPUT DOCUMENT!\n");
                #endif

                output_filename = *argv;
                found_output_document = true;
            }
            else
            {
                #ifdef DEBUG_HUFFMAN
                    printf("POINTER IS NULL -> INPUTFILENAME AS OUTPUTFILENAME!\n");
                #endif

                if (p_properties->mode == COMPRESS)
                {
                    output_filename = get_new_filename(input_filename, COMPRESS_MIME_TYPE);
                }
                else
                {
                    output_filename = get_new_filename(input_filename, DECOMPRESS_MIME_TYPE);
                }
                
            }
        }
    }

    if (found_input_document && found_output_document && (strcmp(input_filename, output_filename) == 0) && !need_help)
    {
        print_error(in_and_output_document_are_the_same);
        exit(EXIT_FAILURE);
    }

    if (!need_help)
    {

#ifdef DEBUG_HUFFMAN
        printf("FILE POINTER setzen und pruefen !\n");
        printf("FP READ Stream geoeffnet !\n");
#endif

        file_read = fopen(input_filename, READ_BINARY);
        test_nullpointer_exception(file_read, input_filename);

#ifdef DEBUG_HUFFMAN
        printf("FP WRITE Stream geoeffnet !\n");
#endif


        file_write = fopen(output_filename, WRITE_BINARY);
        test_nullpointer_exception(file_write, output_filename);

#ifdef DEBUG_HUFFMAN
        printf("FILE POINTER in die PROPERTIES STRUCT uebernehmen !\n");
#endif

        p_properties->input_file = file_read;
        p_properties->output_file = file_write;
    }
#ifdef DEBUG_HUFFMAN
    printf("END OF PROPERTIES!\n");
#endif

    return p_properties;
}



extern void delete_properties(PROPERTIES** p_properties)
{
    free(*p_properties);
    *p_properties = NULL;
}



extern MODE properties_get_mode(PROPERTIES* p_properties)
{
    return p_properties->mode;
}



extern char* properties_get_input_filename(PROPERTIES* p_properties)
{
    return p_properties->input_filename;
}



extern FILE* properties_get_input_stream(PROPERTIES* p_properties)
{
    return p_properties->input_file;
}



extern char* properties_get_output_filename(PROPERTIES* p_properties)
{
    return p_properties->output_filename;
}



extern FILE* properties_get_output_stream(PROPERTIES* p_properties)
{
    return p_properties->output_file;
}



static char* get_new_filename(char* filename, const char* mime_type)
{
    size_t length = strlen(filename);
    char* new_filename = malloc(sizeof(char) * (length + 4));
    strcpy(new_filename, filename);
    strcat(new_filename, mime_type);
    return new_filename;
}