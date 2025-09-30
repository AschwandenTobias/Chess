#ifndef PAWN_H
#define PAWN_H

#include "../move.h"
#include "../position.h"


class Pawn {
public:
    static bool isMoveValid(const Move& move, const Position& position, bool white);
};

#endif