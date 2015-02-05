#include <stdio.h>
/*---------------------------------------------------------------------------------*/
/*---------------DEKLERATION EINER PORPERTIES STRUCT-------------------------------*/
/*---------------------------------------------------------------------------------*/
typedef struct
{
	enum
	{
		COMPRESS,
		DECOMPRESS,
	}MODE;

	FILE *file_read;
	FILE *file_write;

}properties;

/*---------------------------------------------------------------------------------*/
/*-----ERSTELLT EINE NEUE STRUCT UND LIEFERT EINEN PROPERTIES POINTER ZUR�CK-------*/
/*---------------------------------------------------------------------------------*/
properties* create_properties(char** argv, int argc);


/*---------------------------------------------------------------------------------*/
/*------GIBT DEN SPEICHER WIEDER FREI BZW. L�SCHT EINEN PROPERTIES POINTER---------*/
/*---------------------------------------------------------------------------------*/
void delete_properties(properties(*p_properties));



