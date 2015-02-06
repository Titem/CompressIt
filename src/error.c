#include "error.h"


extern void print_error(int message)
{

	switch (message)
	{
	case dont_found_input_document:
		printf("Es wurde keine Eingabe Datei angegeben !\n");
		break;
	case dont_found_compress_mode:
		printf("Es wurde keine Angabe über die Instruktion gemacht !\n");
		break;
	case too_many_arguments:
		printf("Es wurden ungueltige Argumente  bzw. zu viele oder zu wenig Arguemnte angegeben !\n");
		break;
	case cant_malloc_memory:
		printf("Ein unbekannter Fehler ist aufgetreten!\n Fehler 0x80071a91\n");
		break;
	case in_and_output_document_are_the_same:
		printf("Ein- und Ausgabedatei sind identisch !\n");
		break;
	case AND:
		printf("Und ");
		break;
	}
	printf("Hilfe ist unterwegs ! Sollte Ihr Personal Computer brennen drücken sie umgehend die LÖSCH Taste!\n");
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
			fprintf(stderr, "%d: Zu viele Dateien wurden geöffnet.\n", errno);
			break;
		default:
			fprintf(stderr, "%d: Ein unbekannter Fehler ist aufgetreten.\n", errno);
			break;
		}
		exit(EXIT_FAILURE);
	}
}