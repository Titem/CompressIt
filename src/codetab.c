

#include "codetab.h"

#include "codetab_element.h"

struct S_CODETAB 
{
    unsigned char length;
    CODETAB_ELEMENT* element[256];
};
