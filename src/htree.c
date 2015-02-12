
/* ======================================================================== *
 * Header-Dateien                                                           *
 * ======================================================================== */

#include "htree.h"

#include <stdlib.h>

#include "freqtab.h"
#include "freqtab_element.h"
#include "codetab.h"
#include "codetab_element.h"
#include "htree_element.h"
#include "pqueue.h"




/* ======================================================================== *
 * Strukturdefinitionen                                                     *
 * ======================================================================== */

struct S_HTREE
{
    CODETAB_ELEMENT* prep_codetab_element;
    HTREE_ELEMENT* tree_pointer;
    HTREE_ELEMENT* root_node;
};




/* ======================================================================== *
 * Funktionsdefinitionen                                                    *
 * ======================================================================== */

extern HTREE* create_htree_from_freqtab(FREQTAB* freqtab)
{
    FREQTAB_ELEMENT* freqtab_element;
    
    while (freqtab_is_emty(freqtab))
    {
        /* freqtab_element aus freqtab entnehmen */
        freqtab_element = freqtab_get_element(freqtab);
    
        /* htree_leaf erstellen mit character und frequency des entnommenen 
         * freqtab_element */
        create_htree_element(LEAF, (void*) create_htree_leaf
                (freqtab_element_get_char(freqtab_element), 
                 freqtab_element_get_frequency(freqtab_element)));
    
    /* neuen htree_leaf der pqueue hinzufügen */
    
    }
    
    /* 2 htree_elemente mit minimalem Gewicht aus der pqueue entnehmen */
    
    /* die zwei entnommenen htree_elemente zusammenführen */
    
    /* zusammengeführtes htree_element der pqueue hinzufügen */
    
    
    /* letztes htree_element aus pqueue entnehmen */
    
    /* htree erzeugen mit dem letzten htree_element als root */
}

extern HTREE* create_htree_from_codetab(CODETAB* codetab)
{
    return NULL;
}

extern void delete_htree(HTREE* htree)
{
    
}

extern CODETAB_ELEMENT* htree_get_codetab_element(HTREE* htree)
{
    return NULL;
}

extern bool htree_is_emty(HTREE* htree)
{
    return false;
}

extern bool htree_search_char(HTREE* htree, bool bit)
{
    return false;
}

extern unsigned char htree_get_char(HTREE* htree)
{
    return 0;
}

extern void htree_print(HTREE* htree)
{
    
}

extern void htree_prep_codetab_element(void)
{
    
}