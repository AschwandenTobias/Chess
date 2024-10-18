#ifndef ROOK_H
#define ROOK_H

#include "chessboard.h"

typedef uint64_t Bitboard;

class Rook {
public:    
    static void moveWhiteRook(Chessboard &board, int startSquare, int endSquare);
    static bool isWhiteRookMoveLegal(Chessboard &board, int startSquare, int endSquare);
    static bool checkHorizontalMoves(Chessboard &board, int startSquare, int endSquare);
};

#endif