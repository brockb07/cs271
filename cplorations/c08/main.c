/****************************************
 * C-ploration 8 for CS 271
 *
 * [NAME] Brock Berg
 * [TERM] FALL 2026
 *
 ****************************************/
#include "parser.h"
#include "symtable.h"
#include "error.h"

int main(int argc, const char *argv[])
{
	if (argc != 2)
	{
		exit_program(EXIT_INCORRECT_ARGUMENTS, argv[0]);
	}

	FILE *fin = fopen(argv[1], "r");
	if (fin == NULL)
	{
		exit_program(EXIT_CANNOT_OPEN_FILE, argv[1]);
	}

	parse(fin);
	fclose(fin);
}
