
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "compressor.h"

#include "freqtab.h"
#include "htree.h"
#include "codetab.h"
#include "content_coder.h"




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
#endif

    return;

    /*Huffmanbaum erstellen*/
    huffman_tree = create_htree(frequency_table);

#ifdef DEBUG_HUFFMAN      
    /*Huffmanbaum auf Bildschirm ausgeben*/
    htree_print(huffman_tree);
#endif

    /*Codebuch erstellen*/
    code_table = create_codetab(huffman_tree, 
                                freqtab_get_content_length(frequency_table));
        
#ifdef DEBUG_HUFFMAN
    /*Codebuch auf Bildschirm ausgeben*/
    codetab_print(code_table);
#endif

    /*Codebuch an den Anfang der Datei schreiben*/
    write_codetab(output_stream, code_table);
        
    /*Inhalt komprimieren*/
    encode_content(input_stream, output_stream, code_table);

}



extern void decompress(FILE* input_stream, FILE* output_stream)
{
    CODETAB* code_table;
    
    /*Codebook aus der komprimierten Datei lesen*/
    code_table = read_codetab(input_stream);
    
    /*Codebuch auf Bildschirm ausgeben*/
    codetab_print(code_table);
    
    /*Inhalt dekomprimieren*/
    decode_content(input_stream, output_stream, code_table);
    
}
