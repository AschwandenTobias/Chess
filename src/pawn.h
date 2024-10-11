#ifndef PAWN_H
#define PAWN_H

#include "chessboard.h"

typedef uint64_t Bitboard;

class Pawn {
public:
    static void moveWhitePawn(Chessboard &board, int startSquare, int endSquare);
    static bool isWhitePawnMoveLegal(Chessboard &board, int startSquare, int endSquare);
    static bool checkForEnPassant(Chessboard &board, int startSquare, int endSquare);
};

#endif