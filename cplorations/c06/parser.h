/****************************************
 * C-ploration 6 for CS 271
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

#define MAX_LINE_LENGTH  200
#define MAX_LABEL_LENGTH  MAX_LINE_LENGTH - 2

enum instr_type {
    INVALID = -1,
    A_TYPE,
    C_TYPE,
};

typedef int16_t hack_addr;
typedef int16_t opcode;

typedef struct c_instruction {
    opcode a:1;
    opcode comp:6;
    opcode dest:3;
    opcode jump:3;

} c_instruction;

typedef struct a_instruction {
    union a_type {
        hack_addr address;
        char *label;
    };
    bool is_addr;

} a_instruction;

typedef struct instruction {
    union inst_type{
        c_instruction C_inst;
        a_instruction A_inst;
    };
    enum instr_type type;
};


/** function prototypes **/
bool is_Atype(const char *);
bool is_label(const char *);
bool is_Ctype(const char *);


char *strip(char *s);
char *extract_label(const char *line, char* label);

void parse(FILE * file);
