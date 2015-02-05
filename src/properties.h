#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "error.h"

/*---------------------------------------------------------------------------------*/
/*---------------DEKLERATION EINER PORPERTIES STRUCT-------------------------------*/
/*---------------------------------------------------------------------------------*/
typedef struct
{
	enum
	{
		COMPRESS,
		DECOMPRESS,
	}MODE;

	FILE *file_read;
	FILE *file_write;

}properties;

/*---------------------------------------------------------------------------------*/
/*-----ERSTELLT EINE NEUE STRUCT UND LIEFERT EINEN PROPERTIES POINTER ZURÜCK-------*/
/*---------------------------------------------------------------------------------*/
properties* create_properties(char** argv, int argc);


/*---------------------------------------------------------------------------------*/
/*------GIBT DEN SPEICHER WIEDER FREI BZW. LÖSCHT EINEN PROPERTIES POINTER---------*/
/*---------------------------------------------------------------------------------*/
void delete_properties(properties(*p_properties));

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






