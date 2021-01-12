#include <string.h>

#include <def.h>
#include <input/input.h>

enum ACTION inputToAction(const char* input) {
    return
        !strcmp(input, "w") ? MOVE_UP :
        !strcmp(input, "a") ? MOVE_LEFT :
        !strcmp(input, "s") ? MOVE_DOWN :
        !strcmp(input, "d") ? MOVE_RIGHT :
        !strcmp(input, "q") ? EXIT : INVALID_ACTION;
}