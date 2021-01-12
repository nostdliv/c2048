#ifndef __DEF_H___
#define __DEF_H___

enum ACTION {
    INVALID_ACTION = -1,
    MOVE_RIGHT,
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_UP,
    RESTART,
    EXIT,
    CHANGE_TILES_COUNT
};

#define SQR(x) (x*x)
typedef unsigned int uint;

#endif
