
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "compressor.h"

#include "freqtab.h"
#include "htree.h"
#include "codetab.h"
#include "content_coder.h"

#define DEBUG_HUFFMAN


/* ======================================================================== *
 * Funktionsdefinitionen                                                    *
 * ======================================================================== */

extern void compress(FILE* input_stream, FILE* output_stream)
{
    FREQTAB* frequency_table;
    HTREE* huffman_tree;
    CODETAB* code_table;
        
    /*Häufigkeitstabelle erstellen*/
    frequency_table = create_freqtab(input_stream);

#ifdef DEBUG_HUFFMAN
    /*Häufigkeitstabelle auf Bildschirm ausgeben*/
    freqtab_print(frequency_table);
    fflush(stdout);
#endif

	/*Inputstream zurücksetzen*/
	rewind(input_stream);

    /*Huffmanbaum erstellen*/
    huffman_tree = create_htree_from_freqtab(frequency_table);

#ifdef DEBUG_HUFFMAN      
    /*Huffmanbaum auf Bildschirm ausgeben*/
    htree_print(huffman_tree);
    fflush(stdout);
#endif

    
    /*Codebuch erstellen*/
    code_table = create_codetab(huffman_tree);

#ifdef DEBUG_HUFFMAN
    /*Codebuch auf Bildschirm ausgeben*/
    codetab_print(code_table);
    fflush(stdout);
#endif
      
    /*Codebuch an den Anfang der Datei schreiben*/
    write_codetab(output_stream, code_table);
	
    /*Inhalt komprimieren*/
    encode_content(input_stream, output_stream, code_table, 
                   freqtab_get_content_length(frequency_table));

	return;

}



extern void decompress(FILE* input_stream, FILE* output_stream)
{
    CODETAB* code_table;
    HTREE* huffman_tree;
    
    /*Codebook aus der komprimierten Datei lesen*/
    code_table = read_codetab(input_stream);
    
#ifdef DEBUG_HUFFMAN
    /*Codebuch auf Bildschirm ausgeben*/
    codetab_print(code_table);
#endif
    
    /*Huffmanbaum erstellen*/
    huffman_tree = create_htree_from_codetab(code_table);
    
#ifdef DEBUG_HUFFMAN      
    /*Huffmanbaum auf Bildschirm ausgeben*/
    htree_print(huffman_tree);
#endif
    
    /*Inhalt dekomprimieren*/
    decode_content(input_stream, output_stream, huffman_tree);
    
}
