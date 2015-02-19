
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

/**
 * Dies ist die Hauptfunktion des Projektes CompressIt. Mit dieser Funktion
 * wird die Anwendung gestartet. Wird die Anwendung fehlerfrei ausgeführt
 * liefert diese Funktion EXIT_SUCCESS (0) zurück.
 * 
 * @param argc Anzahl 
 * @param argv Test2
 * @return Ganzzahl, die einen Fehler-Code repräsentiert
 *         (Wird die Anwendung fehlerfrei ausgeführt ist dieser Rückgabewert 
 *          EXIT_SUCCESS (0).)
 */
int main(int argc, char** argv);




/* ======================================================================== *
 * Funktionsdefinitionen                                                    *
 * ======================================================================== */

int main(int argc, char** argv)
{
    PARAMETERLIST* parameterlist = create_parameterlist(argv, argc);
    
    
    #ifdef DEBUG_HUFFMAN
    /*Für die Zeit zuständig.*/
    clock_t begin = NULL;
    clock_t end = NULL;
    /*Timer starten*/
    begin = clock();
    #endif


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
    /*Timer beenden*/
    end = clock();
    printf("\nBenoetigte Zeit: %i ms\n\n", (int) (end - begin));
    getchar();
    #endif

    
    exit(EXIT_SUCCESS);
}

