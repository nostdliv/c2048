#include <stdlib.h>
#include <def.h>

extern uint* g_v_tiles_state;
extern int g_cells;

int tryCreateNewTile() {
    int tileset[2] = { 2, 4 };
    uint* v_free_tiles = malloc(sizeof(uint) * SQR(g_cells));
    uint free_tiles_index = 0;
    for (int i = 0; i < SQR(g_cells); i++) {
        if (g_v_tiles_state[i] == 0) {
            v_free_tiles[free_tiles_index++] = i;
        }
    }
    g_v_tiles_state[v_free_tiles[rand() % free_tiles_index]] = tileset[rand() % 2];
    free(v_free_tiles);
    if (free_tiles_index < 1) return -1;
    return 0;
}
