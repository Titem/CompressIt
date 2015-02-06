#include "compressor.h"
#include "freqtab.h"

extern void compress(FILE* input_stream, FILE* output_stream)
{
	/*H�ufigkeitstabelle erstellen.*/
	FREQTAB* frequency_table = NULL;
	frequency_table = create_frequency_table(input_stream);

	/*H�ufigkeitstabelle auf dem Bildschirm ausgeben.*/
	print_frequency_table(frequency_table);

	/*Kompriemierungsvorgang einleiten.*/


}

extern void decompress(FILE* input_stream, FILE* output_stream);
