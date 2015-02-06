#include "freqtab_element.h"

#define MAX_CHARACTERS 256


typedef struct{

	freqtab_element* freq_table[MAX_CHARACTERS];
	short working_index;

}freq_table;
/*---------------------------------------------------------------------------------*/
/*-----FÜGT EIN NEUES ELEMENT IN DIE FREQTAB HINZU---------------------------------*/
/*---------------------------------------------------------------------------------*/
void update_frequency_table(freq_table* freq_tab_p, unsigned char character);


/*---------------------------------------------------------------------------------*/
/*-----DEN FREQTAB MIT NULL INITIALISIERN------------------------------------------*/
/*---------------------------------------------------------------------------------*/
void init_freq_table(freq_table* freq_tab_p);

/*---------------------------------------------------------------------------------*/
/*-----INITIALISIERT DEN WORKING INDEX DER FREQTAB---------------------------------*/
/*---------------------------------------------------------------------------------*/
freqtab_init_working_index(freq_table* freq_tab_p);
