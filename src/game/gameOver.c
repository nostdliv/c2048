#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <def.h>
#include <tiles.h>

extern struct game_state g_game_state;
extern int* g_v_tiles_state;
extern int g_cells;

void reset() {
    resetTiles();
    g_game_state.score = 0;
}

void gameOver() {
    char* buf = malloc(sizeof(char) * 4);
begin:
    CLEARSCREEN;
    printf("Game Over!\nYour score: %d\n\nPlay again? [y/n]: ", g_game_state.score);
    fgets(buf, 2, stdin);
    if (!strcmp(buf, "y")) {
        reset();
    } else if (!strcmp(buf, "n")) {
        g_game_state.quit = 1;
    } else {
        goto begin;
    }
    free(buf);
    return;
}
