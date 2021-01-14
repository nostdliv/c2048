#include <string.h>

#include <def.h>
#include <input/handleInput.h>

extern struct game_state g_game_state;

enum ACTION getActionFromString(const char* input) {
    return
        !strcmp(input, "w") ? MOVE_UP :
        !strcmp(input, "a") ? MOVE_LEFT :
        !strcmp(input, "s") ? MOVE_DOWN :
        !strcmp(input, "d") ? MOVE_RIGHT :
        !strcmp(input, "q") ? EXIT : INVALID_ACTION;
}

void handleInput(const char* input) {
    enum ACTION action = getActionFromString(input);
}
