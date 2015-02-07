
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

    /*Häufigkeitstabelle auf Bildschirm ausgeben*/
    freqtab_print(frequency_table);
    
    return;

    /*Huffmanbaum erstellen*/
    huffman_tree = create_htree(frequency_table);
        
    /*Huffmanbaum auf Bildschirm ausgeben*/
    htree_print(huffman_tree);
        
    /*Codebuch erstellen*/
    code_table = create_codetab(huffman_tree);
        
    /*Codebuch auf Bildschirm ausgeben*/
    codetab_print(code_table);
        
    /*Codebuch an den Anfang der Datei schreiben*/
    wirte_codetab(output_stream, code_table);
        
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
