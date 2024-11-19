#ifndef ENGINE_H
#define ENGINE_H

#include <cstdint>
#include <vector>
#include <utility>
#include "../chessboard.h" 


class Engine {
public:
    Engine() = default;

    static int evaluationFunction(Chessboard &board);
    static std::pair<int, int> selectMove(std::vector<std::pair<int, int>> possibleMoves, bool white);
};

#endif
