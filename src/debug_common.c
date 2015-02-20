
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "debug_common.h"

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>




/* ======================================================================== *
 * Funktionsdefinitionen                                                    *
 * ======================================================================== */

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
        *converted_char = 'u';
        converted_char++;
        *converted_char = 'e';
        converted_char++;
        *converted_char = '\0';
        converted_char--;
        converted_char--;
        break;

    case 220: /* Ü */
        *converted_char = 'U';
        converted_char++;
        *converted_char = 'E';
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
        *converted_char = 'A';
        converted_char++;
        *converted_char = 'E';
        converted_char++;
        *converted_char = '\0';
        converted_char--;
        converted_char--;
        break;

    case 246: /* ö */
        *converted_char = 'o';
        converted_char++;
        *converted_char = 'e';
        converted_char++;
        *converted_char = '\0';
        converted_char--;
        converted_char--;
        break;

    case 214: /* Ö */
        *converted_char = 'O';
        converted_char++;
        *converted_char = 'E';
        converted_char++;
        *converted_char = '\0';
        converted_char--;
        converted_char--;
        break;

    case 223: /* ß */
        *converted_char = 's';
        converted_char++;
        *converted_char = 's';
        converted_char++;
        *converted_char = '\0';
        converted_char--;
        converted_char--;
        break;

    case 150: /* -- */
        *converted_char = '-';
        converted_char++;
        *converted_char = '-';
        converted_char++;
        *converted_char = '\0';
        converted_char--;
        converted_char--;
        break;

    case 132: /* " unten */
        *converted_char = '"';
        converted_char++;
        *converted_char = 'U';
        converted_char++;
        *converted_char = '\0';
        converted_char--;
        converted_char--;
        break;

    case 148: /* " oben */
        *converted_char = '"';
        converted_char++;
        *converted_char = 'O';
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
