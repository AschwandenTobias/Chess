#ifndef BISHOP_H
#define BISHOP_H

#include "../chessboard.h"
#include <vector>

typedef uint64_t Bitboard;

class Bishop {
public:    
    static void moveWhiteBishop(Chessboard &board, int startSquare, int endSquare);
    static bool isWhiteBishopMoveLegal(Chessboard &board, int startSquare, int endSquare);    
    static void moveBlackBishop(Chessboard &board, int startSquare, int endSquare);
    static bool isBlackBishopMoveLegal(Chessboard &board, int startSquare, int endSquare);
    static bool checkDiagonalMoves(Chessboard &board, int startSquare, int endSquare);
    static std::vector<int> getAttackingSquares(Chessboard &board, int startSquare, int  endSquare);
};

#endif