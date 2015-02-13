
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




/* ======================================================================== *
 * Strukturdefinitionen                                                     *
 * ======================================================================== */

struct S_HTREE
{
    CODETAB_ELEMENT* prep_codetab_element;
    HTREE_ELEMENT* prep_htree_element;
    HTREE_ELEMENT* tree_pointer;
    HTREE_ELEMENT* root_node;
};




/* ======================================================================== *
 * Funktionsprototypen                                                      *
 * ======================================================================== */

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
    PQUEUE_ELEMENT* pqueue_element_left;
    PQUEUE_ELEMENT* pqueue_element_right;
    printf("PQUEUE Number of Elements vor insert: %i\n\n", (int)pqueue_get_number_of_entries(pqueue));
    while (!freqtab_is_emty(freqtab))
    {
        /* freqtab_element aus freqtab entnehmen */
        /*HIER IST DER FEHLER freqtab_element is NULL.*/
        freqtab_element = freqtab_get_element(freqtab);
    
        /* htree_leaf erstellen mit character und frequency des entnommenen 
         * freqtab_element */
        new_htree_element = create_htree_element(LEAF, (void*) create_htree_leaf
                (freqtab_elememt_get_char(freqtab_element)));
    
        /* neuen htree_leaf der pqueue hinzufügen */
        pqueue_insert_htree_element(pqueue, new_htree_element, freqtab_element_get_frequency(freqtab_element));
    
    }
    printf("\nPQUEUE Number of Elements nach insert: %i \n\n", (int)pqueue_get_number_of_entries(pqueue));
    
    pqueue_print(pqueue);
    
    while (pqueue_get_number_of_entries(pqueue) >= 2)
    {
        /* 2 htree_elemente mit minimalem Gewicht aus der pqueue entnehmen */
        pqueue_element_left = pqueue_get_min_entry(pqueue);
        pqueue_element_right = pqueue_get_min_entry(pqueue);
    
        /* die zwei entnommenen htree_elemente zusammenführen */
        new_htree_element = merge_htree_elements(pqueue_element_get_htree_element(pqueue_element_left),
                                                 pqueue_element_get_htree_element(pqueue_element_right));
    
        /* zusammengeführtes htree_element der pqueue hinzufügen */
        pqueue_insert_htree_element(pqueue, new_htree_element, pqueue_element_get_weight(pqueue_element_left) + pqueue_element_get_weight(pqueue_element_right));
        
    }
    
    printf("\n\nPQUEUE Number of Elements: %i\n\n", (int) pqueue_get_number_of_entries(pqueue));
    /* letztes htree_element aus pqueue entnehmen */
    new_htree_element = pqueue_element_get_htree_element(pqueue_get_min_entry(pqueue));
    
    /* htree erzeugen mit dem letzten htree_element als root */
    new_htree->root_node = new_htree_element;
    new_htree->tree_pointer = new_htree_element;
    /* Initialisierung htree_get_codetab_element */
    htree_prep_codetab_element(new_htree); 
    
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
    
    /* Wurzel erstellen */
    root_node = create_htree_element(NODE, create_htree_node(NULL, NULL));
    htree_element = root_node;
    
    while (!codetab_is_empty(codetab))
    {
        /*codetab_element aus codetab entnehmen */
        codetab_element = codetab_get_element(codetab);
        
        /* Index mit 0 initialisieren */
        index = 0;
                
        length = codetab_element_get_code_length(codetab_element);
        
        while (index >= length - 2)
        {
            if (htree_element_is_leaf(htree_element))
            {
                printf("HTREE.c hier stimmt was nicht!");
                exit(EXIT_FAILURE);
            }
            
            /* Bit mit Index holen */
            bit = codetab_element_is_bit_set(codetab_element, index);
            
            if (bit)
            {
                if (htree_node_has_right(((HTREE_NODE*)htree_element_get_element(htree_element))))
                {
                    /* rechtes Kind erzeugen und anhängen */
                    htree_node_set_right((HTREE_NODE*)htree_element_get_element(htree_element), create_htree_element(NODE, create_htree_node(NULL, NULL)));
                }
                
                /* rechtes Kind auswählen */
                htree_element = htree_node_get_right(((HTREE_NODE*)htree_element_get_element(htree_element)));
            }
            else
            {
                if (htree_node_has_left(((HTREE_NODE*)htree_element_get_element(htree_element))))
                {
                    /* linkes Kind erzeugen und anhängen */
                    htree_node_set_left((HTREE_NODE*)htree_element_get_element(htree_element), create_htree_element(NODE, create_htree_node(NULL, NULL)));
                }
                
                /* linkes Kind auswählen */
                htree_element = htree_node_get_left(((HTREE_NODE*)htree_element_get_element(htree_element)));
            }
            
            index++;
        }
        
        /* Bit mit Index holen */
        bit = codetab_element_is_bit_set(codetab_element, index);
        
        if (bit)
        {
            /* rechtes Kind erzeugen und anhängen */
            htree_node_set_right((HTREE_NODE*)htree_element_get_element(htree_element), create_htree_element(LEAF, create_htree_leaf(codetab_element_get_char(codetab_element))));
        }
        else
        {
            /* linkes Kind erzeugen und anhängen */
            htree_node_set_left((HTREE_NODE*)htree_element_get_element(htree_element), create_htree_element(LEAF, create_htree_leaf(codetab_element_get_char(codetab_element))));
        }
        
    }
    
    new_htree->root_node = root_node;
    new_htree->tree_pointer = root_node;
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
    
    if (!htree_is_emty(htree))
    {
        /* nächsten codetab_element vorbereiten */
        htree_prep_codetab_element(htree);
    }
    
    delete_htree_element(&(htree->prep_htree_element));
    
    return prep_codetab_element;
}


extern bool htree_is_emty(HTREE* htree)
{
    return htree->root_node == NULL;
}


extern bool htree_search_char(HTREE* htree, bool bit)
{
    if (htree_element_is_leaf(htree->tree_pointer))
    {
        printf("htree.c htree_search_char(): hier stimmt was nicht!");
        exit(EXIT_FAILURE);
    }
    
    if (bit)
    {
        /* @TODO: Wird das benötigt */
        if (htree_node_has_right((HTREE_NODE*)htree_element_get_element(htree->tree_pointer)))
        {
            printf("htree.c htree_search_char(): hier stimmt was nicht!");
            exit(EXIT_FAILURE);
        }
        
        /* rechtes Kind auswählen */
        htree->tree_pointer = htree_node_get_right((HTREE_NODE*)htree_element_get_element((htree->tree_pointer)));
    }
    else
    {
        /* @TODO: Wird das benötigt */
        if (htree_node_has_left((HTREE_NODE*)htree_element_get_element(htree->tree_pointer)))
        {
            printf("htree.c htree_search_char(): hier stimmt was nicht!");
            exit(EXIT_FAILURE);
        }
        
        /* linkes Kind auswählen */
        htree->tree_pointer = htree_node_get_left((HTREE_NODE*)htree_element_get_element((htree->tree_pointer)));
    }
    
    return htree_element_is_leaf(htree->tree_pointer);
}


extern unsigned char htree_get_char(HTREE* htree)
{
    /* char aus dem Element lesen auf den der tree_pointer zeigt */
    unsigned char character = htree_leaf_get_char(((HTREE_LEAF*)htree_element_get_element(htree->tree_pointer)));
    
    /* tree_pointer auf Wutzelknoten zurücksetzen */
    htree->tree_pointer = htree->root_node;
    
    return character; 
}


extern void htree_print(HTREE* htree)
{
    printf("\nBinär Baum:\n");
    htree_element_print(htree->root_node);
}


static void htree_prep_codetab_element(HTREE* htree)
{
    CODETAB_ELEMENT* codetab_element;
    bool code[256];
    bool** new_code;
    unsigned char index = 0;

    /* Wurzelknoten auswählen */
    HTREE_ELEMENT* htree_element = htree->root_node;
    
    while (!htree_element_is_leaf(htree_element))
    {
        if (htree_node_has_left((HTREE_NODE*)htree_element_get_element(htree_element)))
        {
            htree_element = htree_node_get_left((HTREE_NODE*)htree_element_get_element(htree_element));
            code[index] = false;
            index++;
        }
        else if(htree_node_has_right((HTREE_NODE*)htree_element_get_element(htree_element)))
        {
            htree_element = htree_node_get_right((HTREE_NODE*)htree_element_get_element(htree_element));
            code[index] = true;
            index++;
        }
        else
        {
            delete_htree_element(&htree_element);
            htree_element = htree->root_node;
            index = 0;
        }
    }
    
    new_code = malloc(sizeof(bool) * index);
            

    memcpy(new_code, code, sizeof(bool) * index);
    
    codetab_element = create_codetab_element(htree_leaf_get_char((HTREE_LEAF*)htree_element_get_element(htree_element)),
                                             new_code, index);
    
    htree->prep_codetab_element = codetab_element;
    
    htree->prep_htree_element = htree_element;
}