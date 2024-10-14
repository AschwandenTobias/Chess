#ifndef KNIGHT_H
#define KNIGHT_H

#include "chessboard.h"

typedef uint64_t Bitboard;

class Knight {
public:
    static void moveWhiteKnight(Chessboard &board, int startSquare, int endSquare);
    static bool isWhiteKnightMoveLegal(Chessboard &board, int startSquare, int endSquare);
    static void moveBlackKnight(Chessboard &board, int startSquare, int endSquare);
    static bool isBlackKnightMoveLegal(Chessboard &board, int startSquare, int endSquare);
};

#endif