#ifndef POSITION_H
#define POSITION_H
#include <cstdint>

#include "piece.h"

class Position {
public:
    Position();
    //The basic pieces
    uint64_t whitePawns;
    uint64_t whiteKnights;
    uint64_t whiteBishops;
    uint64_t whiteRooks;
    uint64_t whiteQueens;
    uint64_t whiteKing;
    uint64_t blackPawns;
    uint64_t blackKnights;
    uint64_t blackBishops;
    uint64_t blackRooks;
    uint64_t blackQueens;
    uint64_t blackKing;

    //More advanced Bitboards
    uint64_t occupiedSquares;
    uint64_t emptySquares;
    uint64_t whiteOccupied;
    uint64_t blackOccupied;
    uint64_t pinnedPieces;
    uint64_t attackMaps;
    uint64_t checkMask;
    uint64_t rayAttacks;
    uint64_t betweenSquares;

    //Maybe for more engine efficiency
    uint64_t passedPawns;
    uint64_t isolatedPawns;

    bool whiteTurn;
    bool isOccupied(int square) const;
    bool isPieceAt(int square, PieceType piece) const;
    PieceType getPieceAt(int square);
    bool isOccupiedByWhitePiece(int square) const;
    bool isOccupiedByBlackPiece(int square) const;
};

#endif