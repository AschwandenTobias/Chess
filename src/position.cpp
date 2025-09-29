#include "position.h"

Position::Position() {
   //The basic pieces
   whitePawns = 0x000000000000FF00ULL;
   whiteKnights = 0x0000000000000042ULL;
   whiteBishops = 0x0000000000000024ULL;
   whiteRooks = 0x0000000000000081ULL;
   whiteQueens = 0x0000000000000008ULL;
   whiteKing = 0x0000000000000010ULL;
   blackPawns = 0x00FF000000000000ULL;
   blackKnights = 0x4200000000000000ULL;
   blackBishops = 0x2400000000000000ULL;
   blackRooks = 0x8100000000000000ULL;
   blackQueens = 0x0800000000000000ULL;
   blackKing = 0x1000000000000000ULL;

   //More advanced Bitboards. TODO: Finish setting them up
   whiteOccupied = whitePawns | whiteKnights | whiteBishops | whiteRooks | whiteQueens  | whiteKing;
   blackOccupied = blackPawns | blackKnights | blackBishops | blackRooks | blackQueens  | blackKing;
   occupiedSquares = whiteOccupied | blackOccupied;
   emptySquares = 0x0000000000000000;
   pinnedPieces = 0x0000000000000000;
   attackMaps = 0x0000000000000000;
   checkMask = 0x0000000000000000;
   rayAttacks = 0x0000000000000000;
   betweenSquares = 0x0000000000000000;

   //Maybe for more engine efficiency
   passedPawns = 0x0000000000000000;
   isolatedPawns = 0x0000000000000000;

    whiteTurn = true;
}

bool Position::isOccupied(int square) const {
    uint64_t mask = 1ULL << square;
    return (occupiedSquares & mask) != 0;
}

bool Position::isWhitePawn(int square) const {
    uint64_t mask = 1ULL << square;
    return (whitePawns & mask) != 0;
}

bool Position::isOccupiedByWhitePiece(int square) const {
    uint64_t mask = 1ULL << square;
    return (whiteOccupied & mask) != 0;
}

bool Position::isOccupiedByBlackPiece(int square) const {
    uint64_t mask = 1ULL << square;
    return (blackOccupied & mask) != 0;
}