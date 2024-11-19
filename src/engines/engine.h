#ifndef ENGINE_H
#define ENGINE_H

#include <cstdint>
#include <vector>
#include <utility>
#include "../chessboard.h" 


class Engine {
public:
    Engine() = default;

    static int evaluationFunction(Chessboard &board, bool white);
    static std::pair<int, int> selectMove(Chessboard &board, std::vector<std::pair<int, int>> possibleMoves, bool white);
    static int minimax(Chessboard &board, int depth, int alpha, int beta, bool isMaximizingPlayer, bool white);
};

#endif
