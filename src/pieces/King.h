#ifndef KING_H
#define KING_H
#include "../chessboard.h"

typedef uint64_t Bitboard;
class King {
public:
    static void moveWhiteKing(Chessboard &board, int startSquare, int endSquare);
    static bool isWhiteKingMoveLegal(Chessboard &board, int startSquare, int endSquare);
    static void moveBlackKing(Chessboard &board, int startSquare, int endSquare);
    static bool isBlackKingMoveLegal(Chessboard &board, int startSquare, int endSquare);
    static bool isSquareInCheck(int square);
    static bool isKingInCheck(Chessboard &board);
};

#endif