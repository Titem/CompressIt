
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include <stdio.h>
#include <stdlib.h>
#ifdef DEBUG_HUFFMAN
#include <time.h>
#endif
#include "parameterlist.h"
#include "compressor.h"
#include "error.h"
/*#define DEBUG_HUFFMAN*/




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

/*Jede C-Anwendung muss genau eine Main-Methode enthalten, in der angegeben ist, wo die Programmausführung beginnen soll.*/
int main(int argc, char** argv);




/* ======================================================================== *
 * Funktionsdefinitionen                                                    *
 * ======================================================================== */

/**
 * main.c
 * @param argc Test
 * @param argv Test2
 */
int main(int argc, char** argv)
{
    PARAMETERLIST* parameterlist;
    #ifdef DEBUG_HUFFMAN
    /*Für die Zeit zuständig.*/
    clock_t begin = NULL;
    clock_t end = NULL;

    /*Timer starten*/
    begin = clock();
    #endif
    /*-----------------------------CODE--------------------------------*/

    parameterlist = NULL;
    parameterlist = create_parameterlist(argv, argc);

    switch (parameterlist_get_run_mode(parameterlist))
    {
    case COMPRESS:
        compress(parameterlist_get_input_stream(parameterlist),
                 parameterlist_get_output_stream(parameterlist));
        break;

    case DECOMPRESS:
        decompress(parameterlist_get_input_stream(parameterlist),
                   parameterlist_get_output_stream(parameterlist));
        break;

    case MANPAGE:
        print_error(help);
        break;

    default:
        printf("Hier stimmt was nicht!");
    }
#ifdef DEBUG_HUFFMAN
    /*-----------------------------CODE--------------------------------*/
    /*Timer beenden*/
    end = clock();

    printf("\nBenoetigte Zeit: %i ms\n\n", (int) (end - begin));

    getchar();
#endif
    exit(EXIT_SUCCESS);
}

