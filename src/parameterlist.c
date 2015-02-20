
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "parameterlist.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "debug_common.h"
#include "error_handler.h"




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
     * die den Dateinamen der Quell-Datei enth�lt.
     */
    char* input_filename;
    
    /**
     * Diese Variable speichert einen Zeiger auf den Eingangs-Datenstrom.
     */
    FILE* input_file;
    
    /**
     * Diese Variable speichert einen Zeiger auf eine Zeichenkette,
     * die den Dateinamen der Ziel-Datei enth�lt.
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

/* Beschreibt die Argumente f�r das Kodieren, Decodieren und den Hilfeaufruf. */
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
 * liefert einen Zeiger auf diesen neu erstellten String zur�ck.
 * 
 * @param filename Zeiger auf die Zeichenkette, die den Dateinamen enth�lt
 * @param mime_type Zeiger auf die Zeichenkette, die den Mime-Typ enth�lt
 * @return Zeiger auf die neu erstellte Zeichenkette
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

    FILE *output_file = NULL;
    FILE *input_file = NULL;

    PARAMETERLIST *new_parameterlist = malloc(sizeof(PARAMETERLIST));

    error_handler_activate(new_parameterlist);
    
    if (new_parameterlist == NULL)
    {
        error_handler_handle_error(CANT_ALLOCATE_MEMORY, __FILE__, __LINE__);
    }
    
    new_parameterlist->run_mode = UNDEFINED;
    new_parameterlist->input_filename = NULL;
    new_parameterlist->input_file = NULL;
    new_parameterlist->output_filename = NULL;
    new_parameterlist->output_file = NULL;
    
#ifdef DEBUG_HUFFMAN
    printf("Analyse der Parameter!\n");
#endif
    
    if (argc <= 1)
    {
        error_handler_handle_error(TO_FEW_ARGUMENTS, __FILE__, __LINE__);
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

            if (argc <= 0)
            {
                error_handler_handle_error(NO_INPUT_FILENAME, __FILE__, __LINE__);
            }
                
            #ifdef DEBUG_HUFFMAN
                printf("Quell-Dateinamen gefunden!\n");
            #endif
            
            input_filename = *argv;
            found_input_document = true;
        }

        else if (!found_input_document && strcmp(*argv, DECOMPRESS_FLAG) == 0)
        {
            new_parameterlist->run_mode = DECOMPRESS;
            argc--;
            argv++;

            if (argc <= 0)
            {
                error_handler_handle_error(NO_INPUT_FILENAME, __FILE__, __LINE__);
            }
            
            #ifdef DEBUG_HUFFMAN
                printf("Quell-Dateinamen gefunden!\n");
            #endif 

            input_filename = *argv;
            found_input_document = true;
        }
        
        else if (strcmp(*argv, HELP_FLAG) == 0)
        {
            new_parameterlist->run_mode = MANPAGE;
            need_help = true;
        }

        else if (found_input_document && !found_output_document)
        {
            #ifdef DEBUG_HUFFMAN
                printf("Ziel-Dateinamen gefunden!\n");
            #endif

            output_filename = *argv;
            found_output_document = true;
        }
        
        else
        {
            error_handler_handle_error(TO_MANY_ARGUMENTS, __FILE__, __LINE__);
        }
    }

    /* automatisch Ziel-Dateinamen generieren */
    if (!found_output_document && !need_help)
    {
        if (new_parameterlist->run_mode == COMPRESS)
        {
            output_filename = parameterlist_get_new_filename(input_filename, COMPRESS_MIME_TYPE);
        }
        else
        {
            output_filename = parameterlist_get_new_filename(input_filename, DECOMPRESS_MIME_TYPE);
        }
    }
    
    /* Pr�fung ob Dateinamen gleich sind */
    if (found_input_document && found_output_document && (strcmp(input_filename, output_filename) == 0) && !need_help)
    {
        error_handler_handle_error(FILENAMES_ARE_EQUAL, __FILE__, __LINE__);
    }

    /* Dateien �ffnen */
    if (!need_help)
    {
        input_file = fopen(input_filename, READ_BINARY);
        if (input_file == NULL)
        {
            error_handler_handle_error(CANT_OPEN_INPUT_FILE, __FILE__, __LINE__);
        }

        #ifdef DEBUG_HUFFMAN
        printf("Input-File-Stream geoeffnet!\n");
        #endif

        output_file = fopen(output_filename, WRITE_BINARY);
        if (output_file == NULL)
        {
            error_handler_handle_error(CANT_OPEN_OUTPUT_FILE, __FILE__, __LINE__);
        }

        #ifdef DEBUG_HUFFMAN
        printf("Output-File-Stream geoeffnet!\n");
        #endif

        new_parameterlist->input_file = input_file;
        new_parameterlist->output_file = output_file;
    }
    
    #ifdef DEBUG_HUFFMAN
    printf("Analyse der Parameter beendet!\n\n\n");
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