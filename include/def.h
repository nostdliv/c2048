#ifndef DEF_H
#define DEF_H

#ifdef WIN32
#define CLEARSCREEN system("cls")
#else
#define CLEARSCREEN system("clear")
#endif

enum ACTION {
    INVALID_ACTION = -1,
    MOVE_RIGHT,
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_UP,
    RESTART,
    EXIT
};

struct game_state {
    int score;
    char quit;
};

#define SQR(x) (x*x)
typedef unsigned int uint;

#endif
