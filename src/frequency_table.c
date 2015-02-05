#include "frequency_table.h"

typedef struct{

	freqtab_element* freq_table[MAX_CHARACTERS];
	int working_index;

}freq_table;


freq_table* create_frequency_table(FILE* input_stream)
{
	char character_from_file;
	freq_table* freq_tab_p;
	freq_tab_p = malloc(sizeof(freq_tab_p));

	if (freq_tab_p != NULL)
	{
		character_from_file = fgetc(input_stream);
		while (character_from_file != EOF)
		{
			update_frequency_table(freq_tab_p,character_from_file);
			character_from_file = fgetc(input_stream);
		}
	}
	else
	{
		print_error(cant_malloc_memory);
		exit(EXIT_FAILURE);
	}
	return freq_tab_p;
}


void update_frequency_table(freq_table* freq_tab_p, char character)
{
	if(freq_tab_p->freq_table[character] == NULL)
	{
		freq_tab_p->freq_table[character] = create_freqtab_element(INKREMENT_CHARCTER, character);
	}
	else
	{
		freq_tab_p->freq_table[character]->frequency = (freq_tab_p->freq_table[character]->frequency + INKREMENT_CHARCTER);
	}
}


void delete_frequency_table(freq_table* freq_tab_p)
{
	free(freq_tab_p);	
	freq_tab_p = NULL;
}


/*????????????????????WELCHES ELEMENT AN WELCHEM INDEX ODER WIE ? UND WOFÜR IST WORKING INDEX?????????????????????*/
freqtab_element*  frequency_table_get_element(freq_table* freq_tab_p)
{
	return freq_tab_p->freq_table[freq_tab_p->working_index];
}


bool frequency_table_is_emty(freq_table* freq_tab_p)
{
	bool found_frequency = false;
	int i = 0;

	for (i = 0; i < MAX_CHARACTERS && !found_frequency; i++)
	{
		/*found_frequency = ((freq_tab_p->freq_table[i])->frequency) > 1;*/
		found_frequency = ((freq_tab_p->freq_table[i]) != NULL);
	}
	return !found_frequency;
}


void print_frequency_table(freq_table* freq_tab_p) 
{
	int i = 0;
	printf("Zeichen ---> Haeufigkeit\n");
	printf("------------------------\n");
	for (i = 0; i < MAX_CHARACTERS; i++)
	{
		if (freq_tab_p->freq_table[i] != NULL)
		{
			printf("%c ---> %d \n", freq_tab_p->freq_table[i]->character,freq_tab_p->freq_table[i]->frequency);
		}
	}
}