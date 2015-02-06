#include "compressor.h"
#include "freqtab.h"

extern void compress(FILE* input_stream, FILE* output_stream)
{
	/*Häufigkeitstabelle erstellen.*/
	FREQTAB* frequency_table = NULL;
	frequency_table = create_freqtab(input_stream);

	/*Häufigkeitstabelle auf dem Bildschirm ausgeben.*/
	freqtab_print(frequency_table);

	/*Kompriemierungsvorgang einleiten.*/


}

extern void decompress(FILE* input_stream, FILE* output_stream);
