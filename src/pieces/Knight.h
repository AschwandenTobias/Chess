#ifndef KNIGHT_H
#define KNIGHT_H

#include "../chessboard.h"
#include <vector>

typedef uint64_t Bitboard;

class Knight {
public:
    static void moveWhiteKnight(Chessboard &board, int startSquare, int endSquare);
    static bool isWhiteKnightMoveLegal(Chessboard &board, int startSquare, int endSquare);
    static void moveBlackKnight(Chessboard &board, int startSquare, int endSquare);
    static bool isBlackKnightMoveLegal(Chessboard &board, int startSquare, int endSquare);
    static std::vector<int> getAttackingSquares(Chessboard &board, int startSquare, int  endSquare);
    static std::vector<std::pair<int, int>> getAllPossibleKnightMoves(Chessboard &board, bool white);
    static bool isKnightMoveLegal(Chessboard &board, Move move, bool white);
};

#endif