#ifndef INPUT_H
#define INPUT_H

#include <def.h>
#include <CStringLinkedList.h>

enum ACTION inputToAction(const char* input);

typedef struct {
    enum ACTION action;
    CStrLL_t* ll_strings;
} cmd_t;

#endif