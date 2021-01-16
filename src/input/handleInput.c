#include <string.h>

#include <def.h>
#include <input.h>
#include <tiles.h>
#include <game.h>

extern struct game_state g_game_state;

enum ACTION getActionFromString(const char* input) {
    return
        !strcmp(input, "w") ? MOVE_UP :
        !strcmp(input, "a") ? MOVE_LEFT :
        !strcmp(input, "s") ? MOVE_DOWN :
        !strcmp(input, "d") ? MOVE_RIGHT :
        !strcmp(input, "r") ? RESTART :
        !strcmp(input, "q") ? EXIT : INVALID_ACTION;
}

int handleInput(const char* input) {
    enum ACTION action = getActionFromString(input);
    if ((action == MOVE_UP)     ||
        (action == MOVE_LEFT)   ||
        (action == MOVE_DOWN)   ||
        (action == MOVE_RIGHT))
    {
        int ret = tryMove(action);
        if (ret < 0) return 0; // move failed, no need to rerender
        else {
            tryCreateNewTile(); // move done succesfully, we need to create a new tile
            g_game_state.score += ret;
            return 1; // rerender needed
        }
    } else if (action == RESTART) {
        gameOver();
    } else if (action == EXIT) {
        g_game_state.quit = 1;
    }
}
