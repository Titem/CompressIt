
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include <stdio.h>
#include <stdlib.h>
#ifdef DEBUG_HUFFMAN
#include <time.h>
#endif
#include "properties.h"
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
    PROPERTIES* properties;
    #ifdef DEBUG_HUFFMAN
    /*Für die Zeit zuständig.*/
    clock_t begin = NULL;
    clock_t end = NULL;

    /*Timer starten*/
    begin = clock();
    #endif
    /*-----------------------------CODE--------------------------------*/

    properties = NULL;
    properties = create_properties(argv, argc);

    switch (properties_get_mode(properties))
    {
    case COMPRESS:
        compress(properties_get_input_stream(properties),
                 properties_get_output_stream(properties));
        break;

    case DECOMPRESS:
        decompress(properties_get_input_stream(properties),
                   properties_get_output_stream(properties));
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

