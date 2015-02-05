#include "main.h"
#define VisualStudio
#define DEBUG
int main(int argc, char** argv)
{

	/*Für die Zeit zuständig.*/
	clock_t begin;
	clock_t end;

	/*Timer starten*/
	begin = clock();

/*-----------------------------CODE--------------------------------*/
	properties* properties;
	properties = malloc(sizeof(properties));

	freq_table* frequency_table;
	frequency_table = malloc(sizeof(freq_table));
	
	if (properties != NULL && frequency_table != NULL)
	{
		properties = create_properties(argv, argc);
		frequency_table = create_frequency_table(properties->file_read);
#ifdef DEBUG
		print_frequency_table(frequency_table);
#endif 

	}








/*-----------------------------CODE--------------------------------*/
	/*Timer beenden*/
	end = clock();

	printf("\n Benoetigte Zeit: %i ms", end - begin);

#ifdef VisualStudio
	getch();
#endif

	return 0;
}

