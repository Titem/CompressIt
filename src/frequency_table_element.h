#include <stdlib.h>

/*---------------------------------------------------------------------------------*/
/*-----STRUCT DEFINITION FÜR FREQUENCY TABLE ELEMENT-------------------------------*/
/*---------------------------------------------------------------------------------*/
typedef struct{

	long frequency;
	char character;

}freqtab_element;


/*---------------------------------------------------------------------------------*/
/*-----ERSTELLT EINE NEUES FREQUENCY TABLE ELEMENT---------------------------------*/
/*---------------------------------------------------------------------------------*/
freqtab_element* create_freqtab_element(long frequency, char character);


/*---------------------------------------------------------------------------------*/
/*-----LÖSCHT EIN FREQUENCY TABLE ELEMENT BZW GIBT DEN SPEICHER WIEDER FREI--------*/
/*---------------------------------------------------------------------------------*/
void delete_freqtab_element(freqtab_element* freq);


/*---------------------------------------------------------------------------------*/
/*-----LIEFERT DAS ZEICHEN EINER FREQUENCY TABLE ELEMENT---------------------------*/
/*---------------------------------------------------------------------------------*/
char freqtab_elememt_get_char(freqtab_element* freq);


/*---------------------------------------------------------------------------------*/
/*-----LIEFERT DIE HÄUFIGKEIT EINER FREQUENCY TABLE ELEMENT------------------------*/
/*---------------------------------------------------------------------------------*/
long freqtab_element_get_frequency(freqtab_element* freq);