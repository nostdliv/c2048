#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <def.h>

extern uint* g_v_tiles_state;
extern char* g_v_field;
extern int g_cells, g_field_size_x, g_field_size_y;

void renderTiles() {
    uint* v_tiles_to_draw = malloc(sizeof(int) * SQR(g_cells));
        memset(v_tiles_to_draw, 0, sizeof(int) * SQR(g_cells));
    int tiles_to_draw_index = 0;

    for (int i = 0; i < SQR(g_cells); i++) {
        if (g_v_tiles_state[i] != 0) v_tiles_to_draw[tiles_to_draw_index++] = i;
    }

    for (int i = 0; i < tiles_to_draw_index; i++) {
        int tilex = v_tiles_to_draw[i] % g_cells;
        int tiley = v_tiles_to_draw[i] / g_cells;
        int x = tilex * (g_field_size_x / g_cells);
        int y = tiley * (g_field_size_y / g_cells);

        char value_to_write[16];
        sprintf(value_to_write, "%d", g_v_tiles_state[v_tiles_to_draw[i]]);

        x += (g_field_size_x / g_cells) / 2 - strlen(value_to_write) / 2;
        y += (g_field_size_y / g_cells) / 2;

        for (int i = 0; i < strlen(value_to_write); i++) {
            g_v_field[y * g_field_size_x + x + i] = value_to_write[i];
        }
    }

    free(v_tiles_to_draw);
}
