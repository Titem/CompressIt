
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "htree.h"

#include <stdlib.h>
#include <string.h>

#include "freqtab.h"
#include "freqtab_element.h"
#include "codetab.h"
#include "codetab_element.h"
#include "htree_element.h"
#include "htree_leaf.h"
#include "htree_node.h"
#include "pqueue.h"
#include "debug_common.h"
#include "error_handler.h"




/* ======================================================================== *
 * Strukturdefinitionen                                                     *
 * ======================================================================== */

/** 
 * Diese Struktur beschreibt den Aufbau eines Huffman-Baumes.
 */
struct S_HTREE
{
    /**
     * Diese Variable speichert den Zeiger auf das f�r die n�chste R�ckgabe 
     * vorbereitete Code-Tabellen-Element.
     */
    CODETAB_ELEMENT* prep_codetab_element;
    
    /**
     * Diese Variable speichert den Zeiger auf das Huffman-baum-Element,
     * welches, bei der n�chsten R�ckgabe des vorbereiteten 
     * Code-Tabellen-Elementes, gel�scht wird.
     */
    HTREE_ELEMENT* dead_htree_element;
    
    /**
     * Diese Variable speichert den Zeiger auf das aktuelle 
     * Huffman-Baum-Element bei der Schriftzeichen-Suche mit htree_search_char.
     */
    HTREE_ELEMENT* search_pointer;
    
    /**
     * Diese Variable speichert den Zeiger auf das Huffman-Baum-Element,
     * welches den Wurzelknoten des gesamten Huffman-Baumes dastellt. 
     */
    HTREE_ELEMENT* root_node;
};




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

/**
 * Diese Funktion bereitet ein Code-Tabellen-Element f�r die R�ckgabe durch die
 * Funktion htree_get_codetab_element vor auf Basis eines Blattes des
 * �bergebenen Huffman-Baumes.
 *  
 * @param htree Zeiger auf den Huffman-Baum, dessen Blatt vorlage f�r das
 *              vorzubereitende Code-tabellen_element ist.
 */
static void htree_prep_codetab_element(HTREE* htree);




/* ======================================================================== *
 * Funktionsdefinitionen                                                    *
 * ======================================================================== */

extern HTREE* create_htree_from_freqtab(FREQTAB* freqtab)
{
    HTREE* new_htree = malloc(sizeof(HTREE));

    PQUEUE* pqueue = create_pqueue();
    FREQTAB_ELEMENT* freqtab_element;
    HTREE_ELEMENT* new_htree_element;
    PQUEUE_ELEMENT* left_pqueue_element;
    PQUEUE_ELEMENT* right_pqueue_element;
    PQUEUE_ELEMENT* last_pqueue_element;
    
    if (new_htree == NULL)
    {
        error_handler_handle_error(CANT_ALLOCATE_MEMORY, __FILE__, __LINE__);
    }
    
    #ifdef DEBUG_HUFFMAN
    printf("PQUEUE Number of Elements vor insert: %i\n\n", 
           (int)pqueue_get_number_of_entries(pqueue));
    #endif
    
    /* Wenn eine leere Datei komprimiert wird, ist die 
     * freqtab von Beginn an leer */
    if (freqtab_is_empty(freqtab))
    {
        new_htree->dead_htree_element = NULL;
        new_htree->prep_codetab_element = NULL;
        new_htree->root_node = NULL;
        new_htree->search_pointer = NULL;
        
        return new_htree;
    }
    
    while (!freqtab_is_empty(freqtab))
    {
        /* freqtab_element aus freqtab entnehmen */
        freqtab_element = freqtab_get_element(freqtab);

        /* htree_leaf erstellen mit character und frequency des entnommenen
         * freqtab_element */
        new_htree_element 
            = create_htree_element(LEAF, 
              (void*) create_htree_leaf(
              freqtab_elememt_get_char(freqtab_element)));

        /* neuen htree_leaf der pqueue hinzuf�gen */
        pqueue_insert_htree_element(
                pqueue, new_htree_element, 
                freqtab_element_get_frequency(freqtab_element));

    }
    
    #ifdef DEBUG_HUFFMAN
    printf("\nPQUEUE Number of Elements nach insert: %i \n\n", 
           (int)pqueue_get_number_of_entries(pqueue));
    pqueue_print(pqueue);
    #endif

    while (pqueue_get_number_of_entries(pqueue) >= 2)
    {
        /* 2 htree_elemente mit minimalem Gewicht aus der pqueue entnehmen */
        left_pqueue_element = pqueue_get_min_entry(pqueue);
        right_pqueue_element = pqueue_get_min_entry(pqueue);

        /* die zwei entnommenen htree_elemente zusammenf�hren */
        new_htree_element = merge_htree_elements(
                pqueue_element_get_htree_element(left_pqueue_element),
                pqueue_element_get_htree_element(right_pqueue_element));
        
        /* zusammengef�hrtes htree_element der pqueue hinzuf�gen */
        pqueue_insert_htree_element(pqueue, new_htree_element, 
                pqueue_element_get_weight(left_pqueue_element) + 
                pqueue_element_get_weight(right_pqueue_element));
        
        /* Resourcen wieder freigeben */
        delete_pqueue_element(&left_pqueue_element);
        delete_pqueue_element(&right_pqueue_element);
    }
    
    #ifdef DEBUG_HUFFMAN
    printf("\n\nPQUEUE Number of Elements: %i\n\n", 
           (int) pqueue_get_number_of_entries(pqueue));
    #endif

    /* letztes htree_element aus pqueue entnehmen */
    last_pqueue_element = pqueue_get_min_entry(pqueue);
    new_htree_element = pqueue_element_get_htree_element(last_pqueue_element);
    
    /* Resourcen wieder freigeben */
    delete_pqueue_element(&last_pqueue_element);

    /* htree erzeugen mit dem letzten htree_element als root */
    new_htree->root_node = new_htree_element;
    new_htree->search_pointer = new_htree_element;
    /* Initialisierung htree_get_codetab_element */
    htree_prep_codetab_element(new_htree);
    
    /* Resourcen wieder freigeben */
    delete_pqueue(&pqueue);

    return new_htree;
}


extern HTREE* create_htree_from_codetab(CODETAB* codetab)
{
    HTREE* new_htree = malloc(sizeof(HTREE));
    HTREE_ELEMENT* root_node;
    HTREE_ELEMENT* htree_element;
    CODETAB_ELEMENT* codetab_element;

    unsigned char index;
    unsigned char length;
    bool bit;

    if (new_htree == NULL)
    {
        error_handler_handle_error(CANT_ALLOCATE_MEMORY, __FILE__, __LINE__);
    }
    
    /* Wurzel erstellen */
    root_node = create_htree_element(NODE, create_htree_node(NULL, NULL));

    while (!codetab_is_empty(codetab))
    {
        htree_element = root_node;

        /*codetab_element aus codetab entnehmen */
        codetab_element = codetab_get_element(codetab);

        /* Index mit 0 initialisieren */
        index = 0;

        length = codetab_element_get_code_length(codetab_element);

        while (index < length - 1)
        {
            if (htree_element_is_leaf(htree_element))
            {
                error_handler_handle_error(INVALID_FILE_CODETAB_INVALID,
                                           __FILE__, __LINE__);
            }

            /* Bit mit Index holen */
            bit = codetab_element_is_bit_set(codetab_element, index);

            if (bit)
            {
                if (!htree_node_has_right(
                    ((HTREE_NODE*)htree_element_get_element(htree_element))))
                {
                    /* rechtes Kind erzeugen und anh�ngen */
                    htree_node_set_right(
                        (HTREE_NODE*)htree_element_get_element(htree_element), 
                        create_htree_element(NODE, 
                            create_htree_node(NULL, NULL)));
                }

                /* rechtes Kind ausw�hlen */
                htree_element = htree_node_get_right(
                    ((HTREE_NODE*)htree_element_get_element(htree_element)));
            }
            else
            {
                if (!htree_node_has_left(
                    ((HTREE_NODE*)htree_element_get_element(htree_element))))
                {
                    /* linkes Kind erzeugen und anh�ngen */
                    htree_node_set_left(
                        (HTREE_NODE*)htree_element_get_element(htree_element), 
                        create_htree_element(NODE, 
                            create_htree_node(NULL, NULL)));
                }

                /* linkes Kind ausw�hlen */
                htree_element = htree_node_get_left(
                    ((HTREE_NODE*)htree_element_get_element(htree_element)));
            }

            index++;
        }

        /* Bit mit Index holen */
        bit = codetab_element_is_bit_set(codetab_element, index);

        if (bit)
        {
            /* rechtes Kind erzeugen und anh�ngen */
            htree_node_set_right(
                (HTREE_NODE*)htree_element_get_element(htree_element), 
                create_htree_element(LEAF, 
                    create_htree_leaf(
                        codetab_element_get_char(codetab_element))));
        }
        else
        {
            /* linkes Kind erzeugen und anh�ngen */
            htree_node_set_left(
                (HTREE_NODE*)htree_element_get_element(htree_element), 
                create_htree_element(LEAF, 
                    create_htree_leaf(
                        codetab_element_get_char(codetab_element))));
        }

    }

    new_htree->root_node = root_node;
    new_htree->search_pointer = root_node;
    htree_prep_codetab_element(new_htree);

    return new_htree;
}


extern void delete_htree(HTREE** htree)
{
    free(*htree);
    *htree = NULL;
}


extern CODETAB_ELEMENT* htree_get_codetab_element(HTREE* htree)
{
    /* vorbereitetes codetab_element dem htree entnehmen und in
     * lokaler Variable zwischenspeichern */
    CODETAB_ELEMENT* prep_codetab_element = htree->prep_codetab_element;

	htree_element_remove(htree->dead_htree_element);

    if (!htree_is_empty(htree))
    {
        /* n�chsten codetab_element vorbereiten */
        htree_prep_codetab_element(htree);
    }

    return prep_codetab_element;
}


extern bool htree_is_empty(HTREE* htree)
{
    return htree->root_node == NULL
           || htree_element_is_removed(htree->root_node);
}


extern bool htree_search_char(HTREE* htree, bool bit)
{
    if (htree_element_is_leaf(htree->search_pointer))
    {
        error_handler_handle_error(INVALID_FILE_CONTENT_INVALID,
                                   __FILE__, __LINE__);
    }

    if (bit)
    {
        if (!htree_node_has_right((HTREE_NODE*)htree_element_get_element
            (htree->search_pointer)))
        {
            error_handler_handle_error(INVALID_FILE_CONTENT_INVALID,
                                       __FILE__, __LINE__);
        }

        /* rechtes Kind ausw�hlen */
        htree->search_pointer = htree_node_get_right(
            (HTREE_NODE*)htree_element_get_element((htree->search_pointer)));
    }
    else
    {
        if (!htree_node_has_left((HTREE_NODE*)htree_element_get_element
            (htree->search_pointer)))
        {
            error_handler_handle_error(INVALID_FILE_CONTENT_INVALID,
                                       __FILE__, __LINE__);
        }

        /* linkes Kind ausw�hlen */
        htree->search_pointer = htree_node_get_left(
            (HTREE_NODE*)htree_element_get_element((htree->search_pointer)));
    }

    return htree_element_is_leaf(htree->search_pointer);
}


extern unsigned char htree_get_char(HTREE* htree)
{
    /* char aus dem Element lesen auf den der tree_pointer zeigt */
    unsigned char character = htree_leaf_get_char(
        ((HTREE_LEAF*)htree_element_get_element(htree->search_pointer)));

    /* tree_pointer auf Wutzelknoten zur�cksetzen */
    htree->search_pointer = htree->root_node;

    return character;
}


extern void htree_print(HTREE* htree)
{
    printf("\nBin�r Baum:\n");
    htree_element_print(htree->root_node);
}


static void htree_prep_codetab_element(HTREE* htree)
{
    CODETAB_ELEMENT* codetab_element;
    bool code[256];
    bool* new_code;
    unsigned char index = 0;

    /* Wurzelknoten ausw�hlen */
    HTREE_ELEMENT* htree_element = htree->root_node;

    if (htree_element_is_leaf(htree_element))
    {
        index++;
    }

    while (!htree_element_is_removed(htree_element) 
           && !htree_element_is_leaf(htree_element))
    {
        if (htree_node_has_left(
            (HTREE_NODE*)htree_element_get_element(htree_element)))
        {
            htree_element = htree_node_get_left(
                (HTREE_NODE*)htree_element_get_element(htree_element));
            code[index] = false;
            index++;
        }
        else if(htree_node_has_right(
                (HTREE_NODE*)htree_element_get_element(htree_element)))
        {
            htree_element = htree_node_get_right(
                (HTREE_NODE*)htree_element_get_element(htree_element));
            code[index] = true;
            index++;
        }
        else
        {
            htree_element_remove(htree_element);
            htree_element = htree->root_node;
            index = 0;
        }
    }

    new_code = malloc(sizeof(bool) * index);
    
    if (new_code == NULL)
    {
        error_handler_handle_error(CANT_ALLOCATE_MEMORY, __FILE__, __LINE__);
    }

    memcpy(new_code, code, sizeof(bool) * index);

    codetab_element = create_codetab_element(htree_leaf_get_char(
        (HTREE_LEAF*)htree_element_get_element(htree_element)), 
        new_code, index);

    htree->prep_codetab_element = codetab_element;

    htree->dead_htree_element = htree_element;
}
