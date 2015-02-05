#include "frequency_table_element.h"

#define MAX_CHARACTERS 256
#define INKREMENT_CHARCTER 1

typedef struct{

	freqtab_element* freq_table[MAX_CHARACTERS];
	int working_index;

}freq_table;

void update_frequency_table(freq_table* freq_tab_p, char character);
void init_freq_table(freq_table* freq_tab_p);
