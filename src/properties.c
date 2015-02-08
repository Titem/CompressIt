
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
    FILE *file_read;
    FILE *file_write;
    MODE mode;
};




/* ======================================================================== *
 * Konstanten                                                     *
 * ======================================================================== */

/*Beschreibt ob codiert oder decodiert werden soll.*/
char* const COMPPRESS_STATUS = "-c";
char* const DECOMPRESS_STATUS = "-d";

/*Beschreibt den Namen der Ausgabedatei, wenn keine angegeben wurde.*/
char* const COMPRESS_NAME = ".hc";
char* const DECOMPRESS_NAME = ".hd";

/*Beschreibt das Argument für den Hilfe Aufruf.*/
char* const HELP = "-h";

/*Beschreibt den Lese- bzw- Schreibevorgang.*/
char* const READ_BINARY = "rb";
char* const WRITE_BINARY = "wb";




/* ======================================================================== *
 * Funktionsdefinitionen                                                    *
 * ======================================================================== */

/*---------------------------------------------------------------------------------*/
/*------INITIALISIERT DEN NAMEN DER AUSGABEDATEI WENN KEINE ANGEGEBEN WURDE--------*/
/*---------------------------------------------------------------------------------*/
static char* init_output_filename(char* input_file_name);




/* ======================================================================== *
 * Funktionsdefinitionen                                                    *
 * ======================================================================== */

extern PROPERTIES* create_properties(char** argv, int argc)
{
    /*---------------------------------------------------------------------------------*/
    /*----------------------------Dekleration von Variablen----------------------------*/
    /*---------------------------------------------------------------------------------*/

    bool found_input_document = false;
    bool found_out_put_document = false;
    bool need_help = false;

    char *output_file_name = NULL;
    char *input_file_name = NULL;

    FILE *file_read = NULL;
    FILE *file_write = NULL;

    PROPERTIES *p_properties = NULL;
    p_properties = malloc(sizeof (PROPERTIES));

    p_properties->file_read = NULL;
    p_properties->file_write = NULL;
    p_properties->mode = UNDEFINED;

    /*---------------------------------------------------------------------------------*/
    /*----------------------------Analyse der Paramter---------------------------------*/
    /*---------------------------------------------------------------------------------*/
    printf("Analyse der Parameter!\n");
    if (p_properties != NULL)
    {
        if ((argc == 1) || (argc == 2) || (argc > 4))
        {
            print_error(too_many_arguments);
            exit(EXIT_FAILURE);
        }
        else
        {
            while (argc > 1)
            {
                argc--;
                argv++;

                if (!found_input_document && strcmp(*argv, COMPPRESS_STATUS) == 0)
                {
                    p_properties->mode = COMPRESS;
                    argc--;
                    argv++;

                    if (*argv != NULL)
                    {
                        input_file_name = *argv;
                        found_input_document = true;
                        printf("FOUND INPUT DOCUMENT AND STATUS -c !\n");
                    }
                    else
                    {
                        print_error(dont_found_input_document);
                        exit(EXIT_FAILURE);
                    }
                }

                if (!found_input_document && strcmp(*argv, DECOMPRESS_STATUS) == 0)
                {
                    p_properties->mode = DECOMPRESS;
                    argc--;
                    argv++;

                    if (*argv != NULL)
                    {
                        input_file_name = *argv;
                        found_input_document = true;
                        printf("FOUND INPUT DOCUMENT AND STATUS -d !\n");
                    }
                    else
                    {
                        print_error(dont_found_input_document);
                        exit(EXIT_FAILURE);
                    }
                }

                if (!found_out_put_document)
                {
                    printf("DONT FOUND OUTPUT DOKUMENT!\n");
                    argc--;
                    argv++;
                    if (*argv != NULL)
                    {
                        printf("FOUND OUTPUT DOCUMENT!\n");
                        output_file_name = *argv;
                        found_out_put_document = true;
                    }
                    else
                    {
                        printf("POINTER IS NULL -> INPUTFILENAME AS OUTPUTFILENAME!\n");
                        /*IMPLEMENIEREN*/
                        output_file_name = init_output_filename(input_file_name);
                        strcpy(output_file_name, input_file_name);


                    }
                }

                if (*argv != NULL && strcmp(*argv, HELP) == 0 && !need_help)
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
            }
        }
    }
    else
    {
        print_error(cant_malloc_memory);
        exit(EXIT_FAILURE);
    }

    /*----------------------------------------------------------------------------------------------*/
    /*----Prüfen ob Ausgabedatei vorhanden ist, wenn nein, neue erstellen mit zugehöriger Endung----*/
    /*----------------------------------------------------------------------------------------------*/
    printf("Pruefen ob Ausgabedatei vorhanden ist, wenn nein, neue erstellen mit zugehoeriger Endung !\n");
    if (!found_out_put_document && !need_help)
    {
        if (p_properties->mode == COMPRESS)
        {
            strcat(output_file_name, COMPRESS_NAME);
            printf("---> Der neue Dateiname heisst jetzt %s !<--- \n", output_file_name);
        }
        else if (p_properties->mode == DECOMPRESS)
        {
            strcat(output_file_name, DECOMPRESS_NAME);
            printf("---> Der neue Dateiname heisst jetzt %s !<--- \n!", output_file_name);
        }
    }
    else if (found_input_document && found_out_put_document && (strcmp(input_file_name, output_file_name) == 0) && !need_help)
    {
        print_error(in_and_output_document_are_the_same);
        exit(EXIT_FAILURE);
    }

    if (!need_help)
    {
        /*---------------------------------------------------------------------------------*/
        /*----------------------FILE POINTER setzen und pruefen-----------------------------*/
        /*---------------------------------------------------------------------------------*/
        printf("FILE POINTER setzen und pruefen !\n");

        printf("FP READ Stream geoeffnet !\n");
        file_read = fopen(input_file_name, READ_BINARY);
        test_nullpointer_exception(file_read, input_file_name);

        printf("FP WRITE Stream geoeffnet !\n");
        file_write = fopen(output_file_name, WRITE_BINARY);
        test_nullpointer_exception(file_write, output_file_name);

        /*---------------------------------------------------------------------------------*/
        /*-------------FILE POINTER in die PROPERTIES STRUCT uebernehmen--------------------*/
        /*---------------------------------------------------------------------------------*/
        printf("FILE POINTER in die PROPERTIES STRUCT uebernehmen !\n");
        p_properties->file_read = file_read;
        p_properties->file_write = file_write;
    }
    printf("END OF OPERATION!\n");
    return p_properties;
}

extern void delete_properties(PROPERTIES* p_properties)
{
    free(p_properties);
    p_properties = NULL;
}

extern MODE properties_get_mode(PROPERTIES* p_properties)
{
    return p_properties->mode;
}

extern FILE* properties_get_input_stream(PROPERTIES* p_properties)
{
    return p_properties->file_read;
}

extern FILE* properties_get_output_stream(PROPERTIES* p_properties)
{
    return p_properties->file_write;
}

static char* init_output_filename(char* input_file_name)
{
    size_t length = strlen(input_file_name);
    char* output_file_name = NULL;
    output_file_name = malloc(length);
    return output_file_name;
}