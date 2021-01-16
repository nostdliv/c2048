#include <stdio.h>
#include <stdlib.h>
#include <def.h>

extern uint* g_v_tiles_state;
extern int g_cells;

void _move(int* p_row);
int _merge(int* p_row);

int tryMove(enum ACTION move) {
    if ((move != MOVE_LEFT)  &&
        (move != MOVE_RIGHT) &&
        (move != MOVE_DOWN)  &&
        (move != MOVE_UP)) return -2;
    // movements will be done row(column) by row(column)
    // with two functions written to make moves in the direction
    // of index increasing

    int score_inc = 0; // value to be added to global score

    // for that needs we allocating an array that will store
    // current row(column) to pass a pointer to movement functions
    int* v_row = malloc(sizeof(int) * g_cells);

    // we will check initial g_v_tiles_state state
    // and compare it after all movement calls
    // if they are same (states), function will return 1
    // to tell caller that move in that direction can't be done
    int* v_tiles_before = malloc(sizeof(int) * SQR(g_cells));
    for (int i = 0; i < SQR(g_cells); i++) {
        v_tiles_before[i] = g_v_tiles_state[i];
    }
    char move_done = 0; // flag to be changed at the end

    if (move == MOVE_RIGHT) {
        for (int y = 0; y < g_cells; y++) {
            int b_i = y * g_cells; // base index
            // (index of [0, y] tile in g_v_tiles_state)

            // copying y-th row into v_row
            for (int i = 0; i < g_cells; i++) {
                v_row[i] = g_v_tiles_state[b_i + i];
            }

            _move(v_row);
            score_inc += _merge(v_row);
            // calling move again, because merging could create empty tiles
            _move(v_row);

            for (int i = 0; i < g_cells; i++) {
                g_v_tiles_state[b_i + i] = v_row[i];
            }
        }

    } else if (move == MOVE_LEFT) {
        for (int y = 0; y < g_cells; y++) {
            int b_i = y * g_cells; // base index
            // (index of [g_cells, y] tile in g_v_tiles_state)
            // because we will be subtrating i

            // reverse copying y-th row into v_row
            for (int x = 0; x < g_cells; x++) {
                v_row[x] = g_v_tiles_state[b_i + g_cells - x - 1];
                // more readable: [(b_i + g_cells)- (x + 1)]
                // like in MOVE_RIGHT, but reversed
            }

            _move(v_row);
            score_inc += _merge(v_row);
            // calling move again, because merging could create empty tiles
            _move(v_row);

            for (int x = 0; x < g_cells; x++) {
                g_v_tiles_state[b_i + g_cells - x - 1] = v_row[x];
                // same logic as in reading loop
            }
        }
    } else if (move == MOVE_DOWN) {
        for (int x = 0; x < g_cells; x++) {
            // copying x-th column into v_row
            for (int y = 0; y < g_cells; y++) {
                v_row[y] = g_v_tiles_state[y * g_cells + x];
            }
            
            _move(v_row);
            score_inc += _merge(v_row);
            // calling move again, because merging could create empty tiles
            _move(v_row);

            for (int y = 0; y < g_cells; y++) {
                g_v_tiles_state[y * g_cells + x] = v_row[y];
                // same logic as in reading loop
            }
        }
    } else if (move == MOVE_UP) {
        for (int x = 0; x < g_cells; x++) {
            // reverse copying x-th column into v_row
            for (int y = 0; y < g_cells; y++) {
                v_row[y] = g_v_tiles_state[(g_cells - y - 1) * g_cells + x];
            }

            _move(v_row);
            score_inc += _merge(v_row);
            // calling move again, because merging could create empty tiles
            _move(v_row);

            for (int y = 0; y < g_cells; y++) {
                g_v_tiles_state[(g_cells - y - 1) * g_cells + x] = v_row[y];
                // same logic as in reading loop
            }
        }
    }

    free(v_row);

    // comparing states to tell was move done or not
    for (int i = 0; i < SQR(g_cells); i++) {
        if (g_v_tiles_state[i] != v_tiles_before[i]) {
            move_done = 1;
            break;
        }
    }

    free(v_tiles_before);

    if (move_done) return score_inc;
    else return -1;
}

int _merge(int* p_row) {
    int sum = 0; // value that will be stored in score_inc
    // merging two tiles if they are identical
    for (int i = g_cells - 1; i > 0; i--) {
        if (p_row[i] == p_row[i - 1] &&
                p_row[i] != 0)
        {
            p_row[i] *= 2;
            sum = p_row[i];
            p_row[i - 1] = 0;
        }
    }
    return sum;
}

void _move(int* p_row) {
    char completed = 1;
    // boolean to controll the recursion

    for (int i = 0; i < g_cells - 1; i++) {
        if (p_row[i + 1] == 0 && p_row[i] != 0) {
            p_row[i + 1] = p_row[i];
            p_row[i] = 0;
        }
    }

    // reverse checking for zeros between other numbers
    // if even one appears, setting completed to false
    for (int i = g_cells - 1; i > 0; i--) {
        if (p_row[i] == 0 && p_row[i - 1] != 0) {
            completed = 0;
            break;
        }
    }
    // calling self if needed
    if (!completed) {
        _move(p_row);
    }
}
