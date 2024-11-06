#ifndef PAWN_H
#define PAWN_H

#include "../chessboard.h"

typedef uint64_t Bitboard;

class Pawn {
public:
    static void moveWhitePawn(Chessboard &board, int startSquare, int endSquare);
    static bool isWhitePawnMoveLegal(Chessboard &board, int startSquare, int endSquare);
    static bool checkForWhiteEnPassant(Chessboard &board, int startSquare, int endSquare);
    static void moveBlackPawn(Chessboard &board, int startSquare, int endSquare);
    static bool isBlackPawnMoveLegal(Chessboard &board, int startSquare, int endSquare);
    static bool checkForBlackEnPassant(Chessboard &board, int startSquare, int endSquare);
    static bool canPawnAttackSquare(Chessboard &board, int square, bool white);

};

#endif