#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <cstdint>

typedef uint64_t Bitboard;
class Chessboard {
public:
    Bitboard whitePawns;
    Bitboard whiteRooks;
    Bitboard whiteKnights;
    Bitboard whiteBishops;
    Bitboard whiteQueen;
    Bitboard whiteKing;
    Bitboard blackPawns;
    Bitboard blackRooks;
    Bitboard blackKnights;
    Bitboard blackBishops;
    Bitboard blackQueen;
    Bitboard blackKing;
    Chessboard();
    void printBoard();
    void moveWhitePawn(int startSquare, int endSquare);
};

#endif