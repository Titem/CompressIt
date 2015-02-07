
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "freqtab.h"

#include <stdlib.h>

#include "error.h"




/* ======================================================================== *
 * Strukturdefinitionen                                                     *
 * ======================================================================== */

struct S_FREQTAB{

	FREQTAB_ELEMENT* freq_table[MAX_CHARACTERS];
	short working_index;

};




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */


/*---------------------------------------------------------------------------------*/
/*-----FÜGT EIN NEUES ELEMENT IN DIE FREQTAB HINZU---------------------------------*/
/*---------------------------------------------------------------------------------*/
static void freqtab_update(FREQTAB* freq_tab_p, unsigned char character);


/*---------------------------------------------------------------------------------*/
/*-----DEN FREQTAB MIT NULL INITIALISIERN------------------------------------------*/
/*---------------------------------------------------------------------------------*/
static void freqtab_init(FREQTAB* freq_tab_p);


/*---------------------------------------------------------------------------------*/
/*-----INITIALISIERT DEN WORKING INDEX DER FREQTAB---------------------------------*/
/*---------------------------------------------------------------------------------*/
static void freqtab_init_working_index(FREQTAB* freq_tab_p);




/* ======================================================================== *
 * Funktionsdefinitionen                                                    *
 * ======================================================================== */

extern FREQTAB* create_freqtab(FILE* input_stream)
{
	char character_from_file;
	FREQTAB* freq_tab_p;
	freq_tab_p = malloc(sizeof(FREQTAB));

	if (freq_tab_p != NULL)
	{

		freqtab_init(freq_tab_p);
		character_from_file = (char) fgetc(input_stream);
		while (character_from_file != EOF)
		{
			/*character_from_file = check_offset(character_from_file);*/
			freqtab_update(freq_tab_p,character_from_file);
			character_from_file = (char) fgetc(input_stream);
			
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




extern void delete_freqtab(FREQTAB* freq_tab_p)
{
	free(freq_tab_p);	
	freq_tab_p = NULL;
}




extern FREQTAB_ELEMENT* freqtab_get_element(FREQTAB* freq_tab_p)
{
	int i = 0;
	short tmp_working_index = freq_tab_p->working_index;
	FREQTAB_ELEMENT* tmp_p = freq_tab_p->freq_table[freq_tab_p->working_index];

	for (i = tmp_working_index; i < 256 && freq_tab_p->freq_table[i] == NULL; i++)
	{
		tmp_working_index++;
	}

	freq_tab_p->working_index = tmp_working_index;

	return tmp_p;
}




extern bool freqtab_is_emty(FREQTAB* freq_tab_p)
{

	return !(freq_tab_p->working_index < 256);
}




extern void freqtab_print(FREQTAB* freq_tab_p)
{
	long count_chars = 0;
	long count_element = 0;
	int i = 0;

	printf("Zeichen  ---> Haeufigkeit ---> NUMERIC\n");
	printf("--------------------------------------\n");

	for (i = 0; i < MAX_CHARACTERS; i++)
	{
		if (freq_tab_p->freq_table[i] != NULL)
		{
			count_element++;
			count_chars = count_chars + freqtab_element_get_frequency(freq_tab_p->freq_table[i]);
			printf("%c \t ---> %d \t  ---> %d \n", freqtab_elememt_get_char(freq_tab_p->freq_table[i]), freqtab_element_get_frequency(freq_tab_p->freq_table[i]), freqtab_elememt_get_char(freq_tab_p->freq_table[i]));
		}
	}
	printf("--------------------------------------\n");
	printf("Zeichen insgesamt    : %d \n", count_chars);
	printf("Zeichen verschieden  : %d \n", count_element);
}




static void freqtab_init_working_index(FREQTAB* freq_tab_p)
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




static void freqtab_init(FREQTAB* freq_tab_p)
{
	int i = 0;
	for (i = 0; i < MAX_CHARACTERS; i++)
	{
		freq_tab_p->freq_table[i] = NULL;
	}
}




static void freqtab_update(FREQTAB* freq_tab_p, unsigned char character)
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





