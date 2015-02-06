#include "frequency_table_element.h"

freqtab_element* create_freqtab_element(char character)
{
	freqtab_element* freq;
	freq = malloc(sizeof(freqtab_element));

	if (freq != NULL)
	{
		freq->character = character;
		freq->frequency = ININIT_CHARCTER;
	}
	return freq;
}

void delete_freqtab_element(freqtab_element* freq)
{
	free(freq);
}


char freqtab_elememt_get_char(freqtab_element* freq)
{
	return freq->character;
}


long freqtab_element_get_frequency(freqtab_element* freq)
{
	return freq->frequency;
}

extern void freqtab_element_inc_frequency(freqtab_element* freq)
{
	freq->frequency++;
}