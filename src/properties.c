#include "properties.h"
#include "error.h"

/*---------------------------------------------------------------------------------*/
/*---------------DEKLERATION EINER PORPERTIES STRUCT-------------------------------*/
/*---------------------------------------------------------------------------------*/
struct S_PROPERTIES
{
	FILE *file_read;
	FILE *file_write;
	MODE MODE;
};


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



PROPERTIES* create_properties(char* argv[], int argc)
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

	PROPERTIES *p_properties;
	p_properties = malloc(sizeof(PROPERTIES));

/*---------------------------------------------------------------------------------*/
/*----------------------------Analyse der Paramter---------------------------------*/
/*---------------------------------------------------------------------------------*/
	printf("Analyse der Parameter !\n");
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
				p_properties->MODE = COMPRESS;
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
				p_properties->MODE = DECOMPRESS;
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
					strcpy(output_file_name,input_file_name);


				}
			}
			
			if (*argv != NULL && strcmp(*argv, HELP) == 0)
			{
				p_properties->MODE = MANPAGE;
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
	printf("Prüfen ob Ausgabedatei vorhanden ist, wenn nein, neue erstellen mit zugehöriger Endung !\n");
	if (!found_out_put_document && !need_help)
	{
		if (p_properties->MODE == COMPRESS)
		{
			strcat(output_file_name, COMPRESS_NAME);
			printf("Der neue Dateiname heisst jetzt %s", output_file_name);
		}
		else if (p_properties->MODE == DECOMPRESS)
		{
			strcat(output_file_name, DECOMPRESS_NAME);
			printf("Der neue Dateiname heisst jetzt %s", output_file_name);
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
		/*----------------------FILE POINTER setzen und prüfen-----------------------------*/
		/*---------------------------------------------------------------------------------*/
		printf("FILE POINTER setzen und prüfen !\n");

		printf("FP READ Stream geöffnet !\n");
		file_read = fopen(input_file_name, READ_BINARY);
		test_nullpointer_exception(file_read, input_file_name);

		printf("FP WRITE Stream geöffnet !\n");
		file_write = fopen(output_file_name, WRITE_BINARY);
		test_nullpointer_exception(file_write, output_file_name);

		/*---------------------------------------------------------------------------------*/
		/*-------------FILE POINTER in die PROPERTIES STRUCT übernehmen--------------------*/
		/*---------------------------------------------------------------------------------*/
		printf("FILE POINTER in die PROPERTIES STRUCT übernehmen !\n");
		p_properties->file_read = file_read;
		p_properties->file_write = file_write;
	}
	printf("END OF OPERATION!\n");
	return p_properties;
}

void delete_properties(PROPERTIES(*p_properties))
{
	free(p_properties);
	p_properties = NULL;
}

char* init_output_filename(char* input_file_name)
{
	int length = strlen(input_file_name);
	char* output_file_name = NULL;
	output_file_name = malloc(length);
	return output_file_name;
}

MODE properties_get_mode(PROPERTIES* p_properties)
{
	return p_properties->MODE;
}

FILE* properties_get_input_stream(PROPERTIES* p_properties)
{
	return p_properties->file_read;
}

FILE* properties_get_output_stream(PROPERTIES* p_properties)
{
	return p_properties->file_write;
}