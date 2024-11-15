#ifndef RANDOMENGINE_H
#define RANDOMENGINE_H

#include <cstdint>
#include <vector>
#include <utility>
#include "../chessboard.h"

class Chessboard; 

class RandomEngine {
public:
    RandomEngine() = default; 
    std::pair<int, int> generateRandomMove(Chessboard& board, bool isWhite);
};

#endif
