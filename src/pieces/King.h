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
    static bool isSquareInWhiteCheck(Chessboard & board, int square);
    static bool isWhiteKingInCheck(Chessboard &board);
    static bool checkBlackBishopMovesForCheck(Chessboard &board, int startSquare);
    static bool checkBlackKnightMovesForCheck(Chessboard &board, int startSquare);

};

#endif