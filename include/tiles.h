#ifndef TILES_H
#define TILES_H

#include <def.h>

int tryCreateNewTile();

// try to make move
// returns sum of tiles merged, and -1 if move in this direction cannot be done
int tryMove(enum ACTION move);

// resets all tiles, and create new two
void resetTiles();

#endif