#ifndef KING_H
#define KING_H

#include "../move.h"
#include "../position.h"


class King {
public:
    static bool isMoveValid(const Move& move, const Position& position, bool white);
};

#endif