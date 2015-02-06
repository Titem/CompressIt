

#include "codetab.h"

#include "codetab_element.h"

struct S_CODETAB 
{
    unsigned char length;
    CODETAB_ELEMENT* element[256];
};


extern CODETAB* create_codetab(HTREE* htree)
{
    
}

extern CODETAB* read_codetab(FILE* input_stream)
{
    
}

extern void wirte_codetab(FILE* output_stream, CODETAB* codetab)
{
    
}

extern void delete_codetab(CODETAB* codetab)
{
    
}

extern unsigned short codetab_get_code(CODETAB* codetab, 
                                       unsigned char character)
{
    
}

extern unsigned char codetab_get_char(CODETAB* codetab, unsigned short code)
{
    
}