#include <stdio.h>

extern char* g_v_field;

extern int g_field_size_x, g_field_size_y;

void drawField() {
    for (int i = 0; i < (g_field_size_x * g_field_size_y); i++) {
        if (i % g_field_size_x == 0) {
            putchar('\n');
        }
        putchar(g_v_field[i]);
    }
    putchar('\n');
}
