#include <stdio.h>
#include <def.h>

extern char g_tile_border;

extern uint* g_v_tiles_state;
extern char* g_v_field;
extern int g_cells, g_field_size_x, g_field_size_y;

void renderTileBorders() {
    for (int i = 0; i < SQR(g_cells); i++) {
        if (g_v_tiles_state[i]) {
            int y_in_cell_coords = i / g_cells;
            int x_in_cell_coords = i % g_cells;

            int cell_size_y = (g_field_size_y / g_cells);
            int cell_size_x = (g_field_size_x / g_cells);

            int tile_size_y = cell_size_y - cell_size_y / 8;
            int tile_size_x = cell_size_x - cell_size_x / 8;

            int tile_offset_y = cell_size_y / 8;
            int tile_offset_x = cell_size_x / 8;

            int y = (y_in_cell_coords * cell_size_y);
            int x = (x_in_cell_coords * cell_size_x);

            // vertical borders
            for (int j = 0; j < tile_size_y; j++) {
                int index = ((y+tile_offset_y) + j) * g_field_size_x + (x+tile_offset_x);
                g_v_field[index] = g_tile_border;
                g_v_field[index + tile_size_x] = g_tile_border;
            }
            // horizontal borders
            for (int j = 0; j < tile_size_x+1; j++) {
                int index = (y+tile_offset_y) * g_field_size_x + ((x+tile_offset_x) + j);
                g_v_field[index] = g_tile_border;
                index = ((y+tile_offset_y) + tile_size_y) * g_field_size_x + ((x+tile_offset_x)+j);
                g_v_field[index] = g_tile_border;
            }
        }
    }
}

