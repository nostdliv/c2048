#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include <clearField.h>
#include <drawField.h>
#include <renderTileBorders.h>
#include <renderTiles.h>

#include <tryCreateNewTile.h>
#include <tryMove.h>

#include <def.h>

#define CELLS 4

#define FIELD_SIZE_X 30
#define FIELD_SIZE_Y 15

#define BORDER '#'
#define TILE_BORDER '#'

char g_border = BORDER;
char g_tile_border = TILE_BORDER;

int g_field_size_x = FIELD_SIZE_X;
int g_field_size_y = FIELD_SIZE_Y;

int g_cells;

uint* g_v_tiles_state;
char* g_v_field;

void renderBorders();

int main(int argc, char** argv) {
    if (argc > 1) {
        if (argc == 2) {
            sscanf(argv[1], "%d", &g_cells);
            // checking for invalid tiles count
            if (g_cells < 3 || g_cells > 6) {
                puts("invalid tiles count (must be from 3 to 6)");
                return -1;
            }
        }
    } else {
        g_cells = CELLS;
    }
    srand(time(0));
    g_v_tiles_state = malloc(sizeof(int) * SQR(g_cells));
        memset(g_v_tiles_state, 0, sizeof(int) * SQR(g_cells));

    g_v_field = malloc(sizeof(int) * (g_field_size_x * g_field_size_y));
        memset(g_v_field, ' ', sizeof(int) * (g_field_size_x * g_field_size_y));


    // creating two inital tiles
    tryCreateNewTile();
    tryCreateNewTile();
    // kinda game loop

    renderBorders();
    renderTileBorders();
    renderTiles();
    drawField();

    tryMove(MOVE_UP);

    clearField();
    renderBorders();
    renderTileBorders();
    renderTiles();
    drawField();
    // game loop end

    free(g_v_tiles_state);
    free(g_v_field);
    putchar('\n');
    return 0;
}

void renderBorders() {
    for (int i = 0; i < g_field_size_x; i++) {
        g_v_field[i] = g_border;
        g_v_field[g_field_size_x * (g_field_size_y - 1) + i] = g_border;
    }
    for (int i = 0; i < g_field_size_y; i++) {
        g_v_field[i * g_field_size_x] = g_border;
        g_v_field[i * g_field_size_x + g_field_size_x - 1] = g_border;
    }
}

