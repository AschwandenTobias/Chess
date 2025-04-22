#ifndef MOVE_H
#define MOVE_H

struct Move {
    int from;
    int to;
    char promotion;
    bool castling;
};

#endif