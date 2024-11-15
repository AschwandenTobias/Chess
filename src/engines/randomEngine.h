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
    std::pair<int, int> selectRandomMove(std::vector<std::pair<int, int>> allMoves, bool isWhite);
};

#endif
