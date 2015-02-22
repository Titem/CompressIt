/** 
 * @mainpage CompressIt - Huffmankomprimierung
 * 
 * <h2>Dieses Projekt realisiert das Komprimieren sowie das Dekomprimieren von 
 * einzelnen Dateien nach dem Huffman-Verfahren.</h2>
 * 
 * <br><br>
 * 
 * <h2>Das Projekt besteht aus folgenden Modulen:</h2>
 * 
 * <br>
 * 
 * <h2>main.c</h2>
 * verwendet: <br> 
 * parameterlist.h - parameterlist.c <br>
 * compressor.h - compressor.c <br>
 * debug_common.h - debug_common.c <br>
 * error_handler.h - error_handler.c <br>
 * messages_de.h
 *  
 * <br>
 * 
 * <h2>parameterlist.h - parameterlist.c</h2>
 * verwendet: <br>
 * error_handler.c - error_handler.h <br>
 * debug_common.c - debug_common.h
 * 
 * <br>
 * 
 * <h2>compressor.h - compressor.c</h2>
 * verwendet: <br>
 * freqtab.h - freqtab.c <br>
 * htree.h - htree.c <br>
 * codetab.h - codetab.c <br>
 * debug_common.h - debug_common.c
 * 
 * <br>
 * 
 * <h2>freqtab.h - freqtab.c</h2>
 * verwendet: <br>
 * freqtab_element.h - freqtab_element.c <br>
 * debug_common.h - debug_common.c <br>
 * error_handler.h - error_handler.c
 * 
 * <br>
 * 
 * <h2>freqtab_element.h - freqtab_element.c</h2>
 * verwendet: <br>
 * debug_common.h - debug_common.c <br>
 * error_handler.h - error_handler.c
 * 
 * <br>
 * 
 * <h2>htree.h - htree.c</h2>
 * verwendet: <br>
 * htree_element.h - htree_element.c <br>
 * htree_node.h - htree_node.c <br>
 * htree_leaf.h - htree_leaf.c <br>
 * pqueue.h - pqueue.c <br>
 * freqtab.h - freqtab.c <br>
 * freqtab_element.h - freqtab_element.c <br>
 * codetab.h - codetab.c <br>
 * codetab_element.h - codetab_element.c <br>
 * debug_common.h - debug_common.c <br>
 * error_handler.h - error_handler.c
 * 
 * <br>
 * 
 * <h2>htree_element.h - htree_element.c</h2>
 * verwendet: <br>
 * htree_node.h - htree_node.c <br>
 * htree_leaf.h - htree_leaf.c <br>
 * debug_common.h - debug_common.c <br>
 * error_handler.h - error_handler.c
 * 
 * <br>
 * 
 * <h2>htree_node.h - htree_node.c</h2>
 * verwendet: <br>
 * htree_element.h - htree_element.c <br>
 * debug_common.h - debug_common.c <br>
 * error_handler.h - error_handler.c
 * 
 * <br>
 * 
 * <h2>htree_leaf.h - htree_leaf.c</h2>
 * verwendet: <br>
 * debug_common.h - debug_common.c <br>
 * error_handler.h - error_handler.c
 * 
 * <br>
 * 
 * <h2>pqueue.h - pqueue.c</h2>
 * verwendet: <br>
 * pqueue_element.h - pqueue_element.c <br>
 * htree_element.h - htree_element.c <br>
 * debug_common.h - debug_common.c <br>
 * error_handler.h - error_handler.c
 * 
 * <br>
 * 
 * <h2>pqueue_element.h - pqueue_element.c</h2>
 * verwendet: <br>
 * htree_element.h - htree_element.c <br>
 * debug_common.h - debug_common.c <br>
 * error_handler.h - error_handler.c
 * 
 * <br>
 * 
 * <h2>codetab.h - codetab.c</h2>
 * verwendet: <br>
 * codetab_element.h - codetab_element.c <br>
 * htree.h - htree.c <br>
 * debug_common.h - debug_common.c <br>
 * error_handler.h - error_handler.c
 * 
 * <br>
 * 
 * <h2>codetab_element.h - codetab_element.c</h2>
 * verwendet: <br>
 * debug_common.h - debug_common.c <br>
 * error_handler.h - error_handler.c
 * 
 * <br>
 * 
 * <h2>content_coder.h - content_coder.c</h2>
 * verwendet: <br>
 * codetab.h - codetab.c <br>
 * debug_common.h - debug_common.c <br>
 * error_handler.h - error_handler.c
 * 
 * <br>
 * 
 * <h2>error_handler.h - error_handler.c</h2>
 * verwendet: <br>
 * parameterlist.h - parameterlist.c <br>
 * messages_de.h <br>
 * debug_common.h - debug_common.c 
 * 
 * <br>
 * 
 * <h2>debug_common.h - debug_common.c</h2>
 * verwendet: <br>
 * error_handler.h - error_handler.c
 * 
 * <br>
 * 
 * <h2>messages_de.h</h2>
 * 
 * <br>
 * 
 * <h2>project.h</h2>
 *
 * <br><br>
 * 
 * @author Tim Buschmann <br>
 *         Artur Leinweber <br>
 *         Alexander Schmitz
 */


