#ifndef INPUT_H
#define INPUT_H

#include <def.h>
#include <CStringLinkedList.h>

// returns 1 if redraw is needed, otherwise returns 0
int handleInput(const char* input);

typedef struct {
    enum ACTION action;
    CStrLL_t* ll_strings;
} cmd_t;

#endif