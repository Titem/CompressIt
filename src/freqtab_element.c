#include "freqtab_element.h"

struct S_FREQTAB_ELEMENT{

	long frequency;
	char character;

};

FREQTAB_ELEMENT* create_freqtab_element(char character)
{
	FREQTAB_ELEMENT* freq;
	freq = malloc(sizeof(FREQTAB_ELEMENT));

	if (freq != NULL)
	{
		freq->character = character;
		freq->frequency = ININIT_CHARCTER;
	}
	return freq;
}

void delete_freqtab_element(FREQTAB_ELEMENT* freq)
{
	free(freq);
}


unsigned char freqtab_elememt_get_char(FREQTAB_ELEMENT* freq)
{
	return freq->character;
}


long freqtab_element_get_frequency(FREQTAB_ELEMENT* freq)
{
	return freq->frequency;
}

extern void freqtab_element_inc_frequency(FREQTAB_ELEMENT* freq)
{
	freq->frequency++;
}