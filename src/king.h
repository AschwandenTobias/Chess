#ifndef KING_H
#define KING_H
#include "chessboard.h"

typedef uint64_t Bitboard;
class King {
public:
    static void moveWhiteKing(Chessboard &board, int startSquare, int endSquare);
    static bool isWhiteKingMoveLegal(Chessboard &board, int startSquare, int endSquare);
};

#endif