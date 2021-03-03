#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include <render.h>

#include <tiles.h>

#include <input.h>

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

struct game_state g_game_state = {0, 0};

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

    // text buffer to render to
    g_v_field = malloc(sizeof(int) * (g_field_size_x * g_field_size_y));
        memset(g_v_field, ' ', sizeof(int) * (g_field_size_x * g_field_size_y));

    // array that will contain tiles state
    g_v_tiles_state = malloc(sizeof(int) * SQR(g_cells));
        // no memset because resetTiles() doing it anyway
        resetTiles();
    
    char rerender_needed = 1; // will store the return value of handleInput();

    while (!g_game_state.quit) {
        if (rerender_needed) {
            CLEARSCREEN;
            printf("%d\n", g_game_state.score);
            clearField();
            renderBorders();
            renderTileBorders();
            renderTiles();
            drawField();
        }

        char* input = malloc(sizeof(char) * 5);
        fgets(input, 2, stdin);

        rerender_needed = handleInput(input);

        free(input);
    }

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
