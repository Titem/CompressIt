#include "properties.h"
#include "error.h"

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


properties* create_properties(char** argv,int argc)
{
/*---------------------------------------------------------------------------------*/
/*----------------------------Dekleration von Variablen----------------------------*/
/*---------------------------------------------------------------------------------*/

	bool found_input_document = false;
	bool found_out_put_document = false;

	char *output_file_name = NULL;
	char *input_file_name = NULL;

	FILE *file_read = NULL;
	FILE *file_write = NULL;

	properties *p_properties;
	p_properties = malloc(sizeof(p_properties));

/*---------------------------------------------------------------------------------*/
/*----------------------------Analyse der Paramter---------------------------------*/
/*---------------------------------------------------------------------------------*/

	if (p_properties != NULL)
	{
		if ((argc == 1) || (argc == 2) || (argc > 4))
		{
			print_error(too_many_arguments);
			exit(EXIT_FAILURE);
		}
		else
		{
			argc--;
			argv++;

			if (!found_input_document && strcmp(*argv, COMPPRESS_STATUS) == 0)
			{
				p_properties->MODE = COMPRESS;
				argc--;
				argv++;

				if (*argv != NULL)
				{
					input_file_name = *argv;
					found_input_document = true;
				}
				else
				{
					print_error(dont_found_input_document);
					exit(EXIT_FAILURE);
				}
			}
			else if (!found_input_document && strcmp(*argv, DECOMPRESS_STATUS) == 0)
			{
				p_properties->MODE = DECOMPRESS;
				argc--;
				argv++;

				if (*argv != NULL)
				{
					input_file_name = *argv;
					found_input_document = true;
				}
				else
				{
					print_error(dont_found_input_document);
					exit(EXIT_FAILURE);					
				}
			}
			else if (!found_out_put_document && found_input_document)
			{
				argc--;
				argv++;
				if (*argv != NULL)
				{
					output_file_name = *argv;
					found_out_put_document = true;
				}
				else
				{
					output_file_name = input_file_name;
				}
			}
			else if (strcmp(*argv, HELP) == 0)
			{
				print_error(help);
				exit(EXIT_FAILURE);
			}
			else if (argc >= 1 && !found_input_document)
			{
				print_error(too_many_arguments);
				print_error(AND);
				print_error(dont_found_input_document);
				exit(EXIT_FAILURE);
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
	
	if (!found_out_put_document)
	{
		if (p_properties->MODE == COMPRESS)
		{
			strcat(output_file_name, COMPRESS_NAME);
		}
		else if (p_properties->MODE == DECOMPRESS)
		{
			strcat(output_file_name, DECOMPRESS_NAME);
		}	
	}
	else if (found_input_document && found_out_put_document && (strcmp(input_file_name, output_file_name) == 0))
	{
		print_error(in_and_output_document_are_the_same);
		exit(EXIT_FAILURE);
	}

/*---------------------------------------------------------------------------------*/
/*----------------------FILE POINTER setzen und prüfen-----------------------------*/
/*---------------------------------------------------------------------------------*/
	file_read = fopen(input_file_name, READ_BINARY);
	test_nullpointer_exception(file_read, input_file_name);

	file_write = fopen(output_file_name, WRITE_BINARY);
	test_nullpointer_exception(file_write, output_file_name);

/*---------------------------------------------------------------------------------*/
/*-------------FILE POINTER in die PROPERTIES STRUCT übernehmen--------------------*/
/*---------------------------------------------------------------------------------*/

	p_properties->file_read = file_read;
	p_properties->file_write = file_write;


	return p_properties;
}

void delete_properties(properties (*p_properties))
{
	free(p_properties);
	p_properties = NULL;
}

