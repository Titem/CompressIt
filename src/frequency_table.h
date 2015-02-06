#include "frequency_table_element.h"

#define MAX_CHARACTERS 256


typedef struct{

	freqtab_element* freq_table[MAX_CHARACTERS];
	int working_index;

}freq_table;
/*---------------------------------------------------------------------------------*/
/*-----FÜGT EIN NEUES ELEMENT IN DIE FREQTAB HINZU---------------------------------*/
/*---------------------------------------------------------------------------------*/
void update_frequency_table(freq_table* freq_tab_p, char character);


/*---------------------------------------------------------------------------------*/
/*-----DEN FREQTAB MIT NULL INITIALISIERN------------------------------------------*/
/*---------------------------------------------------------------------------------*/
void init_freq_table(freq_table* freq_tab_p);


/*---------------------------------------------------------------------------------*/
/*-----PRÜFT DIE CHARACTER UND FPÜGT EINEN OFFSET HINZU----------------------------*/
/*---------------------------------------------------------------------------------*/
//char check_offset(char character_from_file);
