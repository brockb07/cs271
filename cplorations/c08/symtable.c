/****************************************
 * C-ploration 8 for CS 271
 *
 * [NAME] Brock Berg
 * [TERM] FALL 2026
 *
 ****************************************/
#include "symtable.h"

struct Symbol *hashArray[SYMBOL_TABLE_SIZE];

int hash(char *str)
{
    unsigned long hash = 5381;
    int c = 0;

    while ((c = *str++))
    {
        hash = (((hash << 5) + hash) + c) % SYMBOL_TABLE_SIZE;
    }

    return hash;
}

void symtable_insert(char *name, hack_addr addr)
{
    struct Symbol *item = (struct Symbol *)malloc(sizeof(struct Symbol));
    item->name = strdup(name);
    item->addr = addr;

    int hashIndex = hash(name);
    while (hashArray[hashIndex] != NULL && hashArray[hashIndex]->name != NULL)
    {
        hashIndex++;
        hashIndex %= SYMBOL_TABLE_SIZE;
    }
    hashArray[hashIndex] = item;
}

struct Symbol *symtable_find(char *name)
{
    int hashIndex = hash(name);

    while (hashArray[hashIndex] != NULL)
    {
        if (strcmp(hashArray[hashIndex]->name, name) == 0)
        {
            return hashArray[hashIndex];
        }

        hashIndex++;
        hashIndex %= SYMBOL_TABLE_SIZE;
    }

    return NULL;
}

void symtable_display()
{
    int i = 0;
    for (i = 0; i < SYMBOL_TABLE_SIZE; i++)
    {
        if (hashArray[i] != NULL)
            printf(" (%s,%d)", hashArray[i]->name, hashArray[i]->addr);
        else
            printf(" ~~ ");
    }

    printf("\n");
}

void symtable_print_labels()
{
    int i = 0;
    for (i = 0; i < SYMBOL_TABLE_SIZE; i++)
    {
        if (hashArray[i] != NULL)
        {
            printf("{%s,%d}\n", hashArray[i]->name, hashArray[i]->addr);
        }
    }
}
