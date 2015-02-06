
#include "htree_element.h"

#include <stdbool.h>

struct S_HTREE_ELEMENT
{
    union
    {
        HTREE_LEAF leaf;
        HTREE_NODE node;
    } element;
    bool is_leaf;
};


struct S_HTREE_LEAF
{
    unsigned char character;
    unsigned long frequency;
};


struct S_HTREE_NODE
{
    HTREE_ELEMENT* left_child;
    HTREE_ELEMENT* right_child;
    unsigned long weight;
};
