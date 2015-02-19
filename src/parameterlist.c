
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "parameterlist.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "error.h"




/* ======================================================================== *
 * Strukturdefinitionen                                                     *
 * ======================================================================== */

/** 
 * Diese Struktur beschreibt den Aufbau einer Parameterliste.
 */
struct S_PARAMETERLIST
{
    /**
     * Diese Variable speichert den Betriebs-Modus der Anwendung.
     */
    RUN_MODE run_mode;
    
    /**
     * Diese Variable speichert einen Zeiger auf eine Zeichenkette,
     * die den Dateinamen der Quell-Datei enthält.
     */
    char* input_filename;
    
    /**
     * Diese Variable speichert einen Zeiger auf den Eingangs-Datenstrom.
     */
    FILE* input_file;
    
    /**
     * Diese Variable speichert einen Zeiger auf eine Zeichenkette,
     * die den Dateinamen der Ziel-Datei enthält.
     */
    char* output_filename;
    
    /**
     * Diese Variable speichert einen Zeiger auf den Ausgangs-Datenstrom.
     */
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
static char* parameterlist_get_new_filename(char* filename, const char* mime_type);




/* ======================================================================== *
 * Funktionsdefinitionen                                                    *
 * ======================================================================== */

extern PARAMETERLIST* create_parameterlist(char** argv, int argc)
{
    bool found_input_document = false;
    bool found_output_document = false;
    bool need_help = false;

    char *output_filename = NULL;
    char *input_filename = NULL;

    FILE *file_read = NULL;
    FILE *file_write = NULL;

    PARAMETERLIST *new_parameterlist = malloc(sizeof(PARAMETERLIST));

    if (new_parameterlist == NULL)
    {
        print_error(cant_malloc_memory);
        exit(EXIT_FAILURE);
    }
    
    new_parameterlist->run_mode = UNDEFINED;
    new_parameterlist->input_filename = NULL;
    new_parameterlist->input_file = NULL;
    new_parameterlist->output_filename = NULL;
    new_parameterlist->output_file = NULL;
    

    

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
            new_parameterlist->run_mode = COMPRESS;
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
            new_parameterlist->run_mode = DECOMPRESS;
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
            new_parameterlist->run_mode = MANPAGE;
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

                if (new_parameterlist->run_mode == COMPRESS)
                {
                    output_filename = parameterlist_get_new_filename(input_filename, COMPRESS_MIME_TYPE);
                }
                else
                {
                    output_filename = parameterlist_get_new_filename(input_filename, DECOMPRESS_MIME_TYPE);
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

        new_parameterlist->input_file = file_read;
        new_parameterlist->output_file = file_write;
    }
#ifdef DEBUG_HUFFMAN
    printf("END OF PROPERTIES!\n");
#endif

    return new_parameterlist;
}



extern void delete_parameterlist(PARAMETERLIST** parameterlist)
{
    free(*parameterlist);
    *parameterlist = NULL;
}



extern RUN_MODE parameterlist_get_run_mode(PARAMETERLIST* parameterlist)
{
    return parameterlist->run_mode;
}



extern char* parameterlist_get_input_filename(PARAMETERLIST* parameterlist)
{
    return parameterlist->input_filename;
}



extern FILE* parameterlist_get_input_stream(PARAMETERLIST* parameterlist)
{
    return parameterlist->input_file;
}



extern char* parameterlist_get_output_filename(PARAMETERLIST* parameterlist)
{
    return parameterlist->output_filename;
}



extern FILE* parameterlist_get_output_stream(PARAMETERLIST* parameterlist)
{
    return parameterlist->output_file;
}



static char* parameterlist_get_new_filename(char* filename, const char* mime_type)
{
    size_t length = strlen(filename);
    char* new_filename = malloc(sizeof(char) * (length + 4));
    strcpy(new_filename, filename);
    strcat(new_filename, mime_type);
    return new_filename;
}