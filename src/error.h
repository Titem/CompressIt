#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

<<<<<<< HEAD
/*---------------------------------------------------------------------------------*/
/*-----------------------------------ENUM FÜR FEHLER-------------------------------*/
/*---------------------------------------------------------------------------------*/
=======

>>>>>>> origin/master
enum error_message
{
	dont_found_input_document,
	dont_found_compress_mode,
	too_many_arguments,
	cant_malloc_memory,
	in_and_output_document_are_the_same,
	help,
	AND,
};


/*---------------------------------------------------------------------------------*/
/*---------------------PRÜFT EINEN STREAM AUF FEHLER-------------------------------*/
/*---------------------------------------------------------------------------------*/
extern void test_nullpointer_exception(FILE *file_p, char* file_name);

/*---------------------------------------------------------------------------------*/
/*---------------------GIBT DENN FEHLER AUF DEM BILDSCHIRM AUS---------------------*/
/*---------------------------------------------------------------------------------*/
void print_error(int error_message);