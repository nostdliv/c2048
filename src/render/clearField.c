#include <stdlib.h>
#include <string.h>

extern char* g_v_field;
extern int g_field_size_x, g_field_size_y;

void clearField() {
    memset(g_v_field, ' ', sizeof(char) *
           (g_field_size_x * g_field_size_y));
}
