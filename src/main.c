#include "properties.h"
#include "freqtab.h"
#include <time.h>
#include "compressor.h"
#include "error.h"
/* #define VisualStudio */
#define DEBUG

/*Jede C-Anwendung muss genau eine Main-Methode enthalten, in der angegeben ist, wo die Programmausführung beginnen soll.*/
int main(int argc, char** argv);


int main(int argc, char *argv[])
{

	/*Für die Zeit zuständig.*/
	clock_t begin;
	clock_t end;

	/*Timer starten*/
	begin = clock();

/*-----------------------------CODE--------------------------------*/

	PROPERTIES* properties = create_properties(argv, argc);
	MODE modus = properties_get_mode(properties);

	switch (modus)
	{
	case COMPRESS:
		compress(properties_get_input_stream(properties), properties_get_output_stream(properties));
	case DECOMPRESS:
		decompress(properties_get_input_stream(properties), properties_get_output_stream(properties));
	case MANPAGE:
		print_error(help);
		/*Hilfestellung*/
	}


	
/*-----------------------------CODE--------------------------------*/
	/*Timer beenden*/
	end = clock();

	printf("\nBenoetigte Zeit: %i ms", end - begin);

#ifdef VisualStudio
	getch();
#endif

	return 0;
}

