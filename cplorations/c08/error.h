/****************************************
 * C-ploration 8 for CS 271
 *
 * [NAME] Brock Berg
 * [TERM] FALL 2026
 *
 ****************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdarg.h>

#ifndef __ERROR_H__
#define __ERROR_H__

enum exitcode
{
	EXIT_INCORRECT_ARGUMENTS = 1,
	EXIT_CANNOT_OPEN_FILE,
	EXIT_TOO_MANY_INSTRUCTIONS,
	EXIT_INVALID_LABEL,
	EXIT_SYMBOL_ALREADY_EXISTS,
};

void exit_program(enum exitcode code, ...);

#endif