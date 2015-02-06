#include "frequency_table.h"
#include "error.h"


freq_table* create_frequency_table(FILE* input_stream)
{
	char character_from_file;
	freq_table* freq_tab_p;
	freq_tab_p = malloc(sizeof(freq_table));

	if (freq_tab_p != NULL)
	{

		init_freq_table(freq_tab_p);
		character_from_file = fgetc(input_stream);
		while (character_from_file != EOF)
		{
			/*character_from_file = check_offset(character_from_file);*/
			update_frequency_table(freq_tab_p,character_from_file);
			character_from_file = fgetc(input_stream);
			
		}
	}
	else
	{
		print_error(cant_malloc_memory);
		exit(EXIT_FAILURE);
	}

	freqtab_init_working_index(freq_tab_p);

	return freq_tab_p;
}

freqtab_init_working_index(freq_table* freq_tab_p)
{
	
	short tmp_working_index = 0;

	/*Was tun wenn datei leer ist, dies ist dann der Fall wenn der
	working index bei 256 ist, die schleife vorher abbrechen*/
	freq_tab_p->working_index = 256;

	while (tmp_working_index < 256 && freq_tab_p->freq_table[tmp_working_index] != NULL)
	{
		tmp_working_index++;
	}

	if (tmp_working_index < 256)
	{
		freq_tab_p->working_index = tmp_working_index;
	}




}

void init_freq_table(freq_table* freq_tab_p)
{
	int i = 0;
	for (i = 0; i < MAX_CHARACTERS; i++)
	{
		freq_tab_p->freq_table[i] = NULL;
	}
}

void update_frequency_table(freq_table* freq_tab_p, unsigned char character)
{
	if(freq_tab_p->freq_table[character] == NULL)
	{
		freq_tab_p->freq_table[character] = create_freqtab_element(character);
	}
	else
	{
		/*freq_tab_p->freq_table[character]->frequency = (freq_tab_p->freq_table[character]->frequency + INKREMENT_CHARCTER);*/
		/*freq_tab_p->freq_table[character]->frequency++;*/
		freqtab_element_inc_frequency(freq_tab_p->freq_table[character]);

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
	int i = 0;
	int tmp_working_index = freq_tab_p->working_index;
	freqtab_element* tmp_p = freq_tab_p->freq_table[freq_tab_p->working_index];

	for (i = tmp_working_index; i < 256 && freq_tab_p->freq_table[i] == NULL; i++)
	{
		tmp_working_index++;
	}

	freq_tab_p->working_index = tmp_working_index;

	return tmp_p;
}


bool frequency_table_is_emty(freq_table* freq_tab_p)
{

	return !(freq_tab_p->working_index < 256);
}


void print_frequency_table(freq_table* freq_tab_p) 
{
	long count_chars = 0;
	int i = 0;
	printf("Zeichen ---> Haeufigkeit ---> NUMERIC\n");
	printf("------------------------\n");
	for (i = 0; i < MAX_CHARACTERS; i++)
	{
		if (freq_tab_p->freq_table[i] != NULL)
		{
			count_chars = count_chars + freq_tab_p->freq_table[i]->frequency;
			printf("%c ---> %d ---> %d \n", freq_tab_p->freq_table[i]->character, freq_tab_p->freq_table[i]->frequency, freq_tab_p->freq_table[i]->character);
		}
	}
	printf("Zeichen insgesamt : %d \n", count_chars);
}