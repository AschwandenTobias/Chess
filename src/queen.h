#ifndef QUEEN_H
#define QUEEN_H

#include "chessboard.h"

typedef uint64_t Bitboard;

class Queen {
public:    
    static void moveWhiteQueen(Chessboard &board, int startSquare, int endSquare);
    static bool isWhiteQueenMoveLegal(Chessboard &board, int startSquare, int endSquare);
    static void moveBlackQueen(Chessboard &board, int startSquare, int endSquare);
    static bool isBlackQueenMoveLegal(Chessboard &board, int startSquare, int endSquare);
};

#endif