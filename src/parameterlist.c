
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
static const char* COMPPRESS_FLAG = "-c";
static const char* DECOMPRESS_FLAG = "-d";
static const char* HELP_FLAG = "-h";

/* Beschreibt den MIME-Typ, der der Ausgabedatei angehangen wird. */
static const char* COMPRESS_MIME_TYPE = ".hc";
static const char* DECOMPRESS_MIME_TYPE = ".hd";

/* Beschreibt den Lese- bzw- Schreibevorgang. */
static const char* READ_BINARY = "rb";
static const char* WRITE_BINARY = "wb";




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

/**
 * Diese Funktion erstellt einen Dateinamen als String auf dem Heap,
 * welcher aus dem Dateinamen und dem angehangenen Mime-Typ besteht und
 * liefert einen Zeiger auf diesen neu erstellten String zurück.
 *
 * @param filename Zeiger auf die Zeichenkette, die den Dateinamen enthält
 * @param mime_type Zeiger auf die Zeichenkette, die den Mime-Typ enthält
 * @return Zeiger auf die neu erstellte Zeichenkette
 */
static char* parameterlist_get_new_filename(char* filename, 
                                            const char* mime_type);




/* ======================================================================== *
 * Funktionsdefinitionen                                                    *
 * ======================================================================== */

extern PARAMETERLIST* create_parameterlist(char** argv, int argc)
{
    PARAMETERLIST *new_parameterlist = malloc(sizeof(PARAMETERLIST));
    
    bool found_input_document = false;
    bool found_output_document = false;
    bool need_help = false;

    error_handler_activate(new_parameterlist);

    if (new_parameterlist == NULL)
    {
        error_handler_handle_error(CANT_ALLOCATE_MEMORY, 
                                   __FILE__, __LINE__);
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
        error_handler_handle_error(TO_FEW_ARGUMENTS, 
                                   __FILE__, __LINE__);
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
                error_handler_handle_error(NO_INPUT_FILENAME, 
                                           __FILE__, __LINE__);
            }

            #ifdef DEBUG_HUFFMAN
                printf("Quell-Dateinamen gefunden!\n");
            #endif

            new_parameterlist->input_filename = *argv;
            found_input_document = true;
        }

        else if (!found_input_document && strcmp(*argv, DECOMPRESS_FLAG) == 0)
        {
            new_parameterlist->run_mode = DECOMPRESS;
            argc--;
            argv++;

            if (argc <= 0)
            {
                error_handler_handle_error(NO_INPUT_FILENAME, 
                                           __FILE__, __LINE__);
            }

            #ifdef DEBUG_HUFFMAN
                printf("Quell-Dateinamen gefunden!\n");
            #endif

            new_parameterlist->input_filename = *argv;
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

            new_parameterlist->output_filename = *argv;
            found_output_document = true;
        }

        else
        {
            error_handler_handle_error(TO_MANY_ARGUMENTS, 
                                       __FILE__, __LINE__);
        }
    }

    /* automatisch Ziel-Dateinamen generieren */
    if (!found_output_document && !need_help)
    {
        if (new_parameterlist->run_mode == COMPRESS)
        {
            new_parameterlist->output_filename 
                = parameterlist_get_new_filename(
                    new_parameterlist->input_filename, 
                    COMPRESS_MIME_TYPE);
        }
        else
        {
            new_parameterlist->output_filename
                = parameterlist_get_new_filename(
                    new_parameterlist->input_filename, 
                    DECOMPRESS_MIME_TYPE);
        }
    }

    /* Prüfung ob Dateinamen gleich sind */
    if (found_input_document && found_output_document 
        && (strcmp(new_parameterlist->input_filename, 
        new_parameterlist->output_filename) == 0) && !need_help)
    {
        error_handler_handle_error(FILENAMES_ARE_EQUAL, 
                                   __FILE__, __LINE__);
    }

    /* Dateien öffnen */
    if (!need_help)
    {
        new_parameterlist->input_file 
            = fopen(new_parameterlist->input_filename, READ_BINARY);
        if (new_parameterlist->input_file == NULL)
        {
            error_handler_handle_error(CANT_OPEN_INPUT_FILE, 
                                       __FILE__, __LINE__);
        }

        #ifdef DEBUG_HUFFMAN
        printf("Input-File-Stream geoeffnet!\n");
        #endif

        new_parameterlist->output_file 
            = fopen(new_parameterlist->output_filename, WRITE_BINARY);
        if (new_parameterlist->output_file == NULL)
        {
            error_handler_handle_error(CANT_OPEN_OUTPUT_FILE, 
                                       __FILE__, __LINE__);
        }

        #ifdef DEBUG_HUFFMAN
        printf("Output-File-Stream geoeffnet!\n");
        #endif
    }

    #ifdef DEBUG_HUFFMAN
    printf("Analyse der Parameter beendet!\n\n\n");
    #endif

    return new_parameterlist;
}



extern void delete_parameterlist(PARAMETERLIST** parameterlist)
{
    free((*parameterlist)->input_file);
    free((*parameterlist)->output_file);
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



static char* parameterlist_get_new_filename(char* filename, 
                                            const char* mime_type)
{
    size_t length = strlen(filename);
    char* new_filename = malloc(sizeof(char) * (length + 4));
    
    if (new_filename == NULL)
    {
        error_handler_handle_error(CANT_ALLOCATE_MEMORY, __FILE__, __LINE__);
    }
    
    strcpy(new_filename, filename);
    strcat(new_filename, mime_type);
    
    return new_filename;
}
