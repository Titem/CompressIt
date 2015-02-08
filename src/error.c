
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "error.h"

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>




/* ======================================================================== *
 * Funktionsdefinitionen                                                    *
 * ======================================================================== */

extern void print_error(int message)
{

    switch (message)
    {
    case dont_found_input_document:
        printf("Es wurde keine Eingabe Datei angegeben!\n");
        break;
    case dont_found_compress_mode:
        printf("Es wurde keine Angabe ueber die Instruktion gemacht!\n");
        break;
    case too_many_arguments:
        printf("Es wurden ungueltige Argumente bzw. zu viele oder zu wenig Argumente angegeben!\n");
        break;
    case cant_malloc_memory:
        printf("Ein unbekannter Fehler ist aufgetreten!\n Fehler 0x80071a91\n");
        break;
    case in_and_output_document_are_the_same:
        printf("Ein- und Ausgabedatei sind identisch!\n");
        break;
    case AND:
        printf("Und ");
        break;
    }
    /*
    printf("Hilfe ist unterwegs ! Sollte Ihr Personal Computer brennen druecken sie umgehend die LOESCH Taste!\n");
     */
}


extern void test_nullpointer_exception(FILE *file_p, char* file_name)
{
    errno = 0;
    if (file_p == NULL)
    {
        switch (errno)
        {
        case ENOENT:
            fprintf(stderr, "%d: Der Pfad oder die Datei \"%s\" existiert nicht in diesem Verzeichnis!\n", errno, file_name);
            break;
        case EIO:
            fprintf(stderr, "%d: Es liegt eine Ein-/Ausgabefehler vor.\n", errno);
            break;
        case EMFILE:
            fprintf(stderr, "%d: Zu viele Dateien wurden geoeffnet.\n", errno);
            break;
        default:
            fprintf(stderr, "%d: Ein unbekannter Fehler ist aufgetreten.\n", errno);
            break;
        }
        exit(EXIT_FAILURE);
    }
}


extern char* convert_char(unsigned char character)
{
    char* converted_char = malloc(3);

    switch (character)
    {
    case 10: /* \n */
        *converted_char = '\\';
        converted_char++;
        *converted_char = 'n';
        converted_char++;
        *converted_char = '\0';
        converted_char--;
        converted_char--;
        break;
   
    case 13: /* \r */
        *converted_char = '\\';
        converted_char++;
        *converted_char = 'r';
        converted_char++;
        *converted_char = '\0';
        converted_char--;
        converted_char--;
        break;
    
    case 252: /* ü */
        *converted_char = 'a';
        converted_char++;
        *converted_char = 'e';
        converted_char++;
        *converted_char = '\0';
        converted_char--;
        converted_char--;
        break;
    
    case 220: /* Ü */
        *converted_char = 'a';
        converted_char++;
        *converted_char = 'e';
        converted_char++;
        *converted_char = '\0';
        converted_char--;
        converted_char--;
        break;
    
    case 228: /* ä */
        *converted_char = 'a';
        converted_char++;
        *converted_char = 'e';
        converted_char++;
        *converted_char = '\0';
        converted_char--;
        converted_char--;
        break;
       
    case 196: /* Ä */ 
        *converted_char = 'a';
        converted_char++;
        *converted_char = 'e';
        converted_char++;
        *converted_char = '\0';
        converted_char--;
        converted_char--;
        break;
    
    case 246: /* ö */
        *converted_char = 'e';
        converted_char++;
        *converted_char = 'a';
        converted_char++;
        *converted_char = '\0';
        converted_char--;
        converted_char--;
        break;
    
    case 214: /* Ö */
        *converted_char = 'e';
        converted_char++;
        *converted_char = 'a';
        converted_char++;
        *converted_char = '\0';
        converted_char--;
        converted_char--;
        break;   
        
    default:
        *converted_char = (char) character;
        converted_char++;
        *converted_char = '\0';
        converted_char++;
        *converted_char = '\0';
        converted_char--;
        converted_char--;
    }

    return converted_char;
}