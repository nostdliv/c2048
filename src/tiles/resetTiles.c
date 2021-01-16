#include <stdlib.h>
#include <string.h>

#include <def.h>

#include <tiles.h>

extern int* g_v_tiles_state;
extern int g_cells;

void resetTiles() {
    memset(g_v_tiles_state, 0, sizeof(int) * SQR(g_cells));
    tryCreateNewTile();
    tryCreateNewTile();
}