/****************************************
 * C-ploration 7 for CS 271
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

#define SYMBOL_TABLE_SIZE 1000

typedef int16_t hack_addr;

struct Symbol
{
    char *name;
    hack_addr addr;
};

int hash(char *str);
struct Symbol *symtable_find(char *name);
void symtable_insert(char *name, hack_addr addr);
void symtable_display_table();
void symtable_print_labels();