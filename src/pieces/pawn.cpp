#include <iostream>
#include "pawn.h"
#include "../position.h"


bool isMoveValid(const Move& move, const Position& position) {
    //First check if white pawn is on from
    //Check it distance makes sense for a pawn move
    //Check if capture would be possible
    //Check for 2nd/7nth row double pawn move
    //Check for en passant
    //Check for promotion
    uint64_t fromMask = 1ULL << move.from;
    uint64_t toMask = 1ULL << move.to;

    

    return false;
}