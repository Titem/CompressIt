#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>


/*Jede C-Anwendung muss genau eine Main-Methode enthalten, in der angegeben ist, wo die Programmausführung beginnen soll.*/
int main(int argc, char** argv);


int main(int argc, char** argv)
{
	/*Für die Zeit zuständig.*/
	clock_t begin;
	clock_t end;
	/*Timer starten*/
	begin = clock();




	/*CODE*/






	/*Timer beenden*/
	end = clock();


	printf("Benoetigte Zeit: %i ms", end - begin);
#ifdef VisualStudio
	getch();
#endif
	return 0;
}

