/* 
 * File:   huffman.c
 * Author: Tim
 *
 * Created on 17. Dezember 2014, 10:53
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Eingabedatei */
static char *in_filename;

/* Ausgabedatei */
static char *out_filename;

/* Richtung */
char direction = ' ';

/**
 * Ermittelt aus den Kommandozeilenparametern die benötigten Informationen
 * für den Programmablauf.
 *
 * @param argc - Anzahl der übergebenen Parameter
 * @param argv - die übergebenen Parameter
 * @return EXIT_SUCCESS
 */
int main(int argc, char *argv[]);

/**
 * Ermittelt aus den Kommandozeilenparametern die benötigten Informationen
 * für den Programmablauf. Das sind die auszugebenden Wörter, die Anzahl der
 * Wörter und die Information, ob die Ausgabe mit einem Zeilenumbruch beendet
 * werden soll oder nicht.
 *
 * @param argc - Anzahl der übergebenen Parameter
 * @param argv - die übergebenen Parameter
 *
 */
static void get_arguments(int argc, char *argv[]);

/**
 * Liefert eine Hilfe als Ausgabe.
 */
static void print_help();


/* ----------------------------------------------------------------------------
 * Funktion: main
 * ------------------------------------------------------------------------- */
int main(int argc, char** argv)
{

    return (EXIT_SUCCESS);
}

/* ----------------------------------------------------------------------------
 * Funktion: get_arguments
 * ------------------------------------------------------------------------- */
static void get_arguments(int argc, char *argv[])
{
    int i;
    in_filename = NULL;
    /*Falls nicht anders angegeben, stdout nutzen */
    out_filename = NULL;
    for (i=1; i < argc; i++)
    {
        if (strcmp(argv[i], "-c") == 0)
        {
            direction = 'c';
           
            in_filename = (char *) malloc(strlen(argv[++i]) * sizeof(char));
        }
        else if (strcmp(argv[i], "-d")  == 0)
        {
            direction = 'd';
            out_filename = (char *) malloc(strlen(argv[++i]) * sizeof(char));
        }
        else if (strcmp(argv[i], "-l")  == 0)
        {
            
        }
        else 
        {
            exit(EXIT_FAILURE);
        }

        /*TODO: Pruefung ob Eingabe = Ausgabedatei */
        
        /* Falls nur eine Eingabedatei uebergeben wurde wird die Ausgabedatei */
        /* automatisch gesetzt. */
        if (in_filename != NULL && out_filename == NULL)
        {
            out_filename = in_filename + 'h' + direction;
        }
        
        if ( direction == ' ' || (in_filename == NULL && out_filename == NULL))
        {
            printf("Fehler bei den Parametern.\n");
            print_help();
            exit(EXIT_FAILURE);
        }
    }
}
static void print_help()
{
    printf("Usage: ./huffman [-c/-d] infile [out_file] \n");
}