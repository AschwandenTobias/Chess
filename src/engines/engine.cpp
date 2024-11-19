#include "engine.h"
#include <iostream>
#include "../chessboard.h"

const int pawnValue = 100;
const int rookValue = 500;
const int knightValue = 300;
const int bishopValue = 300;
const int queenValue = 900;

int Engine::evaluationFunction(Chessboard &board) {
    int score = 0;
    return score;
}

std::pair<int, int> Engine::selectMove(std::vector<std::pair<int, int>> possibleMoves, bool white) {
    std::pair<int, int> selectedMove;
    return selectedMove;
}
