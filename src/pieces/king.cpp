#include <iostream>
#include "king.h"

bool King::isMoveValid(const Move& move, const Position& position, bool white) {
    int from = move.from;
    int to = move.to;
    int distance = std::abs(from - to);
    
    return true;
}